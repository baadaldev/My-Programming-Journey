#include<stdio.h>

int main()
{
    int age[5];
    float cgpa[5];
    int sum = 0;

    // Input
    for(int i = 0; i < 5; i++)
    {
        printf("Enter student %d age: ", i + 1);
        scanf("%d", &age[i]);

        printf("Enter student %d CGPA: ", i + 1);
        scanf("%f", &cgpa[i]);
    }

    // Highest CGPA setup
    float maxCgpa = cgpa[0];
    int topStudent = 0;

    printf("\nAll Data\n\n");

    // Print data + calculate sum + find highest CGPA
    for(int i = 0; i < 5; i++)
    {
        printf("Student %d\n", i + 1);
        printf("Age : %d\n", age[i]);
        printf("CGPA: %.2f\n\n", cgpa[i]);

        sum += age[i];

        if(cgpa[i] > maxCgpa)
        {
            maxCgpa = cgpa[i];
            topStudent = i;
        }
    }

    float avg = (float)sum / 5;

    printf("Average Age : %.2f\n", avg);
    printf("Highest CGPA: %.2f\n", maxCgpa);
    printf("Top Student : %d\n", topStudent + 1);

    return 0;
}
