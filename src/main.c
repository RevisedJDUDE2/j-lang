#include <stdio.h>
#include <stdlib.h>
#include <vector.h>

int main() {
    Vector_t* names_vector = vector_init();
    //names_vector->data[0] = (char*)"World";
    vector_push_back(names_vector, (char*)"Hello");
    vector_push_back(names_vector, (char*)"World");
    vector_push_back(names_vector, (int*)545);
    //they are the same with vector_at(vector, index);
    //fprintf(stdout, "%s\n", (char*)names_vector->data[0]);
    //fprintf(stdout, "%s\n", (char*)names_vector->data[1]);
    fprintf(stdout, "%s\n", (char*)vector_at(names_vector, 0));
    fprintf(stdout, "%s\n", (char*)vector_at(names_vector, 1));
    fprintf(stdout, "%d\n", (int*)vector_at(names_vector, 2));
    vector_pop_back(names_vector);
    fprintf(stdout, "%d\n", (int*)vector_at(names_vector, 2));
    return EXIT_SUCCESS;
}