#include "sudoManager/Table.hpp"

Table::Table(){};  // default constructor
Table::Table(int capacity) {
  for (int i = 0; i < capacity; i++) {
    seats.push_back(TableSeat(i));
  }
}  // constructor
Table::~Table() = default;  // destructor

bool Table::isOccupied() const {
  for (auto& seat : seats) {
    if (seat.isOccupied()) {
      return true;
    }
  }
  return false;
}  // check if any seat is occupied
int Table::getCapacity() const { return seats.size(); }

std::vector<const TableSeat*> Table::getUnservedSeats() {
  std::vector<const TableSeat*> unservedSeats;
  for (auto& seat : seats) {
    if (seat.isOccupied() && !seat.isServed()) {
      unservedSeats.push_back(&seat);
    }
  }
  return unservedSeats;
}  // get the number of seats

void Table::occupy() {
  if (isOccupied()) {
    throw std::invalid_argument("Error: Table is already occupied.");
  }
  for (auto& seat : seats) {
    seat.seatGuest();
  }
}  // occupy all seats

void Table::occupy(int number) {
  if (isOccupied()) {
    throw std::invalid_argument("Error: Table is already occupied.");
  }
  if (number <= 0) {
    throw std::invalid_argument("Error: Cannot seat less than 1 guest.");
  }
  if (number > seats.size()) {
    throw std::invalid_argument(
        "Error: Cannot seat more guests than the table can hold.");
  }
  for (int i = 0; i < number; i++) {
    seats[i].seatGuest();
  }
}  // occupy a number of seats
void Table::vacate() {
  for (auto& seat : seats) {
    seat.removeGuest();
  }
}  // vacate all seats

TableSeat& Table::getSeat(int number) {
  if (number < 0 || number >= seats.size()) {
    throw std::out_of_range("Seat number is out of range");
  }
  return seats[number];
}  // get a seat by number