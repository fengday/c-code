#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char input[20]={0};
	system("shutdown -s -t 60");
again:
	printf("���Խ���һ���Ӻ�ػ�\n���룺123456 ��ȡ���ػ�\n");
	scanf("%s",&input);
	if(strcmp(input,123456)) 
	{
		system("shutdown -a"); 
	}
	else
	{
		printf("�������");
goto again; 
	}
} 
