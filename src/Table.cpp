//
// Created by derekjtong on 4/17/2023.
//
#include "sudoManager/Table.hpp"

#include <stdexcept>
Table::Table(int numberOfSeats) {
  for (int i = 0; i < numberOfSeats; i++) {
    m_seats.push_back(TableSeat(i));
  };
}
int Table::getCapacity() const { return m_seats.size(); }

bool Table::isOccupied() const {
  return std::find_if(m_seats.begin(), m_seats.end(), [](const auto& seat) {
           return seat.isOccupied();
         }) != m_seats.end();
}

bool Table::isServed() const {
  auto unserved_seat = std::find_if(
      m_seats.begin(), m_seats.end(),
      [](const auto& seat) { return seat.isOccupied() && !seat.isServed(); });
  return unserved_seat == m_seats.end();
}

int Table::getUnservedSeats() const {
  int unservedSeats = 0;
  for (auto& seat : m_seats) {
    if (seat.isOccupied() && !seat.isServed()) {
      unservedSeats++;
    }
  }
  return unservedSeats;
}

void Table::occupyAll() {
  if (isOccupied()) {
    throw std::logic_error("Error: Table is already occupied");
  }
  for (auto& seat : m_seats) {
    seat.setOccupied(true);
  }
}

void Table::occupy(int number) {
  if (number > m_seats.size()) {
    throw std::invalid_argument("Error: Not enough capacity");
  }
  if (number <= 0) {
    throw std::invalid_argument("Error: Must seat at least one");
  }
  if (isOccupied()) {
    throw std::logic_error("Error: Table is already occupied");
  }
  for (int i = 0; i < number; i++) {
    m_seats[i].setOccupied(true);
  }
}
void Table::serveAll() {
  if (isServed()) {
    throw std::logic_error("Error: Tables are already served");
  }
  for (auto& seat : m_seats) {
    if (seat.isOccupied()) {
      seat.setServed(true);
    }
  }
}
void Table::serve(int number) {
  if (number > m_seats.size()) {
    throw std::invalid_argument("Error: Cannot serve more than table capacity");
  }
  if (number > getUnservedSeats()) {
    throw std::invalid_argument(
        "Error: Cannot serve more than number of unserved seats");
  }
  if (number == 0) {
    throw std::invalid_argument("Error: Cannot serve zero seats");
  }
  if (number <= 0) {
    throw std::invalid_argument("Error: Cannot serve negative seats");
  }
  if (!isOccupied()) {
    throw std::logic_error("Error: Cannot serve meal to unoccupied table");
  }
  int meals = number;
  for (auto& seat : m_seats) {
    if (meals == 0) return;
    if (!seat.isServed()) {
      seat.setServed(true);
      meals--;
    }
  }
}
void Table::vacate() {
  for (auto& seat : m_seats) {
    seat.setOccupied(false);
  }
}