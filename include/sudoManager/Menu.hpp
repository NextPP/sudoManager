#ifndef SUDOMANAGER_MENU_HPP
#define SUDOMANAGER_MENU_HPP

#include<iostream>
#include<vector>
#include<stdexcept>
#include "sudoManager/Item.hpp"

class Menu {
private:
  std::vector<Item> menuItems;
  std::vector<Item>::iterator findItem(int);
  std::vector<Item>::iterator findItem(const std::string&);
public:
  Menu();
  Menu(const std::vector<Item>&);
  ~Menu();

  void add_menu_item(const Item&);
  void removeMenuItem(int); // item_ID
  void removeMenuItem(const std::string&);
  const Item getMenuItem(const std::string&);
  float getMenuItemPrice(const std::string&);
  void print_menu();
};

#endif