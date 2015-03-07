#include <stdlib.h>
#include <stdio.h>
#include "models/stack.h"

stack* InitStack(void *item) {
	stack *newStack = malloc(sizeof(stack));

	newStack->item = item;
	newStack->next = NULL;

	return newStack;
}

void Push (stack **stkptr, void *item) {
	stack *newCell = InitStack(item);
	newCell->next = *stkptr;
	*stkptr = newCell;
}

void* Peek (stack *stk) {
	return stk->item;
}

void* Pop (stack **stkptr) {
	stack *tempStack = *stkptr;
	void *tempItem = tempStack->item;

	tempStack->item = NULL;

	*stkptr = (*stkptr)->next;

	free (tempStack);

	tempStack = NULL;

	return tempItem;
}

void DestructStack (stack **stkptr) {
	int i = 0;
	stack *tempStack = NULL;

	while(*stkptr != NULL) {
		i++;
		tempStack = *stkptr;
		*stkptr = (*stkptr)->next;
		
		if(tempStack->item != NULL) {
			printf("Destroying stack item %d\n", i);
			free (tempStack->item);
			tempStack->item = NULL;
		}
		printf("Destroying stack %d\n", i);
		free (tempStack);
		printf("Destroyed stack %d\n", i);
		tempStack = NULL;
	}
	*stkptr = NULL;
}