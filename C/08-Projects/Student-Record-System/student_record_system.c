#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Student {
    int id;
    char name[50];
    float cgpa;
};

struct Student students[MAX];
int count = 0;

void addStudent() {
    printf("\nEnter ID: ");
    scanf("%d", &students[count].id);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter CGPA: ");
    scanf("%f", &students[count].cgpa);

    count++;

    printf("\nStudent Added Successfully!\n");
}

void displayStudents() {
    if (count == 0) {
        printf("\nNo Student Found!\n");
        return;
    }

    printf("\n===== STUDENT LIST =====\n");

    for (int i = 0; i < count; i++) {
        printf("\nID   : %d", students[i].id);
        printf("\nName : %s", students[i].name);
        printf("\nCGPA : %.2f\n", students[i].cgpa);
    }
}

void searchStudent() {
    int id;
    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("\nStudent Found!");
            printf("\nID   : %d", students[i].id);
            printf("\nName : %s", students[i].name);
            printf("\nCGPA : %.2f\n", students[i].cgpa);
            return;
        }
    }

    printf("\nStudent Not Found!\n");
}

void deleteStudent() {
    int id;

    printf("\nEnter Student ID to Delete: ");
    scanf("%d", &id);

    int found = -1;

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("\nStudent Not Found!\n");
        return;
    }

    for (int i = found; i < count - 1; i++) {
        students[i] = students[i + 1];
    }

    count--;

    printf("\nStudent Deleted Successfully!\n");
}

void updateStudent() {
    int id;

    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {

            printf("\nEnter New Name: ");
            scanf(" %[^\n]", students[i].name);

            printf("Enter New CGPA: ");
            scanf("%f", &students[i].cgpa);

            printf("\nUpdated Successfully!\n");
            return;
        }
    }

    printf("\nStudent Not Found!\n");
}

void sortByCGPA() {
    struct Student temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {

            if (students[j].cgpa < students[j + 1].cgpa) {

                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("\nSorted By CGPA!\n");
}

void saveToFile() {

    FILE *fp = fopen("students.txt", "w");

    if (fp == NULL) {
        printf("\nFile Error!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp,
                "%d %s %.2f\n",
                students[i].id,
                students[i].name,
                students[i].cgpa);
    }

    fclose(fp);

    printf("\nData Saved Successfully!\n");
}

void loadFromFile() {

    FILE *fp = fopen("students.txt", "r");

    if (fp == NULL) {
        printf("\nNo Previous Data Found!\n");
        return;
    }

    count = 0;

    while (fscanf(fp,
                  "%d %s %f",
                  &students[count].id,
                  students[count].name,
                  &students[count].cgpa) != EOF) {

        count++;
    }

    fclose(fp);

    printf("\nData Loaded Successfully!\n");
}

int main() {

    int choice;

    loadFromFile();

    while (1) {

        printf("\n========================");
        printf("\nSTUDENT MANAGEMENT SYSTEM");
        printf("\n========================");

        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Delete Student");
        printf("\n5. Update Student");
        printf("\n6. Sort By CGPA");
        printf("\n7. Save To File");
        printf("\n8. Exit");

        printf("\n\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            deleteStudent();
            break;

        case 5:
            updateStudent();
            break;

        case 6:
            sortByCGPA();
            break;

        case 7:
            saveToFile();
            break;

        case 8:
            saveToFile();
            printf("\nThank You!\n");
            exit(0);

        default:
            printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}