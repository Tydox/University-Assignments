#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> 

typedef struct
{
	char* nameC;
	int grade;
	int passing_grade;
}course;

typedef struct
{
	int day;
	int month;
	int year;
}date;

typedef struct
{
	char* name;
	char school_year;
	int courses_num;
	date birthdate;
	course* current_courses;
	
}student;

double studentAverage(student* name);
course* coursesNotSuccedeed(student* name, int* failed_courses_num);
void init_student(student* stdname);
void init_course(student* stdname);
int isBirthday(date birthday);

void main()
{
	int student_num = 0;
	printf("Enter the amount of students:\n");
	scanf("%d", &student_num);
	student* pstudent = (student*)malloc(student_num * sizeof(student));

	
	free(pstudent);
	pstudent = NULL;
	
	
};

double studentAverage(student* name)
{
	double avg = 0;
	for (int i = 0; i < name->courses_num; ++i)
	{
		avg = avg + (name->current_courses[i]->grade);
	}
	avg = avg/(name->courses_num);
	return avg;
}

course* coursesNotSuccedeed(student* name, int* failed_courses_num)
{
	int failedcoursenum = 0;
	for( int i=0; i<name->courses_num;++i)
	{
		if ((name->current_courses[i]->grade) < (name->current_courses[i]->passing_grade))
		{
			++failedcoursenum;
		}

	}
	if(failedcoursenum==0)
	{
		*failed_courses_num = 0;
		return NULL;
	}
	course* failed_courses_adr = (course*)malloc(failedcoursenum * sizeof(course));
	if (failed_courses_adr == 0)
	{
		printf("Memory error\n");
		return NULL;
	}
	int j = 0;
	for (int i = 0; i < name->courses_num; ++i)
	{
		if ((name->current_courses[i]->grade) < (name->current_courses[i]->passing_grade))
		{
			memcpy(failed_courses_adr+j, name->current_courses[i], sizeof(course));
			++j;
		}
	}
	
	*failed_courses_num = failedcoursenum;
	return NULL;
}

int isBirthday(date* birthday)
{
	time_t now = time(0);
	struct tm* ltm = localtime(&now);
	if ((birthday->day == ltm->tm_mday) && (((birthday->month)-1) == ltm->tm_mon) && (birthday->year == ltm->tm_year))
		return 1;
		
	return 0;
}

void init_student(student* stdname)
{
	puts("Enter name:");
	scanf(" %[^\n]s", stdname->name);
	puts("Enter School Year:");
	scanf(" %c", &(stdname->school_year));
	puts("Enter Student total amount of courses:");
	scanf(" %d", &(stdname->courses_num));
	puts("Enter year of birth:");
	scanf(" %d", &(stdname->birthdate.year));
	puts("Enter month of birth:");
	scanf(" %d", &(stdname->birthdate.month));
	puts("Enter day of birth:");
	scanf(" %d", &(stdname->birthdate.day));

	*(stdname->current_courses)=(course*)malloc((stdname->courses_num) * sizeof(course));
}
void init_course(student* stdname)
{
	char tempstr[100] = "";
	printf("Enter the name of the course:\n");
	scanf(" %[^\n]s", tempstr);
	//stdname->current_courses = (char*)malloc((strlen(tempstr) + 1 * sizeof(char)));
	
}
void print_student(student* stdname)
{
	printf("Name: %s\n ", stdname->name);
	printf("School year: %d\n", (stdname->school_year));
	printf("Total amount of courses: %d\n", (stdname->courses_num));
	printf("Date of birth: %d.%d.%d", (stdname->birthdate.year), (stdname->birthdate.month), (stdname->birthdate.day));
}