// Bank.cpp
// Calvin Tallent

#include "Bank.h"
#include "Account.h"
#include "Transaction.h"
#include "Util.cpp"
#include <queue>
#include <system_error>
#include <vector>

void Bank::addUser(Customer user) { users.push_back(user); }

std::vector<Customer> Bank::getUsers() { return users; }
Customer Bank::getUser(int i) { return users[i]; }
void Bank::deleteUser(int i) { users.erase(users.begin() + i); }

void Bank::setUser(int i, Customer user) { users[i] = user; }

void Bank::write(std::ostream &f) {
  std::string header("START_BANK");
  size_t headerLength = header.size();
  f.write((char *)&headerLength, sizeof(headerLength));
  f.write((char *)&header[0], headerLength);

  size_t numCustomers = users.size();
  f.write((char *)&numCustomers, sizeof(numCustomers));
  for (size_t i = 0; i < users.size(); i++) {
    users[i].write(f);
  }

  f.write((char *)&penaltiesLastProcessed, sizeof(penaltiesLastProcessed));

  std::string footer("END_BANK");
  size_t footerLength = footer.size();
  f.write((char *)&footerLength, sizeof(footerLength));
  f.write((char *)&footer[0], footerLength);
}

void Bank::read(std::istream &f) {
  std::string header;
  size_t headerLength;
  f.read((char *)&headerLength, sizeof(headerLength));
  header.resize(headerLength);
  f.read((char *)&header[0], headerLength);
  if (header != "START_BANK") {
    throw std::runtime_error("Cannot parse bank header");
  }

  size_t numCustomers;
  f.read((char *)&numCustomers, sizeof(numCustomers));
  users.clear();
  for (size_t i = 0; i < numCustomers; i++) {
    Customer c;
    c.read(f);
    users.push_back(c);
  }
  f.read((char *)&penaltiesLastProcessed, sizeof(penaltiesLastProcessed));

  std::string footer;
  size_t footerLength;
  f.read((char *)&footerLength, sizeof(footerLength));
  footer.resize(footerLength);
  f.read((char *)&footer[0], footerLength);

  if (footer != "END_BANK") {
    throw std::runtime_error("Cannot parse transaction footer");
  }
}

void Bank::processPenalties() {
  // for each customer
  // - get list of transactions
  // - for each transaction
  // - - customerAccount[transactionIndex]
  //      .processPenalties(&transaction,&vector<transaction>);

  for (Customer customer : users) {
    for (size_t i = 0; i < customer.getTransactions().size(); i++) {
      Account a = customer.getAccount(customer.getTransactions()[i].getIndex());
      a.processPenalties(customer.getTransactions()[i],
                         customer.getTransactions());
    }
  }

  this->penaltiesLastProcessed = std::chrono::system_clock::now();
}
