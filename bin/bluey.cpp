#include <iostream>

#include "sudoManager/Item.hpp"
int main() {
  Item spaghetti;
  Item lasagna(23, "Lasagna", 13.21, 4);
  spaghetti.setItemID(1);
  spaghetti.setName("Spaghetti");
  spaghetti.setPrice(9.98);
  spaghetti.setStock(8);
  spaghetti.appendAdditionalInfo("Some info");

  std::cout << "Hi, I'm Bluey, I will be your server." << std::endl;
  spaghetti.printItemInfo();
  lasagna.printItemInfo();
  return 0;
}