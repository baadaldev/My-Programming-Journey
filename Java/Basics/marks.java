import java.util.Scanner;

class Student {
    int id;
    String name;
    double marks;

    Student(int id, String name, double marks) {
        this.id = id;
        this.name = name;
        this.marks = marks;
    }
}

public class marks {

    static Student[] students = new Student[100];
    static int count = 0;
    static Scanner sc = new Scanner(System.in);

    public static void addStudent() {
        System.out.print("Enter ID: ");
        int id = sc.nextInt();
        sc.nextLine();

        System.out.print("Enter Name: ");
        String name = sc.nextLine();

        System.out.print("Enter Marks: ");
        double marks = sc.nextDouble();

        students[count] = new Student(id, name, marks);
        count++;

        System.out.println("Student Added Successfully!");
    }

    public static void displayStudents() {
        if (count == 0) {
            System.out.println("No Students Found!");
            return;
        }

        System.out.println("\n----- Student List -----");

        for (int i = 0; i < count; i++) {
            System.out.println("ID: " + students[i].id);
            System.out.println("Name: " + students[i].name);
            System.out.println("Marks: " + students[i].marks);
            System.out.println("----------------------");
        }
    }

    public static void searchStudent() {
        System.out.print("Enter Student ID to Search: ");
        int searchId = sc.nextInt();

        boolean found = false;

        for (int i = 0; i < count; i++) {
            if (students[i].id == searchId) {
                System.out.println("\nStudent Found!");
                System.out.println("ID: " + students[i].id);
                System.out.println("Name: " + students[i].name);
                System.out.println("Marks: " + students[i].marks);
                found = true;
                break;
            }
        }

        if (!found) {
            System.out.println("Student Not Found!");
        }
    }

    public static void findHighestMarks() {
        if (count == 0) {
            System.out.println("No Students Available!");
            return;
        }

        int highestIndex = 0;

        for (int i = 1; i < count; i++) {
            if (students[i].marks > students[highestIndex].marks) {
                highestIndex = i;
            }
        }

        System.out.println("\nTop Student:");
        System.out.println("ID: " + students[highestIndex].id);
        System.out.println("Name: " + students[highestIndex].name);
        System.out.println("Marks: " + students[highestIndex].marks);
    }

    public static void main(String[] args) {

        while (true) {
            System.out.println("\n===== Student Management System =====");
            System.out.println("1. Add Student");
            System.out.println("2. Display Students");
            System.out.println("3. Search Student");
            System.out.println("4. Find Highest Marks");
            System.out.println("5. Exit");

            System.out.print("Enter Choice: ");
            int choice = sc.nextInt();

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
                    findHighestMarks();
                    break;

                case 5:
                    System.out.println("Program Ended.");
                    sc.close();
                    return;

                default:
                    System.out.println("Invalid Choice!");
            }
        }
    }
}