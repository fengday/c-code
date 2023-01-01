#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int mo[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int pin(int year,int month,int day)
{
	if((year%4==0&&year%100!=0)||(year%400==0))
	mo[2]=29;
	else
	mo[2]=28;
	if(day==0)
	return 0;
	if(month<=0||month>12)
	return 0;
	else 
	{
		if(mo[month]<day)
		return 0;
	}
	return 1;
}
int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int year,month,day,i,j,a,b,c;
  scanf("%d/%d/%d",&a,&b,&c);
  for(i=19600101;i<20591231;i++)
  {
  	year=i/10000;
  	month=i/100%100;
  	day=i%100;
  	if(pin(year,month,day))
  	{
  		if((year%100==a&&month==b&&day==c)||(year%100==c&&month==b&&day==a)||(year%100==c&&month==a&&day==b))
	     {
	     	printf("%02d-%02d-%02d\n",year,month,day);
		 }
	  }
  }

  return 0;
}
