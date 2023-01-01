#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int i,m,n,c,d;
  double a,b,f=0,k=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
  	scanf("%d",&m);
    if(m>=60)
  	    f++;
	  if(m>=85)
	  	k++;
  }
  
  a=(f/n)*100;
  b=(k/n)*100;
 
  c=(int)(a+0.5);
  d=(int)(b+0.5);
  printf("%d%%\n",c);
  printf("%d%%",d); 
  return 0;
}
