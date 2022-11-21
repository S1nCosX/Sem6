#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <stdio.h>

struct vector;

struct vector* vector(int size);//initialize vector

int vector_get_size(struct vector* v);//return size of vector

int vector_get_capacity(struct vector* v);//return capacity of vector

int vector_get(struct vector* v, int i);//return v[i]

void vector_set(struct vector* v, int i, int new_value);//set v[i] to new_value

struct vector* vector_resize(struct vector* v, int size);//resize vector to new size

void vector_push(struct vector* v, int value);//push value to end of vector

void vector_destroy(struct vector* v);//TURN YOUR VECTOR TO DUST >:D

struct vector* vector_copy(struct vector* v_target, struct vector* v_source);//add v_source to end of v_target

void vector_print(struct vector* v, FILE* stream);//print vector to stream
#endif
