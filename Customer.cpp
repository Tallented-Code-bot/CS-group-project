#include "Customer.h"
#include "Account.h"
#include <fstream>

float Customer::netWorth() {
  float sum = 0;
  for (Account account : accounts) {
    sum += account.getBalance();
  }
  return sum;
}

void Customer::setAccount(int i, Account account) { accounts[i] = account; }

void Customer::write(std::ostream &f) {
  std::size_t size;

  size = name.size();
  f.write((char *)&size, sizeof(size_t));
  f.write((char *)name.c_str(), size);

  size = address.size();
  f.write((char *)&size, sizeof(size_t));
  f.write((char *)address.c_str(), size);

  size = accounts.size();
  f.write((char *)&size, sizeof(size_t));
  f.write((char *)&accounts[0], size * sizeof(Account));
  // for (int i = 0; i < size; i++) {
  //   accounts[i].write(f);
  // }
}

void Customer::read(std::istream &f) {

  size_t size;
  char *data;

  f.read((char *)&size, sizeof(size));
  data = new char[size + 1];
  f.read(data, size);
  data[size] = '\0';
  name = data;
  delete[] data;

  f.read((char *)&size, sizeof(size));
  data = new char[size + 1];
  f.read(data, size);
  data[size] = '\0';
  address = data;
  delete[] data;

  f.read((char *)&size, sizeof(size));
  accounts = std::vector<Account>(size);
  f.read((char *)&accounts[0], size * sizeof(Account));
}
