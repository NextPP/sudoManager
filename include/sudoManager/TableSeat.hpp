//
// Created by derekjtong on 4/17/2023.
//

#ifndef SUDOMANAGER_TABLESEAT_HPP
#define SUDOMANAGER_TABLESEAT_HPP

class TableSeat{
public:
  TableSeat(int seatNumber);

  // getters
  int getSeatNumber() const;
  bool isServed() const;
  bool isOccupied() const;

  // setters
  void setServed(bool isServed);
  void setOccupied(bool isOccupied);

 private:
  int m_seatNumber;
  bool m_isOccupied;
  bool m_isServed;
};

#endif // SUDOMANAGER_TABLESEAT_HPP