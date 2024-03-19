

#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"

class Savings : public Account {
private:
  float withdrawal_penalty;

public:
  // Constructor initializing base class Account and additional attributes
  Savings(Customer owner, float balance, float monthly_interest,
          float withdrawal_penalty)
      : Account(owner, balance, monthly_interest),
        withdrawal_penalty(withdrawal_penalty) {}
};

#endif
