#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_student_info(Student *student) {
  // file open
  FILE *file = fopen("student_info.csv", "a");
  if (file == NULL) {
    printf("Error opening file: %s\n", "student_info.csv");
    return -1;
  }

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

  printf("Enter marks(out of 10) for Physics, Maths, Electrical, C Language, "
         "Mechanical (space-separated): ");
  if (scanf("%d %d %d %d %d", &student->marks[0], &student->marks[1],
            &student->marks[2], &student->marks[3],
            &student->marks[4]) != NUM_SUBJECTS) {
    fprintf(stderr, "Error: Invalid format for marks. Please enter five "
                    "space-separated integers.\n");
    return -1;
  }
  getchar();

  // Calculate GPA
  student->gpa = ((5 * student->marks[0]) + (4 * student->marks[1]) +
                  (4 * student->marks[2]) + (student->marks[3] * 5) +
                  (student->marks[4] * 3)) /
                 21.0;

  // Append student data to the CSV file
  fprintf(file, "%s,%s,%d,%s,%d,%d,%d,%d,%d\n", student->name, student->roll,
          student->sem, student->sec, student->marks[0], student->marks[1],
          student->marks[2], student->marks[3], student->marks[4]);

  fclose(file);
  return 0;
}
// Function to display grades from CSV file
void display_grades(const char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file: %s\n", filename);
    return;
  }

  printf("\nGrade Card\n");
  printf("\n %-20s | %-15s | %-7s | %-7s | %-5s\n", "Student Name",
         "Roll Number", "Semester", "Section", "CGPA");
  printf("====================================================================="
         "==========\n");

  char line[100];
  fgets(line, sizeof(line), file); // To skip the first line

  while (fgets(line, sizeof(line), file)) {
    char name[MAX_NAME_LENGTH], roll[MAX_ROLL_LENGTH], sec[MAX_SEC_LENGTH];
    int sem, marks[NUM_SUBJECTS];
    float gpa;
    // Parse CSV line
    sscanf(line, "%[^,],%[^,],%d,%[^,],%d,%d,%d,%d,%d", name, roll, &sem, sec,
           &marks[0], &marks[1], &marks[2], &marks[3], &marks[4]);

    // Calculate GPA
    gpa = ((5 * marks[0]) + (4 * marks[1]) + (4 * marks[2]) + (marks[3] * 5) +
           (marks[4] * 3)) /
          21.0;

    // Print student data
    printf("\n %-20s   %-15s   %-7d   %-7s   %-5f\n", name, roll, sem, sec,
           gpa);
    printf("%-7s Marks:\n", "");
    for (int j = 0; j < NUM_SUBJECTS; j++) {
      printf("          - %s: %d\n",
             (j == 0)   ? "Physics"
             : (j == 1) ? "Maths"
             : (j == 2) ? "Electrical"
             : (j == 3) ? "C Language"
                        : "Mechanical",
             marks[j]);
    }
    printf("\n");
  }

  fclose(file);
}
// Function to search for a student by name
void search_student_by_name(const char *filename, const char *name) {
  int found = 0;
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file: %s\n", filename);
    return;
  }
  printf("\nSearch results: \n");
  printf("\nGrade Card\n");
  printf("\n %-20s | %-15s | %-7s | %-7s | %-5s\n", "Student Name",
         "Roll Number", "Semester", "Section", "CGPA");
  printf("====================================================================="
         "==========\n");

  char line[100];
  fgets(line, sizeof(line), file); // To skip the first line

  while (fgets(line, sizeof(line), file)) {
    char std_name[MAX_NAME_LENGTH], roll[MAX_ROLL_LENGTH], sec[MAX_SEC_LENGTH];
    int sem, marks[NUM_SUBJECTS];
    float gpa;
    // Parse CSV line
    sscanf(line, "%[^,],%[^,],%d,%[^,],%d,%d,%d,%d,%d", std_name, roll, &sem,
           sec, &marks[0], &marks[1], &marks[2], &marks[3], &marks[4]);

    // Calculate GPA
    gpa = ((5 * marks[0]) + (4 * marks[1]) + (4 * marks[2]) + (marks[3] * 5) +
           (marks[4] * 3)) /
          21.0;
    printf("\n");
    if (strcmp(std_name, name) == 0) {
      printf("\n %-20s   %-15s   %-7d   %-7s   %-5f\n", std_name, roll, sem,
             sec, gpa);
      printf("%-7s Marks:\n", "");
      for (int j = 0; j < NUM_SUBJECTS; j++) {
        printf("          - %s: %d\n",
               (j == 0)   ? "Physics"
               : (j == 1) ? "Maths"
               : (j == 2) ? "Electrical"
               : (j == 3) ? "C Language"
                          : "Mechanical",
               marks[j]);
      }
      printf("\n");
      found = 1;
    }
  }

  if (!found) {
    printf("No matching student found.\n");
  }
}

void erase_student_data(const char *filename) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    printf("Error opening file %s for erasing.\n", filename);
    return;
  }
  fclose(file);
  printf("Student data erased successfully.\n");
}
