# CS Group Project

([Link to Github](https://github.com/Tallented-Code-bot/CS-group-project))

This is the CS 162 group project, by Calvin Tallent and Dimitriy Shvets.




## UML Diagram

``` mermaid
classDiagram
    class Bank{
       + users: vector~Customer~
       + addUser(Customer): void
    }
    


    class Account{
        + balance: float
        + monthly_interest: float
        + virtual deposit(float amount): void
        + virtual withdraw(float amount): void
    }



    class Customer{
        + name: string
        + address: string
        + accounts: vector~Account~
    }


    class Checking{

    }

    class Savings{
        + withdrawal_penalty: float
    }



    class CD{
        + term: int
        + withdrawal_penalty: float
    }

    class MoneyMarket{
        + withdrawal_penalty: float
        + maturity_penalty: float
    }



    Account <|-- Checking
    Account <|-- Savings
    Account <|-- CD
    Account <|-- MoneyMarket
    Customer *-- Account

```
