#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATASIZE 81

typedef struct Folder {
	struct file** file_name; // file* file_name[size]
	unsigned int files_num;
}f;

typedef struct file {
	char file_name[DATASIZE];
	char data_type[2];
	union Content{
		f f;
		union Data {
			char text[DATASIZE];
		}d;
	}content;
	
}File; // total size is 164 with data, with folder well its unlimited since malloc duh bitch stfu nigga piece of shit


void printf_files(File* name);
File* new_files(char data_type);


main() {
	File* f1;
	char optchar;
	
	printf("New file Generator\nEnter What type you want\n[d] Data\n[f] Folder\nUser Input[d/f]: ");
	scanf_s(" %c", &optchar,2);
	f1 = new_files(optchar);

	printf_files(f1);
	//testing
	/*printf("File Name: %s\n", f1->file_name);
	printf("Type: %c\n", f1->content.f.file_name);
	printf("Data: %u\n", f1->content.f.files_num);*/
	//free(f1);
};


void printf_files(File* name)
{
	if (*(name->data_type) == 'f') {
		//empty size 0
		if (name->content.f.files_num == 0) {
			//printf("Empty Folder\n");
			printf("\nFile Name: %s\n", name->file_name);
			printf("Type: %s\n", name->data_type);
			printf("Size: %u\n", name->content.f.files_num);

			return;
		}
		if (name->content.f.files_num >= 1) {
			if (*(name->data_type) == 'd' && name->content.f.files_num == 1)
			{
				printf("\nFile Name: %s\n", name->file_name);
				printf("Type: %s\n", name->data_type);
				printf("Data: %s\n", name->content.d.text);
				free(name);
				return;
			}
			else if (*(name->data_type) == 'f') {
				if (name->content.f.files_num == 1)
				{
					printf("\nDDFile Name: %s\n", name->file_name);
					printf("Type: %s\n", name->data_type);
					printf("Amount: %u\n", name->content.f.files_num);
					printf_files(name->content.f.file_name[0]);
					free(name);
					return;
				}
				else {
					for (unsigned j = 0; j < name->content.f.files_num ;++j)
					{
						if ((name->content.f.file_name[j]->data_type[0]) == 'd')
						{
							printf("\nFile Name: %s\n", name->content.f.file_name[j]->file_name);
							printf("Type: %s\n", name->content.f.file_name[j]->data_type);
							printf("Data: %s\n", name->content.f.file_name[j]->content.d.text);
							free(name->content.f.file_name[j]);
						}
						else if (*(name->content.f.file_name[j]->data_type) == 'f')
						{
							printf("\nFile Name: %s\n", name->content.f.file_name[j]->file_name);
							printf("Type: %s\n", name->content.f.file_name[j]->data_type);
							printf("Size: %u\n", name->content.f.file_name[j]->content.f.files_num);
							printf_files(name->content.f.file_name[j]->content.f.file_name[0]);

						}
					}

				}
			}
		}
	}
	else
		if (*(name->data_type) == 'd')
		{
			printf("\nFile Name: %s\n", name->file_name);
			printf("Type: %s\n", name->data_type);
			printf("Data: %s\n", name->content.d.text);
			free(name);
			return;
		}
}

	



	//if (*(name->data_type) == 'd') {
	//	for (unsigned int i = 0; i < name->content.f.files_num; ++i) {
	//		if (*(name->data_type) == 'd')
	//		{
	//			printf("\nFile Name: %s\n", name->file_name);
	//			printf("Type: %s\n", name->data_type);
	//			printf("Data: %s\n", name->content.d.text);
	//			free(name);
	//			return;
	//		}
	//	}
	//}
	//else
	//	if (*(name->data_type) == 'f')
	//	{
	//		printf empty folder
	//		if (name->content.f.files_num == 0) {
	//			printf("\nDDFile Name: %s\n", name->file_name);
	//			printf("Type: %s\n", name->data_type);
	//			printf("Amount: %u\n", name->content.f.files_num);
	//			free(name);
	//			return;
	//		}
	//		else {
	//			for (unsigned int i = 0; i < name->content.f.files_num; ++i)
	//			{
	//				if (i == 0) {
	//					printf("\nGGFile Name: %s\n", name->file_name);
	//					printf("Type: %s\n", name->data_type);
	//					printf("Amount: %u\n", name->content.f.files_num);
	//					printf_files(name->content.f.file_name[i]);
	//				}
	//				else
	//				{
	//					if (i != 0)
	//					{
	//						if (name->content.f.file_name[i]->content.f.files_num > 0) {
	//							printf("\nFile Name: %s\n", name->content.f.file_name[i]->file_name);
	//							printf("Type: %s\n", name->content.f.file_name[i]->data_type);
	//							printf("Amount: %u\n", name->content.f.file_name[i]->content.f.files_num);
	//							printf_files(name->content.f.file_name[++i]);
	//						}
	//						else
	//							printf_files(name->content.f.file_name[i]);
	//					}
	//				}
	//				
	//			
	//				
	//				
	//			}
	//			for (unsigned int i = 0; i < name->content.f.files_num; ++i) {
	//					free(name->content.f.file_name[i]->content.f.files_num);
	//			}
	//			free(name);
	//			return;
	//		}
	//	}

File* new_files(char data_type)
{
	File* new_file;
	switch (data_type)
	{
	case 'd':
		new_file = (File*)malloc(sizeof(File));
		if (new_file == NULL){
			printf("MEM ERROR, EXIT\n");
		return NULL;
	}
		memcpy(new_file->data_type, "d", 2);
		printf("Enter File Name: ");
		scanf_s(" %[^\n]s", &(new_file->file_name),DATASIZE);
		printf("Enter File Data[80 char]: ");
		scanf_s(" %[^\n]s", &(new_file->content.d.text),DATASIZE);
		return new_file;

	case 'f':
		new_file = (File*)malloc(sizeof(File));
		printf("Enter File Name: ");
		scanf_s(" %[^\n]s", &(new_file->file_name),DATASIZE);
		printf("Enter How Many Files In Folder: ");
		scanf_s(" %u", &(new_file->content.f.files_num));
		
		if ((new_file->content.f.files_num) == 0)
		{
			memcpy(new_file->data_type, "f", 2);
			return new_file;
		}
		if ((new_file->content.f.files_num) > 0) {
			//int temp_num = (new_file->content.f.files_num);
			memcpy(new_file->data_type, "f", 2);
			new_file->content.f.file_name = (File**)malloc((new_file->content.f.files_num) * sizeof(File*));
			if (new_file->content.f.file_name == NULL) {
				printf("MEM ERROR, EXIT\n");
				return NULL;
			}

			//loop + recursive
			for (unsigned int i = 0; i < new_file->content.f.files_num; ++i) {
				char optchar;
				printf("New file Generator[%d]\nEnter What type you want\n[d] Data\n[f] Folder\nUser Input[d/f]: ",i);
				scanf_s(" %c", &optchar, 2);
				new_file->content.f.file_name[i] = new_files(optchar);
			}

			return new_file;
		}
	default:
		printf("ERROR RETURNING NULL POINTER\n");
		return NULL;
	}
}
