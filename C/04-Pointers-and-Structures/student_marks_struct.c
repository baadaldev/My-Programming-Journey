#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float marks;
};

void addStudent(struct Student s[], int *count) {
    printf("Enter ID: ");
    scanf("%d", &s[*count].id);

    printf("Enter Name: ");
    scanf("%s", s[*count].name);

    printf("Enter Marks: ");
    scanf("%f", &s[*count].marks);

    (*count)++;
    printf("Student Added Successfully!\n");
}

void displayStudents(struct Student s[], int count) {
    int i;

    if(count == 0) {
        printf("No Students Found!\n");
        return;
    }

    printf("\n----- Student List -----\n");

    for(i = 0; i < count; i++) {
        printf("ID: %d\n", s[i].id);
        printf("Name: %s\n", s[i].name);
        printf("Marks: %.2f\n", s[i].marks);
        printf("----------------------\n");
    }
}

void searchStudent(struct Student s[], int count) {
    int id, i, found = 0;

    printf("Enter Student ID to Search: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++) {
        if(s[i].id == id) {
            printf("\nStudent Found!\n");
            printf("ID: %d\n", s[i].id);
            printf("Name: %s\n", s[i].name);
            printf("Marks: %.2f\n", s[i].marks);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Student Not Found!\n");
    }
}

void findHighestMarks(struct Student s[], int count) {
    if(count == 0) {
        printf("No Students Available!\n");
        return;
    }

    int i, index = 0;

    for(i = 1; i < count; i++) {
        if(s[i].marks > s[index].marks) {
            index = i;
        }
    }

    printf("\nTop Student:\n");
    printf("ID: %d\n", s[index].id);
    printf("Name: %s\n", s[index].name);
    printf("Marks: %.2f\n", s[index].marks);
}

int main() {
    struct Student students[100];
    int count = 0;
    int choice;

    while(1) {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Find Highest Marks\n");
        printf("5. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent(students, &count);
                break;

            case 2:
                displayStudents(students, count);
                break;

            case 3:
                searchStudent(students, count);
                break;

            case 4:
                findHighestMarks(students, count);
                break;

            case 5:
                printf("Program Ended.\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}