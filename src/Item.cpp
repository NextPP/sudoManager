//
// Created by Jahrr on 4/6/2023.
//
// Last edited by Jahrr on 4/6/2023
//
#include "sudoManager/Item.hpp"

// Number values that are not set are set to -1 by default
Item::Item() : item_ID_{-1}, name_{"Not Set"}, price_{-1}, stock_{-1} {}

Item::Item(
    int item_ID, std::string_view item_name, float item_price, int item_stock)
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

  price_string = std::to_string(price_);
  price_string.erase(price_string.find('.') + 3, std::string::npos);

  std::cout << "Item #" << item_ID_ << ": "
            << "Name: " << name_ << ", "
            << "Price: " << ((price_ >= 0.f) ? price_string : "Not Set") << ", "
            << "Amount in Stock: "
            << ((stock_ >= 0) ? std::to_string(stock_) : "Not Set") << ", "
            << "Additional Information: "
            << ((!additional_info_.empty()) ? additional_info_ : "None\n")
            << std::endl;
}

// Getter and setter functions
const std::string& Item::getName() const { return name_; }
void Item::setName(const std::string& name) { name_ = name; }
float Item::getPrice() const { return price_; }
void Item::setPrice(float price) { price_ = price; }
int Item::getStock() const { return stock_; }
void Item::setStock(int stock) { stock_ = stock; }
int Item::getItemID() const { return item_ID_; }
void Item::setItemID(int item_ID) { item_ID_ = item_ID; }
const std::string& Item::getAdditionalInfo() const { return additional_info_; }
