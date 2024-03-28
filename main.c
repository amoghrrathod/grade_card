#include <stdio.h>
#include "student.h"

int main() {
    int num_students = 1; // Number of students
    printf("Enter number of students: ");
    scanf("%d",&num_students);
    getchar();

    Student students[num_students]; // Array of Student structures
    
    for (int i = 0; i < num_students; i++) {
        printf("\nStudent %d information:\n", i + 1);
        int result = get_student_info(&students[i]); // Get info for each student
        if (result != 0) { // Handle errors
            fprintf(stderr, "Error getting information for student %d.\n", i + 1);
            return 1;
        }
    }

    /*printf("\nGrade Card:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Student %d:\n", i + 1);
        printf("  Name: %s\n", students[i].name);
        printf("  Roll number: %s\n",students[i].roll);
        printf("  GPA: %f\n", students[i].gpa);
        printf("  Marks:\n");
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            printf("    - %s: %d\n", (j == 0) ? "Physics" : (j == 1) ? "Maths" : (j == 2) ? "Electrical" : (j == 3) ? "C Language" : "Mechanical", students[i].marks[j]);
        }
    }*/
    printf("========================================================");
    printf("\nGrade Card\n");
    printf("========================================================");
    printf("\n%-5s | %-20s | %-15s | %-5s\n","Srno.","Student Name","Roll Number","CGPA");
    printf("========================================================");
for (int i=0;i<num_students;i++) {
      printf("\n%-5d | %-20s | %-15s | %-5f\n",i+1,students[i].name,students[i].roll,students[i].gpa); 
      printf("%-7s Marks:\n","");
      for (int j = 0; j < NUM_SUBJECTS;j++) {
      printf("          - %s: %d\n", (j == 0) ? "Physics" : (j == 1) ? "Maths" : (j == 2) ? "Electrical" : (j == 3) ? "C Language" : "Mechanical", students[i].marks[j]);
        }
      printf("========================================================\n");

    }
    return 0;
}
