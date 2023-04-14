#include "../include/sudoManager/TableSeat.hpp"

// defaut constructor
TableSeat::TableSeat() : seatNumber(0), occupied(false), served(false) {}

// constructor
TableSeat::TableSeat(int theSeatNumber)
    : seatNumber(theSeatNumber), occupied(false), served(false) {}

// destructor
TableSeat::~TableSeat() = default;

// get seat number
int TableSeat::getSeatNumber() const { return seatNumber; }

// check if seat is occupied
bool TableSeat::isOccupied() const { return occupied; }

// check if seat is served
bool TableSeat::isServed() const { return served; }

// seat guest
void TableSeat::seatGuest() { occupied = true; }

// remove guest
void TableSeat::removeGuest() { occupied = false; }

// serve guest
void TableSeat::serve() {
  if (served == true)
    throw std::logic_error("Error: Seat is already served.");
  else
    served = true;
}

// clear seat
void TableSeat::clear() { served = false; }