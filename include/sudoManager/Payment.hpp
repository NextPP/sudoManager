//
// Created by HORIA on 17.04.2023.
//

#ifndef SUDOMANAGER_PAYMENT_HPP
#define SUDOMANAGER_PAYMENT_HPP

#include <chrono>
#include <ctime>

#include "sudoManager/Bill.hpp"

class Payment {
 public:
  explicit Payment(Bill& bill) : m_bill{bill} {};

  // methods
  void card_payment();
  void cash_payment();
  void check_payment();

 private:
  Bill& m_bill;
  time_t m_time{};

  void update_time();
  void generate_receipt();
  void init_transaction();
};

#endif  // SUDOMANAGER_PAYMENT_HPP
