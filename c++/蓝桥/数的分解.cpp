#include <stdio.h>
int fun(int i)//�жϸ�������û��2��4 
{
    int flag=0;
    if(i!=2 && i%10!=2 && i/10%10!=2 && i/100%10!=2 && i/1000%10!=2 && i!=4 && i%10!=4 && i/10%10!=4 && i/100%10!=4)
        flag=1;
    return flag;
}

int main()
{    
    int sum=0;
    for(int i=1;i<=2019;i++)//����ȡ��������2000���� 
    {
        for(int j=i+1;j<=2019-i;j++)//��Ϊ2019����ѭ��������ȻС��2019-i��kͬ�������㷨���Ӷ� 
        {
            for(int k=j+1;k<=2019-j;k++)
            {
                if(i+j+k==2019 && fun(i)==1 && fun(j)==1 && fun(k)==1)
                    sum+=1; 
                else
                    continue;
            }
          }
      }
      printf("%d",sum);
    return 0;
}
