//
// set.h
// OAF - 2. beadando - 7. feladat
//
// Soos Balint
// HDX9MU
//

#ifndef SET_H
#define SET_H

class Set 
{
	public:
		enum Exceptions{EMPTY, CONTAIN, INVALID_ITEM};
		Set();
		Set(int n);
		~Set();

		Set(Set& s);
		Set& operator= (Set& s);

		void put(int n);
		void remove(int n);
		void print();
		void intersection(Set& s);
		void symDef(Set& s);
		bool isContain(int n);
		bool isEmpty();
		int getSize();
		int * getItems();
	
	private:
		int * items;
		int size;
};

#endif