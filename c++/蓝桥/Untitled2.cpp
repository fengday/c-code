#include<stdio.h>
main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a+b>c&&b+c>a&&a+c>b&&a>0&&b>0&&c>0)
	{
		if((a*a+b*b==c*c)||(a*a+c*c==b*b )||(b*b+c*c==a*a))
		   printf("该三角形为直角三角形");
		else if(a==b&&b==c) 
		printf("该三角形为等边三角形");
	       else if(a==b||b==c||a==c)
	       printf("该三角形为等腰三角形");
	       else printf("该三角形为普通三角形");
	}
	else printf("不能构成三角形"); 
}
