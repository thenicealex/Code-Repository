#include <stdio.h>
#define SIZE 8
int main(int argc, char *argv[]) {
    int array[SIZE] = {49, 38, 65, 97, 76, 13, 27, 49};
    int i, j;
    int key;

    for (i = 1; i < SIZE; i++) {
        key = array[i];
        j = i;
        while (j > 0 && array[j - 1] > key) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key;
    }

    for (i = 0; i < SIZE; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    return 0;
}
