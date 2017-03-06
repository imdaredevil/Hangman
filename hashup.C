#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *a,q[100],*ptr;
int i=0,tr=5;
void getquestion()
{
printf("enter the question.\n");
scanf("%[^\n]s",q);
}
void replacement()
{
	do
	{
	if(q[i]!=' ')
	a[i]='_';
	else
	a[i]=' ';
	i++;
	}while(q[i]!='\0');
}
void guess()
{
int j=0,k=1,hash[26];
i=0;

	while(1)
	{
	printf("\n%s\n",a);
	printf("\nmake your guess by typing the letter\n");
	fflush(stdin);
	scanf("%c",ptr);
	if(hash[*ptr-97]==1)
	printf("u have already made the same guess");	
		else
		{
			for(j=0;a[j]!='\0';j++)
			{
				if(*ptr==q[j])
				{
				a[j]=q[j];
				k=2;
				}
			}
			if(k==1)
			{
			if(tr>1)
			printf("wrong guess. you can make only %d more wrong guesses. Beware! ur man at stake",--tr);
			else
			tr--;
			}
		k=1;j=0;
			for(j=0;a[j]!='\0'&&a[j]!='_';j++);
			if(a[j]=='\0')
			{
			printf("\n%s",a);
			printf("U have saved ur man ");
			
			break;
			}
			if(tr==0)
			{
			printf("u lost");
			break;
			}
		hash[*ptr-97]=1;
		}
	i++;
	}
}				
int main()
{
ptr=(char*)malloc(sizeof(char));
ptr=(char*)malloc((strlen(q)+1)sizeof(char))
getquestion();
replacement();
guess();
return 0;
}