#include <stdio.h>
int myAdd(int a, int b) {
    int c = b;
    return a + b;
}

int main(int argc, char *argv[]) {
    int a = 1;
    int res = myAdd(1, 2);
    printf("%d", res);

    return 0;
}
