all:
	-clang -c student.c && clang main.c student.o -o out
