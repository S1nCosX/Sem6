#include "../include/vector.h"
#include <stdio.h>

int main(int argc, char** argv){
    FILE* output_stream = stdout;
    if (argc == 2)
        output_stream = fopen(argv[1], "wb");

    printf("--------push test--------\n");
    struct vector* v1= vector(10);
    vector_push(v1, 69);
    vector_push(v1, 420);
    vector_push(v1, 80085);
    vector_print(v1, output_stream);
    printf("--------set test--------\n");
    vector_set(v1, 2, 1337);
    vector_print(v1, output_stream);

    printf("--------vector num 1--------\n");
    vector_print(v1, output_stream);

    printf("--------vector num 2--------\n");
    struct vector* v2= vector(9);
    vector_push(v2, 911);
    vector_push(v2, 1111);
    vector_push(v2, 0);
    vector_print(v2, output_stream);

    printf("--------copy test (v2 <- v1)--------\n");
    v2 = vector_copy(v2, v1);
    vector_print(v2, output_stream);

    printf("--------resize test (more)--------\n");
    printf("copacity : %d; size : %d\n", vector_get_capacity(v2), vector_get_size(v2));
    v2 = vector_resize(v2, 40);
    vector_print(v2, output_stream);
    printf("copacity : %d; size : %d\n", vector_get_capacity(v2), vector_get_size(v2));

    printf("--------resize test (less))--------\n");
    printf("copacity : %d; size : %d\n", vector_get_capacity(v2), vector_get_size(v2));
    v2 = vector_resize(v2, 2);
    vector_print(v2, output_stream);
    printf("copacity : %d; size : %d\n", vector_get_capacity(v2), vector_get_size(v2));
    
    printf("--------free test--------\n");
    vector_destroy(v1);
    vector_destroy(v2);

    fclose(output_stream);
}