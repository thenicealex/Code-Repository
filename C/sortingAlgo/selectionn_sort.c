#include <stdio.h>
#define SIZE 8
int main(int argc, char *argv[])
{
	int array[SIZE] = {49, 38, 65, 97, 76, 13, 27, 49};
	int i, j;
	int minKey;

	for (i = 0; i<SIZE-1; i++) {
		minKey = i;
		for (j = i+1; j<SIZE; j++) {
			if (array[minKey] > array[j]) minKey = j;
		}
		if (minKey != i) {
			int temp = array[i];
			array[i] = array[minKey];
			array[minKey] = temp;
		}
	}
	for (i=0;i<SIZE;i++) {
		printf("array[%d] = %d\n", i, array[i]);
	}
	return 0;
}
