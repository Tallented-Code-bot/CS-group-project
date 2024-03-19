

#ifndef CERTIFICATE_DEPOSIT_H
#define CERTIFICATE_DEPOSIT_H

#include "Account.h"

class CertificateDeposit : public Account {
private:
  int term;
  float withdrawal_penalty;

public:
  // Constructor initializing base class Account and additional attributes
  CertificateDeposit(float balance, float monthly_interest, int term,
                     float withdrawal_penalty)
      : Account(balance, monthly_interest), term(term),
        withdrawal_penalty(withdrawal_penalty) {}
};

#endif
