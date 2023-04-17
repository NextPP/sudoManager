//
// Created by HORIA on 17.04.2023.
//
#include "sudoManager/Bill.hpp"

//getters
bool Bill::get_status() const { return m_status; }

//setters
void Bill::set_status(bool status) { m_status = status; }

//methods
void Bill::generate() const {

  std::cout << "Bill #" << m_id << std::endl;
  std::cout << "Amount: $" << m_amount << std::endl;
  std::cout << "Tip: $" << m_amount * m_tip_percentage / 100 << std::endl;
  std::cout << "Total: $" << m_amount + m_amount * m_tip_percentage / 100 << std::endl;
  std::cout << "Status: " << (m_status ? "Paid" : "Not Paid") << std::endl;

}

void Bill::add_item(const Item& item) {

  m_items.push_back(item);
  update_amount(item);

}

void Bill::update_amount(const Item& item) {

  m_amount += item.getPrice();

}

void Bill::recalculate_amount() {

  m_amount = std::accumulate(m_items.begin(), m_items.end(), 0.0,
                             [](double acc, const Item& item) {
                               return acc + item.getPrice();
                             });

}

/*
 * Removes the first item with the same id as the one passed as argument
 * Recalculates the amount
 */
void Bill::remove_item(const Item& item) {

  for (auto it = m_items.begin(); it != m_items.end(); ++it) {

    if (it->getItemID() == item.getItemID()) {

      m_items.erase(it);
      break;

    }

  }

  recalculate_amount();

}

void Bill::set_tip_percentage(int tip_percentage) {

  m_tip_percentage = tip_percentage;

}
double Bill::get_amount() const { return m_amount; }
