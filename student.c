#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int get_student_info(Student *student) {
    student->name = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));
    if (student->name == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return -1;
    }
    
    student->roll = (char *)malloc(MAX_ROLL_LENGTH * sizeof(char));
    if (student->roll == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(student->name);
        return -1;
    }

    student->sec = (char *)malloc(MAX_SEC_LENGTH * sizeof(char));
    if (student->sec == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(student->name);
        free(student->roll);
        return -1;
    }

    printf("Enter student name (or leave blank to finish): ");
    if (fgets(student->name, MAX_NAME_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error reading name.\n");
        return -1;
    }
    student->name[strlen(student->name) - 1] = '\0';

    printf("Enter roll number: ");
    if (fgets(student->roll, MAX_ROLL_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error reading roll number.\n");
        return -1;
    }
    student->roll[strlen(student->roll) - 1] = '\0';

    printf("Enter semester: ");
    if (scanf("%d", &student->sem) != 1) {
        fprintf(stderr, "Error reading semester.\n");
        return -1;
    }
    getchar();

    printf("Enter section: ");
    if (fgets(student->sec, MAX_SEC_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error reading section.\n");
        return -1;
    }
    student->sec[strlen(student->sec) - 1] = '\0';

    printf("Enter marks(out of 10) for Physics, Maths, Electrical, C Language, Mechanical (space-separated): ");
    if (scanf("%d %d %d %d %d", &student->marks[0], &student->marks[1], &student->marks[2], &student->marks[3], &student->marks[4]) != NUM_SUBJECTS) {
        fprintf(stderr, "Error: Invalid format for marks. Please enter five space-separated integers.\n");
        return -1;
    }
    getchar();

    // Calculate GPA
    student->gpa = ((5 * student->marks[0]) + (4 * student->marks[1]) + (4 * student->marks[2]) + (student->marks[3] * 5) + (student->marks[4] * 3)) / 21.0;

    return 0;
}

// Function to search for a student by name
void search_student_by_name(Student *students, int num_students, const char *name) {
    int found = 0;
    printf("\nSearch Results for \"%s\":\n", name);
    printf("\nGrade Card\n");
                    printf("\n %-20s | %-15s | %-7s | %-7s | %-5s\n","Student Name","Roll Number","Semester","Section","CGPA");
                    printf("===============================================================================");
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].name, name) == 0) {
    printf("\n %-20s | %-15s | %-7d | %-7s | %-5f\n",students[i].name, students[i].roll, students[i].sem, students[i].sec, students[i].gpa);
            printf("%-7s Marks:\n","");
                        for (int j = 0; j < NUM_SUBJECTS;j++) {
                            printf("          - %s: %d\n", (j == 0) ? "Physics" : (j == 1) ? "Maths" : (j == 2) ? "Electrical" : (j == 3) ? "C Language" : "Mechanical", students[i].marks[j]);
                        }
            printf("\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No matching student found.\n");
    }
}

// Function to search for a student by roll number
void search_student_by_roll(Student *students, int num_students, const char *roll) {
    int found = 0;
    printf("\nSearch Results for \"%s\":\n", roll);
                        printf("\nGrade Card\n");
                    printf("\n %-20s | %-15s | %-7s | %-7s | %-5s\n","Student Name","Roll Number","Semester","Section","CGPA");
                    printf("===============================================================================");
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].roll, roll) == 0) {
    printf("\n %-20s | %-15s | %-7d | %-7s | %-5f\n",students[i].name, students[i].roll, students[i].sem, students[i].sec, students[i].gpa);
            printf("%-7s Marks:\n","");
                        for (int j = 0; j < NUM_SUBJECTS;j++) {
                            printf("          - %s: %d\n", (j == 0) ? "Physics" : (j == 1) ? "Maths" : (j == 2) ? "Electrical" : (j == 3) ? "C Language" : "Mechanical", students[i].marks[j]);
                        }
            found = 1;
            break; // Assuming roll numbers are unique, so we can stop searching after finding the first match
        }
    }
    if (!found) {
        printf("No matching student found.\n");
    }
}


void free_student_memory(Student *students) {
    free(students);
}

