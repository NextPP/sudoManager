//
// Created by derekjtong on 4/17/2023.
//

#include "sudoManager/TableSeat.hpp"

TableSeat::TableSeat(int seatNumber) {
  m_seatNumber = seatNumber;
  m_isServed = false;
  m_isOccupied = false;
}

int TableSeat::getSeatNumber() const { return m_seatNumber; }

bool TableSeat::isServed() const { return m_isServed; }

void TableSeat::setServed(bool isServed) { m_isServed = isServed; }

bool TableSeat::isOccupied() const { return m_isOccupied; }

void TableSeat::setOccupied(bool isOccupied) { m_isOccupied = isOccupied; }