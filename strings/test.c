#include <stdio.h>
#include <stdlib.h>

#define MAX 15

int main() {
    char buf[MAX];
    fgets(buf, MAX, stdin);
    printf("%s\n", buf);
    printf("test\n");
    return 0;
}