/*
        this is for c not for the language!
*/
#include <stdlib.h>
#include <stdio.h>

#define LOG_FILE "LOG.txt"

static int ENABLE_LOGS = 1;

static int vector_maxsize = 100000; //resize as needeed by the vector_resize()

typedef struct Vector {
    void** data;
    int size;
} Vector_t;

Vector_t* vector_init(void);
void vector_push_back(Vector_t* vector, void* element);
void* vector_at(Vector_t* vector, int index);
int vector_size(Vector_t* vector);