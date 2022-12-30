#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct kid {
    char name[30];
    char region;
    int distance;
} kid;

int compare(const void *a_ptr, const void *b_ptr);
void output(kid *kids, int size);

int main() {
    int i;
    int num_kids;
    kid *kids, *kid_aux;

    scanf("%d", &num_kids);
    kids = (kid *) malloc(num_kids * sizeof(kid));

    for (i = 0; i < num_kids; i++) {
        kid_aux = &kids[i];

        scanf("%s", kid_aux->name); getchar(); //trash character;
        kid_aux->region = getchar();
        scanf("%d", &kid_aux->distance);
    }

    qsort(kids, num_kids, sizeof(kid), compare);

    output(kids, num_kids);
    free(kids);

    return 0;
}

int compare(const void *a_ptr, const void *b_ptr) {
    const kid a = *(kid *) a_ptr;
    const kid b = *(kid *) b_ptr;

    if (a.region != b.region)
        return a.region - b.region;
    if (a.distance != b.distance)
        return a.distance - b.distance;
    return strncmp(a.name, b.name, 30);
}

void output(kid *kids, int size) {
    int i;

    for (i = 0; i < size; i++) {
        puts(kids[i].name);
    }
}