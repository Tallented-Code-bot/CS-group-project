

#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"

class Savings : public Account {
private:
  float withdrawal_penalty;

public:
  // Constructor initializing base class Account and additional attributes
  Savings(float balance, float monthly_interest, float withdrawal_penalty)
      : Account(balance, monthly_interest),
        withdrawal_penalty(withdrawal_penalty) {}

  virtual std::string getName() { return "Savings"; }

  void read(std::istream &f);
  void write(std::ostream &f);
};

#endif
