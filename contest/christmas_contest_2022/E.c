#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_BUFFER 197
#define MAX_TREE_SIZE 99

void searchForEmpty(int arr[], int size);

int main() {
    char str_template[MAX_STR_BUFFER];
    int *tree = (int *) calloc(MAX_TREE_SIZE, sizeof(int));
    int i, num_layers, length;

    scanf("%d", &num_layers);

    for (i = 0; i < num_layers; i++) {
        scanf("%s", str_template);
        length = strlen(str_template);
        tree[(length + 1) / 2 - 1] = 1;
    }

    searchForEmpty(tree, num_layers);

    free(tree);

    return 0;
}

void searchForEmpty(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (!arr[i]) {
            puts("no");
            return;
        }
    }
    puts("yes");
}