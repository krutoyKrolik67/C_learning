#include <stdlib.h>

void showArr(int *arr, size_t length){
    printf("\n TOTAL ELEMENTS: %zu\n{", length);
    for(size_t i = 0; i < length; i++){
        if(i == length - 1){
             printf(" %d", arr[i]); break;}
        printf(" %d,", arr[i]);
    }
    printf("}");
}

int main(){
    size_t arrLength;
    int *myArr;
    printf("I'd like to make my array with .. elements: ");

    if(!scanf("%zu", &arrLength))
    {
        printf("\n ERROR:Invalid input");
        return 1;
    }

    if(arrLength > 0){
        myArr = malloc(arrLength * sizeof(int));
        if(myArr == NULL) {
            printf("ERROR: Could not allocate memory!"); return 1;
        }
    }else{
        printf("Array cant be 0 or less!");
        return 1;
    }

    printf("Now please enter each element...\n");
    for(size_t i = 0; i < arrLength; i++)
    {
        printf("Element%d:", i);
        scanf("%d", &myArr[i]);
    }
    showArr(myArr, arrLength);
    free(myArr);
}
