#ifndef SUDOMANAGER_MENU_HPP
#define SUDOMANAGER_MENU_HPP

#include<iostream>
#include<vector>
#include<stdexcept>
#include "sudoManager/Item.hpp"

class Menu {
    private:
        std::vector<Item> menu_items;
        std::vector<Item>::iterator find_item(int);
        std::vector<Item>::iterator find_item(const std::string&);
    public:
        Menu();
        Menu(const std::vector<Item>&);
        ~Menu();

        void add_menu_item(const Item&);
        void remove_menu_item(int); // item_ID
        void remove_menu_item(const std::string&);
        const Item get_menu_item(const std::string&);
        float get_menu_item_price(const std::string&);
        void print_menu();
};

#endif