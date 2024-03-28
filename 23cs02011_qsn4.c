#include <stdio.h>
#include <string.h>
// Structure for Address
typedef struct {
    char street[50];
    char city[50];
    char zip_code[10];
} Address;

// Structure for Person
typedef struct {
    char name[50];
    Address address;
} Person;

int main() {
    // Create a Person variable
    Person person1;
    
    // Assign values to the Person's details
    strcpy(person1.name, "S P");
    strcpy(person1.address.street, "ALKAPURI");
    strcpy(person1.address.city, "RATLAM");
    strcpy(person1.address.zip_code, "12345");
    
    // Print the Person's details
    printf("Person's Name: %s\n", person1.name);
    printf("Address: %s, %s, %s\n", person1.address.street, person1.address.city, person1.address.zip_code);

    return 0;
}