#include <vector.h>

Vector_t* vector_init(void) {
    FILE* log_file = fopen(LOG_FILE, "w");
    Vector_t* temp = (Vector_t*)malloc(sizeof(Vector_t));
    temp->size = 0;
    temp->data = (void**)malloc(vector_maxsize * sizeof(void*));
    if(temp->data == NULL) {
        if(ENABLE_LOGS == 1) {
            fprintf(log_file, "temp.data == NULL >> exiting now\n");
        }
        exit(EXIT_FAILURE);
    }
    fprintf(log_file, "Starting Loop now\n");
    for (int i = 0; i < vector_maxsize; i++) {
        fprintf(log_file, "temp.data[%d] = NULL >> at location : %p\n", i, &temp->data[i]);
        temp->data[i] = NULL; // Initialize to NULL or some default value
    }
    fclose(log_file);
    return temp;
}

void vector_push_back(Vector_t* vector, void* element) {
    FILE* log_file = fopen(LOG_FILE, "a");
    if(vector_size(vector) == 0) {
        fprintf(log_file, "Push an element at vector now size = %d, Location = %p\n", vector->size, &vector->data[vector->size]);
        vector->data[vector->size] = element;
        vector->size = 1;
    } else {
        fprintf(log_file, "Push an element at vector now size = %d, Location = %p\n", vector->size, &vector->data[vector->size]);
        vector->data[vector->size] = element;
        vector->size += 1;
    }
    fclose(log_file);
}

void* vector_at(Vector_t* vector, int index) {
    return vector->data[index];
}
int vector_size(Vector_t* vector) {
    return vector->size;
}

void vector_pop_back(Vector_t* vector) {
    FILE* log_file = fopen(LOG_FILE, "a");
    vector->data[vector_size(vector) - 1] = NULL;
    fprintf(log_file, "Removing an element at index: %d\n", vector->size);
    fprintf(log_file, "vector->data[vector_size(vector) >> %d] = %p >> \n", vector_size(vector) - 1, &vector->data[vector_size(vector) - 1]);
    vector->size -= 1;
    fclose(log_file);
}