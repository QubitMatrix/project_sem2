#include <stdio.h>
#include <string.h>
#include "file.h"
int checkalp(int chr,char key[])
{
	for(int k=0;k<strlen(key);k++)
	{
		if(chr==(int)(key[k]))
			return 1;
	}
	return 0;
}
void square(struct square* s,char* key,char choice,char arr[5][5])
{
	int count=0;
	int index =0;
	int chr=96;
	for(int i=0;i<5;i++)
	{
		for (int j=0;j<5;j++)
		{
			if(key[index]!='\0')
			{
				if(key[index]!='j')
				{
				    arr[i][j]=key[index];//store each letter in key into arr
				    s->c=key[index];
				    s->row=i;
				    s->column=j;
				      //printf("%c%d%d\n",s->c,s->row,s->column);
				    s++;
				      
				}    
				else
				{
				    j--;//if j it is ignored
				}
				index++;
				
		        }
			else//when key ends, the elements not present in key are pushed in order into the array
			{
				do
				{
					chr++;
					if((char)chr!='j')
					arr[i][j]=(char)(chr);
					else
					{
					chr++;
					arr[i][j]=(char)(chr);
					}
				      
				}while(checkalp(chr,key));
				    s->c=(char)(chr);
			        s->row=i;
		      	    s->column=j;
			        //printf("%c%d%d\n",s->c,s->row,s->column);
				s++;
             		}
	        }
		
	}
	//print the square in matrix format
	if(choice=='y' || choice=='Y')
	{
	for(int i=0;i<5;i++)
	    {
		for(int j=0;j<5;j++)
		{
			printf("%c ",arr[i][j]);

		}
	     printf("\n");
            }
       }
}
void splits(struct square*s,char input[50],char arr[5][5],int choice_num)
{
        char digraph[3];
        int count=0;
        char temp[3];
	for(int i=0;i<strlen(input);i++)
	{
		
		temp[count]=input[i];
		count++;
		if(count==2)
		{
			count=0;
			if(temp[0]==temp[1])
			{
				temp[1]='x';//bogus x for non unique pairs		
				i--;
			}
			if(choice_num == 0) encrypt(s,temp,arr);
			else decrypt(s,temp,arr);

           	}
		
	}
	if(count==1)
	{//actually we don't need the else condition here as the input will be evenly split
		temp[1]='z';
		if(choice_num == 0) encrypt(s,temp,arr);
		
	}
	
}
void encrypt(struct square* s3, char digraph[2],char arr[][5]){
	int row0 =0,column0 =0,row1=0,column1=0;
	char enc1,enc2;
// the code finds the respective rows and columns of both the digraphs.
	for(int i=0;i<25;i++) 
    {
    	if(s3->c==digraph[0]){
    		row0 = s3->row;
			column0 =s3->column;
		}
		else if(s3->c == digraph[1])
		{
			row1 = s3->row ;
			column1 = s3->column ;
		}
		s3++;
	}
//To find the positon of the encrypted characters
// if Both the characters are in same row find letter on the right
	if(row0 == row1){
		if(column0 !=4 && column1 !=4){
			enc1 = arr[row0][column0+1];
			enc2 = arr[row0][column1+1];
		}
		else if (column0 != 4 && column1 == 4){
			enc1 = arr[row0][column0+1];
			enc2 = arr[row0][0];
		}
		else{
			enc1 = arr[row0][4];
			enc2 = arr[row0][column1+1];
		}
	}
// If Both the characters are in the same column find the letter take the below letter
	else if(column0 == column1){
		if(row0 != 4 && row1 !=4){
			enc1 = arr[row0+1][column0];
			enc2 = arr[row1+1][column0];
		}
		else if(row0 != 4 && row1 == 4){
			enc1 = arr[row0+1][column0];
			enc2 = arr[0][column0];
		}
		else {
			enc1 = arr[0][column0];
			enc2 = arr[row1+1][column0];
		}
	}
// If the characters are arranged as the diagonals of a rectangle, take the corresponding row and column nos
	else{
		enc1 = arr[row0][column1];
		enc2 = arr[row1][column0];
	}
	printf("%c%c",enc1,enc2);
}
void decrypt(struct square* s3, char digraph[2],char arr[][5]){
	int row0 =0,column0 =0,row1=0,column1=0;
	char enc1,enc2;
	char decrypt_t[3];
// the code finds the respective rows and columns of both the digraphs.
	for(int i=0;i<25;i++) 
    {
    	if(s3->c==digraph[0]){
    		row0 = s3->row;
			column0 =s3->column;
		}
		else if(s3->c == digraph[1]){
			row1 = s3->row ;
			column1 = s3->column ;
		}
		s3++;
	}
//To find the positon of the decrypted characters
// if Both the characters are in same row find letter on the left
	if(row0 == row1){
		if(column0 !=0 && column1 !=0){
			enc1 = arr[row0][column0-1];
			enc2 = arr[row0][column1-1];
		}
		else if (column0 != 0 && column1 == 0){
			enc1 = arr[row0][column0-1];
			enc2 = arr[row0][4];
		}
		else{
			enc1 = arr[row0][0];
			enc2 = arr[row0][column1-1];
		}
	}
// If Both the characters are in the same column find the letter take the letter above
	else if(column0 == column1){
		if(row0 != 0 && row1 !=0){
			enc1 = arr[row0-1][column0];
			enc2 = arr[row1-1][column0];
		}
		else if(row0 != 0 && row1 == 0){
			enc1 = arr[row0-1][column0];
			enc2 = arr[4][column0];
		}
		else {
			enc1 = arr[4][column0];
			enc2 = arr[row1-1][column0];
		}
	}
// If the characters are arranged as the diagonals of a rectangle, take the corresponding row and column nos
	else{
		enc1 = arr[row0][column1];
		enc2 = arr[row1][column0];
	}
	printf("%c%c",enc1,enc2);

}

