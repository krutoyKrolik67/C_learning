#include <stdio.h>
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

int main(){
    FILE *file;
    char buffer[100];


    file = fopen("../myText.txt", "r");
    if(file == NULL){
        perror("\n FAILED to open file!");
        return 1;
    }
    return 0;
}