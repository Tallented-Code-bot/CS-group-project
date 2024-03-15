

#ifndef CERTIFICATE_DEPOSIT_H
#define CERTIFICATE_DEPOSIT_H

#include "Account.cpp"
#include "Account.h"

class CertificateDeposit : Account {
private:
  int term;
  float withdrawal_penalty;
};

#endif
