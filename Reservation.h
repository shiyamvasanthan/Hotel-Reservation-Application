#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Date.h"
using namespace std;

class Reservation {	
	public:
		Reservation(string customerName, Date& checkIn, int duration);
		void setDuration(int);
		bool overlaps(Reservation&);
		bool lessThan(Reservation&);
		bool lessThan(Date&);
		void print();
	private:
		string customerName;
		Date checkIn;
		int stay;
};
#endif