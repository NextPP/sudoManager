//
// Created by HORIA on 17.04.2023.
//

#ifndef SUDOMANAGER_BILL_HPP
#define SUDOMANAGER_BILL_HPP

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include "sudoManager/Item.hpp"

class Bill {
 public:
  explicit Bill(int id, int tip_percentage = 0)
      : m_id{id}, m_tip_percentage{tip_percentage}, m_amount{0.0} {};

  // getters
  [[nodiscard]] bool get_status() const;
  [[nodiscard]] double get_amount() const;

  // setters
  void set_status(bool status);
  void set_tip_percentage(int tip_percentage);

  // methods
  void generate() const;
  void add_item(const Item& item);
  void remove_item(const Item& item);

 private:
  int m_id{};
  int m_tip_percentage{};
  double m_amount{};
  bool m_status{false};
  std::vector<Item> m_items{};

  void update_amount(const Item& item);
  void recalculate_amount();
};

#endif  // SUDOMANAGER_BILL_HPP
