#include <stdio.h>
#include "student.h"

int main() {
    int num_students = 1; // Number of students
    Student students[num_students]; // Array of Student structures

    for (int i = 0; i < num_students; i++) {
        printf("\nStudent %d information:\n", i + 1);
        int result = get_student_info(&students[i]); // Get info for each student
        if (result != 0) { // Handle errors
            fprintf(stderr, "Error getting information for student %d.\n", i + 1);
            return 1;
        }
    }

    printf("\nGrade Card:\n");
    for (int i = 0; i < num_students; i++) {
        printf("Student %d:\n", i + 1);
        printf("  Name: %s\n", students[i].name);
        printf("  Roll number: %s\n",students[i].roll);
        printf("  GPA: %f\n", students[i].gpa);
        printf("  Marks:\n");
        for (int j = 0; j < NUM_SUBJECTS; j++) {
            printf("    - %s: %d\n", (j == 0) ? "Physics" : (j == 1) ? "Maths" : (j == 2) ? "Electrical" : (j == 3) ? "C Language" : "Mechanical", students[i].marks[j]);
        }
    }

    return 0;
}
