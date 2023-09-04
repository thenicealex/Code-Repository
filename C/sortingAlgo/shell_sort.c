#include <stdio.h>
#define SIZE 8
int main(int argc, char *argv[]) {
    int array[SIZE] = {49, 38, 65, 97, 76, 13, 27, 49};
    int dk = 5;
    int i, j;
    int key, temp;

    for (key = SIZE; key > 0; key /= 2) {

        for (i = key; i < SIZE; i++) {
            temp = array[i];
            j = i;
            while (j > 0 && array[j - key] > temp) {
                array[j] = array[j - key];
                j -= key;
            }
            array[j] = temp;
        }
    }

    for (i = 0; i < SIZE; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    return 0;
}
