#include<stdio.h>
enum Color
{
	red,
	yellow,
	blue
};
int add(int a,int b)
{
	int c=a+b;
	return c;
}
int main()
{
	int num1,num2;
	enum Color color=blue;
	printf("%d",color);
	scanf("%d%d",&num1,&num2);
	printf("%d",add(num1,num2));
	return 0;
}
