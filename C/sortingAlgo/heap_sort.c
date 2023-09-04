#include <stdio.h>
#define SIZE 8

void HeapJust(int array[], int start, int len) {
    int largest = start;
    int left = 2 * start + 1;
    int right = 2 * start + 2;
    if (left < len && array[left] > array[largest]) {
        largest = left;
    }
    if (right < len && array[right] > array[largest]) {
        largest = right;
    }
    if (largest != start) {
        int temp = array[start];
        array[start] = array[largest];
        array[largest] = temp;
        HeapJust(array, largest, len);
    }
}

void HeapSort(int array[]) {
    int i;
    for (i = SIZE / 2 - 1; i >= 0; i--) {
        HeapJust(array, i, SIZE);
    }
    for (i = SIZE - 1; i >= 0; i--) {
        int temp = array[i];
        array[i] = array[0];
        array[0] = temp;
        HeapJust(array, 0, i);
    }
}

int main(int argc, char *argv[]) {
    int array[SIZE] = {49, 38, 65, 97, 76, 13, 27, 49};
    int i, j;

    HeapSort(array);
    for (i = 0; i < SIZE; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    return 0;
}
