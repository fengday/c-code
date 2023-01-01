#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int i,n,a,q,w,s;
  scanf("%d",&n);
  int k[n],b[n];
  for(i=0;i<n;i++)
  {
  	scanf("%d%d",&k[i],&b[i]);
  }
  s=n;
  for(q=0;q<n;q++)
  {
  	for(w=q+1;w<n;w++)
  	{
  		if(k[q]!=k[w])
  		{
  			s++;
		  }
		else if(b[q]==b[w])
		{
			s--;
		}
	  }
  }
  printf("%d",s);
  return 0;
}
