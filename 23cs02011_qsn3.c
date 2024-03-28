#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

int compare_dates(Date date1, Date date2) {
    if (date1.year > date2.year) {
        return 1;
    } else if (date1.year < date2.year) {
        return -1;
    } else {
        if (date1.month > date2.month) {
            return 1;
        } else if (date1.month < date2.month) {
            return -1;
        } else {
            if (date1.day > date2.day) {
                return 1;
            } else if (date1.day < date2.day) {
                return -1;
            } else {
                return 0;
            }
        }
    }
}

int main() {
    Date date1 = {2024, 3, 22};
    Date date2 = {2024, 3, 21};

    int result = compare_dates(date1, date2);
    printf("%d\n", result); // Output: 1

    return 0;
}