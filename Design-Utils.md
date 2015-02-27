## Stack

	A generic FIFO stack.  It doesn't free the memory of the items it contains.

* Stack

````c
typedef struct  {
	void *item;
	stack *next;
} stack;

stack *myStack = InitStack();
Push(myStack, myItem1);
Push(myStack, myItem2);
item *myItem3 = Pop(myStack);

````

### Functions

* stack* InitStack();

	Initialize a new stack object.

* void Push (stack *stk, void *item)

	Push an item void* on the stack*.

* void* Pop (stack *stk)

	Returns the void* item from the top of stack*.
	Frees the top of the stack item.
	Returns null on the last value.

* void DestructStack (stack *stk)

	Free the stack memory.
	Sets the item to null.  Item must be freed by it's creator.
