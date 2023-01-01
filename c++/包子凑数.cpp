#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int i,j,k,s,a,b,c;
  int count=0;
  	scanf("%d",&a);
  	scanf("%d",&b);
  	scanf("%d",&c);
	for(s=1;s<10000;s++)
	{

  	  for(i=0;i<=s;i++)
  	    for(j=0;j<=s;j++)
          for(k=0;k<=s;k++)         
		    {
		 	    if(a*i+b*j+c*k==s) break;
				
			}	 
			if(i<s||j<s||k<s)
			 {continue;}
			 else 
			 {
			 	printf("%d,",s);
		     	count++;
			 }
   }
			/*  if(count>100)
			  {
			  	printf("INF\n");
				  }	
			   else
			   printf("%d\n",count);*/
  return 0;
}
