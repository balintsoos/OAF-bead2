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
// inicializalasnal a halmaz elemeit tartalmazo lancolt lista egy nullpointer
Set::Set()
{
	root = new Node();
}

// constructor w/ argumentum
// inicializal, majd az argumentumkent atadott erteket berakja a lancolt listaba
Set::Set(int n)
{
	Set();
	put(n);
}

// destructor
// torli a halmaz elemeit reprezentalo lancolt listat
Set::~Set()
{
	Node *p = root;
	while (p != 0)
	{
		Node *q = p->next;
		delete p;
		p = q;
	}
}

// sajat masolo konstructor
Set::Set(Set& s)
{
	// lista lebontasa
	while(root != 0)
	{
		Node *p = root;
		root = p->next;
		delete p;
	}
	
	// lista felepitese
	root = new Node();
	Node *thisCurrent = root->next;
	Node *sCurrent = s.root->next;
	while(sCurrent != 0)
	{
		thisCurrent = new Node(sCurrent->value);
		thisCurrent->next = new Node(sCurrent->next->value);
		thisCurrent = thisCurrent->next;
		sCurrent = sCurrent->next;
	}
}

// sajat ertekadas operator
Set& Set::operator= (Set& s)
{
	if (this == &s) return *this;
	
	// lista lebontasa
	while(root != 0)
	{
		Node *p = root;
		root = p->next;
		delete p;
	}
	
	// lista felepitese
	root = new Node();
	Node *thisCurrent = root->next;
	Node *sCurrent = s.root->next;
	while(sCurrent != 0)
	{
		thisCurrent = new Node(sCurrent->value);
		thisCurrent->next = new Node(sCurrent->next->value);
		thisCurrent = thisCurrent->next;
		sCurrent = sCurrent->next;
	}
	return *this;
}

// elem berakasa a halmazba
// 
// bemeneti adat: egesz szam, berakni kivant ertek
// kimeneti adat: nincs (void)
void Set::put(int n)
{
	if(isEmpty())
	{
		root->next = new Node(n);
	}
	else
	{
		if (!isContain(n))
		{
			Node *u = root;
			Node *p = root->next;

			while(p != 0 && (p->value < n))
			{
				u = p;
				p = p->next;
			}
			
			u->next = new Node(n, u->next);
		}
		else
		{
			throw CONTAIN;
		}
	}
}

// elem kivetele a halmazbol
// 
// bemeneti adat: egesz szam, amit ki szeretnenk venni a halmazbol
// kimeneti adat: nincs (void)
void Set::remove(int n)
{
	if (isContain(n))
	{
		Node *u = root;
		Node *p = root->next;

		while(p != 0 && (p->value < n))
		{
			u = p;
			p = p->next;
		}

		u->next = p->next;
		delete p;
	}
	else
	{
		throw INVALID_ITEM;
	}
}

// halmaz megjelenitese
// listan vegighaladva kiirjuk a konzolra az elemeket
// bemeneti ertek: nincs, kimeneti ertek: nincs
void Set::print()
{
	cout << endl << "Items: ";
	Node *p = root->next;

	while(p != 0)
	{
		cout << p->value << " ";
		p = p->next;
	}
	cout << endl;
}

// ket halmaz metszete
// ha egyik halmaz sem ures,
// a halmazokon vegigiteralva a mindkettoben 
// elofordulo elemeket kiirjuk
// kihasznaljuk hogy a lista rendezett:
// haladva parhuzamosan a lista elemein, ha
// a ket ertek megegyezik akkor metszetelemet talatunk
// ha az ertek kulonbozik, akkor a relacio alapjan
// az egyik listan tovabbiteralunk
// a folyamat addig folytatodik amig el nem erjuk 
// valamelyik lista veget
// bemeneti adat: egy halmaz
// kimeneti adat: nincs (void)
void Set::intersection(Set& s)
{
	if (!isEmpty() && !s.isEmpty())
	{
		// int iOfThis = size-1;
		// int iOfArg = s.getSize()-1;
		// int * itemsOfArg = s.getItems();

		// while (iOfThis >= 0 && iOfArg >= 0)
		// {
		// 	if (items[iOfThis] > itemsOfArg[iOfArg])
		// 	{
		// 		iOfThis--;
		// 	}
		// 	else if (items[iOfThis] < itemsOfArg[iOfArg])
		// 	{
		// 		iOfArg--;
		// 	}
		// 	else if (items[iOfThis] == itemsOfArg[iOfArg])
		// 	{
		// 		cout << items[iOfThis] << " ";
		// 		iOfThis--;
		// 		iOfArg--;
		// 	}
		// }
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

// tartalmaz-e a halmaz egy adott elemet
// lineraris keresest alkalmazva keressuk az elemet a listaban
// bemeneti adat: egesz szam
// kimeneti adat: logikai (bool)
bool Set::isContain(int n)
{
	bool found = false;
	Node *p = root->next;
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
	return root->next == 0;
}
