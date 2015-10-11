//
// app.h
// OAF - 2. beadando - 7. feladat
//
// Soos Balint
// HDX9MU
//

#ifndef APP_H
#define APP_H
#include "set.h"

class App
{
	public:
		App();
		//~App();

		void run();
	
	private:
		int size;
		Set* sets;
		int currentSet;

		void displayNav();
		void newSet();
		void changeCurrentSet();
		void put();
		void remove();
		void print();
		void isContain();
		void isEmpty();
		void intersection();
		void symDef();
};

#endif