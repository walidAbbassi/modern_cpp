// chaine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <locale>
#include <codecvt>
#include <string>
using namespace std;

void GetChar()
{

	char c = 'd';
	char *str = "str ==> Hello Everyone!\n ";

	int size = 1024;
	// can allocate size dynamically.
	char* str2 = (char*)malloc(sizeof(char) * size);
	str2 = "str2 ==> Hello Everyone!\n ";
	char str3[] = "str3 ==> Hello Everyone!\n ";

	printf(str);
	printf("\n str strlen = %d , %s", strlen(str), str);
	printf(str2);
	printf("\n str2 strlen = %d , %s", strlen(str2), str2);
	printf(str3);
	printf("\n str2 strlen = %d , %s", strlen(str3), str3);

}

int _tmain(int argc, _TCHAR* argv[])
{
	GetChar();
	system("PAUSE");

	return 0;
}

