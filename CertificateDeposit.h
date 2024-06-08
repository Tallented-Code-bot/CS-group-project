// CertificateDeposit.h
// Calvin Tallent

#ifndef CERTIFICATE_DEPOSIT_H
#define CERTIFICATE_DEPOSIT_H

#include "Account.h"

class CertificateDeposit : public Account {
private:
  int months;
  float withdrawal_penalty;

public:
  // Constructor initializing base class Account and additional attributes
  CertificateDeposit(float balance = 0, float monthly_interest = 0,
                     int term = 0, float withdrawal_penalty = 0)
      : Account(balance, monthly_interest), months(term),
        withdrawal_penalty(withdrawal_penalty) {}

  std::string getName() { return "Certificate of Deposit"; }

  AccountType getType() { return CERTIFICATE_DEPOSIT; }

  void write(std::ostream &f);
  void read(std::istream &f);

  void processPenalties(Transaction &transaction,
                        PriorityQueueWrapper<Transaction> &transactions);
};

#endif
