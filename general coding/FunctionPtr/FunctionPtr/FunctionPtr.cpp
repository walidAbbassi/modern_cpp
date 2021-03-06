// FunctionPtr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "assert.h"
#include <iostream>

void my_int_func(int x) {
	printf("my_int_func :%d\n", x);
}

void *my_int_func2(int x) {
	printf("*my_int_func2 :%d\n", x);
	return NULL;
}

int _tmain(int argc, _TCHAR* argv[])
{
	void(*foo)(int);
	foo = &my_int_func;

	void* (*foo2)(int);
	foo2 = my_int_func2;

	/* call my_int_func */
	foo(1);	/* or (*foo)(1); */

	/* call my_int_func2 */
	foo2(2); /* or (*foo2)(2); */
	
	system("PAUSE");
	return 0;
}

