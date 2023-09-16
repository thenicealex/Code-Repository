#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
    int array[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int i, j;
    int exp;
    int size = sizeof(array) / sizeof(array[0]);
    int min = array[0], max = array[0];
    for (i = 0; i < size; i++) {
        if (array[i] > max) max = array[i];
        if (array[i] < min) min = array[i];
    }

    for (exp = 1; max / exp > 0; exp *= 10) {
        int result[size];
        int count[10] = {0};
        for (i = 0; i < size; i++) {
            count[(array[i] / exp) % 10]++;
        }
        for (j = 1; j < 10; j++) {
            count[j] += count[j - 1];
        }
        // int *result = (int *)malloc(sizeof(int) * size);
        // memset(result, 0, size * sizeof(int));
        for (j = 0; j < size; j++) {
            result[count[(array[j] / exp) % 10] - 1] = array[j];
            count[(array[j] / exp) % 10]--;
        }
        for (j = 0; j < size; j++) {
            array[j] = result[j];
        }
    }

    for (i = 0; i < size; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    return 0;
}
