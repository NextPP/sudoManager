//
// Created by Jahrr on 4/6/2023.
//
// Last edited by Jahrr on 4/6/2023
//

#ifndef SUDOMANAGER_ITEM_HPP
#define SUDOMANAGER_ITEM_HPP

#include <iostream>
#include <sstream>
#include <vector>
class Item {
 private:
  std::string name_;
  float price_;
  int stock_;
  std::string additional_info_;

 public:
  Item();
  Item(std::string item_name, float item_price, int item_stock);
  ~Item() = default;

  void printItemInfo();
  void appendAdditionalInfo(const std::string& info);


  //Getters and setters
  const std::string& getName() const;
  void setName(const std::string& name);
  float getPrice() const;
  void setPrice(float price);
  int getStock() const;
  void setStock(int stock);
  const std::string& getAdditionalInfo() const;
};

#endif  // SUDOMANAGER_ITEM_HPP
