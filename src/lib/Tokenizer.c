#include <Tokenizer.h>
void Out(void) {
    printf(".\n");
}
void InitTokenizer(TOKENIZER_TYPE* type) {
    type->vect = vector_init();
}
void Tokenize(TOKENIZER_TYPE* type, const char** arg_v) {
    //type->file = fopen(arg_v[1], "r");
    type->file = fopen("file.j", "r");
    char* read_ptr;
    while(fgets(read_ptr, 500, type->file)) {
        fprintf(stderr, "at line: %s", read_ptr);
        char* tokens = strtok(read_ptr, " ");
        vector_push_back(type->vect, (char*)tokens);
        while (tokens != NULL) {
            tokens = strtok(NULL, " ");
            vector_push_back(type->vect, (char*)tokens);
            fprintf(stderr, "%s", tokens);
        }
    }
    fclose(type->file);
}