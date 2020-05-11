#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX 10000
#define ADD_NEW_FAMILY 2
#define ADD_CHILD_TO_FAMILY 3
#define DEMISE_REMOVE 4
#define PRINT_FAMILY 5
#define DESTROY_TOWM_FREE 6

typedef struct person {
	char* name;
	unsigned int gender;//1-female, 0-male
}Person;

typedef struct family {
	char* family_name;
	Person* mother;
	Person *father; // parents' names
	Person **children_list;// list of the children in this family
	unsigned int child_list_size; // size of child_list array
	unsigned int current_listChild_size;
}Family;


typedef struct listFamilys {
 	Family** list;
	unsigned int  current_listFamily_size; // current size of family
}ListFamilys;



//functions decleration: 
ListFamilys *   initown();
 void Add_New_Family(ListFamilys* );
 Person * init_person();
 void Add_Child(ListFamilys*); //Person*** , unsigned int*, unsigned int* );//to existing family
 void remove_person(ListFamilys*); //passing away
 void print_family(Family);
 void free_town(ListFamilys*);
 Family* find_family_by_FN(Family**, unsigned int , char*);
 Person* find_person_by_CN(Person**, unsigned int , char*);


	 //functions declaration:
 void main()
 {
	 ListFamilys const *Family_List = initown();  // Family_List->list[0]->children_list[3]->name
	 
 	
	 int option;
	 do {
		 printf("\n**********MENU**************\n");
		 printf("choose your choice\n");
		 printf("ADD_NEW_FAMILY 2\n");
		 printf("ADD_CHILD_TO_FAMILY 3\n");
		 printf("DEMISE_REMOVE 4\n");
		 printf("PRINT_FAMILY 5\n");
		 printf("DESTROY_TOWM_FREE 6\n");
		 printf("*****************************\n");
		 scanf("%d", &option);
		 switch (option)
		 {

		 case ADD_NEW_FAMILY:
		 {
			 Add_New_Family(Family_List);
			 break;
		 }
		 case ADD_CHILD_TO_FAMILY:
		 {
			 Add_Child(Family_List);

			 break;
		 }
		 case DEMISE_REMOVE:
		 {
			 remove_person(Family_List);
			 break;
		 }

		 case PRINT_FAMILY:
		 {
			 printf("enter family name to print: ");
			 char name[20];
			 fseek(stdin, 0, SEEK_END);
			 scanf("%s", name);

			 Family *PF2 = find_family_by_FN(Family_List->list, Family_List->current_listFamily_size, name);
			 if (PF2)
			 {
				 print_family(*PF2);

			 }
			 else
			 {
				 printf("invalid family name to print, type option again\n");
				 scanf("%d", &option);
			 }
			 break;
		 }
		 case DESTROY_TOWM_FREE:
		 {
			 printf("are you sure to destroy ANGOLA?\n1-YES\nany key-No");
			 fseek(stdin, 0, SEEK_END);
			 if (getchar() == '1')
			 {
				 free_town(Family_List);
				 printf("BYE BYE");
				 system("pause");
			 }
			 else
			 {
				 option = 1;
			 }

		 }
		 default:
		 {
			 printf("invalid choice please try again:\n");
			 break;
		 }


		 }
	 } while (option != DESTROY_TOWM_FREE);
 }


	 Person* init_person()
 {
	 Person* person = (Person*)malloc(sizeof(Person));
//	 assert(person);//free #1
	 if (person)
	 {
		 printf("please enter name of person: ");
		
		 char tempname[20]={'\0'};//assuing

	 	scanf(" %[^\n]s",tempname);
	
		 char * new_PN = (char*)malloc(strlen(tempname) + 1); //doto free #2
		// assert(new_PN);  
		 strcpy(new_PN, tempname);
		 person->name = new_PN;
		 do {
			 printf("please enter gender of person:1-female, 0-male: ");
			 scanf("%u", &person->gender);
			 if (person->gender == 1 || person->gender == 0)
				 break;
		 } while (1);
	 }
	 return person;

 }


  ListFamilys *  initown()
{
	 ListFamilys *  listFamilys= (ListFamilys*)malloc(sizeof(ListFamilys)); //doto free3
	 if (!listFamilys)
	 {
		 printf("error allocation in initown"); //from now ill use assert
		 exit(1);
	 }
	listFamilys->current_listFamily_size = 0;
	Family **  THE_Familylist = (Family**)malloc(sizeof(Family*));//freeeee
	//assert(THE_Familylist);
	THE_Familylist = NULL;
	listFamilys->list = THE_Familylist;
	return listFamilys;
}


  void Add_New_Family(ListFamilys* ListFamilys)
  {

	  if ((ListFamilys==NULL) || (ListFamilys->current_listFamily_size == MAX))
	  {
		  printf("error message in add new family function: list dosent exist or - Angola reached max of familes\n");
		  getchar();
		  return;
	  }
	  // step 2
	  printf("please enter family name:");
	  char tempname[20];//assuing
	  fseek(stdin, 0, SEEK_END);
	 	scanf("%[^\n]s",tempname);
	  char * new_FN = (char*)malloc(strlen(tempname) + 1); //doto free4
	  //assert(new_FN);
	  strcpy(new_FN, tempname);
	  Family* Newfamily = (Family*)malloc(sizeof(Family));   /////////  important to remeber !   //free#5
	  //assert(Newfamily);


	  if (find_family_by_FN(ListFamilys->list, ListFamilys->current_listFamily_size, new_FN))
	  {
		  printf("family name %s, is already exist. back to main\n", new_FN);
		  free(Newfamily);
		  free(new_FN);
		  return;
	  }
	  else
	  {
		  Newfamily->family_name = new_FN;
		  ListFamilys->list = (Family**)realloc(ListFamilys->list,++(ListFamilys->current_listFamily_size));
		  //assert(ListFamilys->list);
		  ListFamilys->current_listFamily_size += 1;               //first updating size of familys
		  ListFamilys->list[(ListFamilys->current_listFamily_size)-1] = Newfamily; //then arr[size-1]
	  }

	   //step 3 - parents
	   Person *Father = NULL, *Mother = NULL, *Child=NULL;
	   int temp;
	   printf("choose the following:\n1-we are cupple of parents\n2-Father only\n3-Mother only");
	   printf("\n_______PARENTS________\n");	 
	   scanf("%d", &temp);
	   switch (temp)
	   {
	   case 1:
	   {
		   printf("fater:"); Father = init_person();
		   printf("mother:"); Mother = init_person();
		   Newfamily->father = Father;
		   Newfamily->mother = Mother;
		   break;
	   }
	   case 2:
	   {
		   printf("fater:"); Father = init_person();
		   Newfamily->father = Father;
		   Newfamily->mother = Mother;
		   break;
	   }
	   case 3:
	   {
		   printf("mother:");  Mother = init_person();
		   Newfamily->father = Father;
		   Newfamily->mother = Mother;
		   break;
	   }
	   default:
	   {
		   printf("please try again:");
		   scanf("%d", &temp);

	   }

	   }

       //step 4  children
	   printf("\n_______CHILDREN________\n");
	   printf("How many children are in  ''%s'''s family ? ", Newfamily->family_name);
	   scanf("%u", &(Newfamily->current_listChild_size));
	   Newfamily->children_list = (Person**)malloc((sizeof(Person*) * (Newfamily->current_listChild_size)) + 2); //free 7
	//   assert(Newfamily->children_list);
	   Newfamily->child_list_size = Newfamily->current_listChild_size + 2;//uptading whole children list

	   if (Newfamily->current_listChild_size == 0)
	   {
	  	 Newfamily->children_list = NULL;
	  	 Newfamily->children_list = 0;
	   }
	   else {

	  	unsigned int i;
	  	 for (i = 0; i < Newfamily->current_listChild_size; i++)
	  	 {
	  		 Child= init_person();
	  		 Newfamily->children_list[i] = Child;
	  	 }
	//  	 Newfamily->children_list[i++] = NULL; // saving prospecting children
	  //	 Newfamily->children_list[i] = NULL;
	   }
	   ListFamilys->list[ListFamilys->current_listFamily_size - 1] = Newfamily;
	   
	   printf("______FAMILY #%d ADDED SECCESFULY_____\n", ListFamilys->current_listFamily_size);	   
   }


 void Add_Child(ListFamilys* ListFamilys)
 {
	
	 printf("enter family name to add: ");
	 fseek(stdin, 0, SEEK_END);
	 char tempname[20]={'\0'};
 		scanf("%[^\n]s",tempname);
 	char *name=tempname;
	 Family *family = find_family_by_FN(ListFamilys->list, ListFamilys->current_listFamily_size, name);
	 if (!family)
	 {
		 printf("error adding a child to non-existing family/child already exist- back to main\n");
		 return;
	 }
	 printf("enter added child name of: ");
	 fseek(stdin, 0, SEEK_END);
	 char tempstr[20]={'0'};
 	scanf("%[^\n]s",tempstr);
 	char *FN = tempstr;
	
	 if ((find_person_by_CN(family->children_list, family->child_list_size, FN)));
	 {
		 printf("error adding a child to non-existing family/child already exist- back to main\n");
		 return;
	 }
	 
		 
		 if (family->current_listChild_size <   family->child_list_size)
		 {
			 for (unsigned int i = family->current_listChild_size; i < family->child_list_size; i++) // i = family->current_listChild_size  also possible
			 {
				 if ((family->children_list[i] == NULL))
				 {
					 printf("adding child:");  
					 Person* Child = init_person();
					 family->children_list[i] = Child;
					 family->current_listChild_size++;
					 break; // just onec 
				 }
				
			 }
		 }
		 else {
		 	
			family->children_list = (Person**)realloc(family->children_list, family->current_listChild_size+3);
			assert(family->children_list);
			family->child_list_size += 3; //

			unsigned int i =family->current_listChild_size;
				 for (i ; i < family->child_list_size; i++)
				 {
					 printf("adding child:");
					 Person* Child = init_person();
					 family->current_listChild_size++;
					 break;
					
				 }
				family->children_list[++i] = NULL;
				family->children_list[++i] = NULL;

		 }
		 for (Family *Ptofamily = *(ListFamilys->list); ListFamilys->list[ListFamilys->current_listFamily_size - 1] == Ptofamily; ListFamilys->list++)
		 {
			 if (Ptofamily == family)
			 {
				 *(ListFamilys->list) = family;
			 }

		 }
 
 }

 void remove_person(ListFamilys* ListFamilys)
 {
	 printf("enter family name of the person to remove: ");
	 fseek(stdin, 0, SEEK_END);
	  char tempstr2[20]={'0'};
 				scanf("%[^\n]s",tempstr2);
 	char *FN = tempstr2;
	 Family * family = find_family_by_FN(ListFamilys->list, ListFamilys->current_listFamily_size, FN);
	 if (!family)
		 printf("error removing a person from the list\n");
	 else {
		
		 char temp;
		 do {
			 printf("choose the following: C-child, M-mother, F- father ");  
			 fseek(stdin, 0, SEEK_END);
			 scanf("%c", &temp);
			 if (temp == 'C'|| temp == 'M'  || temp == 'F')
				 break;
		 } while (1);
		
		 switch (temp)
	 {
		 case 'M':
		 {
			 if (!family->father)
			 {
				 printf("Cannot report the death of a single-parent parent");
				 break;
			 }
			 free(family->mother->name);
			 free(family->mother);

		 }
		 case 'F':
		 {
			 if (!family->mother)
			 {
				 printf("Cannot report the death of a single-parent parent");
				 break;
			 }
			 free(family->father->name); 
			 free(family->father);
		 }
		 case 'C':
		 {
			 printf("enter child name: ");
			 fseek(stdin, 0, SEEK_END);
			 char tempstr2[20]={'0'};
 				scanf("%[^\n]s",tempstr2);
		 		char *CN = tempstr2;
			 Person* child_free = find_person_by_CN(family->children_list, family->current_listChild_size, CN);
			 if (!child_free)
				 printf("error removing %s  from children list. apperantly does not exist in the list\n",CN);
			 else
			 {
				
				 free(child_free->name);
				 free(child_free); //free child type peson
				 family->children_list = (Person**)realloc(family->children_list, ++(family->current_listChild_size));
				 family->current_listChild_size--;
			 }
		
		 }
	 }
		 for (unsigned int j = 0; j < ListFamilys->current_listFamily_size ; j++)
		 {
			 if (ListFamilys->list[j] == family)
			 {
				 ListFamilys->list[j]=family;  ////the chain !!!!! 
			 }
		 }
  }

 }

 void print_family(Family family)
 {


	 if (family.family_name)
	 {
		 printf("%s's family are:\n", family.family_name);
		 family.father ? printf("father: %s,n", family.father->name) : printf("FATHER DOES NOT EXIST");
		 printf("gender: Male\n");//neccerebly 
		 family.mother ? printf("mother: %s,", family.mother->name) : printf("MOTHER DOES NOT EXIST");
		 printf("gender: Female\n");

		 for (unsigned int i = 0; i < family.current_listChild_size; i++)
		 {
			 printf("name of child %d : %s, ",i+1, family.children_list[i]->name);
			 family.children_list[i]->gender == 0 ? printf("gender:Male\n") : printf("gender:Female\n");

		 }

	 }
	 else {
		 printf("family dosen't exist in print family function");
	 }
 }
 void free_town(ListFamilys* familylist)// correct frase
 {
	 if (familylist)
	 {
		 for (unsigned int i = 0; i < familylist->current_listFamily_size; i++)
		 {
			 free(familylist->list[i]->family_name);
		 	free(familylist->list[i]->father->name);
			 free(familylist->list[i]->father);
			 free(familylist->list[i]->mother->name);
			 free(familylist->list[i]->mother);

			 for (int j = 0; i < familylist->list[i]->current_listChild_size; i++)
			 { 
				 free(familylist->list[i]->children_list[j]->name);
				 free(familylist->list[i]->children_list[j]);
			 }
		 }
		 printf("Angola is free now\n");
		 free(familylist);
	 }
	 else {
		 printf("family dosen't exist in free_town - Angola function");
	 }
 }
   Family* find_family_by_FN(Family**  familylists, unsigned int size_of_list, char* FN)
 {
	 if (familylists)
	 {
		 for (unsigned int i = 0; i < size_of_list; i++)
		 {
			 if (strcmp(familylists[i]->family_name, FN) == 0)
				 return familylists[i];
		 }
	 }
		 return NULL;

 }

   Person* find_person_by_CN(Person** childrenlist, unsigned int size_CL , char* CN)
   {
	   
	   if (childrenlist)
	   {
		   for (int i=0; childrenlist[size_CL-1]==NULL; childrenlist++)// different
		   {
			   if (strcmp(childrenlist[0]->name, CN) == 0)
				   return *childrenlist;
		   }
	   }
	   else {
		   printf("couldn't find child, returning NULL");
		   return NULL;
	   }
 	

   }
 

