#include <stdio.h>
#define SIZE 8
int main(int argc, char *argv[]) {
    int array[SIZE] = {49, 38, 65, 97, 76, 13, 27, 49};
    int i, j;
    int swapped;

    for (i = 0; i < SIZE; i++) {
        swapped = 0;
        for (j = 0; j < SIZE - i - 1; j++) { // An optimized place
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
    for (i = 0; i < SIZE; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    return 0;
}
