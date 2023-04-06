#include <iostream>
#include "../src/Item.hpp"
int main() {
  Item spaghetti;
  spaghetti.setName("Spaghetti");
  spaghetti.setPrice(9.98);
  spaghetti.setStock(8);
  spaghetti.appendAdditionalInfo("Some info");

  std::cout<<"Hi, I'm Bluey, I will be your server."<<std::endl;
  spaghetti.printItemInfo();
  return 0;
}