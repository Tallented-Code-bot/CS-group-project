

#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"

class Checking : public Account {
public:
  // Constructor initializing base class Account
  Checking(float balance, float monthly_interest)
      : Account(balance, monthly_interest) {}

  virtual std::string getName() { return "Checking"; }
};

#endif
