// MoneyMarket.h
// Calvin Tallent

#ifndef MONEY_MARKET_H
#define MONEY_MARKET_H

#include "Account.h"
#include <istream>
#include <ostream>

class MoneyMarket : public Account {
private:
  float withdrawal_penalty;
  float maturity_penalty;

public:
  // Constructor initializing base class Account and additional attributes
  MoneyMarket(float balance = 0, float monthly_interest = 0,
              float withdrawal_penalty = 0, float maturity_penalty = 0)
      : Account(balance, monthly_interest),
        withdrawal_penalty(withdrawal_penalty),
        maturity_penalty(maturity_penalty) {}

  std::string getName() { return "Money Market"; }

  AccountType getType() { return MONEYMARKET; }

  void write(std::ostream &f);
  void read(std::istream &f);

  void processPenalties(Transaction &transaction,
                        PriorityQueueWrapper<Transaction> &transactions);
};
#endif
