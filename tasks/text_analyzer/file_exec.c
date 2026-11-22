#include <stdio.h>
#include <stdlib.h>
#include "file_exec.h"
//Code for fining current working directory
/*
#include <unistd.h>
void whereAmI(){
    char cwd[1024];
    if(getcwd(cwd, sizeof cwd) == NULL){
        perror("Couldn't find current working directory");
        return 1;
    }

    printf("\nApp lands here:\n%s\n", cwd);
}
whereAmI();
*/

char *readFile(char* filename, int* count, int* stringCount, int* charCount, int* spacesCount){
    FILE *file = fopen(filename, "r");
    if(!file){
        perror("Couldn't read file!");
        return NULL;
    }
    int capacity = 10;

    char* buffer = malloc(capacity * sizeof(char));

    int ch;
    while((ch = fgetc(file)) != EOF){
        if(ch == '\n'){
            *count +=1;
            *stringCount += 1;
        }else if(ch == ' '){
            *count += 1;
            *spacesCount +=1;
        }else{
            *count += 1;
            *charCount +=1;
        }
        if(*count == capacity){
            capacity *= 2;
            buffer = realloc(buffer, capacity * sizeof(char));
            if(!buffer){
                perror("Failed to allocate memory!");
                fclose(file);
                return NULL;
            }
        }
        buffer[*count - 1] = ch;
    }
    fclose(file);
    if(*count == capacity){
        capacity += 1;
        buffer = realloc(buffer, capacity * sizeof(char));
    }
    buffer[*count] = '\0';
    return buffer;
}