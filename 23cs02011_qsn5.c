#include <stdio.h>
#include <stdbool.h>

#define NUM_TESTS 3
#define PASS_MARK 35

// Structure definition
struct CourseRecord {
    char firstName[50];
    char lastName[50];
    int rollNumber;
    char department[50];
    char courseCode[20];
    int testMarks[NUM_TESTS];
};

// Function to calculate average test marks
float averageTestMarks(struct CourseRecord record) {
    float totalMarks = 0;
    for (int i = 0; i < NUM_TESTS; i++) {
        totalMarks += record.testMarks[i];
    }
    return totalMarks / NUM_TESTS;
}

// Function to check if a student passed the test
bool hasPassed(struct CourseRecord record) {
    float avgMarks = averageTestMarks(record);
    return avgMarks >= PASS_MARK;
}

int main() {
    // Example usage
    struct CourseRecord student1 = {"rajesh", "agrawal", 101, "Computer Science", "CS101", {70, 65, 75}};
    struct CourseRecord student2 = {"mahesh", "Sharma", 102, "Electrical Engineering", "EE201", {10, 50, 30}};

    printf("Average test marks for %s %s: %.2f\n", student1.firstName, student1.lastName, averageTestMarks(student1));
    printf("Result for %s %s: %s\n", student1.firstName, student1.lastName, hasPassed(student1) ? "Pass" : "Fail");

    printf("Average test marks for %s %s: %.2f\n", student2.firstName, student2.lastName, averageTestMarks(student2));
    printf("Result for %s %s: %s\n", student2.firstName, student2.lastName, hasPassed(student2) ? "Pass" : "Fail");

    return 0;
}
