

#include "Account.h"
#include <iostream>

void Account::deposit(float amount) {
  balance += amount; // Increase balance by the deposited amount
}

void Account::withdraw(float amount) {
  if (balance >= amount) {
    balance -=
        amount; // Decrease balance by the withdrawn amount if sufficient funds
  } else {
    std::cout << "Insufficient funds\n"; // Display error message if funds are
                                         // insufficient
  }
}
