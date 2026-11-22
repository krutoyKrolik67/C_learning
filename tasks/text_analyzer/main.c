#include <stdlib.h>
#include <stdio.h>


void showArr(int *arr, size_t length){
    printf("\n TOTAL ELEMENTS: %zu\n{", length);
    for(size_t i = 0; i < length; i++){
        if(i == length - 1){
             printf(" %d", arr[i]); break;}
        printf(" %d,", arr[i]);
    }
    printf("}");
}

int sumArray(int *arr, size_t length){
    int sum = 0;
    for(size_t i = 0; i < length; i++)
    {
        sum += arr[i];
    }
    return sum;
}

float avgArray(int *arr, size_t length){
    float sum = sumArray(arr, length);
    return sum / length;
}

int *minMaxArr(int *arr, size_t length){
    int *minMaxArr = malloc(2 * sizeof(int));
    if(minMaxArr == NULL){
        printf("\n ERROR: Couldnt allocate memory for minMax Array!!");
        return NULL;
    }
    minMaxArr[0] = arr[0];
    minMaxArr[1] = arr[0];
    for(size_t i = 0; i < length; i++)
    {
        if(arr[i] < minMaxArr[0]){
            minMaxArr[0] = arr[i];
        }
        if(arr[i] > minMaxArr[1]){
            minMaxArr[1] = arr[i];
        }
    }
    return minMaxArr;
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
        printf("Element%zu:", i);
        scanf("%d", &myArr[i]);
    }
    showArr(myArr, arrLength);
    printf("\n Sum is %d", sumArray(myArr, arrLength));
    int *minMax = minMaxArr(myArr, arrLength);
    printf("\n Min of arr is %d, und max is %d", minMax[0], minMax[1]);
    printf("\n The average is %f", avgArray(myArr, arrLength));
    free(minMax);
    free(myArr);
}
