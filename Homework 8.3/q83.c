#include <stdio.h>

#define SIZE 501

int text_Encryptor(char tstr1[], char estr1[]);

void main()
{
	char str[SIZE] = { '\0' };
	char encrypt_str[SIZE] = { '\0' };
	printf("Enter your text [%d]: \n", SIZE-1);
	scanf_s(" %[^\n]s", str, SIZE - 1);
	printf("Enter your word to encrypt [%d]: \n", SIZE - 1);
	scanf_s(" %[^\n]s", encrypt_str, SIZE - 1);
	
	printf("%s\nEncryped: %d", str, text_Encryptor(str, encrypt_str));
	
	
}

int text_Encryptor(char tstr1[], char estr1[])
{
	int count=0;
	int verifier = 0;
	int encryped = 0;// count size of encrypted word
	while (estr1[count]!='\0')
	{
		++count;		
	}
	int i = 0;
	while( tstr1[i] != '\0') 
	{
		if (tstr1[i] == estr1[0]) // search for first letter on the string for matching char
		{
			
			for (int j = i, w=0, temp=count; temp>0; ++j,++w,--temp) // check that all letters are matching in order
			{
				if (tstr1[j] == estr1[w])
				{
					verifier = 0;
				}
				else verifier = -1;
				
			}
			if (verifier==0)
			{
				
				for (int j = i ,temp=count; temp>0 ; ++j, --temp)
				{
					tstr1[j] = '*';
				}
				++encryped;
			}
		}
		
		++i;
	}
	
	return encryped;
}
