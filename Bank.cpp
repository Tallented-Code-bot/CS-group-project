

#include "Bank.h"

void Bank::addUser(Customer user) { users.push_back(user); }

std::vector<Customer> Bank::getUsers() { return users; }
Customer Bank::getUser(int i) { return users[i]; }
void Bank::deleteUser(int i) { users.erase(users.begin() + i); }

void Bank::setUser(int i, Customer user) { users[i] = user; }
