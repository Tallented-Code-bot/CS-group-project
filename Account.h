

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Customer.h"

class Account {
private:
  Customer owner;
  float balance;
  float monthly_interest;

public:
  virtual void deposit(float amount);
  virtual void withdraw(float amount);
  // TODO Create constructor
};

#endif
