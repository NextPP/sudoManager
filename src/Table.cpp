#include "../include/sudoManager/Table.hpp"

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

int Table::getUnservedSeats() {
  int unservedSeats = 0;
  for (auto& seat : seats) {
    if (seat.isOccupied() && !seat.isServed()) {
      unservedSeats++;
    }
  }
  return unservedSeats;
}  // get the number of seats

void Table::serve() {
  if (!isOccupied()) {
    throw std::logic_error("Error: Table is not occupied.");
  }
  if (getUnservedSeats() == 0) {
    throw std::logic_error("Error: All seats are already served.");
  }
  for (auto& seat : seats) {
    if (seat.isOccupied() && !seat.isServed()) {
      seat.serve();
      return;
    }
  }
}  // serve a meal
void Table::serve(int number) {
  if (number <= 0) {
    throw std::invalid_argument("Error: Cannot serve less than 1 meal.");
  }
  if (!isOccupied()) {
    throw std::logic_error("Error: Table is not occupied.");
  }
  if (number > getUnservedSeats()) {
    throw std::logic_error(
        "Error: Cannot serve more meals than there are unserved seats.");
  }
  int meals = number;
  for (auto& seat : seats) {
    if (meals == 0) return;
    if (seat.isServed() == false) {
      seat.serve();
      meals--;
    }
  }
}  // serve a number of meals

void Table::occupy() {
  if (isOccupied()) {
    throw std::invalid_argument("Error: Table is already occupied.");
  }
  for (auto& seat : seats) {
    seat.seatGuest();
  }
}  // occupy all seats

void Table::occupy(int number) {
  if (number <= 0) {
    throw std::invalid_argument("Error: Cannot seat less than 1 guest.");
  }
  if (isOccupied()) {
    throw std::logic_error("Error: Table is already occupied.");
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