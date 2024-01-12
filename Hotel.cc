#include "Hotel.h"

Hotel::Hotel(){
    numRooms = 0;
}

//Bonus
Hotel::~Hotel(){
    for(int i = 0; i < numRooms; i++){
        delete rooms[i];
    }
}

bool Hotel::addRoom(int roomNumber, string bedType, int capacity, bool fr){
    if(numRooms >= MAX_ROOMS) return false;

    Room* room = new Room(roomNumber, bedType, capacity, fr);
    int index = numRooms;

    //Check the array first for any duplicates before we shift any elements
    for(int i = 0; i < numRooms; i++){
        if(roomNumber == rooms[i]->getRoomNumber()){
            delete room;
            return false;
        }
    }

    while(index > 0){
        if(rooms[index-1]->lessThan(*room)){
            break;
        }

        rooms[index] = rooms[index - 1];
        index--;
    }

    rooms[index] = room;
    numRooms++;
    return true;
}

bool Hotel::deleteRoom(int roomNumber){
    int index = 0;

    while(index < numRooms){
        if(roomNumber == rooms[index]->getRoomNumber()){
            break;
        }

        index++;
    }

    if (index == numRooms) return false;

    delete rooms[index];

    while(index < numRooms - 1){
        rooms[index] = rooms[index+1];
        index++;
    }

    numRooms--;
    return true;
}

bool Hotel::getRoom(int roomNumber, Room** room){
    for(int i = 0; i < numRooms; i++){
        if(roomNumber == rooms[i]->getRoomNumber()){
            *room = rooms[i];
            return true;
        }
    }

    return false;
} 

bool Hotel::addReservation(string customer, string bedType, int capacity, bool fr, Date& date, int duration){
    for(int i = 0; i < numRooms; i++){
        if(rooms[i]->isMatch(bedType, capacity, fr) && rooms[i]->addReservation(customer, date, duration)){
            return true;
        }
    }

    //If we look through all the rooms and none of the criteria matches return false
    return false;
}

void Hotel::print(){
    for(int i = 0; i < numRooms; i++){
        rooms[i]->print();
    }
}

void Hotel::printReservations(){
    for(int i = 0; i < numRooms; i++){
        rooms[i]->printReservations();
    }
}

