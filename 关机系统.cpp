#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char input[20]={0};
	system("shutdown -s -t 60");
again:
	printf("电脑将于一分钟后关机\n输入：123456 将取消关机\n");
	scanf("%s",&input);
	if(strcmp(input,123456)) 
	{
		system("shutdown -a"); 
	}
	else
	{
		printf("输入错误");
goto again; 
	}
} 
