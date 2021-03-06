// decltype.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

struct A {
	double x;
};

void f() {
	enum  Chiffres {
		Zero, Un, Deux, Trois,
		Quatre, Cinq, Six, Sept, Huit, Neuf
	};
	Chiffres chif = Chiffres::Sept;

	auto chiff = 3;
	int nb = Chiffres::Trois;
}
const A* a = new A;

decltype(a->x) x3;						// type of x3 is double (declared type)
decltype((a->x)) x4 = x3;				// type of x4 is const double& (lvalue expression)

template <class T, class U>
auto add(T t, U u) -> decltype(t + u);	//trailing type : return type depends on template parameters


/*decltype (x * y)  multiply(X x, Y y) {
// x & y in decltype are not in the scope yet!
return x*y;
}*/
//TRAILING RETURN TYPE :
//EROOR : we can not deduce the resulting type that has the execution .....

template<typename X, typename Y>
auto  multiply(X x, Y y) -> decltype (x * y) { return x * y; }
auto ff = multiply(25.2, 5);


template <class T, class U>				//return type depends on template parameters
auto add(T t, U u) -> decltype(t + u) { return t + u; };


///////////////////////////////////////////////////
template <typename Builder>
auto
makeAndProcessObject(const Builder& builder) -> decltype(builder.makeObject())
{
	auto val = builder.makeObject();
	// do with val
	return val;
}
///////////////////////////////////////////////////////////
int main()
{
	int i = 33;
	decltype(i) j = i * 2;
	int ii = add(4, 5);

	std::cout << "example 1 ==> i = " << i << ", "
		<< "ii = " << ii << ", "
		<< "j = " << j << '\n';

	auto f = [](int a, int b) -> int {
		return a * b;
	};

	decltype(f) f2 = f;					// the type of a lambda function is unique and unnamed
	i = f(2, 2);
	j = f2(3, 3);

	std::cout << "example 2 ==> i = " << i << ", "
		<< "j = " << j << '\n';
	system("PAUSE");
}