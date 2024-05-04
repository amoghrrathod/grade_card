# GRADE CARD IN C

Grade Card Management System

This repository contains a C program for managing student grade cards. The program allows users to:

- Add new students with their details such as name, roll number, semester, section, and marks in different subjects.
- Display the grade card for all added students, including their names, roll numbers, semester, section, GPA, and marks in each subject.
- Search for a student by name or roll number and display their grade card.

The program utilizes dynamic memory allocation to manage student data efficiently. It is organized into separate files for clarity and modularity:

- main.c: Contains the main program logic, including the menu interface and user interactions.
- student.h: Defines the Student struct and function prototypes for managing student data.
- student.c: Implements the functions defined in student.h for adding students, displaying grade cards, and searching for students.
  \*updated student.c contains system where the input is stored in a separated file and you never have to keep typing the same names again and again. The search option can simply be used to browse through the grade card application.

Feel free to explore and use this program for managing student grade cards in your educational projects!

To run this program simply download it and run it with the below commands in your terminal:

```
git clone https://github.com/arr3939/grade_card && cd grade_card
make && ./main
```

## Working Video

https://github.com/arr3939/grade_card/assets/151803946/78ac8118-e40f-4b1c-9413-4bf7414cdea3
