// Account.h
// Calvin Tallent

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "PriorityQueueBetter.h"
#include "Transaction.h"
#include "Util.cpp"
#include <string>
#include <vector>

enum AccountType {
  GENERIC_ACCOUNT,
  CERTIFICATE_DEPOSIT,
  CHECKING,
  MONEYMARKET,
  SAVINGS,
};

class Account {
protected:
  float balance;
  float monthly_interest;

public:
  // Constructor with default values for balance and monthly_interest
  Account(float balance = 0.0f, float monthly_interest = 0.0f)
      : balance(balance), monthly_interest(monthly_interest) {}

  virtual ~Account() {}

  // Virtual functions for deposit and withdraw operations
  virtual Transaction deposit(float amount);
  virtual Transaction withdraw(float amount);

  // Accessor methods for balance and name
  float getBalance() const { return balance; }
  virtual std::string getName() { return "Generic Account"; }
  virtual AccountType getType() { return GENERIC_ACCOUNT; }

  virtual void
  processPenalties(Transaction &transaction,
                   PriorityQueueWrapper<Transaction> &transactions);

  bool operator<(Account other) { return balance < other.balance; }

  virtual void write(std::ostream &f);
  virtual void read(std::istream &f);
};

#endif
