#include <vector.h>

Vector_t* vector_init(void) {
    FILE* fp = fopen(LOG_FILE, "w");
    Vector_t* temp = (Vector_t*)malloc(sizeof(Vector_t));
    temp->size = 0;
    temp->data = (void**)malloc(vector_maxsize * sizeof(void*));
    if(temp->data == NULL) {
        if(ENABLE_LOGS == 1) {
            fprintf(fp, "temp.data == NULL >> exiting now\n");
        }
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "Starting Loop now\n");
    for (int i = 0; i < vector_maxsize; i++) {
        fprintf(fp, "temp.data[%d] = NULL >> at location : %p\n", i, &temp->data[i]);
        temp->data[i] = NULL; // Initialize to NULL or some default value
    }
    fclose(fp);
    return temp;
}

void vector_push_back(Vector_t* vector, void* element) {
    FILE* log_file = fopen(LOG_FILE, "w");
    if(vector_size(vector) == 0) {
        fprintf(log_file, "Push an element at vector now size = %d, Location = %p", vector->size, &vector->data[vector->size]);
        vector->data[vector->size] = element;
        vector->size = 1;
    } else {
        fprintf(log_file, "Push an element at vector now size = %d, Location = %p", vector->size, &vector->data[vector->size]);
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