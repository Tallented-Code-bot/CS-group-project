#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Account.h"
#include <string>
#include <vector>

class Customer {
private:
  std::string name;
  std::string address;
  std::vector<Account> accounts;

public:
  // Default constructor with default values for name and address
  Customer(std::string name = "John Doe",
           std::string address = "123 Main Street")
      : name(name), address(address) {}

  // Accessor methods
  std::string getName() const { return name; }
  std::string getAddress() const { return address; }

  // Mutator methods
  void setAddress(std::string address) { this->address = address; }
  void setName(std::string name) { this->name = name; }

  void addAccount(Account account) { accounts.push_back(account); }
  std::vector<Account> getAccounts() { return accounts; }
  Account getAccount(int i) { return accounts[i]; }
  void deleteAccount(int i) { accounts.erase(accounts.begin() + i); }
  void setAccount(int i, Account account);

  float netWorth();

  // This allows us to sort by name
  bool operator<(Customer other) { return name < other.name; }

  void write(std::ostream &f);
  void read(std::istream &f);
};

#endif
