// Transaction.h
// Calvin Tallent

#ifndef TRANSACTION_H
#define TRANSACTION_H

// #include "Uuid.h"
#include <chrono>
#include <cstddef>
#include <iostream>
#include <istream>
#include <ostream>
#include <stdexcept>

enum TransactionType { DEBIT, CREDIT };

class Transaction {
private:
  std::chrono::system_clock::time_point date;
  size_t accountIndex;
  TransactionType type;
  float amount;
  bool shouldProcess;
  // date, account, customer, debit/credit

public:
  Transaction(TransactionType type = DEBIT, float amount = 0, int index = 0) {
    accountIndex = index;
    this->type = type;
    this->amount = amount;
    this->shouldProcess = true;
    date = std::chrono::system_clock::now();
  }

  float getAmount() { return amount; }
  size_t getIndex() { return accountIndex; }
  TransactionType getType() { return type; }
  std::chrono::system_clock::time_point getDatetime() { return date; }
  bool getShouldProcess() { return shouldProcess; }

  void setAmount(float amount) { this->amount = amount; }
  void setIndex(int index) { this->accountIndex = index; }
  void setType(TransactionType type) { this->type = type; }
  void setDatetime(std::chrono::system_clock::time_point date) {
    this->date = date;
  }
  void process() { this->shouldProcess = false; }

  bool operator<(const Transaction other) const {
    return this->date < other.date;
  }
  bool operator>(const Transaction other) const {
    return this->date > other.date;
  }
  bool operator==(const Transaction other) const {
    return this->date == other.date && this->amount == other.amount &&
           this->type == other.type && this->accountIndex == other.accountIndex;
  }

  void write(std::ostream &f) const {
    std::string header("START_TRANSACTION");
    size_t headerLength = header.size();
    f.write((char *)&headerLength, sizeof(headerLength));
    f.write((char *)&header[0], headerLength);

    f.write((char *)&type, sizeof(type));
    f.write((char *)&amount, sizeof(amount));
    f.write((char *)&date, sizeof(date));
    f.write((char *)&accountIndex, sizeof(accountIndex));
    f.write((char *)&shouldProcess, sizeof(shouldProcess));

    std::string footer("END_TRANSACTION");
    size_t footerLength = footer.size();
    f.write((char *)&footerLength, sizeof(footerLength));
    f.write((char *)&footer[0], footerLength);
  }

  void read(std::istream &f) {
    std::string header;
    size_t headerLength;
    f.read((char *)&headerLength, sizeof(headerLength));
    header.resize(headerLength);
    f.read((char *)&header[0], headerLength);
    if (header != "START_TRANSACTION") {
      throw std::runtime_error("Cannot parse transaction header");
    }

    f.read((char *)&type, sizeof(type));
    f.read((char *)&amount, sizeof(amount));
    f.read((char *)&date, sizeof(date));
    f.read((char *)&accountIndex, sizeof(accountIndex));
    f.read((char *)&shouldProcess, sizeof(shouldProcess));

    std::string footer;
    size_t footerLength;
    f.read((char *)&footerLength, sizeof(footerLength));
    footer.resize(footerLength);
    f.read((char *)&footer[0], footerLength);

    if (footer != "END_TRANSACTION") {
      throw std::runtime_error("Cannot parse transaction footer");
    }
  }
};

#endif
