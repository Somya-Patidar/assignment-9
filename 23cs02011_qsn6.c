#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_RECORDS 100


struct Student {
    char name[50];
    int rollNumber;
    float percentage;
};

//GLOBAL DECLARATAION
struct Student studentDB[MAX_RECORDS];
int numRecords = 0;


void insert(struct Student s);
void sortName();
char* findOne(const char* prefix);
void specs(int result[]);
void delete(int rollNumber);


void insert(struct Student s) {
    int i, j;
    // Find the correct position to insert according to roll number
    for (i = 0; i < numRecords; i++) {
        if (studentDB[i].rollNumber > s.rollNumber)
            break;
    }
    // Shift records to make space for the new record
    for (j = numRecords; j > i; j--) {
        studentDB[j] = studentDB[j - 1];
    }
    // Insert the new record
    studentDB[i] = s;
    numRecords++;
}

// Function to sort the database according to name
void sortName() {
    int i, j;
    struct Student temp;
    for (i = 0; i < numRecords - 1; i++) {
        for (j = 0; j < numRecords - i - 1; j++) {
            if (strcmp(studentDB[j].name, studentDB[j + 1].name) > 0) {
                temp = studentDB[j];
                studentDB[j] = studentDB[j + 1];
                studentDB[j + 1] = temp;
            }
        }
    }
}

// Function to find one name from the database that starts with the given prefix
char* findOne(const char* prefix) {
    for (int i = 0; i < numRecords; i++) {
        if (strncmp(studentDB[i].name, prefix, strlen(prefix)) == 0)
            return studentDB[i].name;
    }
    return NULL;
}

// Function to calculate specifications (Count, Highest Percentage, Lowest Percentage, Mean, Standard Deviation)
void specs(int result[]) {
    float sum = 0, mean, variance = 0, sd;
    float highest = studentDB[0].percentage;
    float lowest = studentDB[0].percentage;

    // Count, Mean, Highest Percentage, Lowest Percentage
    for (int i = 0; i < numRecords; i++) {
        sum += studentDB[i].percentage;
        if (studentDB[i].percentage > highest)
            highest = studentDB[i].percentage;
        if (studentDB[i].percentage < lowest)
            lowest = studentDB[i].percentage;
    }
    result[0] = numRecords;
    mean = sum / numRecords;
    result[1] = highest;
    result[2] = lowest;
    result[3] = mean;

    // Standard Deviation
    for (int i = 0; i < numRecords; i++) {
        variance += pow(studentDB[i].percentage - mean, 2);
    }
    sd = sqrt(variance / numRecords);
    result[4] = sd;
}

// Function to delete a record based on roll number
void delete(int rollNumber) {
    int i, j;
    for (i = 0; i < numRecords; i++) {
        if (studentDB[i].rollNumber == rollNumber) {
            for (j = i; j < numRecords - 1; j++) {
                studentDB[j] = studentDB[j + 1];
            }
            numRecords--;
            printf("Record with roll number %d deleted successfully.\n", rollNumber);
            return;
        }
    }
    printf("Record with roll number %d not found.\n", rollNumber);
}

int main() {
    // Test the functions
    struct Student s1 = {"John", 101, 80.5};
    struct Student s2 = {"Alice", 102, 75.3};
    struct Student s3 = {"Bob", 103, 85.2};
    struct Student s4 = {"David", 104, 90.0};
    struct Student s5 = {"Emily", 105, 77.8};

    // Insert records
    insert(s1);
    insert(s2);
    insert(s3);
    insert(s4);
    insert(s5);

    // Display current records
    printf("Current Records:\n");
    for (int i = 0; i < numRecords; i++) {
        printf("Name: %s, Roll Number: %d, Percentage: %.2f\n", studentDB[i].name, studentDB[i].rollNumber, studentDB[i].percentage);
    }

    // Sort by name
    sortName();
    printf("\nSorted Records by Name:\n");
    for (int i = 0; i < numRecords; i++) {
        printf("Name: %s, Roll Number: %d, Percentage: %.2f\n", studentDB[i].name, studentDB[i].rollNumber, studentDB[i].percentage);
    }

    // Find one name starting with "Dav"
    printf("\nFound name starting with 'Dav': %s\n", findOne("Dav"));

    // Calculate specifications
    int result[5];
    specs(result);
    printf("\nSpecifications:\n");
    printf("Count: %d\n", result[0]);
    printf("Highest Percentage: %.2f\n", (float)result[1]);
    printf("Lowest Percentage: %.2f\n", (float)result[2]);
    printf("Mean: %.2f\n", (float)result[3]);
    printf("Standard Deviation: %.2f\n", (float)result[4]);

    // Delete record with roll number 103
    delete(103);

    // Display records after deletion
    printf("\nRecords after deletion:\n");
    for (int i = 0; i < numRecords; i++) {
        printf("Name: %s, Roll Number: %d, Percentage: %.2f\n", studentDB[i].name, studentDB[i].rollNumber, studentDB[i].percentage);
    }

    return 0;
}
