all: student.c main.c 
	clang -c student.c && clang main.c student.o -o out
