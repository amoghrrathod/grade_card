#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100
#define NUM_SUBJECTS 5 // total subjects 
#define MAX_ROLL 15
#define MAX_GPA 10.0
#define MAX_SEM 8 
typedef struct {
    char name[MAX_NAME_LENGTH]; // Single name for the student
    int marks[NUM_SUBJECTS]; // Marks for all subjects
    int num_students;// Number of students stored
    char roll[MAX_ROLL];// Roll number of students
    float gpa;//gpa
    int sem[MAX_SEM];//SEM
} Student;

int get_student_info(Student *student);

#endif
