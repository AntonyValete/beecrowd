#include <stdio.h>
#include <stdlib.h>

typedef struct number {
    int number;
    int modulo;
} number;

int compare(const void *a_ptr, const void *b_ptr);

int main() {
    int num_numbers, modulo_target;

    while (1) {
        scanf("%d %d", &num_numbers, &modulo_target);
        
        if (!(num_numbers + modulo_target)) {
            puts("0 0");
            break;
        }

        number *numbers = (number *) malloc(num_numbers * sizeof(number));

        for (int i = 0; i < num_numbers; i++) {
            scanf("%d", &numbers[i].number);
            numbers[i].modulo = numbers[i].number % modulo_target;
        }

        qsort(numbers, num_numbers, sizeof(number), compare);

        printf("%d %d\n", num_numbers, modulo_target);
        for (int i = 0; i < num_numbers; i++) {
            printf("%d\n", numbers[i].number);
        }

        free(numbers);
    }
    return 0;
}

int compare(const void *a_ptr, const void *b_ptr) {
    const number a = *(number *) a_ptr;
    const number b = *(number *) b_ptr;

    if (a.modulo != b.modulo)
        return a.modulo - b.modulo;
    if (a.number % 2 == 0 && b.number % 2 == 0)
        return a.number - b.number;
    if (a.number % 2 != 0 && b.number % 2 != 0)
        return b.number - a.number;
    if (a.number % 2 != 0)
        return -1;
    return 1;
}