#include<stdio.h>
main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a+b>c&&b+c>a&&a+c>b&&a>0&&b>0&&c>0)
	{
		if((a*a+b*b==c*c)||(a*a+c*c==b*b )||(b*b+c*c==a*a))
		   printf("��������Ϊֱ��������");
		else if(a==b&&b==c) 
		printf("��������Ϊ�ȱ�������");
	       else if(a==b||b==c||a==c)
	       printf("��������Ϊ����������");
	       else printf("��������Ϊ��ͨ������");
	}
	else printf("���ܹ���������"); 
}
