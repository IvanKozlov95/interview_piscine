#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
	struct s_stone {
		int size;
		struct s_stone *next;
	};


/*--------------------------------
  :) function you must implement
  --------------------------------*/
//stone is a pointer to the first
void sortStones(struct s_stone **stone);


/*--------------------------------
  ?? test function used in main
  --------------------------------*/
struct s_stone *genRandomStoneList(int n);
void printStone(struct s_stone *stone);
struct s_stone *createStone(int size);
void exitWithMsg(char *msg);


/*--------------------------------
  &  your own other function
  --------------------------------*/

struct s_group {
  int size;
  struct s_group *next;
  struct s_stone *first;
  struct s_stone *last;
};

typedef struct s_group    t_group;
typedef struct s_stone    t_stone;

#endif
