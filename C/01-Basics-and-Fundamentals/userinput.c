#include <stdio.h>

int main()
{
    int n, i;
    int marks[100];

    printf("How many students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter mark of student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    printf("\nStudent Marks:\n");

    for(i = 0; i < n; i++)
    {
        printf("Student %d = %d\n", i + 1, marks[i]);
    }

    return 0;
}
