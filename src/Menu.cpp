#include "sudoManager/Menu.hpp"
#include "sudoManager/Item.hpp"

Menu::Menu() = default;

Menu::Menu(const std::vector<Item>& vec)
    : menu_items(vec) {}

Menu::~Menu() = default;

std::vector<Item>::iterator Menu::find_item(int item_ID) {
    std::vector<Item>::iterator it = menu_items.begin();
    while (it != menu_items.end() && (*it).getItemID() != item_ID) {
        it++;
    }
    return it;
}

std::vector<Item>::iterator Menu::find_item(const std::string& item_name) {
    std::vector<Item>::iterator it = menu_items.begin();
    while (it != menu_items.end() && (*it).getName() != item_name) {
        it++;
    }
    return it;
}

void Menu::add_menu_item(const Item& item) {
    // adds item only if item doesn't exist in menu_items
    // assuming item_ID to be a unique attribute
    if (find_item(item.getItemID()) == menu_items.end()) {
        menu_items.push_back(item);
    } else {
        throw std::invalid_argument("Item already exists");
    }
}

void Menu::remove_menu_item(int item_ID) {
    // erases item with ID: item_ID if exists
    std::vector<Item>::iterator it = find_item(item_ID);
    if (it != menu_items.end()) {
        menu_items.erase(it);
    } else {
        throw std::invalid_argument("Item with iD: " + std::to_string(item_ID) + " doesn't exist");
    }
}

void Menu::remove_menu_item(const std::string& item_name) {
    // erases item with name: item_name if exists
    std::vector<Item>::iterator it = find_item(item_name);
    if (it != menu_items.end()) {
        menu_items.erase(it);
    } else {
        throw std::invalid_argument("Item with Name: " + item_name + " doesn't exist");
    }
}

const Item Menu::get_menu_item(const std::string& item_name) {
    std::vector<Item>::iterator it = find_item(item_name);
    if (it == menu_items.end()) {
        throw std::invalid_argument("Item with Name: " + item_name + " doesn't exist");
    } else {
        return *it;
    }
}

float Menu::get_menu_item_price(const std::string& item_name) {
    std::vector<Item>::iterator it = find_item(item_name);
    if (it == menu_items.end()) {
        throw std::invalid_argument("Item with Name: " + item_name + " doesn't exist");
    } else {
        return (*it).getPrice();
    }
}

#ifndef OSTREAM_ITEM_OVERLOADED
std::ostream& operator<<(std::ostream &os, Item& item) {
    item.printItemInfo();
    return os;
}
#endif

void Menu::print_menu() {
    for (Item item: menu_items) {
        std::cout << item << "\n";
    }
}