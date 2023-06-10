#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "hospitalheader.h"
int g;
main()
{
	system("COLOR B0");
	printf("\t\t\t\tWELCOME ");
    sleep(1);
    printf("TO  ");
    sleep(1);
    printf("HOSPITAL  ");
    sleep(1);
    printf("MANAGEMENT  ");
    sleep(1);
    printf("SYSTEM ");  
	printf("\n\n\t 1.LOGIN\n\t 2.EXIT OR QUIT:");
	scanf("%d",&g);
	switch(g)
	{
		case 1:login();
		break;
		case 2: return(0);
		break;
		default:printf("\n option not found...........please enter the valid option........");
	}
return(0);	
}
