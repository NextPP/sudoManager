#include <iostream>
#include "../src/Item.hpp"
int main() {
  Item spaghetti;
  spaghetti.setName("Spaghetti");
  spaghetti.setPrice(9.98);
  spaghetti.setStock(8);
  spaghetti.appendAdditionalInfo("Some info");

  spaghetti.printItemInfo();
  return 0;
}