#include <stdio.h>
const int buffSize = 100;

int my_strlen(char s[]){
    for(int i = 0; i < buffSize; i++)
    {
        if(s[i] == '\n') {
            return i;
        }
    }
}
void reverse(char s[], int n){
    for(int i = 0; i < n / 2; i++){
        char buff = s[i];
        s[i] = s[n-1-i];
        s[n-1-i] = buff;
    }
}

int main(){  
    char s[buffSize];
    printf("Enter a string!\n");
    fgets(s, sizeof(s), stdin);
    int n = my_strlen(s);
    reverse(s,n);
    printf("Your reversed string\nis\nhere:\n%s", s);
}