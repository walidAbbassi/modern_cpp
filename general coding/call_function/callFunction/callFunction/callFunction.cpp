// callFunction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void function(int x, int y) {
	std::cout << "example function 1 value : " << x << " , " << y << std::endl;
	int i = 0;
}

void function(int x, char a) {
	std::cout << "example function 2 value : " << x << " , " << a << std::endl;
	int i = 0;

}
void function(int x, int y, int z) {
	std::cout << "example function 3 value : " << x << " , " << y << " , " << z << std::endl;
	int i = 0;
}


void function_fct(int i, int j = 10, int k = 20) {
	// instructions
	std::cout << "example function_fct value : " << i << " , " << j << " , " << k << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{

	function(1, 2);
	function(1, 'b');
	char c = 'a';
	function(1, c);

	function(1, 2, 3);

	//call Function
	function_fct(1, 2, 3);// i = 1 j = 2 k = 3
	function_fct(1, 2);// i = 1 j = 2 k = 20
	function_fct(1);// i = 1 j = 10 k = 20
					//fct();//ERREUR Function invalide
	system("PAUSE");
	return 0;
}

