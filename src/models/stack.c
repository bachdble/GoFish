#include <stdlib.h>
#include "models/stack.h"

stack* InitStack() {
	stack *newStack = malloc(sizeof(stack));

	newStack->item = NULL;
	newStack->next = NULL;

	return newStack;
}

void Push (stack *stk, void *item) {
	stack *newCell = InitStack();
	newCell->item = item;
	newCell->next = stk;

	stk = newCell;
}

void* Pop (stack *stk) {
	stack *tempStack = stk;
	void *tempItem = tempStack->item;

	tempStack->item = NULL;

	stk = stk->next;

	free (tempStack);

	tempStack = NULL;

	return tempItem;
}

void DestructStack (stack *stk) {
	stack *tempStack = NULL;

	while(stk != NULL) {
		tempStack = stk;
		stk = stk->next;
		free (tempStack->item);
		tempStack->item = NULL;
		free (tempStack);
		tempStack = NULL;
	}

}