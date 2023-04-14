#ifndef SUDOMANAGER_TABLESEAT_HPP
#define SUDOMANAGER_TABLESEAT_HPP

class TableSeat {
 public:
  TableSeat();                // default constructor
  TableSeat(int seatNumber);  // constructor
  ~TableSeat();               // destructor

  int getSeatId() const;    // get seat number
  bool isOccupied() const;  // check if seat is occupied
  bool isServed() const;    // check if seat is served

  void seatGuest();    // seat a guest
  void removeGuest();  // remove a guest

  void serve();  // serve a guest
  void clear();  // clear a seat

 private:
  int seatNumber;
  bool occupied;
  bool served;
};

#endif  // SUDOMANAGER_TABLESEAT_HPP