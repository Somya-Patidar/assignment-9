#include <stdio.h>
#include <string.h>

// Structure to hold student details
struct Student {
    char rollNo[20];
    char name[50];
    char address[100];
    int age;
    float averageMarks;
};

// Function to read details of students
void readStudentDetails(struct Student students[], int n) {
    printf("Enter details for %d students:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Roll No: ");
        fgets(students[i].rollNo, sizeof(students[i].rollNo), stdin);
        strtok(students[i].rollNo, "\n"); // remove newline
        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        strtok(students[i].name, "\n"); // remove newline
        printf("Address: ");
        fgets(students[i].address, sizeof(students[i].address), stdin);
        strtok(students[i].address, "\n"); // remove newline
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Average Marks: ");
        scanf("%f", &students[i].averageMarks);
        getchar(); // consume newline character left in input buffer
    }
}

// Function to display details of students
void displayStudentDetails(struct Student students[], int n) {
    printf("\nStudent Details:\n");
    printf("----------------\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %s\n", students[i].rollNo);
        printf("Name: %s\n", students[i].name);
        printf("Address: %s\n", students[i].address);
        printf("Age: %d\n", students[i].age);
        printf("Average Marks: %.2f\n", students[i].averageMarks);
        printf("\n");
    }
}

int main() {
    struct Student students[6]; // Array to hold details of 6 students
    readStudentDetails(students, 6);
    displayStudentDetails(students, 6);
    return 0;
}
