#include "sudoManager/Table.hpp"

Table::Table(){};
Table::Table(int capacity) {
  for (int i = 0; i < capacity; i++) {
    seats.push_back(TableSeat(i));
  }
}
Table::~Table() = default;

bool Table::isOccupied() const {
  for (auto& seat : seats) {
    if (seat.isOccupied()) {
      return true;
    }
  }
  return false;
}
int Table::getCapacity() const { return seats.size(); }

std::vector<const TableSeat*> Table::getUnservedSeats() {
  std::vector<const TableSeat*> unservedSeats;
  for (auto &seat : seats) {
    if (seat.isOccupied() && !seat.isServed()) {
      unservedSeats.push_back(&seat);
    }
  }
  return unservedSeats;
}

void Table::occupy() {
  if (isOccupied()) {
    throw std::invalid_argument("Error: Table is already occupied.");
  }
  for (auto& seat : seats) {
    seat.seatGuest();
  }
}

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
}
void Table::vacate() {
  for (auto& seat : seats) {
    seat.removeGuest();
  }
}

TableSeat& Table::getSeat(int number) {
  if (number < 0 || number >= seats.size()) {
    throw std::out_of_range("Seat number is out of range");
  }
  return seats[number];
}