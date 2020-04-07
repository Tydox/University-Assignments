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
	
}File; // total size is 164 with data


int printf_files(File* name);
File* new_files(char data_type);


main() {
	File* f1;
	char optchar;
	
	printf("New file Generator\nEnter What type you want\n[d] Data\n[f] Folder\nUser Input[d/f]: ");
	scanf_s(" %c", &optchar,2);
	f1 = new_files(optchar);

	printf("\nFolder Size: %d", printf_files(f1));
};


int printf_files(File* name)
{
	int size = 0;
	//stop 1
	if (*(name->data_type) == 'f' && name->content.f.files_num == 0)
	{
		return 0;
	}
	//stop 2
	if (*(name->data_type) == 'd')
	{
		size = strlen(name->content.d.text)+1;
		return size;
	}
	
	if (*(name->data_type) == 'f') {

		for (unsigned j = 0; j < name->content.f.files_num; ++j)
		{
			if (*(name->content.f.file_name[j]->data_type) == 'f')
			{
				return size += printf_files(name->content.f.file_name[j]);
			}
			if ((name->content.f.file_name[j]->data_type[0]) == 'd')
			{
				size += strlen(&(name->content.f.file_name[j]->content.d))+1;
				free(name->content.f.file_name[j]);
			}
		}

	}
}

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
