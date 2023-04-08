#include <iostream>
#include "sudoManager/Item.hpp"
int main() {
  Item spaghetti;
  Item pasta(7, "Pasta", 158.49, 1);
  spaghetti.setItemID(1);
  spaghetti.setName("Spaghetti");
  spaghetti.setPrice(9);
  spaghetti.setStock(8);
  spaghetti.getPrice();
  spaghetti.appendAdditionalInfo("Some info");
  pasta.appendAdditionalInfo("The rarest and most expensive pasta there is");

  std::cout<<"Hi, I'm Bluey, I will be your server."<<std::endl;
  spaghetti.printItemInfo();
  pasta.printItemInfo();
  return 0;
}