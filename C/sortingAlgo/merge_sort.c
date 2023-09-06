#include <inttypes.h>
#include <stdio.h>

void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int i, j, k;

    int L[n1], R[n2];  // n1 + n2 = size

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

void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int main(int argc, char *argv[]) {
    int array[] = {49, 38, 65, 97, 76, 13, 27, 49};
    int size = sizeof(array) / sizeof(array[0]);
    int left = 0;
    int right = size - 1;
    int i, j;

    mergeSort(array, left, right);

    for (i = 0; i < size; i++) {
        printf("array[%d] = %d\n", i, array[i]);
    }
    return 0;
}
