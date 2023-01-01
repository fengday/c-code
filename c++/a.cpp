#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define M 80
char fun(char *ss)
{
	int a,i,j=0,k;
	char *p=ss;
	char b[M];
	a=strlen(ss);
	for(i=0;i<a;i++)
	{
		b[i]=ss[a-i-1];
		
	}
/*	printf("%s\n",b);
	while(*p++!='\0')
	{
		j++;
	}
	printf("%d\n",j);*/
	if(strcmp(ss,b)==0)
	return 1;
	else return 0;
}
main()
{
	char s[M];
	scanf("%s",&s);
	if(fun(s)) printf("yes");
	else printf("no");
}


