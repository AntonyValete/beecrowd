#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define isItRaining(ch) ((ch == 'Y') ? (true) : (false))

int main() {
    int N;
    int umbrellasAtWork, umbrellasAtHome;
    char homeToWork, workToHome;

    scanf("%d %d %d", &N, &umbrellasAtHome, &umbrellasAtWork); getchar();

    for (int i = 0; i < N; i++) {
        scanf("%c %c", &homeToWork, &workToHome); getchar();

        if (isItRaining(homeToWork) || !umbrellasAtWork) {
            printf("Y ");
            umbrellasAtHome--;
            umbrellasAtWork++;
        } else {
            printf("N ");
        }

        if (isItRaining(workToHome) || !umbrellasAtHome) {
            printf("Y\n");
            umbrellasAtWork--;
            umbrellasAtHome++;
        } else {
            printf("N\n");
        }
    }
    printf("\n");

    return 0;
}