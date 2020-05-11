#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void addRow(char* fileName,int width);


void main()
{
	//open file pointer
	FILE* wfile1 = fopen("./files/matrix.txt","w");
	//check if open was successful 
	if(!wfile1)
		exit(-69);
	//write to file a string of numbers
	fprintf(wfile1,"%s","010203010203010203");
	//allow me to view changes to verify (open the file again)
	fflush(wfile1);
	//close the file pointer
	fclose(wfile1);

	//pointer to file name
	char* cfile1="./files/matrix.txt";
	addRow(cfile1,5);

	
	
}

void addRow(char* fileName, int width)
{
	//open a file with appendix to add to the end
	FILE* afile = fopen("./files/matrix.txt","a");
	if(!afile)
{		printf("Unable to open file");
		exit(-69);
}

	for(int i =1;i<=width;++i)
	{
		fprintf(afile,"%.2d",i);
		fflush(afile);
	}
	fclose(afile);

}
