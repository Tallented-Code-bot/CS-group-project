# CS Group Project

([Link to Github](https://github.com/Tallented-Code-bot/CS-group-project))






## UML Diagram

``` mermaid
classDiagram
    class Bank{
        - users: list~Customer~
        - filename: string
        - penaltiesLastProcessed: time_point
        + addUser(Customer)
        + getUsers() list~Customer~
        + getUser(int) Customer
        + deleteUser(int)
        + setUser(int, Customer)
        + write(ostream &)
        + read(istream &)
        + save()
        + processPenalties()
        + getPenaltiesLastProcessed() time_point
    }



    class Account{
        # balance: float
        # monthly_interest: float
        + virtual deposit(float) Transaction
        + virtual withdraw(float) Transaction

        + getBalance() float
        + getName() string
        + getType() AccountType

        + write(ostream &)
        + read(istream &)

        + operator~(Account) bool

        + processPenalties(&Transaction,\n &PriorityQueueWrapper~Transaction~)
    }

    class AccountType{
    ~~enumeration~~
    + GENERIC_ACCOUNT
    + CERTIFICATE_DEPOSIT
    + CHECKING
    + MONEYMARKET
    + SAVINGS
    }



    class Customer{
        - name: string
        - address: string
        - accounts: list~Account *~
        - transactions: PriorityQueueWrapper~Transaction~

        + getName() string
        + getAddress() string
        + setName(string)
        + setAddress(string)

        + addAccount(Account)
        + getAccounts() &list~Account~
        + getAccount(int) &Account
        + deleteAccount(int)

        + getTransactions() &PriorityQueueWrapper~Transaction~

        + withdraw(int, float)
        + deposit(int, float)

        + netWorth() float

        + write(ostream &)
        + read(istream &)
    }


    class Checking{
        + getName() string
        + getType() AccountType

        + write(ostream &)
        + read(istream &)

        + processPenalties(&Transaction,\n &PriorityQueueWrapper~Transaction~)
    }

    class Savings{
        - withdrawal_penalty: float
        + getName() string
        + getType() AccountType

        + write(ostream &)
        + read(istream &)

        + processPenalties(&Transaction,\n &PriorityQueueWrapper~Transaction~)
    }



    class CD{
        - months: int
        - withdrawal_penalty: float

        + getName() string
        + getType() AccountType

        + write(ostream &)
        + read(istream &)

        + processPenalties(&Transaction,\n &PriorityQueueWrapper~Transaction~)
    }

    class MoneyMarket{
        - withdrawal_penalty: float
        - maturity_penalty: float

        + getName() string
        + getType() AccountType

        + write(ostream &)
        + read(istream &)

        + processPenalties(&Transaction,\n &PriorityQueueWrapper~Transaction~)
    }


    class Transaction{
        - date: time_point
        - accountIndex: size_t
        - type: TransactionType
        - amount: float
        - shouldProcess: bool

        + getAmount() float
        + getIndex() size_t
        + getType() TransactionType
        + getDatetime() time_point
        + getShouldProcess() bool

        + setAmount(float)
        + setIndex(int)
        + setType(TransactionType)
        + setDatetime(time_point)

        + process()

        + operator~(Transaction) bool
        + operator~(Transaction) bool
        + operator==(Transaction) bool

        + write(&ostream)
        + read(&istream)
    }

    class TransactionType{
    ~~enumerate~~
    + DEBIT
    + CREDIT
    }



    Checking --|> Account
    Savings --|> Account
    Account <|-- CD
    Account <|-- MoneyMarket
    Customer *-- Account
    Customer *-- Transaction
    Bank *-- Customer
    Account *-- AccountType
    TransactionType --* Transaction

```
