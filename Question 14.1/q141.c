#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	long id;
	union Grade {
		char grade_char;
		unsigned int grade_num; //unsign gives only positive numbers x>0
	}grade;
}StudentGrade;


StudentGrade* init_student_grade(StudentGrade* student_name);
void print_student_grade(StudentGrade* student_name);

void main()
{

	StudentGrade* Daniel = NULL;
	Daniel = init_student_grade(Daniel);
	print_student_grade(Daniel);

	free(Daniel);
}

StudentGrade* init_student_grade(StudentGrade* student_name)
{
	int opt_val;


	student_name = (StudentGrade*)malloc(sizeof(StudentGrade));
	if (!student_name)
	{
		printf("Dynamic Mem Error, exiting.");
		exit(0);
	}

	printf("Enter the students id[9 Digits]: ");
	scanf_s(" %ld", &(student_name->id));
	printf("Grade Format:\n1. Character\n2. Decimal Number\n");
	scanf_s("%d", &opt_val);
	while (!(opt_val >= 1 && opt_val <= 2))
	{
		printf("Incorrect value, try again\nGrade Format:\n1. Character\n2. Decimal Number\n");
		scanf_s("%d", &opt_val);

	}

	if (opt_val == 1)
	{
		printf("Enter the Grade in Characters [A/B/C/D/E/F]: ");
		scanf_s(" %c", &(student_name->grade.grade_char), 2);

	}
	else if (opt_val == 2)
	{
		printf("Enter the Grade in Decimal Number[0-100]: ");
		scanf_s(" %d", &(student_name->grade.grade_num));
	}
	return student_name;
}

void print_student_grade(StudentGrade* student_name)
{
	printf("Student ID: %d\n", student_name->id);

	if (student_name->grade.grade_char >= 'A' && student_name->grade.grade_char <= 'F')
		printf("Student Grade: %c", student_name->grade.grade_char);
	else
		printf("Student Grade: %d", student_name->grade.grade_num);

}
