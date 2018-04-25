#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_item {
	int idx;
	struct s_item *next;
};

struct s_stack {
	struct s_item *item;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
struct s_stack *initStack();
void push(struct s_stack *stack, int idx);
int pop(struct s_stack *stack);

char *console(void);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/


/*--------------------------------
  &  your own other function
  --------------------------------*/

# define UNDO "UNDO"
# define SEND "SEND"
# define MSG_SIZE 256

typedef struct s_item		t_item;
typedef struct s_stack	t_stack;

#endif
