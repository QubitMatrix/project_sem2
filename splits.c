#include<stdio.h>
#include<string.h>
int main()
{
	char input[100];
	char digraph[3];
        int count=0;
        char temp[3];
	scanf("%[^\n]s",input);
	printf("%d",strlen(input));
	//char (*p)[2]=input;
	printf("%s",temp);
	for(int i=0;i<strlen(input);i++)
	{
		
		temp[count]=input[i];
		count++;
		//printf("*%c ",temp[count-1]);
		if(count==2)
		{
			count=0;
			if(temp[0]==temp[1])
			{
				temp[1]='x';//bogus x for non unique pairs
				
				
				i--;
			}
printf("%s ",temp);
           	//encrypt_pair(temp);
           	}
		
	}
	if(count==1)
	{
		printf("%c%c ",temp[0],'z');
	}
	
	return 0;
}

