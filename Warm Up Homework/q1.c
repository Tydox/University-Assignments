#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int day;
	int month;
	int year;
	
}Date;

typedef struct
{
	int phone_nbr;
	Date start_date;
	Date end_date;
	
}Suspect;

typedef struct
{
	char* name;
	int users_amount;
	Suspect** suspects;
	Date call_date;
	
} Call;

typedef struct
{
	Call* array;
	int size;

} Call_list;

typedef struct
{
	Suspect* person;
	int size;

} Suspect_list;


void init_suspect(Suspect_list* list, int size);


void main()
{
	Suspect_list sl1;
	int size = 0;
	
	init_suspect(&sl1, size++);
	//printf("0%d\n", (sl1.person[size - 1].phone_nbr));

	free(sl1.person);
}

//void init_suspect(Suspect* sus_array, int* size)
//{
//	//char temp_num[11]={"00.00.0000"};
//	//++*size;
//	//sus_array = (Suspect*)realloc(sus_array, (*size)*sizeof(Suspect));
//	//if(!sus_array)
//	//{
//	//	printf("Error Mem Alloc\n");
//	//	exit(0);
//	//}
//	//
//	//printf("Enter your suspects phone number[10 digits]: ");
//	//scanf_s(" %10d", (sus_array+*size)->phone_nbr);
//	//printf("Enter your suspects arrest date[dd.mm.yyyy]: ");
//	//scanf_s(" %[^\n]s", temp_num,8);
//	//memcpy(sus_array[*size].end_date.day, temp_num,2);
//	//memcpy(sus_array[*size].end_date.month, temp_num+3, 2);
//	//memcpy(sus_array[*size].end_date.year, temp_num + 6, 4);
//
//	
//}

void init_suspect(Suspect_list* list, int size)
{
	//++size;
	if (size>0)
		list->person = (Suspect*)realloc(list->person, (++size) * sizeof(Suspect)); //size +1 array

	else
		list->person = (Suspect*)malloc((++size) * sizeof(Suspect)); //size +1 array

	if(!(list->person))
	{
		printf("Mem Alloc failed on init_suspect!\n");
		exit(1);
	}
	
		printf("Enter Phone Number [10 digits]: "); // phone number
		scanf_s(" %10d", &(list->person[size-1].phone_nbr));

		printf("Enter Start date[dd:mm:yyyy]: ");// start date
		scanf_s(" %d:%d:%d", &(list->person[size-1].start_date.day), &(list->person[size-1].start_date.month), &(list->person[size-1].start_date.year));

		printf("Enter End day[dd:mm:yyyy]: ");// end date
		scanf_s(" %d:%d:%d", &(list->person[size-1].end_date.day), &(list->person[size-1].end_date.month), &(list->person[size-1].end_date.year));

	
}
