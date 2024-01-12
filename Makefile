all: a1

a1: Room.o Date.o Reservation.o Hotel.o main.o
	g++ -o a1 Room.o Date.o Reservation.o Hotel.o main.o

main.o:
	g++ -c main.cc

Date.o: defs.h Date.h Date.cc
	g++ -c Date.cc

Room.o: defs.h Room.h Room.cc
	g++ -c Room.cc

Reservation.o: defs.h Reservation.h Reservation.cc
	g++ -c Reservation.cc

Hotel.o: defs.h Hotel.h Hotel.cc
	g++ -c Hotel.cc

clean:
	rm -f a1 *.o