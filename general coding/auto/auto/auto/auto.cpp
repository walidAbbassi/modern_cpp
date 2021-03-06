// auto.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
using namespace std;

int &fooRef(void)
{
	int x = 17;
	return x;
}
int *fooPtr(void)
{
	int x = 15;
	return &x;
}

void refAuto()
{
	int& fooRef();
	auto bar = fooRef();  // int
	auto& baz = fooRef(); // int&
	cout << "refAuto: \n   ==>(int) auto bar = " << bar << " \n   ==>(&int) auto& baz = " << baz << endl;;
}

void pointerAuto()
{
	int* fooPtr();
	auto p_bar = fooPtr();  // int*
	auto *p_baz = fooPtr();  // int*
	cout << "pointerAuto: \n   ==>(*int) auto p_bar = " << *p_bar << " \n   ==>(*int) auto *p_baz = " << *p_baz << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	auto j = 10;
	auto str = "error";

	//error C3538: in a declarator-list 'auto' must always deduce to the same type
	//auto j=10 ,str="error";
	int *k = new int;
	*k = 10;

	printf(" *k = %d\n", *k);
	delete k;

	int v = 6;
	printf("  v = %d\n", v);

	int *w = &v;
	printf(" *w = %d\n", *w);

	*w = 5;
	auto t = *w;
	printf("  2nd - v = %d\n", v);

	printf("  t = %d\n", t);

	auto a = 5.0, b = 10.0;
	auto i = 1.0, *ptr = &a, &ref = b;
	char s[15];

	map<string, string> address_book;
	//address_book["Alex"] = "";
	map<string, string>::iterator itr = address_book.begin();
	auto itr2 = address_book.begin();

	refAuto();
	pointerAuto();
	system("PAUSE");
	return 0;
}
