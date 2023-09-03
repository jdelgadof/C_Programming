//
// Created by Jeferson on 28/08/2023.
//
#include <stdio.h>

int main() {
    int numStudents;

    printf("How many students:");
    scanf("%d", &numStudents);

    int grades[numStudents];
    for (int i = 0; i < numStudents; i++) {
        grades[i] = -1; // Initialize the array elements to -1
    }

    while (1)
    {
        int index;
        int value;
        printf("Enter student number (1 – 4) or 0 to stop:");
        scanf("%d", &index);
        if(index == 0)
        {
            break;
        }
        if(index >= 0 && index < numStudents) {
            printf("Enter grade (0 – 5) for student %d or -1 to cancel:", index);
            scanf("%d", &value);
            if(value > 0 && value <6)
            {
                grades[index - 1] = value;
            }
            else if(value == -1)
            {
                continue;
            }
            else{
                printf("Invalid grade!\n");
            }
        }
        else {
            printf("Invalid student number!\n");
        }
    }

    printf("Student \tGrade\n");
    for (int i = 0; i < numStudents; i++) {
        if (grades[i] == -1)
        {
            printf("%d\t\tN/A\n", i+1);
        }
        else{
            printf("%d\t\t%d\n", i + 1, grades[i]);
        }

    }

    return 0;
}