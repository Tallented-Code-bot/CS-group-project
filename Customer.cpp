// Customer.cpp
// Calvin Tallent

#include "Customer.h"
#include "Account.h"
#include "CertificateDeposit.cpp"
#include "CertificateDeposit.h"
#include "Checking.h"
#include "MoneyMarket.cpp"
#include "MoneyMarket.h"
#include "Savings.cpp"
#include "Savings.h"
#include "Transaction.h"
#include <fstream>
#include <iterator>
#include <queue>

float Customer::netWorth() {
  float sum = 0;
  for (Account *account : accounts) {
    sum += account->getBalance();
  }
  return sum;
}

void Customer::withdraw(int account, float amount) {
  auto front = accounts.begin();
  std::advance(front, account);

  Transaction t = (*front)->withdraw(amount);
  t.setIndex(account);

  transactions.push(t);
}

void Customer::deposit(int account, float amount) {
  auto front = accounts.begin();
  std::advance(front, account);
  Transaction t = (*front)->deposit(amount);
  t.setIndex(account);

  transactions.push(t);
}

// void Customer::setAccount(int i, Account account) { accounts[i] = account; }

void Customer::write(std::ostream &f) {
  // Write customer header
  std::string header("START_CUSTOMER");
  size_t headerSize = header.size();
  f.write((char *)&headerSize, sizeof(headerSize));
  f.write((char *)&header[0], headerSize);

  // write firstName and address
  size_t firstNameSize = firstName.size();
  size_t lastNameSize = lastName.size();
  size_t addressSize = address.size();
  f.write((char *)&firstNameSize, sizeof(firstNameSize));
  f.write((char *)&lastNameSize, sizeof(lastNameSize));
  f.write((char *)&addressSize, sizeof(addressSize));
  f.write((char *)&firstName[0], firstNameSize);
  f.write((char *)&lastName[0], lastNameSize);
  f.write((char *)&address[0], addressSize);

  // write accounts
  size_t numAccounts = accounts.size();
  f.write((char *)&numAccounts, sizeof(numAccounts));
  // for (size_t i = 0; i < numAccounts; i++) {
  for (auto it = accounts.begin(); it != accounts.end(); ++it) {
    int accountType = (*it)->getType();
    f.write((char *)&accountType, sizeof(accountType));

    (*it)->write(f);
  }

  // write transactions
  std::priority_queue<Transaction> transactionsClone(transactions);
  size_t numTransactions = transactionsClone.size();
  f.write((char *)&numTransactions, sizeof(numTransactions));
  for (size_t i = 0; i < numTransactions; i++) {
    transactionsClone.top().write(f);
    transactionsClone.pop();
  }

  std::string footer("END_CUSTOMER");
  size_t footerSize = footer.size();
  f.write((char *)&footerSize, sizeof(footerSize));
  f.write((char *)&footer[0], footerSize);
}

void Customer::read(std::istream &f) {
  std::string header;
  size_t headerSize;
  f.read((char *)&headerSize, sizeof(headerSize));
  header.resize(headerSize);
  f.read((char *)&header[0], headerSize);
  if (header != "START_CUSTOMER") {
    throw std::runtime_error("Cannot parse customer header");
  }

  // read name and address
  size_t firstNameSize;
  size_t lastNameSize;
  size_t addressSize;
  f.read((char *)&firstNameSize, sizeof(firstNameSize));
  f.read((char *)&lastNameSize, sizeof(lastNameSize));
  f.read((char *)&addressSize, sizeof(addressSize));
  firstName.resize(firstNameSize);
  lastName.resize(lastNameSize);
  address.resize(addressSize);
  f.read((char *)&firstName[0], firstNameSize);
  f.read((char *)&lastName[0], lastNameSize);
  f.read((char *)&address[0], addressSize);

  // write accounts
  size_t numAccounts;
  f.read((char *)&numAccounts, sizeof(numAccounts));
  accounts.clear();
  for (size_t i = 0; i < numAccounts; i++) {
    int accountType;
    f.read((char *)&accountType, sizeof(accountType));

    Account *a;

    switch (accountType) {
    case GENERIC_ACCOUNT:
      a = new Account();
      break;
    case CHECKING:
      a = new Checking();
      break;
    case SAVINGS:
      a = new Savings();
      break;
    case MONEYMARKET:
      a = new MoneyMarket();
      break;
    case CERTIFICATE_DEPOSIT:
      a = new CertificateDeposit();
      break;
    }

    a->read(f);
    accounts.push_back(a);
  }

  // read transactions
  size_t numTransactions;
  f.read((char *)&numTransactions, sizeof(numTransactions));
  while (!transactions.empty()) {
    transactions.pop();
  }
  for (size_t i = 0; i < numTransactions; i++) {
    Transaction t;
    t.read(f);
    transactions.push(t);
  }

  std::string footer;
  size_t footerSize;
  f.read((char *)&footerSize, sizeof(footerSize));
  footer.resize(footerSize);
  f.read((char *)&footer[0], footerSize);

  if (footer != "END_CUSTOMER") {
    throw std::runtime_error("Cannot parse customer footer");
  }
}
