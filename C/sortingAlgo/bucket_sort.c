#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
    int array[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int i, j;
    int size = sizeof(array) / sizeof(array[0]);
    int min = array[0], max = array[0];
    for (i = 0; i < size; i++) {
        if (array[i] > max) max = array[i];
        if (array[i] < min) min = array[i];
    }
    int size2 = max - min + 1;
    int *count = (int *)malloc(size2 * sizeof(int));
    memset(count, 0, size2 * sizeof(int));
    for (i = 0; i < size; i++) {
        count[array[i] - min]++;
    }

    j = 0;
    for (i = 0; i < size2; i++) {
        while (count[i] > 0) {
            array[j] = i + min;
            count[i]--;
            j++;
        }
    }

    for (i = 0; i < size; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    return 0;
}
