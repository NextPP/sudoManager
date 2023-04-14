#include "../include/sudoManager/Table.hpp"

// default constructor
Table::Table(){};

// constructor, zero indexed
Table::Table(int capacity) {
  for (int i = 0; i < capacity; i++) {
    seats.push_back(TableSeat(i));
  }
}

// destructor
Table::~Table() = default;

// check if any seat is occupied
bool Table::isOccupied() const {
  for (auto& seat : seats) {
    if (seat.isOccupied()) {
      return true;
    }
  }
  return false;
}

// get the total number of seats
int Table::getCapacity() const { return seats.size(); }

// get number of occupied seats
int Table::getOccupiedSeats() {
  int occupiedSeats = 0;
  for (auto& seat : seats) {
    if (seat.isOccupied()) {
      occupiedSeats++;
    }
  }
  return occupiedSeats;
}

// get the number of unserved seats
int Table::getUnservedSeats() {
  int unservedSeats = 0;
  for (auto& seat : seats) {
    if (seat.isOccupied() && !seat.isServed()) {
      unservedSeats++;
    }
  }
  return unservedSeats;
}

// serve a meal
void Table::serveOne() {
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
}

// serve a number of meals
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
}

// occupy all seats
void Table::occupy() {
  if (isOccupied()) {
    throw std::invalid_argument("Error: Table is already occupied.");
  }
  for (auto& seat : seats) {
    seat.seatGuest();
  }
}

// occupy a number of seats
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
}

// vacate all seats
void Table::vacate() {
  for (auto& seat : seats) {
    seat.removeGuest();
  }
}

// get a seat by number
TableSeat& Table::getSeat(int number) {
  if (number < 0 || number >= seats.size()) {
    throw std::out_of_range("Seat number is out of range");
  }
  return seats[number];
}