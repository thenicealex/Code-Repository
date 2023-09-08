#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
    int array[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int size = sizeof(array) / sizeof(array[0]);
    int i, j;
    int min = array[0], max = array[0];
    for (i = 0; i < size; i++) {
        if (array[i] > max) max = array[i];
        if (array[i] < min) min = array[i];
    }
    int size2 = max - min + 1;
    int *count = (int *)malloc(size2 * sizeof(int));
    int *result = (int *)malloc(size * sizeof(int));
    memset(result, 0, size * sizeof(int));
    memset(count, 0, size2 * sizeof(int));
    for (i = 0; i < size; i++) {
        count[array[i] - min]++;
    }
    for (i = 1; i < size2; i++) {
        count[i] += count[i - 1];
    }
    for (j = 0; j < size; j++) {
        result[count[array[j] - min] - 1] = array[j];
        count[array[j] - min]--;
    }
    for (i = 0; i < size; i++) {
        array[i] = result[i];
    }
    for (i = 0; i < size; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }

    free(count);
    free(result);
    return 0;
}
