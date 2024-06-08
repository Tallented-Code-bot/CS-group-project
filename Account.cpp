// Account.cpp
// Calvin Tallent

#include "Account.h"
#include "Transaction.h"
#include <iostream>
#include <stdexcept>

Transaction Account::deposit(float amount) {
  balance += amount; // Increase balance by the deposited amount
  Transaction t(DEBIT, amount);
  return t;
}

Transaction Account::withdraw(float amount) {
  if (balance >= amount) {
    balance -=
        amount; // Decrease balance by the withdrawn amount if sufficient funds
  } else {
    throw std::runtime_error("Cannot withdraw: insufficient funds");
  }

  Transaction t(CREDIT, amount);
  return t;
}

void Account::write(std::ostream &f) {
  std::string header("START_GENERIC_ACCOUNT");
  size_t headerLength = header.size();
  f.write((char *)&headerLength, sizeof(headerLength));
  f.write((char *)&header[0], headerLength);

  f.write((char *)&balance, sizeof(balance));
  f.write((char *)&monthly_interest, sizeof(monthly_interest));

  std::string footer("END_GENERIC_ACCOUNT");
  size_t footerLength = footer.size();
  f.write((char *)&footerLength, sizeof(footerLength));
  f.write((char *)&footer[0], footerLength);
}

void Account::read(std::istream &f) {

  std::string header;
  size_t headerLength;
  f.read((char *)&headerLength, sizeof(headerLength));
  header.resize(headerLength);
  f.read((char *)&header[0], headerLength);
  if (header != "START_GENERIC_ACCOUNT") {
    throw std::runtime_error("Cannot parse generic account header");
  }

  f.read((char *)&balance, sizeof(balance));
  f.read((char *)&monthly_interest, sizeof(monthly_interest));

  std::string footer;
  size_t footerLength;
  f.read((char *)&footerLength, sizeof(footerLength));
  footer.resize(footerLength);
  f.read((char *)&footer[0], footerLength);

  if (footer != "END_GENERIC_ACCOUNT") {
    throw std::runtime_error("Cannot parse generic account footer");
  }
}

void Account::processPenalties(
    Transaction &transaction, PriorityQueueWrapper<Transaction> &transactions) {
  // We just set the transaction to have been processed.
  transaction.process();
}
