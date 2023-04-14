#include "sudoManager/TableSeat.hpp"

TableSeat::TableSeat() : seatNumber(0), occupied(false), served(false) {}
TableSeat::TableSeat(int theSeatNumber)
    : seatNumber(theSeatNumber), occupied(false), served(false) {}
TableSeat::~TableSeat() = default;

int TableSeat::getSeatId() const { return seatNumber; }
bool TableSeat::isOccupied() const { return occupied; }
bool TableSeat::isServed() const { return served; }

void TableSeat::seatGuest() { occupied = true; }
void TableSeat::removeGuest() { occupied = false; };

void TableSeat::serve() { served = true; }
void TableSeat::clear() { served = false; }