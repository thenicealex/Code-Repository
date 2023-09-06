#include <stdio.h>
#include <string.h>
#define SIZE 8
int main(int argc, char *argv[]) {
    int array[SIZE] = {49, 38, 65, 97, 76, 13, 27, 49};
    int i, j;

    for (i = 0; i < SIZE; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    return 0;
}
