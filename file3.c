#include <stdio.h>
#include <string.h>

typedef struct Emp_detail {
    int age;
    float sal_inc;
    char job_loc[30];
} emp;  

int main() {
    int menu;
    emp record[5];

    // record[0].age = 30;
    // record[0].sal_inc = 0.5;
    // strcpy(record[0].job_loc, "New York");

    // printf("age=%d, sal_inc=%.2f, job_loc=%s\n", record[0].age, record[0].sal_inc, record[0].job_loc);

    do {
        printf("\nPlease enter your choice:\n");
        printf("1. Insert a new employee\n");
        printf("2. Update an existing employee\n");
        printf("3. Remove employee\n");
        printf("4. Print details of an employee\n");
        printf("5. Exit\n");

        scanf("%d", &menu);

        switch (menu) {
            case 1: {
                printf("Insert a new employee:\n");
                for (int i = 0; i < 5; i++) {
                    if (record[i].age == 0) {
                        printf("Enter age for employee %d: ", i + 1);
                        scanf("%d", &record[i].age);
                        printf("Enter salary increment for employee %d: ", i + 1);
                        scanf("%f", &record[i].sal_inc);
                        printf("Enter job location for employee %d: ", i + 1);
                        scanf("%s", record[i].job_loc);
                        break;
                    }
                }
                break;
            }

            case 2: {
                int emp_index;
                printf("Enter employee index to update (1 to 5): ");
                scanf("%d", &emp_index);
                if (emp_index >= 1 && emp_index <= 5 && record[emp_index - 1].age != 0) {
                    printf("Updating employee %d\n", emp_index);
                    printf("Enter new age: ");
                    scanf("%d", &record[emp_index - 1].age);
                    printf("Enter new salary increment: ");
                    scanf("%f", &record[emp_index - 1].sal_inc);
                    printf("Enter new job location: ");
                    scanf("%s", record[emp_index - 1].job_loc);
                } else {
                    printf("Invalid employee index or employee is not initialized.\n");
                }
                break;
            }

            case 3: {
                int emp_index;
                printf("Enter employee index to remove (1 to 5): ");
                scanf("%d", &emp_index);
                if (emp_index >= 1 && emp_index <= 5 && record[emp_index - 1].age != 0) {
                    printf("Removing employee %d\n", emp_index);
                    record[emp_index - 1].age = 0; 
                    record[emp_index - 1].sal_inc = 0.0;
                    strcpy(record[emp_index - 1].job_loc, "");
                } else {
                    printf("Invalid employee index or employee is not initialized.\n");
                }
                break;
            }

            case 4: {
                int emp_index;
                printf("Enter employee index to view (1 to 5): ");
                scanf("%d", &emp_index);
                if (emp_index >= 1 && emp_index <= 5 && record[emp_index - 1].age != 0) {
                    printf("Employee %d details:\n", emp_index);
                    printf("Age: %d\n", record[emp_index - 1].age);
                    printf("Salary Increment: %.2f\n", record[emp_index - 1].sal_inc);
                    printf("Job Location: %s\n", record[emp_index - 1].job_loc);
                } else {
                    printf("Invalid employee index or employee is not initialized.\n");
                }
                break;
            }

            case 5:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (menu != 5);

    return 0;
}

