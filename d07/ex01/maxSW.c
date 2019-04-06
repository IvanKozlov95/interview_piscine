/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxSW.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:36:08 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/04/05 18:24:45 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "header.h"

struct s_dequeNode *newNode(int value) {
  struct s_dequeNode *new = calloc(1, sizeof(struct s_dequeNode));
  new->value = value;
  return new;
}

struct s_deque *dequeInit(void) {
  struct s_deque *new = calloc(1, sizeof(struct s_deque));
  return new;
}

void setEmpty(struct s_deque *deque, struct s_dequeNode *node) {
  deque->first = node;
  deque->last = node;
}

void pushFront(struct s_deque *deque, int value) {
  struct s_dequeNode *new = newNode(value);

  new->next = deque->first;
	if (deque->first)
		deque->first->prev = new;
	deque->first = new;
	if (!deque->last)
		deque->last = new;;
}

void pushBack(struct s_deque *deque, int value) {
  struct s_dequeNode *new = newNode(value);

  new->prev = deque->last;
	if (deque->last)
		deque->last->next = new;
	deque->last = new;
	if (!deque->first)
		deque->first = new;
}

int popFront(struct s_deque *deque) {
  struct s_dequeNode *tmp = deque->first;
  int                 ret = INT_MIN;

	if (tmp) {
    ret = tmp->value;
    deque->first = tmp->next;
    if (!deque->first)
      deque->last = NULL;
    else
      deque->first->prev = NULL;
    free(tmp);
  }
	return (ret);
}

int peekDirection(struct s_deque *deque, int front) {
  if (!isEmpty(deque)) {
    if (front)
      return deque->first->value;
    else
      return deque->last->value;
  }
  return INT_MIN;
}

int popBack(struct s_deque *deque) {
  struct s_dequeNode *tmp = deque->last;
  int                 ret = INT_MIN;

	if (tmp) {
    ret = tmp->value;
    deque->last = tmp->prev;
    if (!deque->last)
      deque->first = NULL;
    else
      deque->last->next = NULL;
    free(tmp);
  }
	return (ret);
}

int isEmpty(struct s_deque *deque) {
  return !(deque && deque->first && deque->last);
}

struct s_max *buildSMax(int *arr, int len) {
  struct s_max    *ret = calloc(1, sizeof(struct s_max));
  ret->length = len;
  ret->max = arr;
  return ret;
}

struct s_max *maxSlidingWindow(int *arr, int n, int k) {
  struct s_deque  *q = dequeInit();
  int             len = n - k + 1;
  int             *maxArr = calloc(len, sizeof(int));
  int             i;

  if (len < 0) return buildSMax(NULL, 0);
  for (i = 0; i < k && i < n; i++) {
    while (!isEmpty(q) && arr[peekDirection(q, 1)] < arr[i]) {
      popBack(q);
    }
    pushBack(q, i);
  }
  for (; i <= n; i++) {
    printf("%d: %d\n", i, arr[i]);
    // printDequeue(q, arr);
    maxArr[i - k] = arr[peekDirection(q, 1)];
    while (!isEmpty(q) && peekDirection(q, 1) <= i - k)
      popFront(q);
    while (!isEmpty(q) && arr[i] > arr[peekDirection(q, 0)])
      popBack(q);
    pushBack(q, i);
  }
  return buildSMax(maxArr, len);
}

void  printDequeue(struct s_deque *q, int *arr) {
  struct s_dequeNode *tmp = q->first;

  printf("queue \n****\n");
  while(tmp) {
    printf("%d: %d <--->", tmp->value, arr[tmp->value]);
    tmp = tmp->next;
  }
  printf("\n***\n\n");
}