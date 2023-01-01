#include <stdio.h>

main()
{
	int a;
	scanf("%d",&a);
	a=a/10;
	switch(a){
		case 10:printf("pre"); 
		case 9:printf("jige");
		case 5:printf("bujige");
		default :printf("df");
	} 
}

