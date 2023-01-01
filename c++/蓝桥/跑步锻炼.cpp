#include <stdio.h>
#include <stdlib.h>
int mo[13]={0,31,29,31,30,31,30,31,31,30,31,30};
int mon(int year,int month,int day)
{
	if((year%4==0&&year%100!=0)||(year%400==0))
	mo[2]=29;
	else mo[2]=28;
	if(day==0)
	return 0;
	if(month<0||month>12)
	return 0;
	else {
		if(mo[month]<day)
		return 0;
	}
	return 1;
}

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int year,month,day,xq=6,i,s=0; 
  for(i=20000101;i<=20201001;i++)
  {
  	year=i/10000;
  	month=i/100%100;
  	day=i%100;
  	
  	if(mon(year,month,day))
  	{
  		if(xq==1||day==1)
  		{
  			s++;
		  }
		  s++;printf("%d,",xq);
		xq++; 
		if(xq==8)
    	xq=1;
	  }
	 
  } 
  return 0;
}
