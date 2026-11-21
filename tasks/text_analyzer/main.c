#include <stdio.h>

void setToZero(int *arrPtr, int length){
    for(int i = 0; i < length; i ++)
    {
        arrPtr[i] = 0;
    }
}

void showArr(int *arrPtr, int length){
    for(int i = 0; i < length; i++)
    {
        printf("\n %d", *(arrPtr + i));
    }
}

int sumArray(int *arrPtr, size_t length){
    int sum = 0;
    for(size_t i = 0; i < length; i++)
    {
        sum += *(arrPtr + i);
    }
    return sum;
}

int main(){
    int myArr[] = {3, 6, 9, 12};
    size_t length =  sizeof myArr / sizeof myArr[0];
    int *ptr = myArr;
    showArr(ptr, length);
    printf("\nThe Sum is %d", sumArray(ptr, length));
    setToZero(ptr, length);
    showArr(ptr, length);
}