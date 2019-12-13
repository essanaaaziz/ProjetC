#include <stdio.h>
#include <stdlib.h>
FILE * f;
int verifier (char login[],char password[])
{char lo[20],pwd[20];
int y,r1;
int r;
y=0;
f=fopen("users.txt","r+");
if(f!=NULL)
{while((fscanf(f,"%s %s %d \n" ,lo,pwd,&r)!=EOF)&&(y==0))
 {
  if(strcmp(login,lo)==0)
			{
				if(strcmp(password,pwd)==0)
					{
						
						return(r);
					}}
}
}
if (y==0)
    r1=-1;
fclose(f);
return r1;
}
