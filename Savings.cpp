// Savings.cpp
// Calvin Tallent

#include "Savings.h"
#include "Account.h"
#include <fstream>

void Savings::write(std::ostream &f) {
  std::string header("START_SAVINGS");
  size_t headerLength = header.size();
  f.write((char *)&headerLength, sizeof(headerLength));
  f.write((char *)&header[0], headerLength);

  f.write((char *)&balance, sizeof(balance));
  f.write((char *)&monthly_interest, sizeof(monthly_interest));
  f.write((char *)&withdrawal_penalty, sizeof(withdrawal_penalty));

  std::string footer("END_SAVINGS");
  size_t footerLength = footer.size();
  f.write((char *)&footerLength, sizeof(footerLength));
  f.write((char *)&footer[0], footerLength);
}

void Savings::read(std::istream &f) {
  std::string header;
  size_t headerLength;
  f.read((char *)&headerLength, sizeof(headerLength));
  header.resize(headerLength);
  f.read((char *)&header[0], headerLength);
  if (header != "START_SAVINGS") {
    throw std::runtime_error("Cannot parse savings header");
  }

  f.read((char *)&balance, sizeof(balance));
  f.read((char *)&monthly_interest, sizeof(monthly_interest));
  f.read((char *)&withdrawal_penalty, sizeof(withdrawal_penalty));

  std::string footer;
  size_t footerLength;
  f.read((char *)&footerLength, sizeof(footerLength));
  footer.resize(footerLength);
  f.read((char *)&footer[0], footerLength);

  if (footer != "END_SAVINGS") {
    throw std::runtime_error("Cannot parse savings footer");
  }
}

void Savings::processPenalties(
    Transaction &transaction, PriorityQueueWrapper<Transaction> &transactions) {

  if (balance < 1000) {
    // withdrawal of 50$

    Transaction t = withdraw(50);
    t.process(); // We don't ever process this transaction
    transactions.push(t);
  }

  transaction.process();
}
