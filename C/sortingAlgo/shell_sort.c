#include <stdio.h>
int main(int argc, char *argv[]) {
    int array[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int size = sizeof(array) / sizeof(array[0]);
    int dk = size / 2;
    int i, j;
    int gap, temp;

    for (gap = dk; gap > 0; gap /= 2) {
        for (i = gap; i < size; i++) {
            temp = array[i];
            j = i - gap;
            while (j >= 0 && array[j] > temp) {
                array[j + gap] = array[j];
                j -= gap;
            }
            array[j + gap] = temp;
        }
    }

    for (i = 0; i < size; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    return 0;
}
