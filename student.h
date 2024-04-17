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

int get_student_info(Student *student);
void search_student_by_name(Student *students, int num_students, const char *roll);
void search_student_by_roll(Student *students, int num_students, const char *roll);
void display_menu();
void clrscr();
void free_student_memory(Student *students);

#endif

