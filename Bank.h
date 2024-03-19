

#ifndef BANK_H
#define BANK_H

#include "Customer.h"
#include <vector>

class Bank {
private:
  std::vector<Customer> users;

public:
  void addUser(Customer user);
};

#endif
