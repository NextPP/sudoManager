#include <gtest/gtest.h>

#include "sudoManager/Table.hpp"

// Test the parameterized constructor
TEST(TableTest, ConstructorParameterized) {
  Table table(4);
  EXPECT_EQ(table.getCapacity(), 4);
}

// Test occupying the table with no guests
TEST(TableTest, OccupyEmpty) {
  Table table(4);
  table.occupyAll();
  EXPECT_TRUE(table.isOccupied());
}

// Test occupying the table with some guests
TEST(TableTest, OccupyPartial) {
  Table table(4);
  table.occupy(2);
  EXPECT_TRUE(table.isOccupied());
  EXPECT_EQ(table.getUnservedSeats(), 2);
}

// Test occupying the table with too many guests
TEST(TableTest, OccupyExcess) {
  Table table(4);
  EXPECT_THROW(table.occupy(5), std::invalid_argument);
}

// Test occupying the table with too few guests
TEST(TableTest, OccupyInsufficient) {
  Table table(4);
  EXPECT_THROW(table.occupy(0), std::invalid_argument);
}

// Test occupying the table that already has guests
TEST(TableTest, OccupyAgain) {
  Table table(10);
  table.occupyAll();
  EXPECT_THROW(table.occupy(5), std::logic_error);
}

// Test vacating a fully occupied table
TEST(TableTest, VacateFull) {
  Table table(4);
  table.occupyAll();
  table.vacate();
  EXPECT_FALSE(table.isOccupied());
}

// Test vacating a partially occupied table
TEST(TableTest, VacatePartial) {
  Table table(4);
  table.occupy(2);
  table.vacate();
  EXPECT_FALSE(table.isOccupied());
  EXPECT_EQ(table.getUnservedSeats(), 0);
}

// Test serve
TEST(TableTest, GetUnserved) {
  Table table(4);
  table.occupyAll();
  table.serve(1);
  EXPECT_EQ(table.getUnservedSeats(), 3);
}

// Test serving extra
TEST(TableTest, ServeExtra) {
  Table table(4);
  table.occupyAll();
  EXPECT_THROW(table.serve(5), std::invalid_argument);
}

// Test serving extra one
TEST(TableTest, ServeExtraOne) {
  Table table(4);
  table.occupyAll();
  table.serve(4);
  EXPECT_THROW(table.serve(1), std::logic_error);
}

// Test serving empty table
TEST(TableTest, ServeUnoccupied) {
  Table table(4);
  EXPECT_THROW(table.serve(1), std::logic_error);
}

// Test table is served
TEST(TableTest, IsServedFalse) {
  Table table(4);
  table.occupyAll();
  table.serve(3);
  EXPECT_FALSE(table.isServed());
}

// Test table is served
TEST(TableTest, IsServedTrue) {
  Table table(4);
  table.occupyAll();
  table.serveAll();
  EXPECT_TRUE(table.isServed());
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}