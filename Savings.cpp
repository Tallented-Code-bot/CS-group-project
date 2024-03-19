

#include "Savings.h"
#include <fstream>

void Savings::write(std::ostream &f) {
  f.write((char *)&balance, sizeof(balance));
  f.write((char *)&monthly_interest, sizeof(monthly_interest));
  f.write((char *)&withdrawal_penalty, sizeof(withdrawal_penalty));
}

void Savings::read(std::istream &f) {
  f.read((char *)&balance, sizeof(balance));
  f.read((char *)&monthly_interest, sizeof(monthly_interest));
  f.read((char *)&withdrawal_penalty, sizeof(withdrawal_penalty));
}
