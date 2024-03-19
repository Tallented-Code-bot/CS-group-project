#include "CertificateDeposit.h"
#include "Account.cpp"
#include "Account.h"
#include "Checking.h"
#include "MoneyMarket.h"
#include "Savings.h"
#include <iostream>

int main() {
  std::string name, address;
  float balance, monthly_interest, amount;
  int term;
  float withdrawal_penalty, maturity_penalty;

  // Get customer details from user input
  std::cout << "Enter customer's name: ";
  std::getline(std::cin, name);
  std::cout << "Enter customer's address: ";
  std::getline(std::cin, address);

  // Create a Customer object with user-provided details
  Customer customer(name, address);

  // Get initial account details from user input
  std::cout << "Enter initial balance: ";
  std::cin >> balance;
  std::cout << "Enter monthly interest rate: ";
  std::cin >> monthly_interest;

  // Create instances of different account types using user-provided details
  CertificateDeposit cd(customer, balance, monthly_interest, 12, 20.0f);
  Checking checking(customer, balance, monthly_interest);
  MoneyMarket mm(customer, balance, monthly_interest, 15.0f, 50.0f);
  Savings savings(customer, balance, monthly_interest, 10.0f);

  // Perform deposit operation for Checking account
  std::cout << "Enter amount to deposit into Checking account: ";
  std::cin >> amount;
  checking.deposit(amount);

  // Perform withdraw operation for Savings account
  std::cout << "Enter amount to withdraw from Savings account: ";
  std::cin >> amount;
  savings.withdraw(amount);

  // Display account balances after operations
  std::cout << "Hello " << customer.getName() << ", your balances:\n";
  std::cout << "Certificate Deposit: $" << cd.getBalance() << std::endl;
  std::cout << "Checking Account: $" << checking.getBalance() << std::endl;
  std::cout << "Money Market: $" << mm.getBalance() << std::endl;
  std::cout << "Savings Account: $" << savings.getBalance() << std::endl;

  return 0;
}
