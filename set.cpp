//
// set.cpp
// OAF - 2. beadando - 7. feladat
//
// Soos Balint
// HDX9MU
//

#include <iostream>
#include "set.h"

using namespace std;

// constructor
// inicializalasnal a halmaz elemeit tartalmazo lancolt lista egy nullpointer, merete 0
Set::Set()
{
	head = 0;
}

// constructor w/ argumentum
// az argumentumkent atadott erteket berakja a halmazba
Set::Set(int n)
{
	Set();
	put(n);
}

// destructor
// torli a halmaz elemeit reprezentalo lancolt listat
Set::~Set()
{
	item *p = head;
	while (p != 0)
	{
		item *q = p->next;
		delete p;
		p = q;
	}
}

// sajat masolo konstructor
Set::Set(Set& s)
{
	//
}

// sajat ertekadas operator
Set& Set::operator= (Set& s)
{
	if (this == &s) return *this;
	delete[] items;
	size = s.size;
	items = new int[size];
	for (int i = 0; i < size; ++i)
	{
		items[i] = s.items[i];
	}
	return *this;
}

// elem berakasa a halmazba
// ha a dinamikus tombunk ures, 0. indexre berakjuk ay elemet
// ha merete nagyobb mint 0 es az adott elem nincs benne a halmazba
// akkor letrehozunk egy eggyel hosszabb ideiglenes tombot, majd
// a beszurasos rendezes algoritmusat alkalmazva atmasoljuk az elemeket
// majd az ideiglenesbol atmasoljuk az eredeti tombbe
// bemeneti adat: egesz szam, berakni kivant ertek
// kimeneti adat: nincs (void)
void Set::put(int n)
{
	if(isEmpty())
	{
		//
	}
	else
	{
		if (!isContain(n))
		{
			item *u, *p;
			for (u = head, p = head->next;
				p != 0 && (p->value < n);
				u = p, p = p->next);
			
			size++;
			Node *i = u;
			i->next = new item(n, i->next);
		}
		else
		{
			throw CONTAIN;
		}
	}
}

// elem kivetele a halmazbol
// ha az adott elem benne van a tombben, akkor letrehozunk
// egy eggyel rovidebb ideiglenes tombot es az adott elem
// kivetelevel minden elemet atmasolunk, majd az ideiglenes
// tombot atmasoljuk az eredetibe
// bemeneti adat: egesz szam, amit ki szeretnenk venni a halmazbol
// kimeneti adat: nincs (void)
void Set::remove(int n)
{
	if (isContain(n))
	{
		int * temp = new int[size-1];
		int tempI = 0;
		for (int i = 0; i < size; ++i)
		{
			if(items[i] != n)
			{
				temp[tempI++] = items[i];
			}
		}
		delete[] items;
		items = temp;
		size--;
	}
	else
	{
		throw INVALID_ITEM;
	}
}

// halmaz megjelenitese
// tombon vegighaladva kiirjuk a konzolra az elemeket
// es a tomb meretet
// bemeneti ertek: nincs, kimeneti ertek: nincs
void Set::print()
{
	cout << "\nSize: " << size << endl;
	cout << "Items: ";
	for (int i = 0; i < size; ++i)
	{
		cout << items[i] << " ";
	}
	cout << endl;
}

// ket halmaz metszete
// ha egyik halmaz sem ures,
// a halmazokon vegigiteralva a mindkettoben 
// elofordulo elemeket kiirjuk
// kihasznaljuk hogy a tomb rendezett:
// hatulrol haladva parhuzamosan a tomb elemein, ha
// a ket ertek megegyezik akkor metszetelemet talatunk
// ha az ertek kulonbozik, akkor a relacio alapjan
// az egyik tombon tovabbiteralunk
// a folyamat addig folytatodik amig el nem erjuk 
// valamelyik tomb veget
// bemeneti adat: egy halmaz
// kimeneti adat: nincs (void)
void Set::intersection(Set& s)
{
	if (!isEmpty() && !s.isEmpty())
	{
		int iOfThis = size-1;
		int iOfArg = s.getSize()-1;
		int * itemsOfArg = s.getItems();

		while (iOfThis >= 0 && iOfArg >= 0)
		{
			if (items[iOfThis] > itemsOfArg[iOfArg])
			{
				iOfThis--;
			}
			else if (items[iOfThis] < itemsOfArg[iOfArg])
			{
				iOfArg--;
			}
			else if (items[iOfThis] == itemsOfArg[iOfArg])
			{
				cout << items[iOfThis] << " ";
				iOfThis--;
				iOfArg--;
			}
		}
		cout << endl;
	}
	else
	{
		throw EMPTY;
	}
}

void Set::symDef(Set& s)
{
	//
}

// tartalmaz-e a halmaz egz adott elemet
// lineraris keresest alkalmazva keressuk az elemet a tombben
// bemeneti adat: egesz szam
// kimeneti adat: logikai (bool)
bool Set::isContain(int n)
{
	bool found = false;
	item *p = head;
	while ((p != 0) && !found)
	{
		if(p->value == n)
		{
			found = true;
		}
		p = p->next;
	}
	return found;
}

// ures-e a halmaz
// bemeneti adat: nincs
// kimeneti adat: logikai (bool)
bool Set::isEmpty()
{
	return head == 0;
}
