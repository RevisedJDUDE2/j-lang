#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <vector.h>

typedef struct TOKENIZER {
    FILE* file;
    char current_token;
    char** current_line;
    Vector_t* vect;
} TOKENIZER_TYPE;
void Out(void);

void InitTokenizer(TOKENIZER_TYPE* type);
void Tokenize(TOKENIZER_TYPE* type, const char** arg_v);
#endif