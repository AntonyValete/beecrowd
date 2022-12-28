#include <stdio.h>
#define MAX 10000

int main() {
    int table[] = {59, 0, 0, 0, 0, 77, 48, 44, 46, 57, 96, 49, 50, 51, 52, 53, 54, 55, 56, 0, 76, 0, 45, 0, 0, 0, 0, 86, 88, 83, 87, 68, 70, 71, 85, 72, 74, 75, 78, 66, 73, 79, 0, 69, 65, 82, 89, 67, 81, 90, 84, 0, 80, 93, 91};
    char str[MAX];

    while (fgets(str, MAX, stdin) != NULL) {
        int i = 0;
        while (str[i] != '\n') {
            if (str[i] == ' ')
                putchar(str[i]);
            else
                printf("%c", (char) table[(int) str[i] - 39]);
            i++;
        }
        putchar('\n');
    }

    return 0;
}