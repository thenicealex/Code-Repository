#include <inttypes.h>
#include <stdio.h>
#define SIZE 8

void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int i, j, k;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = array[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = array[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k++] = L[i++];
        } else {
            array[k++] = R[j++];
        }
    }
    while (i < n1) {
        array[k++] = L[i++];
    }
    while (j < n2) {
        array[k++] = R[j++];
    }
}

void quickSort(int array[], int left, int right) {
    if (left < right) {
        int mid = right + (right - left) / 2;
        quickSort(array, left, mid);
        quickSort(array, mid + 1, right);
        merge(array, left, mid, right);
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
