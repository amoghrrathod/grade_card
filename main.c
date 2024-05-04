#include "student.h"
#include <stdio.h>

void clrscr() { printf("\033[1;1H\033[2J"); }

void display_menu() {
  printf("\nMenu:\n");
  printf("1. Add Student\n");
  printf("2. Display Grades\n");
  printf("3. Search student\n");
  printf("4. Erase all student Data\n");
  printf("5. Exit\n");
  printf("Enter your choice: ");
}

int main() {
  clrscr();
  int num_students = 0;
  Student students[MAX_STUDENTS]; // array of student structures
  int choice;
  
  FILE *file = fopen("student_info.csv", "a");
    if (file == NULL) {
        printf("Error opening file: %s\n", "student_info.csv");
        return -1;
    }

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
      fflush(file);
      fseek(file, 0, SEEK_SET);
      clrscr();
      break;
    case 2:
      clrscr();
      fflush(file);
      fseek(file, 0, SEEK_SET);
      display_grades("student_info.csv");
      break;

      break;
    case 3:
      clrscr();
      fflush(file);
      fseek(file, 0, SEEK_SET);
      char search[MAX_NAME_LENGTH];
      printf("Enter student name to search: ");
      scanf("%s", search);
      search_student_by_name("student_info.csv", search);
      break;
    case 4:
      clrscr();
      erase_student_data("student_info.csv");
      break;
    case 5:
      clrscr();
      printf("Exiting program...\n");
      break;
    default:
      clrscr();
      printf("Invalid choice. Please enter a number between 1 and 4.\n");
    }
    fclose(file);
  } while (choice != 5);

  return 0;
}
