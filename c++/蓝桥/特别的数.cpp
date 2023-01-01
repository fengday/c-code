#include <stdio.h>
#include <stdlib.h>
int fun(int a)
{
	int m=0;
	while(a!=0)
	{
		if(a%10==2||a%10==0||a%10==1||a%10==9)
		{
			m=1;
			break;
		}
		a=a/10;
	}
	return m;
}
int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int n,i,j=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
  	if(fun(i))
  	j+=i;
  }
  printf("%d",j);
  return 0;
}
