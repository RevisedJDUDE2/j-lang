#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct TOKENIZER {
    char current_token;
    char** current_line;
} TOKENIZER_TYPE;
void Out(void);