#include "sudoManager/Item.hpp"
#include "sudoManager/Bill.hpp"
#include "sudoManager/Payment.hpp"
#include <gtest/gtest.h>

TEST(EnvironmentTEST, LinkTest) { ASSERT_EQ(1, 1); }

TEST(BillTest, Status) {

  Bill bill {1, 10};

  ASSERT_EQ(bill.get_status(), false);

}

TEST(BillTest, Amount) {

  Bill bill {1};

  bill.add_item({1, "Spaghetti", 10.0, 1});

  ASSERT_EQ(bill.get_amount(), 10.0);

}

TEST(BillTest, AddItem) {

  Bill bill {1};

  std::vector<Item> items {
      {1, "Spaghetti", 10.0, 1},
      {2, "Pizza", 20.0, 1},
      {3, "Coca-Cola", 5.0, 1},
      {4, "Water", 2.0, 1}
  };

  for (auto& item : items)
    bill.add_item(item);

  ASSERT_EQ(bill.get_amount(), 37.0);

}

TEST(BillTest, RemoveItem) {

  Bill bill {1};

  std::vector<Item> items {
      {1, "Spaghetti", 10.0, 1},
      {2, "Pizza", 20.0, 1},
      {3, "Coca-Cola", 5.0, 1},
      {4, "Water", 2.0, 1}
  };

  for (auto& item : items)
    bill.add_item(item);

  for (auto& item : items)
    bill.remove_item(item);

  ASSERT_EQ(bill.get_amount(), 0.0);

}

TEST(PaymentTest, CardPayment) {

  Bill bill {1};

  bill.add_item({1, "Spaghetti", 10.0, 1});

  Payment payment {bill};

  payment.card_payment();

  ASSERT_EQ(bill.get_status(), true);

}

TEST(PaymentTest, CashPayment) {

  Bill bill {1};

  bill.add_item({1, "Spaghetti", 10.0, 1});

  Payment payment {bill};

  payment.cash_payment();

  ASSERT_EQ(bill.get_status(), true);

}

TEST(PaymentTest, CheckPayment) {

  Bill bill {1};

  bill.add_item({1, "Spaghetti", 10.0, 1});

  Payment payment {bill};

  payment.check_payment();

  ASSERT_EQ(bill.get_status(), true);

}