#include "file_exec.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    char *filename = "myText.txt";
    int count = 0;
    int spaceCount = 0;
    int stringCount = 0;
    int charCount =0;
    char* buffer = readFile(filename, &count, &stringCount, &charCount, &spaceCount);
    printf("\n Array count: %d\n Number of strings: %d\n Number of chars: %d\n Number of spaces: %d\n", count, stringCount, charCount, spaceCount);
    printf("\t Here is the text \t \n");
    for (int i = 0; i < count; i++)
    {
        printf("%c", buffer[i]);
    }
    printf("\nhi makefile!");
    free(buffer);
    return 0;
}