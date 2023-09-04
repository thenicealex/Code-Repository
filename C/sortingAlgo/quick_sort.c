#include <stdio.h>
#define SIZE 8

int partition(int array[], int left, int right) {
    int pivotkey = array[left];
    while (left < right) {
        while (left < right && array[right] >= pivotkey)
            right--;
        array[left] = array[right];
        while (left < right && array[left] <= pivotkey)
            left++;
        array[right] = array[left];
    }
    array[left] = pivotkey;
    return left;
}

void quickSort(int array[], int left, int right) {
    if (left < right) {
        int pivotkeylo = partition(array, left, right);
        quickSort(array, left, pivotkeylo - 1);
        quickSort(array, pivotkeylo + 1, right);
    }
}

int main(int argc, char *argv[]) {
    int array[SIZE] = {49, 38, 65, 97, 76, 13, 27, 49};
    int left = 0;
    int right = SIZE - 1;
    int i, j;

    quickSort(array, left, right);

    for (i = 0; i < SIZE; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    return 0;
}
