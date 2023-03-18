#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct People {
    int peopleXIndex;
    int peopleYIndex;
} People;

int main() {
    int numberOfFools;
    People iThPeople;

    scanf("%d", &numberOfFools);

    int *keepTrackOfFools = (int *) calloc(numberOfFools + 1, sizeof(int));

    if (keepTrackOfFools == NULL) {
        fprintf(stderr, "C adventures\n");
        exit(1);
    }

    for (int i = 1; i <= numberOfFools; i++) {
        scanf("%d %d", &iThPeople.peopleXIndex, &iThPeople.peopleYIndex);

        if (!keepTrackOfFools[iThPeople.peopleXIndex]) {
            keepTrackOfFools[iThPeople.peopleXIndex]++;
        }
        if (!keepTrackOfFools[iThPeople.peopleYIndex]) {
            keepTrackOfFools[iThPeople.peopleYIndex]++;
        }        
    }
    
    for (int i = 1; i <= numberOfFools; i++) {
        if (!keepTrackOfFools[i]) {
            putchar('N');
        }
        else {
            putchar('Y');
        }
    }
    putchar('\n');

    free(keepTrackOfFools);

    return 0;
}