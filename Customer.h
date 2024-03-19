#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
  std::string name;
  std::string address;

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
};

#endif
