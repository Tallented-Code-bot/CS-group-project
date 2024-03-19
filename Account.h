

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
protected:
  float balance;
  float monthly_interest;

public:
  // Constructor with default values for balance and monthly_interest
  Account(float balance = 0.0f, float monthly_interest = 0.0f)
      : balance(balance), monthly_interest(monthly_interest) {}

  // Virtual functions for deposit and withdraw operations
  virtual void deposit(float amount);
  virtual void withdraw(float amount);

  // Accessor methods for balance and name
  float getBalance() const { return balance; }
  virtual std::string getName();

  bool operator<(Account other) { return balance < other.balance; }

  void write(std::ostream &f);
  void read(std::istream &f);
};

#endif
