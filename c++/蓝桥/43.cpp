#include<stdio.h>
int main()
{
   int m,n,k,i,j,f=0,count=0;
   scanf("%d%d%d",&m,&n,&k);
   int a[m][n];
   	for(i=0;i<m;i++){
	for(j=0;j<n;n++){
	   	scanf("%d",a[i][j]);
		 } 
		}
	int x,y,p,q,b,c;
	for(x=m;x<m;x++){
	for(y=n;y<n;y++){
		for(p=0;p<m-x;p++){
		for(q=0;q<n-y;q++){
			for(b=0;b<m;b++){
			for(c=0;c<n;c++){
				f=f+a[b][c];
				if(f>k)
				count++;
				f=0;
			}
			}
		}
		}
	}
	} 
	printf("%d",count);
	return 0;
}
