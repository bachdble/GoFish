#ifndef STACK_H_
#define STACK_H_

typedef struct stack stack;

struct stack {
	void *item;
	stack *next;
};

/**
 * 	Initialize a new stack object with an item.
 *
 * @param Item to push.
 *
 * @return A new stack object.
 */
stack* InitStack(void *item);

/**
 * Push a void* item void* on the stack **stkptr.
 *
 * @param stack **stkptr A pointer to the head of the stack pointer.
 * @param void *item The item to push.
 */
void Push (stack **stkptr, void *item);

/**
 * Returns the void* item from the top of stack **stkptr.
 * Frees the top of the stack item.
 * Returns null on the last value.
 *
 * @param stack **stkptr A pointer to the head of the stack pointer.
 *
 * @return void* The popped item or null if the bottom item is popped.
 */
void* Pop (stack **stkptr);

/**
 * Returns the void* item from the top of stack *stk.
 *
 * @param stack *stk A pointer to the head of the stack.
 *
 * @return void* The item or null if the bottom item is popped.
 */
void* Peek (stack *stk);

/**
 * Free the stack memory.
 * Frees and sets the item to null.
 *
 * @param stack **stkptr A pointer to the head of the stack pointer.
 */
void DestructStack (stack **stkptr);

#endif