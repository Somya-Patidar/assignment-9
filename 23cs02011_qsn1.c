#include <stdio.h>
struct company {
    char name[100];
    char address[100];
    char phone[15];
    int noOfEmployee;
};

int main() {
   
    struct company comp;

    
    printf("Enter company name: ");
    gets(comp.name);
    
    printf("Enter company address: ");
    gets(comp.address);
    

    printf("Enter company phone: ");
    scanf("%s", comp.phone);

    printf("Enter number of employees: ");
    scanf("%d", &comp.noOfEmployee);

    // Display the values
    printf("\nCompany Details:\n");
    printf("Name: %s\n", comp.name);
    printf("Address: %s\n", comp.address);
    printf("Phone: %s\n", comp.phone);
    printf("Number of employees: %d\n", comp.noOfEmployee);

    return 0;
}
