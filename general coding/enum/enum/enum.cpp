// enum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "suit.h"
#include "season.h"
using namespace std;

const season spring = { 0 },
summer = { 1 },
autumn = { 2 },
winter = { 3 };

const suit clubs = { 0 },
diamonds = { 1 },
hearts = { 2 },
spades = { 3 };

/************************************************* ENUM *************************************************/
//the client has to query the "type" of each object, and manually invoke the desired method.
class Sirene {
public:
	static enum Etat { ALLUMEE, ETEINTE, CLIGNOTANT };
	Sirene() {
		m_id = s_next++;
		m_etat = (Etat)(m_id % 3);
	}
	Etat get_etat() { return m_etat; }
	void allumer() { cout << m_id << "-allumer \n"; }
	void eteindre() { cout << m_id << "-eteindre \n"; }
	void clignoter() { cout << m_id << "-clignoter \n"; }
private:
	Etat m_etat;  int  m_id;
	static int s_next;
};
int Sirene::s_next = 0;
void VerifyEnum()
{
	cout << "\nVerifyEnum " << endl;
	Sirene *equipement = new Sirene();
	if (equipement->get_etat() == Sirene::ALLUMEE)
		cout << "Sirene enum ALLUMEE: " << Sirene::ALLUMEE << endl;
	Sirene *equipement2 = new Sirene();
	cout << "equipement Sirene get_etat: : " << equipement->get_etat() << endl;
	cout << "equipement2 Sirene get_etat: : " << equipement2->get_etat() << endl;

}

void VerifyEnum2()
{
	cout << "\nVerifyEnum2 " << endl;
	enum months { JAN = 1, FEB, MAR = 2, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC } m;
	enum days { LUN = 1, MARDI, MER, JEU, VEN, SAM, DIM } d;
	// m = 5;			// compilation error
	// m = d;			// compilation error
	int i = MAR;		// ok
	m = (months)i;		// ok; casting needed

	cout << "sizeof(months) : " << sizeof(months) << endl;
	cout << "Jan : " << JAN << " ; Feb : " << FEB << " ; Mar : " << MAR << " ; Apr : " << APR << endl;

	//not possible !
	/*
	int k= winter;
	suit trumps = winter;
	spring = winter;
	*/
	cout << "sizeof(suit) : " << sizeof(suit) << endl;
	cout << "sizeof(season) : " << sizeof(season) << endl;
	cout << "const enum strong values (seasons) : " << spring.value << winter.value << summer.value << endl;
}

void VerifyEnumFortementType()
{
	cout << "\nVerifyEnumFortementType " << endl;
	enum class Chiffres { Zero, Un, Deux, Trois, Quatre, Cinq, Six, Sept, Huit, Neuf };
	Chiffres chif;
	chif = Chiffres::Sept;
	int nb;
	nb = (int)Chiffres::Trois;
	cout << "sizeof(Chiffres) : " << sizeof(Chiffres) << endl;
	cout << "chif : " << static_cast<int>(chif) << endl;
	cout << "nb : " << nb << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	VerifyEnum();
	VerifyEnum2();
	VerifyEnumFortementType();
	system("Pause");
	return 0;
}

