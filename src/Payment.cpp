//
// Created by HORIA on 17.04.2023.
//
#include "sudoManager/Payment.hpp"

// methods
void Payment::init_transaction() {
  if (m_bill.get_status())
    throw std::invalid_argument("Bill already paid");
  else
    m_bill.set_status(true);

  generate_receipt();
}

void Payment::generate_receipt() {
  m_bill.generate();

  update_time();

  std::cout << "Time: " << std::ctime(&m_time) << std::endl;

  if (m_bill.get_status())
    std::cout << "Payment successful" << std::endl;
  else
    std::cout << "Payment failed" << std::endl;
}

void Payment::update_time() {
  auto now{std::chrono::system_clock::now()};

  m_time = std::chrono::system_clock::to_time_t(now);
}
void Payment::card_payment() { init_transaction(); }
void Payment::cash_payment() { init_transaction(); }
void Payment::check_payment() { init_transaction(); }
