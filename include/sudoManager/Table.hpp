//
// Created by derekjtong on 4/17/2023.
//

#ifndef SUDOMANAGER_TABLE_HPP
#define SUDOMANAGER_TABLE_HPP

#include <vector>

#include "TableSeat.hpp"

class Table {
 public:
  Table(int numberOfSeats);

  // getters
  int getCapacity() const;
  bool isOccupied() const;
  bool isServed() const;
  int getUnservedSeats() const;

  // setters

  // methods
  void occupyAll();
  void occupy(int number);
  void serveAll();
  void serve(int number);
  void vacate();

 private:
  std::vector<TableSeat> m_seats;  // 0-indexed
};

#endif  // SUDOMANAGER_TABLE_HPP