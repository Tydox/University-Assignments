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
	Suspect* init_call;
	int suspects_amount;
	Suspect* suspects;
	Date call_date;
	
} Call;

typedef struct
{
	Call* c_list;
	int size;

} Call_list;

typedef struct
{
	Suspect* person;
	int size;

} Suspect_list;


void init_suspect(Suspect_list* list, int size);

void init_call(Suspect_list* slist, int ssize, Call_list* clist, int csize);

void main()
{
	Suspect_list sl1;
	int slist = 0;
	
	//init_suspect(&sl1, slist++);
	//free(sl1.person);
	
	Call_list cl1;
	int clist = 0;
	
	init_call(&sl1, slist, &cl1,clist);

	
	
}


void init_suspect(Suspect_list* list, int size)
{
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
		scanf_s(" %010d", &(list->person[size-1].phone_nbr));

		printf("Enter Start date[dd:mm:yyyy]: ");// start date
		scanf_s(" %d:%d:%d", &(list->person[size-1].start_date.day), &(list->person[size-1].start_date.month), &(list->person[size-1].start_date.year));

		printf("Enter End day[dd:mm:yyyy]: ");// end date
		scanf_s(" %d:%d:%d", &(list->person[size-1].end_date.day), &(list->person[size-1].end_date.month), &(list->person[size-1].end_date.year));

	
}

void init_call(Suspect_list* slist, int ssize, Call_list* clist, int csize)
{
	if (csize == 0)
		clist->c_list = (Call*)malloc((++csize) * sizeof(Call));
	else
		clist->c_list = (Call*)realloc(clist->c_list,(++csize) * sizeof(Call));
	if (!(clist->c_list))
	{
		printf("Mem Alloc failed on init_suspect!\n");
		exit(1);
	}

	clist->c_list[csize - 1].init_call = (Suspect*)malloc(sizeof(Suspect));
	if (!(clist->c_list[csize - 1].init_call))
	{
		printf("Mem Alloc failed on init_suspect!\n");
		exit(1);
	}

		printf("Enter Phone number of initiate suspect: ");
		scanf_s(" %d", &(clist->c_list[csize - 1].init_call->phone_nbr));		
		printf("Enter the number of participants: ");
		scanf_s(" %d", &(clist->c_list[csize - 1].suspects_amount));
		printf("Enter the suspects numbers:\n");
		clist->c_list->suspects = (Suspect*)malloc((clist->c_list[csize - 1].suspects_amount) * sizeof(Suspect));
		if (!(clist->c_list->suspects))
		{
			printf("Mem Alloc failed on init_suspect!\n");
			exit(1);
		}

	for(int i=0;i< clist->c_list[csize - 1].suspects_amount;++i)
		{
		printf("Suspect [%d]: ", i + 1);
		scanf_s(" %010d", &(clist->c_list[csize - 1].suspects[i].phone_nbr));
		}

	int clistnum = clist->c_list[csize - 1].suspects_amount;
	clist->c_list[csize - 1].suspects_amount = 0;
	// compare clist suspects init call phone numbers with slist person phone number 	
	for (int i = 0; i < clist->c_list[csize - 1].suspects_amount; ++i)
	{
		//first row, we go by call suspect to compare with the list of suspects

		for (int j = 0; j < slist->size; ++j)
		{
			//running on columns 
			//check if suspect and call person phone numbers are matching
				
			if (slist->person[j].phone_nbr == clist->c_list[csize - 1].init_call->phone_nbr)
			{
				//check if init call sus same as one of the sus in the list
				++(clist->c_list[csize - 1].suspects_amount);
			}


			for (int w = 0; w < clistnum; ++w)
			{
				if (slist->person[j].phone_nbr == clist->c_list[csize - 1].suspects[w].phone_nbr)
				{
					//check if init call sus list same as one of the sus in the list
					++(clist->c_list[csize - 1].suspects_amount);
				}
			}
		}
	}
	free(clist->c_list->suspects);
	clist->c_list->suspects = (Suspect*)malloc((clist->c_list[csize - 1].suspects_amount) * sizeof(Suspect));
	clistnum = clist->c_list[csize - 1].suspects_amount;
	for (int j = 0; j < slist->size; ++j)
		{
			for (int w = 0; w < clistnum; ++w)
			{
				//copy suspect from list to call list log
				clist->c_list[csize - 1].suspects[w] = slist->person[j];
			}
		}
	


	
	free(clist->c_list[csize - 1].init_call);
	free(clist->c_list->suspects);
	free(clist->c_list);

	
}
