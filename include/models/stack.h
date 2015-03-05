#ifndef STACK_H_
#define STACK_H_

typedef struct stack stack;

struct stack {
	void *item;
	stack *next;
};

/**
 * 	Initialize a new stack object.
 *
 * @return A new stack object.
 */
stack* InitStack();

/**
 * Push a void* item void* on the stack *stk.
 *
 * @param stack *stk The head of the stack.
 * @param void *item The item to push.
 */
void Push (stack *stk, void *item);

/**
 * Returns the void* item from the top of stack *stk.
 * Frees the top of the stack item.
 * Returns null on the last value.
 *
 * @param stack *stk The head of the stack.
 *
 * @return void* The popped item or null if the bottom item is popped.
 */
void* Pop (stack *stk);

/**
 * Free the stack memory.
 * Frees and sets the item to null.
 *
 * @param stack *stk The head of the stack.
 */
void DestructStack (stack *stk);


#endif