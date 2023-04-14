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

  void seatGuest();    // seat guest
  void removeGuest();  // remove guest

  void serve();  // serve guest
  void clear();  // clear seat

 private:
  int seatNumber;
  bool occupied;
  bool served;
};

#endif  // SUDOMANAGER_TABLESEAT_HPP