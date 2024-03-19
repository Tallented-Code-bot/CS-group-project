

#ifndef BANK_H
#define BANK_H

#include "Customer.h"
#include <vector>

class Bank {
private:
  std::vector<Customer> users;

public:
  void addUser(Customer user);
  std::vector<Customer> getUsers();
  Customer getUser(int i);
  void deleteUser(int i);
  void setUser(int i, Customer user);
};

#endif
