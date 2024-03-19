

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

std::string Account::getName() { return "Generic Account"; }

void Account::write(std::ostream &f) {
  f.write((char *)&balance, sizeof(balance));
  f.write((char *)&monthly_interest, sizeof(monthly_interest));
}

void Account::read(std::istream &f) {
  f.read((char *)&balance, sizeof(balance));
  f.read((char *)&monthly_interest, sizeof(monthly_interest));
}
