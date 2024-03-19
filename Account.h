

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Customer.h"

class Account {
private:
  Customer owner;
  float balance;
  float monthly_interest;

public:
  // Constructor with default values for balance and monthly_interest
  Account(Customer owner, float balance = 0.0f, float monthly_interest = 0.0f)
      : owner(owner), balance(balance), monthly_interest(monthly_interest) {}

  // Virtual functions for deposit and withdraw operations
  virtual void deposit(float amount);
  virtual void withdraw(float amount);

  // Accessor methods for balance
  float getBalance() const { return balance; }
};

#endif
