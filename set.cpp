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

Set& Set::operator+ (Set& s)
{
	intersection(s);
	return *this;
}

Set& Set::operator- (Set& s)
{
	symDef(s);
	return *this;
}

std::ostream& operator<<(std::ostream& o, Set& s){
	if(!s.isEmpty())
	{
		Set::Node *p = s.root->next;
		while(p != 0)
		{
			o << p->value << " ";
			p = p->next;
		}
	}
	else
	{
		o << "empty set";
	}
	o << endl;
	return o;
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
	if(!isEmpty())
	{
		Node *p = root->next;
		while(p != 0)
		{
			cout << p->value << " ";
			p = p->next;
		}
	}
	else
	{
		cout << "empty set";
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
		Node *itemOfThis = root->next;
		Node *itemOfArg = s.root->next;

		while (itemOfThis != 0 && itemOfArg != 0)
		{
			if (itemOfThis->value > itemOfArg->value)
			{
				itemOfArg = itemOfArg->next;
			}
			else if (itemOfThis->value < itemOfArg->value)
			{
				itemOfThis = itemOfThis->next;
			}
			else if (itemOfThis->value == itemOfArg->value)
			{
				cout << itemOfThis->value << " ";
				itemOfThis = itemOfThis->next;
				itemOfArg = itemOfArg->next;
			}
		}
		cout << endl;
	}
	else
	{
		throw EMPTY;
	}
}

// ket halmaz syimmetrikus differenciaja
// bemeneti adat: egy halmaz
// kimeneti adat: nincs (void)
void Set::symDef(Set& s)
{
	if(isEmpty())
	{
		s.print();
	}
	else if(s.isEmpty())
	{
		print();
	}
	else
	{
		Node *This = root->next;
		Node *Arg = s.root->next;

		while (This != 0 && Arg != 0)
		{
			if (This->value > Arg->value)
			{
				cout << Arg->value << " ";
				Arg = Arg->next;
			}
			else if (This->value < Arg->value)
			{
				cout << This->value << " ";
				This = This->next;
			}
			else if (This->value == Arg->value)
			{
				This = This->next;
				Arg = Arg->next;
			}
		}
		if (This == 0)
		{
			while (Arg != 0)
			{
				cout << Arg->value << " ";
				Arg = Arg->next;
			}
		}
		else if (Arg == 0)
		{
			while (This != 0)
			{
				cout << This->value << " ";
				This = This->next;
			}
		}
		cout << endl;
	}
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
