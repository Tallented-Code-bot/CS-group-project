

#ifndef MONEY_MARKET_H
#define MONEY_MARKET_H

#include "Account.h"

class MoneyMarket : public Account {
private:
  float withdrawal_penalty;
  float maturity_penalty;

public:
  // Constructor initializing base class Account and additional attributes
  MoneyMarket(Customer owner, float balance, float monthly_interest,
              float withdrawal_penalty, float maturity_penalty)
      : Account(owner, balance, monthly_interest),
        withdrawal_penalty(withdrawal_penalty),
        maturity_penalty(maturity_penalty) {}
};

#endif
