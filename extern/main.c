#include<stdio.h>

/*
 *  command to use gcc -o ext main.c file.c --> to produce an executable
 * */

extern void change();

int main(){
	extern int a;
	extern int fun();
	/*extern int b;
	printf("accessing variable b of file.c , whose value is %d\r\n",b);*/
	/*
	 * if we try to access b present in the file.c we get undefined reference to b error
	 * */
	printf("the value of a is %d\r\n",a);
	change();
	printf("the value of a is %d\r\n",a);
	printf("%d\r\n",fun());
	return 0;
}
