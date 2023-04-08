//
// Created by Jahrr on 4/6/2023.
//
// Last edited by Jahrr on 4/6/2023
//

#include "sudoManager/Item.hpp"

Item::Item() = default;

Item::Item(int item_ID, std::string_view item_name, float item_price, int item_stock)
    : item_ID_{item_ID},
      name_{item_name},
      price_{item_price},
      stock_{item_stock} {}

void Item::appendAdditionalInfo(const std::string& info) {
  if (additional_info_.empty()) {
    additional_info_ = info;
  } else {
    additional_info_ += ", " + info;
  }
}

void Item::printItemInfo() {
  // We have to check if the value has been set or not. Name is the exception
  // because we can set it to "Not Set" by default.

  // We need to remove the zeroes from this because std::to_string doesn't have
  // formatting options

  std::string price_string;
  if (price_) {
    price_string = std::to_string(price_.value());
    price_string.erase(price_string.find('.') + 3, std::string::npos);
  }
  std::cout << ((item_ID_) ? "Item #" + std::to_string(item_ID_.value()) : "Unknown ID") << ": "
            << "Name: " << (!name_.empty() ? name_ : "Not Set") << ", "
            << "Price: " << ((price_) ? price_string : "Not Set") << ", "
            << "Amount in Stock: "
            << ((stock_) ? std::to_string(stock_.value()) : "Not Set") << ", "
            << "Additional Information: "
            << ((!additional_info_.empty()) ? additional_info_ : "None")
            << std::endl;
}

// Getter and setter functions
const std::string& Item::getName() const { return name_; }
void Item::setName(const std::string& name) { name_ = name; }
void Item::setItemID(int item_ID) { item_ID_ = item_ID; }
const std::string& Item::getAdditionalInfo() const { return additional_info_; }
void Item::setPrice(float price) { price_ = price; }

//This seems repetitive, but I want to show the users these messages
//instead of them getting a nasty exception message
float Item::getPrice() const {
  if (price_) {
    return price_.value();
  } else {
    std::cout << "This item does not currently have a price set\n";
    exit(-1);
  }
}

int Item::getStock() const {
  if (stock_) {
    return stock_.value();
  } else {
    std::cout << "This item does not currently have a stock amount set\n";
    exit(-1);
  }
}
void Item::setStock(int stock) { stock_ = stock; }
int Item::getItemID() const {
  if (item_ID_) {
    return item_ID_.value();
  } else {
    std::cout << "This item does not currently have an ID set\n";
    exit(-1);
  }
}