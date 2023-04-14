#ifndef SUDOMANAGER_TABLESEAT_HPP
#define SUDOMANAGER_TABLESEAT_HPP

class TableSeat {
 public:
  TableSeat();
  TableSeat(int seatNumber);
  ~TableSeat();

  int getSeatId() const;
  bool isOccupied() const;
  bool isServed() const;

  void seatGuest();
  void removeGuest();

  void serve();
  void clear();

 private:
  int seatNumber;
  bool occupied;
  bool served;
};

#endif  // SUDOMANAGER_TABLESEAT_HPP