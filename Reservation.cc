#include "Reservation.h"

Reservation::Reservation(string customerName, Date& checkIn, int duration){
    this->customerName = customerName;
    this->checkIn = checkIn;
    this->stay = duration;
}

void Reservation::setDuration(int duration){
    if(duration < 1){
        duration = 1;
    }

    stay = duration;
}

bool Reservation::overlaps(Reservation& r){
    Date d1(checkIn);
    Date d2(r.checkIn);

    //If the start dates of the reservations are the same, we know they overlap
    if(d1.equals(d2)){
        return true;
    }

    if(d1.lessThan(d2)){
        d1.addDays(stay - 1);
        return !d1.lessThan(d2);
    } else {
        d2.addDays(r.stay - 1);
        return !d2.lessThan(d1);
    }
}

bool Reservation::lessThan(Reservation& res){
    if(overlaps(res)){
        return false;
    }

    return checkIn.lessThan(res.checkIn);
}

bool Reservation::lessThan(Date& d){
    Date d1(checkIn);

    d1.addDays(stay - 1);

    return d1.lessThan(d);
}

void Reservation::print(){
    cout << "Reservation for " << customerName << " on ";
    checkIn.print();
    cout << " for " << stay << " days." << endl;
}