// Bank.h
// Calvin Tallent

#ifndef BANK_H
#define BANK_H

#include "Customer.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <istream>
#include <new>
#include <ostream>
#include <stdexcept>
#include <string>
#include <list>

class Bank {
private:
  std::list<Customer> users;
  std::string filename;
  std::chrono::system_clock::time_point penaltiesLastProcessed;

public:
  Bank(std::string filename) {
    this->filename = filename;

    std::ifstream file(filename);

    try {
      read(file);
    } catch (std::runtime_error &e) {
      users.clear();
      std::cerr << "Cannot read file " << filename
                << ", creating bank from scratch.\n";
    } catch (std::bad_alloc &e) {
      users.clear();
      std::cerr << "Cannot read file " << filename
                << ", creating bank from scratch.\n";
    }
    file.close();
  }

  void addUser(Customer user);
  std::list<Customer> getUsers();
  Customer getUser(int i);
  void deleteUser(int i);
  void setUser(int i, Customer user);

  std::chrono::system_clock::time_point getPenaltiesLastProcessed() {
    return penaltiesLastProcessed;
  }

  void write(std::ostream &f);
  void read(std::istream &f);

  void save() {
    std::ofstream file(filename);
    write(file);
    file.close();
  }

  void processPenalties();
};

#endif
