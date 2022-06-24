#include <stdio.h>
#include <string.h>
struct square
{
char c;
int row;
int column;
};
int checkalp(int,char []);//check if letter already printed from key
void square(struct square* ,char* ,char);//create the square
void splits(struct square*,char*);//create digraphs
void pos(struct square*, char [2]);//gets the position of each letter in each digraph

int main()
{
	struct square s1[27];
	char key[27];//key should be unique
	char input[100];
	char choice;
	printf("Enter the key");
	scanf("%s",key);
	printf("Type 'y' to print the square, anything else to continue without displaying\n");
	scanf("\n%c",&choice);
	square(s1,key,choice);
	printf("Enter text to be encrypted");
        scanf("%s",input);
	splits(s1,input);
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
void square(struct square* s,char* key,char choice)
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
void splits(struct square*s,char input[5])
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
                
              	pos(s,temp);
           	}
		
	}
	if(count==1)
	{
		temp[1]='z';
		pos(s,temp);
	}
	
	
}
void pos(struct square* s2 , char digraphs[2])
{
      printf("%c %c\n",digraphs[0],digraphs[1]);
      for(int i=0;i<25;i++) 
      {
           if(s2->c==digraphs[0] ||s2->c==digraphs[1])
                printf("%c%d%d\n",s2->c,s2->row,s2->column);
      s2++;
      }
}

