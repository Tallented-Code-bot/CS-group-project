// Savings.h
// Calvin Tallent

#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"

class Savings : public Account {
private:
  float withdrawal_penalty;

public:
  // Constructor initializing base class Account and additional attributes
  Savings(float balance = 0, float monthly_interest = 0,
          float withdrawal_penalty = 0)
      : Account(balance, monthly_interest),
        withdrawal_penalty(withdrawal_penalty) {}

  std::string getName() { return "Savings"; }

  AccountType getType() { return SAVINGS; }

  void write(std::ostream &f);
  void read(std::istream &f);
  void processPenalties(Transaction &transaction,
                        PriorityQueueWrapper<Transaction> &transactions);
};

#endif
