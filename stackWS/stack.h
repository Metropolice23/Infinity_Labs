#ifndef __DO2_STACK_H__
#define __DO2_STACK_H__
#include <stddef.h> /* size_t data type */

/* Should be in c file
A structure to represent a stack 
struct stack {
    size_t capacity;
    size_t size;
    void **array;
};
*/

typedef struct stack stack_t;

/* function to create a stack of given capacity. 
   if sucsses returns stack pointer address
   if failure returns NULL
*/
stack_t *StackCreate(size_t capacity);

/* Deallocate stack array and stack*/
void StackDestroy(stack_t *stack);

/* Returns last value in stack , undefined in empty stack*/
void *StackPop(stack_t *stack);
 
/*  Adds and item on top of the stack , undefined in full stack */
void StackPush(stack_t *stack, void *value);

/* Return the top element  */
void *StackPeek(const stack_t *stack);

/* returns the size of number of elements in stack */
size_t StackSize(const stack_t *stack);

/* returns 1 if stack empty, 0 if not  */
int IsStackEmpty(const stack_t *stack);

/* returns stack capacity value */
size_t StackCapacity(const stack_t *stack);

#endif /* DO2_STACK_H */
