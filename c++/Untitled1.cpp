#include<stdio.h>//�����ж��������� 
int main(){
    int months[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int year,month,day;
    int ans=6;//һ��һ�������� 
    int cnt=0;//������ 
    for(year=2000;year<=2020;year++){
        if(year%4==0&&year%100!=0||year%400==0){
            months[2]=29;
        }else{
            months[2]=28;
        }
    for(month=1;month<=12;month++){//���� 
        for(day=1;day<=months[month];day++){//���� 
            cnt++;//ÿ��һǧ�� 
            if(ans==8){
                ans=1;//ans������ 8 ʱ��� 1 
            } 
            if(ans==1||day==1){//����ζ��A�ԣ�B�ԣ�ABͬʱ��������� 
                cnt++;//��һ���³�����һ���³�����һǧ�� 
            }
            ans++;//����ڶ��� 
            if(year==2020&&month==10&&day==1){//��2020.10.1����ѭ�� 
                printf("%d",cnt);
            } 
        }
    }
}
    return 0;//һ��һ������Ҫ�´� 
}
