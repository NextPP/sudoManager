#ifndef SUDOMANAGER_TABLE_HPP
#define SUDOMANAGER_TABLE_HPP

#include <stdexcept>
#include <vector>

#include "TableSeat.hpp"

class Table {
 public:
  Table();              // default constructor
  Table(int capacity);  // constructor
  ~Table();             // destructor

  bool isOccupied() const;  // check if any seat is occupied
  int getCapacity() const;  // get the number of seats

  int getUnservedSeats();  // get all unserved seats
  void serve();            // serve a meal
  void serve(int number);  // serve a number of meals

  void occupy();            // occupy all seats
  void occupy(int number);  // occupy a number of seats
  void vacate();            // vacate all seats

  TableSeat& getSeat(int number);  // get a seat by number

 private:
  std::vector<TableSeat> seats;  // vector of seats
};
#endif  // SUDOMANAGER_TABLE_HPP