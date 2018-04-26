#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 10);

	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	printf("asdasdasdSum: %d Energy: %d Stack: %d\n", 1, tankPop(tank), tank->n);
	printf("asdSum: %d Energy: %d Stack: %d\n", 1, tankPop(tank), tank->n);
	// printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	// printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	// printf("dasdum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);


	tankPush(tank, 10);
	tankPush(tank, 11);
	tankPush(tank, 12);
	tankPush(tank, 13);
	tankPush(tank, 14);
	tankPush(tank, 15);
	tankPush(tank, 16);

	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);
	printf("Sum: %d Energy: %d Stack: %d\n", tank->stacks[tank->n - 1]->sum, tankPop(tank), tank->n);


	return (0);
}