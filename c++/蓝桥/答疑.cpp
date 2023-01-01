#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int n;
  scanf("%d",&n);
  int a[n],b[n],c[n],d[n],s,e[n];
  for(int i=0;i<n;i++)
  {
    scanf("%d%d%d",&a[i],&b[i],&c[i]);
    d[i]=a[i]+b[i]+c[i];
   } 
  printf("%d,%d,%d\n",d[0],d[1],d[2]);
   for(int j=0;j<n;j++)
   {
   	for(int k=j+1;k<n;k++)
   	{
   		if(d[j]>d[k])
   		s=d[j];
   		d[j]=d[k];
   		d[k]=s;
   		printf("%d,%d,%d\n",d[0],d[1],d[2]);
	   }
	  
   }
   printf("%d,%d,%d\n",d[0],d[1],d[2]);
   for(int h=1;h<n;h++)
   {
   	e[0]=d[0];
   	e[h]=e[h-1]+d[h];
   }
   for(int h=0;h<n;h++)
   {
   printf("%d,",e[h]);
   }
   int g=0;
   for(int t=0;t<n;t++)
   {
   	
   	g=g+(e[t]-c[t]);printf("%d,",g);
   }
  
  return 0;
}
