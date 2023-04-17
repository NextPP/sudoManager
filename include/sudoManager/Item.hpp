//
// Created by Jahrr on 4/6/2023.
//
// Last edited by Jahrr on 4/6/2023
//

#ifndef SUDOMANAGER_ITEM_HPP
#define SUDOMANAGER_ITEM_HPP

#include <iostream>

#include <string_view>

class Item {
 private:
  std::string name_;
  int item_ID_;
  float price_;
  int stock_;
  std::string additional_info_;

 public:
  Item();
  Item(
      int item_ID, std::string_view item_name, float item_price,
      int item_stock);
  ~Item() = default;

  void printItemInfo();
  void appendAdditionalInfo(const std::string& info);

  // Getters and setters
  const std::string& getName() const;
  void setName(const std::string& name);
  float getPrice() const;
  void setPrice(float price);
  int getStock() const;
  void setStock(int stock);
  const std::string& getAdditionalInfo() const;
  int getItemID() const;
  void setItemID(int item_ID);
};

#endif  // SUDOMANAGER_ITEM_HPP
