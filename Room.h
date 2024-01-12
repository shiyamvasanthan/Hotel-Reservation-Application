#ifndef ROOM_H
#define ROOM_H
#include "Reservation.h"

#include "defs.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Room{
    public:
        Room(int, string, int, bool);
        ~Room();
        int getRoomNumber();
        bool isMatch(string, int, bool);
        bool lessThan(Room&);
        bool addReservation(string, Date&, int);
        void print();
        void printReservations();
    private:
        int roomNumber;
        string bedType;
        int capacity;
        bool hasFridge;
        Reservation* reservations[MAX_RES];
        int numReservations;
};

#endif