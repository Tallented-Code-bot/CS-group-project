#include "Account.cpp"
#include "Account.h"
#include "Bank.cpp"
#include "Bank.h"
#include "CertificateDeposit.h"
#include "Checking.h"
#include "Customer.cpp"
#include "Customer.h"
#include "MoneyMarket.h"
#include "Savings.h"
#include "Util.cpp"
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

// Clears the screen
void clearScreen() {
  // This ANSI code clears the screen.
  cout << "\033[2J\033[1;1H";
}

// Prints the main menu
int printMainMenu() {

  while (true) {
    clearScreen();
    cout << "(1) Add customer\n";
    cout << "(2) Select customer\n";
    cout << "(3) View overview\n";
    cout << "(4) Quit\n";
    int selected;
    cin >> selected;

    if (selected > 0 && selected <= 4) {
      return selected;
    }
  }
}

// The dialog to add a customer
Customer addCustomer() {
  clearScreen();

  cout << "Add a customer:\n\n";

  string name;
  cout << "Please enter your name: ";
  getline(cin, name);

  string address;
  cout << "Please enter your address: ";
  getline(cin, address);

  Customer c(name, address);

  cout << "\n\nAdding customer " << c.getName() << " living at "
       << c.getAddress() << ".";

  return c;
}

Account addAccount() {

  int selection;
  while (true) {
    clearScreen();

    cout << "Add an account:\n\n";

    cout << "(1) Checkings\n";
    cout << "(2) Savings\n";
    cout << "(3) CD\n";
    cout << "(4) MoneyMarket\n";
    cin >> selection;
    if (selection >= 1 && selection <= 4) {
      break;
    }
  }

  int balance;
  cout << "What is the starting balance: ";
  cin >> balance;

  // TODO Replace these zeros

  Account a;
  switch (selection) {
  case 1:
    a = Checking(balance, 0);
    break;
  case 2:
    a = Savings(balance, 0, 0);
    break;
  case 3:
    a = CertificateDeposit(balance, 0, 0, 0);
    break;
  case 4:
    a = MoneyMarket(balance, 0, 0, 0);
    break;
  }

  return a;
}

// Create the menu to select a customer
int selectCustomer(vector<Customer> users) {
  while (true) {
    clearScreen();
    cout << "Select customer: \n";

    for (int i = 0; i < users.size(); i++) {
      cout << "(" << (i + 1) << ") " << users[i].getName() << "\n";
    }

    int selection;
    cin >> selection;

    if (selection >= 1 && selection <= users.size()) {
      return selection - 1;
    }
  }
}

// Create the menu to select an account
int selectAccount(vector<Account> accounts) {
  if (accounts.size() == 0) {
    return -1;
  }
  while (true) {
    clearScreen();
    cout << "Select account: \n";

    for (int i = 0; i < accounts.size(); i++) {
      cout << "(" << (i + 1) << ") " << accounts[i].getName() << ": $"
           << accounts[i].getBalance() << "\n";
    }

    int selection;
    cin >> selection;

    if (selection >= 1 && selection <= accounts.size()) {
      return selection - 1;
    }
  }
}

void accountMenu(Customer &c, int accountId) {
  if (accountId == -1) {
    return;
  }
  while (true) {
    clearScreen();
    cout << c.getAccount(accountId).getName() << " ($"
         << c.getAccount(accountId).getBalance() << "):\n\n";

    cout << "(1) Deposit to account\n";
    cout << "(2) Withdraw from account\n";
    cout << "(3) Delete account\n";
    cout << "(4) Go home\n";

    int selection;
    cin >> selection;

    switch (selection) {
    case 1: // deposit
    {
      clearScreen();
      cout << "How much to deposit: ";
      float a;
      cin >> a;

      Account account = c.getAccount(accountId);
      account.deposit(a);

      c.setAccount(accountId, account);

      break;
    }
    case 2: // withdraw
    {
      clearScreen();
      cout << "How much to withdraw: ";
      float b;
      cin >> b;

      Account account = c.getAccount(accountId);
      account.withdraw(b);
      c.setAccount(accountId, account);

      break;
    }
    case 3: // Delete account
      c.deleteAccount(accountId);
      return;
    case 4: // Go home
      return;
    }
  }
}

void customerMenu(Bank &b, int customerId) {
  while (true) {
    clearScreen();
    cout << b.getUser(customerId).getName() << ":\n\n";

    cout << "(1) Add account\n";
    cout << "(2) Select account\n";
    cout << "(3) Delete user\n";
    cout << "(4) Go home\n";

    int selection;
    cin >> selection;

    switch (selection) {
    case 1: // Add account
    {

      Customer user = b.getUser(customerId);

      user.addAccount(addAccount());
      b.setUser(customerId, user);
      break;
    }
    case 2: // Select account
    {
      Customer user = b.getUser(customerId);
      accountMenu(user, selectAccount(b.getUser(customerId).getAccounts()));
      b.setUser(customerId, user);
      break;
    }
    case 3: // Delete user
      b.deleteUser(customerId);
      return;
    case 4: // Go home
      return;
    }
  }
}

// Shows the overview of the bank
void printOverview(Bank &b) {
  clearScreen();

  vector<Customer> users = b.getUsers();
  sort(users.begin(), users.end());

  for (Customer user : users) {
    cout << user.getName() << "\n";

    vector<Account> accounts = user.getAccounts();
    sort(accounts.begin(), accounts.end());

    for (Account account : accounts) {
      cout << "    " << account.getName() << ": " << account.getBalance()
           << "\n";
    }
  }

  string temp;
  cout << "Type anything to continue...\n";
  cin >> temp;
}

int main() {
  Bank b;

  Customer c("Calvin Tallent", "409 Cherry Blossom Loop");
  c.addAccount(Checking(500, 0));
  c.addAccount(Savings(500, 0, 0));

  b.addUser(c);
  b.addUser(Customer("Austin Tallent", "409 Cherry Blossom Loop"));
  b.addUser(Customer("Iain Tallent", "409 Cherry Blossom Loop"));

  std::ofstream file("file.bin");
  b.getUser(0).write(file);
  file.close();

  while (true) {
    int mainSelected = printMainMenu();
    cout << mainSelected << "\n";

    switch (mainSelected) {
    case 1: // Add user
      b.addUser(addCustomer());
      break;
    case 2: // Select user
      customerMenu(b, selectCustomer(b.getUsers()));
      break;
    case 3: // view overview
      printOverview(b);
      break;
    case 4: // quit
      return 0;
    }
  }

  return 0;
}
