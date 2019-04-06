/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junkFood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:15:49 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/04/05 20:03:09 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

struct s_node		*getStart(struct s_graph *graph, char *youAreHere)
{
  for (int i = 0; graph->places[i]; i++)
    if (strcmp(graph->places[i]->name, youAreHere) == 0)
      return graph->places[i];
  return NULL;
}

void	resetVisited(struct s_node *start)
{
  struct s_queue	*q = queueInit();
  struct s_node	*node;

  enqueue(q, start);
  while (q->first)
  {
    node = dequeue(q);
    node->visited = 0;
    for (int i = 0; node->connectedPlaces[i]; i++) {
      struct s_node *kid = node->connectedPlaces[i];
      if (kid->visited)
        enqueue(q, kid);
    }
  }
}

struct s_sellers	*buildAnswer(struct s_queue *queue, int dist, int count)
{
	struct s_sellers *ret = malloc(sizeof(struct s_sellers));
	ret->placeNames = calloc(count + 1, sizeof(char*));
	ret->distance = dist;
	for (int i = 0; i < count; i++)
		ret->placeNames[i] = dequeue(queue)->name;
	return (ret);
}

struct s_sellers *closestSellers(struct s_graph *graph, char *youAreHere) {
  struct s_queue  *q = queueInit();
  struct s_queue  *ret = queueInit();

  int             dist = 0, count = 0;
  struct s_node   *start = getStart(graph, youAreHere);

  if (!start) return NULL;

  enqueue(q, start);
  enqueue(q, NULL);
  while (q->first || q->last) {
    while (1) {
      struct s_node *current = dequeue(q);
      if (!current) break;
      current->visited = 1;

      if (current->hasCerealBar) {
        count++;
        enqueue(ret, current);
      }
      else {
        for (int i = 0; current->connectedPlaces[i]; i++) {
          struct s_node *kid = current->connectedPlaces[i];
          if (!kid->visited) {
            kid->visited = 1;
            enqueue(q, kid);
          }
        }
      }
    }
    enqueue(q, NULL);
    if (count > 0) break ;
    dist++;
  }
  resetVisited(start);
  return buildAnswer(ret, dist, count);
}
