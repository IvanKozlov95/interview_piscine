#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
	!! required structure
	--------------------------------*/

struct s_art {
	char *name;
	int price;
};


/*--------------------------------
	:) function you must implement
	--------------------------------*/

int searchPrice(struct s_art **arts, int n, char *name);


/*--------------------------------
	?? test function used in main 
	--------------------------------*/

struct s_art **getArts(int *n);


/*--------------------------------
	&  your own other function
	--------------------------------*/

typedef struct s_art	t_art;
int										arts_len(t_art **arts);

#endif
