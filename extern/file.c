#include<stdio.h>

/*
 * if you want your variable and function scope to be restricted to a particular file
 * then you have to declare them as global static
 */

static int b = 197;

int a = 202;

int fun(){
	printf("static int b = %d present in file.c\r\n",b);
	printf("fun is called which is present in file.c\r\n");
	return 115;
}
