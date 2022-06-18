#include <stdio.h>
#include <string.h>
struct square
{
char c;
int row;
int column;
};
int checkalp(int,char[]);//check if letter already printed from key
void pos(struct square* s, char digraphs[2]);//gets the position of each letter in each digraph

int main()
{
	struct square s1[27];
	//struct square *s=s1;
	char key[27];//key should be unique
	char input[100];
	scanf("%s",key);
	square(&s1,key);
	printf("enter");
	scanf("%s",input);
	splits(&s1,input);
	pos(&s1,"ab");
	return 0;
}
int checkalp(int chr,char key[])
{
	for(int k=0;k<strlen(key);k++)
	{
		if(chr==(int)(key[k]))
			return 1;
	}
	return 0;
}
void square(struct square* s,char* key)
{
        
	int count=0;
	int index =0;
	int chr=96;
	char arr[5][5];
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
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			printf("%c ",arr[i][j]);

		}
		printf("\n");
	}

}
void splits(struct square*s,char input[5])
{
        char digraph[3];
        //char input[100];
        //scanf("%s",input);
        int count=0;
        char temp[3];
	printf("%d",strlen(input));
	for(int i=0;i<strlen(input);i++)
	{
		
		temp[count]=input[i];
		count++;
		printf("*%c ",temp[count-1]);
		if(count==2)
		{
			count=0;
			if(temp[0]==temp[1])
			{
				printf("a");
				temp[1]='x';//bogus x for non unique pairs		
				i--;
			}
                printf("%s",temp);
//           	pos(&s,temp);//encrypt_pair(temp);
           	}
		
	}
	if(count==1)
	{
		printf("%c%c ",temp[0],'z');
	}
	
	
}
void pos(struct square* s2 , char digraphs[2])
{
      for(int i=0;i<25;i++) 
      {
           if(s2->c==digraphs[0] ||s2->c==digraphs[1])
                printf("%c%d%d\n",s2->c,s2->row,s2->column);
      s2++;
      }
}

