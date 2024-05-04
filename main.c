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
      /*clrscr();
      // Open csv file in write mode
      FILE *student_info = fopen("student_info.csv", "w");
      if (!student_info) {
        printf("Failed to open file.");
        break;
      }

      if (num_students > 0) {
        printf("\nGrade Card\n");
        fprintf(student_info,
                "Srno., Student Name, Roll Number, Semester, Section, CGPA, "
                "Physics, Maths, Electrical, C Language, Mechanical\n");
        for (int i = 0; i < num_students; i++) {
          fprintf(student_info, "%d, %s, %s, %d, %s, %f, %d, %d, %d, %d, %d\n",
                  i + 1, students[i].name, students[i].roll, students[i].sem,
                  students[i].sec, students[i].gpa, students[i].marks[0],
                  students[i].marks[1], students[i].marks[2],
                  students[i].marks[3], students[i].marks[4]);

          printf("\n%-5d   %-20s   %-15s   %-7d   %-7s   %-5f\n", i + 1,
                 students[i].name, students[i].roll, students[i].sem,
                 students[i].sec, students[i].gpa);
          printf("%-7s Marks:\n", "");
          for (int j = 0; j < NUM_SUBJECTS; j++) {
            printf("          - %s: %d\n",
                   (j == 0)   ? "Physics"
                   : (j == 1) ? "Maths"
                   : (j == 2) ? "Electrical"
                   : (j == 3) ? "C Language"
                              : "Mechanical",
                   students[i].marks[j]);
          }
          printf("============================================================="
                 "==================\n");
        }
        fclose(student_info); // Close the file after writing all data
      } else {
        printf("No students added yet.\n");
        fclose(student_info); // Close the file if no data is written
        }*/
      clrscr();
      display_grades("student_info.csv");
      break;

      break;
    case 3:
      clrscr();
      char search[MAX_NAME_LENGTH];
      printf("Enter student name to search: ");
      scanf("%s", search);
      search_student_by_name(students, num_students, search);

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
  } while (choice != 5);

  return 0;
}
