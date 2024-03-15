# CS Group Project




## UML Diagram

``` mermaid
classDiagram
    class Account{
        + owner: Customer
        + balance: float
        + monthly_interest: float
        + virtual deposit(float amount): void
        + virtual withdraw(float amount): void
    }



    class Customer{
        + name: string
        + address: string
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
