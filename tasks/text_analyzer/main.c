#include "file_exec.h"
#include <stdio.h>
#include <stdlib.h>

extern char *optarg;

void print_usage(char *prog_name){
    printf("Usage: %s -f <filename>\n", prog_name);
    printf("Options:\n  -f <filename> Parh to the file to analyze.\n  -h            Show this help message\n");
}


int main(int argc, char* argv[]){
    char *filename = NULL;
    int opt;

    while ((opt = getopt(argc, argv, "f:h")) != -1)
    {
        switch (opt)
        {
        case 'f':
            filename = optarg;
            break;
        case 'h':
            print_usage(argv[0]);
            return 0;
        default:
            print_usage(argv[0]);
            return 1;
        }
    }
    if(filename == NULL){
        fprintf(stderr, "No file provided!\n\n");
        print_usage(argv[0]);
        return 1;
    }



    int count = 0, spaceCount = 0, stringCount =0, charCount = 0;
    char* buffer = readFile(filename, &count, &stringCount, &charCount, &spaceCount);
    if(buffer == NULL)
    {
        perror("File is NULL");
        return 1;
    }
    printf("\n Array count: %d\n Number of strings: %d\n Number of chars: %d\n Number of spaces: %d\n", count, stringCount, charCount, spaceCount);
    printf("\t Here is the text \t \n");
    for (int i = 0; i < count; i++)
    {
        printf("%c", buffer[i]);
    }
    free(buffer);
    return 0;
}