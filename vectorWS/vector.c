#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "vector.h"

typedef struct vector
{
    size_t capacity;
    size_t size;
    size_t elem_size;
    void *array;
}vector_t;

typedef struct vector vector_t;

/* Creates vector varible ,recives size of element*/
void *VectorCreate(size_t elem_size, size_t capacity)
{
    vector_t* vector = (vector_t*)malloc((sizeof(size_t) * 3) + (capacity * elem_size));
    vector->capacity = capacity;
    vector->elem_size = elem_size;
    vector->size = 0;
    vector->array = (void*)malloc(capacity * elem_size);
    return vector;
}

/* Returns total number of items in vector */
size_t VectorSize(const vector_t *vector)
{
    return vector->size;
}

/* Resizes vector size (in .c file)*/
static void VectorResize(vector_t *vector, int capacity)
{
    vector->capacity = capacity;
    vector->array = (void*)realloc(vector->array, capacity * vector->elem_size);
}

/* Adds item at end of array*/
void VectorAppend(vector_t *vector, const void *item)
{
    memcpy(vector->array + (vector->size * vector->elem_size), item, vector->elem_size);
    ++vector->size;
    if(vector->size >= (vector->capacity) - 2)
    {
      VectorResize(vector, ((vector->capacity) * 2));
    }
}

/* Returns value in index */
void *VectorGet(const vector_t *vector, int index)
{
    return (vector->array + (index * vector->elem_size));
}

/* Deletes item at the end of array */
void VectorPop(vector_t *vector)
{
    --vector->size;
    if(vector->size < (vector->capacity / 4))
    {
        VectorResize(vector, (vector->capacity) / 2);
    }
}

/*Deletes vector data structore */
void VectorDestroy(vector_t *vector)
{
    free(vector->array);
    free(vector);
}

/*Checks if vector is empty,True returns 0, False returns 1 */
int VectorIsEmpty(const vector_t *vector)
{
    if (vector->size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    } 
}

/*Returns capacity size*/
size_t VectorCapacity(const vector_t *vector)
{
    return vector->capacity;
}



