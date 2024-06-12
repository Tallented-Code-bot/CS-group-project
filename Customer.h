// Customer.h
// Calvin Tallent

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Account.h"
#include "Transaction.h"
#include "Util.cpp"
#include <algorithm>
#include <list>
#include <queue>
#include <random>
#include <string>

class Customer {
private:
  std::string firstName;
  std::string lastName;
  std::string address;
  std::list<Account *> accounts;
  PriorityQueueWrapper<Transaction> transactions;

public:
  // Default constructor with default values for name and address
  Customer(std::string firstName = "John", std::string lastName = "Doe",
           std::string address = "123 Main Street")
      : firstName(firstName), lastName(lastName), address(address) {}

  // Accessor methods
  std::string getFirstName() const { return firstName; }
  std::string getLastName() const { return lastName; }
  std::string getAddress() const { return address; }
  std::string getName() const { return firstName + " " + lastName; }
  // uuids::uuid getUUID() { return uuid; }

  // Mutator methods
  void setAddress(std::string address) { this->address = address; }
  void setFirstName(std::string name) { this->firstName = name; }
  void setLastName(std::string name) { this->lastName = name; }

  void addAccount(Account *account) { accounts.push_back(account); }
  std::list<Account *> &getAccounts() { return accounts; }
  Account &getAccount(int i) {

    auto front = accounts.begin();
    // return *accounts[i];
    std::advance(front, i);

    return **front;
  }
  void deleteAccount(int i) {
    auto front = accounts.begin();
    std::advance(front, i);
    delete *front;
    accounts.erase(front);
  }
  // void setAccount(int i, Account account);
  void withdraw(int account, float amount);
  void deposit(int account, float amount);

  PriorityQueueWrapper<Transaction> &getTransactions() { return transactions; }

  float netWorth();

  // This allows us to sort by name
  bool operator<(Customer other) { return lastName < other.lastName; }

  void write(std::ostream &f);
  void read(std::istream &f);
};

#endif
