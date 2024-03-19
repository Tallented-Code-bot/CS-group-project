

#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"

class Checking : public Account {
public:
  // Constructor initializing base class Account
  Checking(Customer owner, float balance, float monthly_interest)
      : Account(owner, balance, monthly_interest) {}
};

#endif
