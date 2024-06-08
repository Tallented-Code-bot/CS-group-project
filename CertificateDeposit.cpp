// CertificateDeposit.cpp
// Calvin Tallent

#include "CertificateDeposit.h"
#include "Account.h"
#include <fstream>

void CertificateDeposit::write(std::ostream &f) {
  std::string header("START_CERTIFICATE_DEPOSIT");
  size_t headerLength = header.size();
  f.write((char *)&headerLength, sizeof(headerLength));
  f.write((char *)&header[0], headerLength);

  f.write((char *)&balance, sizeof(balance));
  f.write((char *)&monthly_interest, sizeof(monthly_interest));
  f.write((char *)&months, sizeof(months));
  f.write((char *)&withdrawal_penalty, sizeof(withdrawal_penalty));

  std::string footer("END_CERTIFICATE_DEPOSIT");
  size_t footerLength = footer.size();
  f.write((char *)&footerLength, sizeof(footerLength));
  f.write((char *)&footer[0], footerLength);
}

void CertificateDeposit::read(std::istream &f) {
  std::string header;
  size_t headerLength;
  f.read((char *)&headerLength, sizeof(headerLength));
  header.resize(headerLength);
  f.read((char *)&header[0], headerLength);
  if (header != "START_CERTIFICATE_DEPOSIT") {
    throw std::runtime_error("Cannot parse certificate deposit header");
  }

  f.read((char *)&balance, sizeof(balance));
  f.read((char *)&monthly_interest, sizeof(monthly_interest));
  f.read((char *)&months, sizeof(months));
  f.read((char *)&withdrawal_penalty, sizeof(withdrawal_penalty));

  std::string footer;
  size_t footerLength;
  f.read((char *)&footerLength, sizeof(footerLength));
  footer.resize(footerLength);
  f.read((char *)&footer[0], footerLength);

  if (footer != "END_CERTICIATE_DEPOSIT") {
    throw std::runtime_error("Cannot parse certificate deposit footer");
  }
}

void CertificateDeposit::processPenalties(
    Transaction &transaction, PriorityQueueWrapper<Transaction> &transactions) {

  double toDeduct;

  if (this->months < 3) {
    // deduct 10% of balance

    toDeduct = 0.10 * balance;
  } else if (this->months < 6) {
    // deduct 20% of balance
    toDeduct = 0.20 * balance;
  } else if (this->months < 12) {
    // deduct 50% of balance
    toDeduct = 0.50 * balance;
  }

  Transaction t = withdraw(toDeduct);
  t.process();
  transactions.push(t);

  transaction.process();
}
