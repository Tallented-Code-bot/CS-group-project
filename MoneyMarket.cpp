// MoneyMarket.cpp
// Calvin Tallent

#include "MoneyMarket.h"
#include "Account.h"

#include <fstream>

void MoneyMarket::write(std::ostream &f) {
  std::string header("START_MONEY_MARKET");
  size_t headerLength = header.size();
  f.write((char *)&headerLength, sizeof(headerLength));
  f.write((char *)&header[0], headerLength);

  f.write((char *)&balance, sizeof(balance));
  f.write((char *)&monthly_interest, sizeof(monthly_interest));
  f.write((char *)&withdrawal_penalty, sizeof(withdrawal_penalty));
  f.write((char *)&maturity_penalty, sizeof(maturity_penalty));

  std::string footer("END_MONEY_MARKET");
  size_t footerLength = footer.size();
  f.write((char *)&footerLength, sizeof(footerLength));
  f.write((char *)&footer[0], footerLength);
}

void MoneyMarket::read(std::istream &f) {
  std::string header;
  size_t headerLength;
  f.read((char *)&headerLength, sizeof(headerLength));
  header.resize(headerLength);
  f.read((char *)&header[0], headerLength);
  if (header != "START_MONEY_MARKET") {
    throw std::runtime_error("Cannot parse money market header");
  }

  f.read((char *)&balance, sizeof(balance));
  f.read((char *)&monthly_interest, sizeof(monthly_interest));
  f.read((char *)&withdrawal_penalty, sizeof(withdrawal_penalty));
  f.read((char *)&maturity_penalty, sizeof(maturity_penalty));

  std::string footer;
  size_t footerLength;
  f.read((char *)&footerLength, sizeof(footerLength));
  footer.resize(footerLength);
  f.read((char *)&footer[0], footerLength);

  if (footer != "END_MONEY_MARKET") {
    throw std::runtime_error("Cannot parse money market footer");
  }
}

void MoneyMarket::processPenalties(
    Transaction &transaction, PriorityQueueWrapper<Transaction> &transactions) {

  if (balance < 10'000) {
    // fine of 200$
    Transaction t = withdraw(200);
    t.process(); // We don't want to process this ever
    transactions.push(t);
  }

  transaction.process();
}
