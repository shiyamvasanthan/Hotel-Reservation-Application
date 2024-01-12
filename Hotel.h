#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Room.h"
#include "defs.h"

class Hotel{
    public:
        Hotel();
        ~Hotel();
        bool addRoom(int, string, int, bool);
        bool deleteRoom(int);
        bool getRoom(int, Room**);
        bool addReservation(string, string, int, bool, Date&, int);
        void print();
        void printReservations();
    private:
        Room* rooms[MAX_ROOMS];
        int numRooms;
};

#endif