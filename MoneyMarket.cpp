

#include "MoneyMarket.h"

#include <fstream>

void MoneyMarket::write(std::ostream &f) {
  f.write((char *)&balance, sizeof(balance));
  f.write((char *)&monthly_interest, sizeof(monthly_interest));
  f.write((char *)&withdrawal_penalty, sizeof(withdrawal_penalty));
  f.write((char *)&maturity_penalty, sizeof(maturity_penalty));
}

void MoneyMarket::read(std::istream &f) {
  f.read((char *)&balance, sizeof(balance));
  f.read((char *)&monthly_interest, sizeof(monthly_interest));
  f.read((char *)&withdrawal_penalty, sizeof(withdrawal_penalty));
  f.read((char *)&maturity_penalty, sizeof(maturity_penalty));
}
