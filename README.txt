Name: Shiyam Vasanthan

Program Files:
Date.h - Stores the date class function protoypes and data members like day, month, and year
Date.cc - Allows the user to increment dates, compare dates, set dates, and print out the date
Reservation.h - Stores the reservation class function protoypes and data members like customer name, check in, and duration of stay
Reservation.cc - Checks if two reservations overlap, compares reservations, and prints out reservations
Room.h - Stores the room class function protoypes and data members like room number, bed type, list of reservations, etc.
Room.cc - Compares room numbers, can add reservations to the room, can check if two rooms match the criteria, and print room info
Hotel.h - Stores the hotel class function protoypes and data members such as list of rooms, and number of rooms
Hotel.cc - Can add rooms to the hotel, can delete rooms from the hotel, can add reservations to a room that matches the criteria, and print all the hotel info 
main.cc - Used to test all the functions to see if they work correctly. Wrote 4 additional tests in the testResOverlap() function
Makefile - Used to compile all the files into one executable
defs.h - Provides some predefined constant for the max number of rooms and reservations

Compilation Instructions:
1. Type "make" in the terminal
2. Type "./a1" in the terminal to execute the program
3. Type Options from "0" through "10" to test different functions (Except 9 because I didn't create the updateReservations() function)
4. Type "valgrind ./a1" in the terminal to execute program using valgrind. When done check to see there's no memory leaks
5. Type "make clean" in the terminal to clean all the object files and the executable
