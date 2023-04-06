//
// Created by Jahrr on 4/6/2023.
//
// Last edited by Jahrr on 4/6/2023
//
#include "Item.hpp"

// Number values that are not set are set to -1 by default
Item::Item() : name_{"Not Set"}, price_{-1}, stock_{-1} {}

Item::Item(std::string item_name, float item_price, int item_stock)
    : name_{std::move(item_name)}, price_{item_price}, stock_{item_stock} {}

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
  price_string.erase(price_string.find_last_not_of('0') + 1, std::string::npos);
  price_string.erase(price_string.find_last_not_of('.') + 1, std::string::npos);

  std::cout << "Item Name: " << name_ << ", "
            << "Price: " << ((price_ >= 0.f) ? price_string : "Not Set") << ", "
            << "Amount in Stock: "
            << ((stock_ >= 0) ? std::to_string(stock_) : "Not Set") << ", "
            << "Additional Information: "
            << ((!additional_info_.empty()) ? additional_info_ : "None\n");
}

// Getter and setter functions
const std::string& Item::getName() const { return name_; }
void Item::setName(const std::string& name) { name_ = name; }
float Item::getPrice() const { return price_; }
void Item::setPrice(float price) { price_ = price; }
int Item::getStock() const { return stock_; }
void Item::setStock(int stock) { stock_ = stock; }
const std::string& Item::getAdditionalInfo() const { return additional_info_; }
