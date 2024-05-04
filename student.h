#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 15
#define MAX_NAME_LENGTH 50
#define MAX_ROLL_LENGTH 15
#define MAX_SEC_LENGTH 10
#define NUM_SUBJECTS 5

typedef struct {
  char *name;
  int marks[NUM_SUBJECTS];
  char *roll;
  float gpa;
  int sem;
  char *sec;
} Student;
void erase_student_data(const char *filename);
int get_student_info(Student *student);
void display_grades(const char *filename);
void search_student_by_name(const char *filename, const char *name);
void display_menu();
void clrscr();
void free_student_memory(Student *students);

#endif
