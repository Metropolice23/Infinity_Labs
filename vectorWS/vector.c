#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include "vector.h"

typedef struct vector
{
    size_t capacity;
    size_t size;
    size_t elem_size;
    void *array;
}vector_t;

/* Creates vector varible ,recives size of element*/
void *VectorCreate(size_t elem_size, size_t capacity)
{
    vector_t *vector = (vector_t*)malloc(sizeof(vector_t));
    if (vector == NULL)
    {
        return NULL;
    }
    vector->capacity = capacity;
    vector->elem_size = elem_size;
    vector->size = 0;
    vector->array = (void*)malloc(capacity * elem_size);
    if (vector->array == NULL)
    {
    	free(vector);
        return NULL;
    }
    return vector;
}

/* Returns total number of items in vector */
size_t VectorSize(const vector_t *vector)
{
    return vector->size;
}

/* Resizes vector size (in .c file)*/
static void VectorResize(vector_t *vector, size_t capacity)
{
    vector->capacity = capacity;
    vector->array = (void*)realloc(vector->array, capacity * vector->elem_size);
}

/* Adds item at end of array*/
void VectorAppend(vector_t *vector, const void *item)
{
    assert (vector->size < vector->capacity);
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
    assert (NULL != vector);
    assert (index < vector->size);
    return (vector->array + (index * vector->elem_size));
}

/* Deletes item at the end of array */
void VectorPop(vector_t *vector)
{
    if (VectorIsEmpty(vector) != 1)
    {
        --vector->size;
        if(vector->size < (vector->capacity / 4))
        {
            VectorResize(vector, (vector->capacity) / 2);
        }
    }
    else
    {
        printf("\nError - Vector is empty!");
    }
}

/*Deletes vector data structore */
void VectorDestroy(vector_t *vector)
{
    if (vector != NULL)
    {
        free(vector->array);
        free(vector);
    }
}

/*Checks if vector is empty,True returns 1, False returns 0 */
int VectorIsEmpty(const vector_t *vector)
{
	assert(vector != NULL);
    return (vector->size == 0); 
}

/*Returns capacity size*/
size_t VectorCapacity(const vector_t *vector)
{
    assert(vector != NULL);
    return vector->capacity;
}

