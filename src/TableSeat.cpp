#include "../include/sudoManager/TableSeat.hpp"

TableSeat::TableSeat()
    : seatNumber(0), occupied(false), served(false) {}  // defaut constructor
TableSeat::TableSeat(int theSeatNumber)
    : seatNumber(theSeatNumber),
      occupied(false),
      served(false) {}              // constructor
TableSeat::~TableSeat() = default;  // destructor

int TableSeat::getSeatNumber() const { return seatNumber; }  // get seat number
bool TableSeat::isOccupied() const {
  return occupied;
}  // check if seat is occupied
bool TableSeat::isServed() const { return served; }  // check if seat is served

void TableSeat::seatGuest() { occupied = true; }      // seat guest
void TableSeat::removeGuest() { occupied = false; };  // remove guest

void TableSeat::serve() {
  if (served == true)
    throw std::logic_error("Error: Seat is already served.");
  else
    served = true;
}  // serve guest
void TableSeat::clear() { served = false; }  // clear seat