// const.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;



///////////////////////CONST//////////////////////////////////////////////////////////////////
char p;
void verifyConst(char *pCharParam)
{
	const char *line[] =
	{
		"the boy stood on the burning deck",
		"his hearts was all a quiver",
		"he gave a cough, his leg fell off",
		"and floated down the river"
	};

	cout << "num of lines :" << (sizeof(line) / sizeof(line[0])) << endl;
	cout << "value of char:" << line[0][0] << endl;
	cout << "value of char:" << **line << endl;

	//1..........
	cout << "==> 1.........." << endl;
	char  str[] = "qwerty";
	const char *pc = str;			//initialization OK 
	cout << "pc 1 : " << pc << endl;
	//pc[3] = 'g';					//compilation error: pc points to a constant
	pc = pCharParam;				//ok
	cout << "pc 2 : " << pc << endl;

	//2............
	cout << "==> 2.........." << endl;
	char *const cp = str;			//pointer constant
	cp[3] = 'a';					//ok
	//cp = p;						//compilation error : cp is a constant
	cout << "cp : " << cp << endl;

	//3............	 
	cout << "==> 3.........." << endl;
	const char*const cpc = str;		//pointer const of const
	//cpc[3]='a';					//compilation error : cpc point to a constant
	//cpc = p;						//compilation error : cpc is a constant
	cout << "cpc : " << cpc << endl;

	//4............ LIKE 1.....		char const <=> const char
	cout << "==> 4....LIKE 1......" << endl;
	char const* pg = "azerty";
	cout << "pg : " << pg << endl;
	//pg[0] = 'b';					//erreur 
	pg = str;						//ok
	cout << "pg : " << pg << endl;

	//5............ LIKE 1....
	cout << "==> 5....LIKE 1......" << endl;
	int v = 5, v2 = 9;
	const int* p1 = &v;				//p1 point to a constant integer, we can not initialize
	//*p1 = 7;						//error
	p1 = &v;
	cout << "p1 : " << *p1 << endl;
	p1 = &v2;
	cout << "p1 : " << *p1 << endl;
	v2 = 11;
	cout << "p1 : " << *p1 << endl;

	//6.......... LIKE 2.....
	cout << "==> 6.....LIKE 2....." << endl;
	int *const p2 = &v;				// the pointer p2 is constant & must be initialized
	const int* const p3 = &v;
	cout << "p3 : " << *p3 << endl;
	v = 6;
	//*p3 = 6;						//error
	cout << "p3 : " << *p3 << endl;

	//7....... LIKE 1.......
	cout << "==> 7.....LIKE 1....." << endl;
	const char *X = "X";
	char *Y;
	// Y = (char*)X;
	// strcpy(Y,"Y");
	cout << "X : " << X[0] << endl;

}
/////////ATTENTION TO typedef/////////////
typedef char *ASTRING;

void verifyConstAvecTypeDef()
{
	char  s[] = "qwerty";
	const ASTRING astring = s;
	//is it 'const char*' or 'char* const' ????

	astring[3] = 'g';				//no compilation error => astring is a pointer constant and does not point to a constant
									//On the other hand 
	//astring = s+1;				//compilation error => so astring is a char* const (LIKE 2......)
}
//////////////////////////////////////////


int _tmain(int argc, _TCHAR* argv[])
{
	char varChar = 0;
	verifyConst(&varChar);
	system("PAUSE");
	return 0;
}

