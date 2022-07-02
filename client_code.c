#include<stdio.h>
#include "file.h"
#include<string.h>
int main()
{
	struct square s1[27]; 
	char key[27];//key should be unique
	char input[100];
	char choice;
	char arr[5][5];
	int enc_dec_num = 0;//choice to encrypt or decrypt. By default is to encrypt
	printf("Enter the key: ");
	scanf("%s",key);
	printf("Type 'y' to print the square, anything else to continue without displaying\n");
	scanf("\n%c",&choice);
	square(s1,key,choice,arr);
	printf("To Encrypt[0] or to Decrypt[1] is the question:");
	scanf("%d",&enc_dec_num);
	printf("Enter text to be encrypted/decrypted: ");
        scanf("%s",input);
	splits(s1,input,arr,enc_dec_num);
	printf("\n");
	return 0;
}
