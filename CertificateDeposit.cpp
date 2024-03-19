
#include "CertificateDeposit.h"
#include "Account.h"
#include <fstream>

void CertificateDeposit::write(std::ostream &f) {
  f.write((char *)&balance, sizeof(balance));
  f.write((char *)&monthly_interest, sizeof(monthly_interest));
  f.write((char *)&term, sizeof(term));
  f.write((char *)&withdrawal_penalty, sizeof(withdrawal_penalty));
}

void CertificateDeposit::read(std::istream &f) {
  f.read((char *)&balance, sizeof(balance));
  f.read((char *)&monthly_interest, sizeof(monthly_interest));
  f.read((char *)&term, sizeof(term));
  f.read((char *)&withdrawal_penalty, sizeof(withdrawal_penalty));
}
