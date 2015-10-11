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
	
	private:
		struct item {
  		int value;
  		item *next;

  		item(int i = 0, item *q = 0) : value(i), next(q) {}
		};
		item *head;
};

#endif