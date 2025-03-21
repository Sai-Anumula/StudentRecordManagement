#include <stdio.h>
#include <string.h>

#define MAX 100  // Maximum number of students

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

struct Student students[MAX];
int count = 0;

void addStudent() {
    if (count >= MAX) {
        printf("Database is full!\n");
        return;
    }
    printf("Enter Roll Number: ");
    scanf("%d", &students[count].rollNo);
    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);
    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);
    count++;
    printf("Student added successfully!\n");
}

void displayStudents() {
    if (count == 0) {
        printf("No records found!\n");
        return;
    }
    printf("\nStudent Records:\n");
    printf("Roll No\tName\t\tMarks\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\n", students[i].rollNo, students[i].name, students[i].marks);
    }
}

void searchStudent() {
    int roll;
    printf("Enter Roll Number to Search: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            printf("Student Found: %s, Marks: %.2f\n", students[i].name, students[i].marks);
            return;
        }
    }
    printf("Student Not Found!\n");
}

void deleteStudent() {
    int roll, i, found = 0;
    printf("Enter Roll Number to Delete: ");
    scanf("%d", &roll);
    for (i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (int j = i; j < count - 1; j++) {
            students[j] = students[j + 1];
        }
        count--;
        printf("Record deleted successfully!\n");
    } else {
        printf("Student Not Found!\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n2. Display Students\n3. Search Student\n4. Delete Student\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: printf("Exiting program...\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
