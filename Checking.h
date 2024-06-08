// Checking.h
// Calvin Tallent

#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"
#include "Transaction.h"
#include <istream>
#include <ostream>
#include <vector>

class Checking : public Account {
public:
  // Constructor initializing base class Account
  Checking(float balance = 0, float monthly_interest = 0)
      : Account(balance, monthly_interest) {}

  std::string getName() { return "Checking"; }

  AccountType getType() { return CHECKING; }

  void processPenalties(Transaction &transaction,
                        PriorityQueueWrapper<Transaction> &transactions) {
    transaction.process();
  }
};

#endif
