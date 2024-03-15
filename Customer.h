

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
  std::string name;
  std::string address;

public:
  Customer(std::string name, std::string address) {
    this->name = name;
    this->address = address;
  }
  std::string getName() { return name; }
  std::string getAddress() { return address; }
  void setAddress(std::string address) { this->address = address; }
  void setName(std::string name) { this->name = name; }
};

#endif
