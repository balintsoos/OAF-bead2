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
		struct Node {
  		int value;
  		Node *next;

  		Node(int i = 0, Node *q = 0) : value(i), next(q) {}
		};
		Node *root;
};

#endif