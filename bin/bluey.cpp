#include "sudoManager/Item.hpp"
#include "sudoManager/Bill.hpp"
#include "sudoManager/Payment.hpp"
#include "sudoManager/Menu.hpp"

int main() {

  std::cout << "Hi, I'm Bluey, I will be your server." << '\n';

  Menu menu {};

  menu.add_menu_item({1, "Spaghetti", 10.0, 1});
  menu.add_menu_item({2, "Pizza", 20.0, 1});
  menu.add_menu_item({3, "Coca-Cola", 5.0, 1});
  menu.add_menu_item({4, "Water", 2.0, 1});

  menu.print_menu();

  auto keepOrdering { true };

  auto itemNumber { 0 };

  Bill bill {1};

  while (keepOrdering) {

    std::cout << "Enter the item number of the item you want to order." << '\n';

    std::cin >> itemNumber;

    switch (itemNumber) {

      case 1:
        bill.add_item(menu.getMenuItem("Spaghetti"));
        break;
      case 2:
        bill.add_item(menu.getMenuItem("Pizza"));
        break;
      case 3:
        bill.add_item(menu.getMenuItem("Coca-Cola"));
        break;
      case 4:
        bill.add_item(menu.getMenuItem("Water"));
        break;
      default:
        std::cout << "Sorry, we don't serve that." << '\n';
        break;
    }

    std::cout << "Is that all ? (y/n)" << '\n';

    auto answer {'n'};

    std::cin >> answer;

    if (answer != 'n')
      keepOrdering = false;

  }

  std::cout << "Do you want to tip the waiter ? (y/n)" << '\n';

  auto answer {'n'};

  std::cin >> answer;

  if (answer == 'y') {
    std::cout << "Tip amount: "
                 "\t 1 : 5%"
                 "\t 2 : 15%"
                 "\t 3 : 25%"
              << '\n';

    auto tip{0};

    std::cin >> tip;

    switch (tip) {
      case 1:
        bill.set_tip_percentage(5);
        break;
      case 2:
        bill.set_tip_percentage(15);
        break;
      case 3:
        bill.set_tip_percentage(25);
        break;
      default:
        std::cout << "No tip" << '\n';
        break;
    }

  }
  std::cout << "Here is your bill: \n";

  bill.generate();

  std::cout << "How would you like to pay ? (1 : Cash, 2 : Card, 3 : Check)" << '\n';

  auto answer2 {0};

  std::cin >> answer2;

  Payment payment {bill};

  auto isPaid {bill.get_status()};

  while (!isPaid) {

    switch (answer2) {
      case 1:
        payment.cash_payment();
        break;
      case 2:
        payment.card_payment();
        break;
      case 3:
        payment.check_payment();
        break;
      default:
        std::cout << "No payment method selected" << '\n';
        break;
    }

    if (bill.get_status()) {

      std::cout << "Thank you for your visit, have a nice day !" << '\n';
      isPaid = true;

    } else {

      std::cout << "Sorry, we couldn't process your payment." << '\n';
      std::cout << "Please try again." << '\n';

    }

  }

  return 0;
}