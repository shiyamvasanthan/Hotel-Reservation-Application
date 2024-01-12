#include "Room.h"

Room::Room(int roomNumber, string bedType, int capacity, bool hasFridge){
    this->roomNumber = roomNumber;
    this->bedType = bedType;
    this->capacity = capacity;
    this->hasFridge = hasFridge;
    numReservations = 0;
}

//Bonus
Room::~Room(){
    for(int i = 0; i < numReservations; i++){
        delete reservations[i];
    }
}
int Room::getRoomNumber(){
    return roomNumber;
}

bool Room::isMatch(string bt, int cap, bool f){
    return bedType == bt && capacity >= cap && (!f || hasFridge);
}

bool Room::lessThan(Room& r){
    return roomNumber < r.roomNumber;
}

bool Room::addReservation(string customerName, Date& d, int duration){
    if (numReservations >= MAX_RES) return false;

    Reservation* reservation = new Reservation(customerName, d, duration);

    int index = numReservations;

    //Iterate through the array and check for reservation overlaps before we shift any elements
    for(int i = 0; i < numReservations; i++){
        if(reservations[i]->overlaps(*reservation)){
            delete reservation;
            return false;
        }
    }

    while(index > 0){
        if(reservations[index - 1]->lessThan(*reservation)){
            break;
        }

        reservations[index] = reservations[index - 1];
        index--;
    }

    reservations[index] = reservation;
    numReservations++;
    return true;
}

void Room::print(){
    cout << "Room " << roomNumber << " " << bedType << " sized bed" << " capacity " << capacity << endl;

    if(hasFridge){
        cout << "This room has a fridge" << endl;
    } else {
        cout << "This room doesn't have a fridge" << endl;
    }
}

void Room::printReservations(){
    print();
    for(int i = 0; i < numReservations; i++){
        reservations[i]->print();
    }
}