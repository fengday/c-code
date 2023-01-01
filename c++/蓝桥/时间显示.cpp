#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  // 请在此输入您的代码


  int long long hh,mm,ss,hm,i;
  scanf("%lld",&hm);
   ss=hm/1000%60;
   mm=hm/1000/60%60;
   hh=hm/1000/60/60%24;
   printf("%02lld:%02lld:%02lld",hh,mm,ss);
  return 0;
}
