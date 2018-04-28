#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_node {
	char	*name;
	struct s_node **children;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/
struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_node *getTreeOfLife(void);


/*--------------------------------
  &  your own other function
  --------------------------------*/

struct s_item {
	void					*node;
	struct s_item *next;
};
typedef struct s_item   t_item;

struct s_queue {
	t_item		*first;
	t_item		*last;
};
typedef struct s_queue	t_queue;

t_queue		*queueInit(void);
void			queueDestroy(t_queue *queue);
void			*dequeue(struct s_queue *queue);
void			enqueue(struct s_queue *queue, void *content);
void			*peek(struct s_queue *queue);
int				isEmpty(struct s_queue *queue);

typedef struct s_node		t_node;


#endif
