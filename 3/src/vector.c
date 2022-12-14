#include "../include/vector.h"
#include <stdlib.h>
#include <stdio.h>

struct vector
{
    int size;
    int capacity;    
    int* value;
};

int vector_get_size(struct vector* v){//return size of vector
    return v->size;
}

int vector_get_capacity(struct vector* v){//return capacity of vector
    return v->capacity;
}

int vector_get(struct vector* v, int i){//return v[i]
    return v->value[i];
}

void vector_set(struct vector* v, int i, int new_value){//set v[i] to new_value
    v->value[i] = new_value;
}

struct vector* vector(int size){//initialize vector
    struct vector* v = malloc(sizeof(struct vector));
    v->size = 0;
    v->capacity = size;
    v->value = malloc(size);
    return v;
}

struct vector* inside_resize(struct vector* v){
    v = ((struct vector*) realloc(v, sizeof(v) + sizeof(v->value)));
    v->capacity = v->capacity * 2;
    return v;
}

struct vector* vector_resize(struct vector* v, int size){//resize vector to new size
    if (v->capacity == 0 || size <= v->capacity){
        v = (struct vector*) realloc(v, size);
        v->capacity = size;
        v->size = size;
        return v;
    }
    else{
        v = (struct vector*) realloc(v, size);
        v->capacity = size;
        v->size = size;
        return v;
    }
}

void vector_push(struct vector* v, int value){//push value to end of vector
    v->value[v->size] = value;
    v->size++;
    if (v->size == v->capacity){
        v = inside_resize(v);
    }
}

void vector_destroy(struct vector* v){//TURN YOUR VECTOR TO DUST
    free(v->value);
    free(v);
}

struct vector* vector_copy(struct vector* v_target, struct vector* v_source){//add v_source to end of v_target
    while(v_target->capacity < v_target->size + v_source->size)
        v_target = inside_resize(v_target);
    
    for(int i = 0; i < v_source->size; i++){
        v_target->value[v_target->size] = v_source->value[i];
        v_target->size++;
    }
    return v_target;
}

void vector_print(struct vector* v, FILE* stream){
    for (int i = 0; i < v->size; i++)
        fprintf(stream, "v[%d] : %d \n", i, v->value[i]);
}