#include "sudoManager/Menu.hpp"

#include "sudoManager/Item.hpp"

Menu::Menu() = default;

Menu::Menu(const std::vector<Item>& vec) : menuItems(vec) {}

Menu::~Menu() = default;

std::vector<Item>::iterator Menu::findItem(int item_ID) {
  std::vector<Item>::iterator it = menuItems.begin();
  while (it != menuItems.end() && (*it).getItemID() != item_ID) {
    it++;
  }
  return it;
}

std::vector<Item>::iterator Menu::findItem(const std::string& item_name) {
  std::vector<Item>::iterator it = menuItems.begin();
  while (it != menuItems.end() && (*it).getName() != item_name) {
    it++;
  }
  return it;
}

void Menu::add_menu_item(const Item& item) {
  // adds item only if item doesn't exist in menuItems
  // assuming item_ID to be a unique attribute
  if (findItem(item.getItemID()) == menuItems.end()) {
    menuItems.push_back(item);
  } else {
    throw std::invalid_argument("Item already exists");
  }
}

void Menu::removeMenuItem(int item_ID) {
  // erases item with ID: item_ID if exists
  std::vector<Item>::iterator it = findItem(item_ID);
  if (it != menuItems.end()) {
    menuItems.erase(it);
  } else {
    throw std::invalid_argument("Item with iD: " + std::to_string(item_ID) +
                                " doesn't exist");
  }
}

void Menu::removeMenuItem(const std::string& item_name) {
  // erases item with name: item_name if exists
  std::vector<Item>::iterator it = findItem(item_name);
  if (it != menuItems.end()) {
    menuItems.erase(it);
  } else {
    throw std::invalid_argument("Item with Name: " + item_name +
                                " doesn't exist");
  }
}

const Item Menu::getMenuItem(const std::string& item_name) {
  std::vector<Item>::iterator it = findItem(item_name);
  if (it == menuItems.end()) {
    throw std::invalid_argument("Item with Name: " + item_name +
                                " doesn't exist");
  } else {
    return *it;
  }
}

float Menu::getMenuItemPrice(const std::string& item_name) {
  std::vector<Item>::iterator it = findItem(item_name);
  if (it == menuItems.end()) {
    throw std::invalid_argument("Item with Name: " + item_name +
                                " doesn't exist");
  } else {
    return (*it).getPrice();
  }
}

#ifndef OSTREAM_ITEM_OVERLOADED
std::ostream& operator<<(std::ostream& os, Item& item) {
  item.printItemInfo();
  return os;
}
#endif

void Menu::print_menu() {
  for (Item item : menuItems) {
    std::cout << item << "\n";
  }
}