#include <stdio.h>
#include <stdlib.h>

int main() {
    int number_cases, i = 0;
    int number_students, above_average_students;
    double mean, percentage_above_average;

    scanf("%d", &number_cases);
    while (number_cases > i) {
        mean = 0;

        scanf("%d", &number_students);
        int *grades = (int *) malloc(number_students * sizeof(int));
        for (int i = 0; i < number_students; i++) {
            scanf("%d", &grades[i]);
            mean += grades[i];
        }

        mean /= number_students;
        
        above_average_students = 0;
        for (int i = 0; i < number_students; i++) {
            if (grades[i] > mean)
                above_average_students++;
        }

        percentage_above_average = (double) 100 * above_average_students / number_students;

        printf("%.3lf%%\n", percentage_above_average);

        free(grades);
        i++;
    }
    return 0;
}