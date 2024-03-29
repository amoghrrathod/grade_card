#include <stdio.h>
#include "student.h"
#include <string.h>

int get_student_info(Student *student) {
    student->num_students = 1;
    float gpa=0.0;
    
    printf("Enter student name (or leave blank to finish): ");
    if (fgets(student->name, MAX_NAME_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error reading name.\n");
        return -1;
    }
    //consume newline char after fgets
    student->name[strlen(student->name)-1]='\0';

    printf("Enter roll number: ");
    if (fgets(student->roll, MAX_ROLL, stdin)==NULL) {
        fprintf(stderr, "Error reading roll number.\n");
        return -2;
    }
    student->roll[strlen(student->roll)-1]='\0';
    
    printf("Enter semester: ");
    if(scanf("%d",&student->sem)!=1) {
        fprintf(stderr, "Error reading semester.\n");
        return -3;
    }
    getchar();
    
    printf("Enter section: "); // Section is both characters and number as users may have sections like abc or 123
    if (fgets(student->sec, MAX_SEC, stdin)==NULL) {
        fprintf(stderr, "Error reading section.\n");
        return -4;
    }
    student->sec[strlen(student->sec)-1]='\0';

    printf("Enter marks(out of 10) for Physics, Maths, Electrical, C Language, Mechanical (space-separated): ");
    
    //input marks
    if (scanf("%d %d %d %d %d", &student->marks[0], &student->marks[1],
               &student->marks[2], &student->marks[3], &student->marks[4]) != NUM_SUBJECTS) {
        fprintf(stderr, "Error: Invalid format for marks. Please enter five space-separated integers.\n");
        return -5;
    }
    // To clear the trailing new line character after scanf 
    getchar();
    // Calculate student gpa
    student->gpa=(float)((5*student->marks[0])+(4*student->marks[1])+(4*student->marks[2])+(student->marks[3]*5)+(student->marks[4]*3))/21;
    printf("\n");

    return 0; 
}
