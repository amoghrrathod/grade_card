#include <stdio.h>
#include "student.h"
void display_menu() {
    printf("\nMenu:\n");
    printf("1. Add Student\n");
    printf("2. Display Grades\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}
void clrscr(){
  printf("\033[1;1H\033[2J");
}
int main() {
    int num_students = 0; 
    Student students[MAX_STUDENTS]; // array of student structures
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);
        getchar(); // consume newline char after scanf

        switch (choice) {
            case 1:
                if (num_students < MAX_STUDENTS) {
                    printf("Enter details for student %d:\n", num_students + 1);
                    if (get_student_info(&students[num_students]) == 0) {
                        num_students++; // +1 number of students
                    } else {
                        printf("Failed to add student. Please try again.\n");
                    }
                } else {
                    printf("Maximum number of students reached.\n");
                }
                clrscr();
                break;
            case 2:
                clrscr();
                if (num_students > 0) {
                    printf("\nGrade Card\n");
                    printf("\n%-5s | %-20s | %-15s | %-7s | %-7s | %-5s\n","Srno.","Student Name","Roll Number","Semester","Section","CGPA");
                    printf("===============================================================================");
                    for (int i=0;i<num_students;i++) {
                        printf("\n%-5d   %-20s   %-15s   %-7d   %-7s   %-5f\n",i+1,students[i].name,students[i].roll,students[i].sem,students[i].sec,students[i].gpa); 
                        printf("%-7s Marks:\n","");
                        for (int j = 0; j < NUM_SUBJECTS;j++) {
                            printf("          - %s: %d\n", (j == 0) ? "Physics" : (j == 1) ? "Maths" : (j == 2) ? "Electrical" : (j == 3) ? "C Language" : "Mechanical", students[i].marks[j]);
                        }
                    printf("===============================================================================\n");
                    }                
                } else {
                    printf("No students added yet.\n");
                }
                break;
            case 3:
                clrscr();
                printf("Exiting program...\n");
                break;
            default:
                clrscr();
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
        }
    } while (choice != 3);

    return 0;
}
