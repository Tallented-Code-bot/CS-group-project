

#ifndef MONEY_MARKET_H
#define MONEY_MARKET_H

#include "Account.cpp"
#include "Account.h"

class MoneyMarket : Account {
private:
  float withdrawal_penalty;
  float maturity_penalty;
};

#endif
