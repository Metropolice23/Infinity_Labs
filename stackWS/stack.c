#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack {
    size_t capacity;
    size_t size;
    void **array;
};

/* function to create a stack of given capacity. 
   if sucsses returns stack pointer address
   if failure returns NULL
*/
stack_t *StackCreate(size_t capacity)
{
    size_t temp = 0;
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t));
    stack->capacity = capacity;
    stack->size = temp;
    stack->array = malloc(stack->capacity * 8);
    return stack;
}

/* Deallocate stack array and stack*/
void StackDestroy(stack_t *stack)
{
    free (stack->array[0]);
    stack->array[0] = NULL;
    stack->capacity = 0;
    stack->size = 0;
    free(stack);
}

/* Returns last value in stack , undefined in empty stack*/
void *StackPop(stack_t *stack)
{
    void *temp = stack->array[stack->size-1];
    stack->array[stack->size-1] = NULL;
    stack->size--;
    return temp;
}
 
/*  Adds and item on top of the stack , undefined in full stack */
void StackPush(stack_t *stack, void *value)
{
    if(stack->size < stack->capacity)
    {
    stack->array[stack->size] = value;
    ++stack->size;
    }
}

/* Return the top element  */
void *StackPeek(const stack_t *stack)
{
    return stack->array[stack->size-1]; 
}

/* returns the size of number of elements in stack */
size_t StackSize(const stack_t *stack)
{
    return stack->size;
}

/* returns 1 if stack empty, 0 if not  */
int IsStackEmpty(const stack_t *stack)
{
    if (stack->size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    } 
}

/* returns stack capacity value */
size_t StackCapacity(const stack_t *stack)
{
    return stack->capacity;
}