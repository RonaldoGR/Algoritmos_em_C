#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
   

    if (argc != 3) {
        printf("Please, provide more command line arguments to continue.\n");
        return 1;
    }
    printf("SECRET KEY: %i\n",  atoi(argv[2]));
    printf("Before: %s\n", argv[1]);
    printf("After:  ");

    for (int i = 0, n = strlen(argv[1]); i < n; i++) {
        printf("%c", argv[1][i] +  atoi(argv[2]));
    } 
    printf("\n");
   
    return 0;
}
