# Bank Account Classes README

## Question
- Define the class bankAccount as an ADT to implement the basic
properties of a bank account. An object of this class should store the 
following data:
- Account holder’s name (string), account number (int), account type
(string, checking/saving), balance (double), and interest rate (double).
- (Store interest rate as a decimal number.) Add appropriate member
functions to manipulate an object (they should include a function to 
- check balance, withdraw, deposit and transfer to other accounts). Use a 
static member in the class to automatically assign account numbers.
- Also declare an array of 10 components of type bankAccount to 
process up to 10 customers and write a program to illustrate how to 
- use your class. Include a constructor and destructor in your program
Q2.
`Inheritance and Composition`
- a. Define the class bankAccount to store a bank customer’s account
number and balance. Suppose that account number is of type int, and
- balance is of type double. Your class should, at least, provide the
following operations: set the account number, retrieve the account
- number, retrieve the balance, deposit and withdraw money, and print
account information. Add appropriate constructors. b. Every bank offers a checking account. Derive the class
- checkingAccount from the class bankAccount (designed in part
- (a)). This class inherits members to store the account number and
- the balance from the base class. A customer with a checking
account typically receives interest, maintains a minimum balance, and pays service charges if the balance falls below the minimum
- balance. Add member variables to store this additional information. In addition to the operations inherited from the base class, this class
should provide the following operations: set interest rate, retrieve
- interest rate, set minimum balance, retrieve minimum balance, set
service charges, retrieve service charges, post interest, verify if the
- balance is less than the minimum balance, write a check, withdraw
(override the method of the base class), and print account information. Add appropriate constructors. c. Every bank offers a savings account. Derive the class
- savingsAccount from the class bankAccount (designed in part
- (a)). This class inherits members to store the account number and
the balance from the base class. A customer with a savings account
- typically receives interest, makes deposits, and withdraws money. In
addition to the operations inherited from the base class, this class
- should provide the following operations: set interest rate, retrieve
interest rate, post interest, withdraw (override the method of the base
- class), and print account information. Add appropriate constructors. d. Write a program to test your classes designed in parts (b) and
(c)

## bankAccount Class

The `bankAccount` class represents the basic properties of a bank account. An object of this class stores the following data:
- Account holder’s name (string)
- Account number (int)
- Account type (string, checking/saving)
- Balance (double)
- Interest rate (double, stored as a decimal number)

### Class Definition

#### bankAccount

The `bankAccount` class has the following attributes:
- `account_holder` (str): Account holder's name.
- `account_number` (int): Account number.
- `account_type` (str): Account type (checking/saving).
- `balance` (float): Current balance.
- `interest_rate` (float): Interest rate as a decimal number.

The class provides the following methods:
- `__init__(self, account_holder, account_type, balance=0.0, interest_rate=0.0)`: Constructor to initialize the `bankAccount` object.
- `check_balance(self)`: Method to check the current balance.
- `withdraw(self, amount)`: Method to withdraw money from the account.
- `deposit(self, amount)`: Method to deposit money into the account.
- `transfer(self, recipient, amount)`: Method to transfer money to another account.
- `__str__(self)`: Method to return a string representation of the `bankAccount` object.

## checkingAccount Class (Derived from bankAccount)

The `checkingAccount` class is derived from the `bankAccount` class. It inherits members to store the account number and balance from the base class.

### Class Definition

#### checkingAccount

The `checkingAccount` class has additional attributes:
- `min_balance` (float): Minimum balance required.
- `service_charge` (float): Service charge for falling below the minimum balance.

In addition to the methods inherited from the base class, `checkingAccount` provides the following methods:
- `verify_min_balance(self)`: Method to check if the balance is less than the minimum balance.
- `write_check(self, amount)`: Method to write a check.
- `withdraw(self, amount)`: Overridden method to include service charges.
- `__str__(self)`: Overridden method to return a string representation of the `checkingAccount` object.

## savingsAccount Class (Derived from bankAccount)

The `savingsAccount` class is derived from the `bankAccount` class. It inherits members to store the account number and balance from the base class.

### Class Definition

#### savingsAccount

In addition to the methods inherited from the base class, `savingsAccount` provides the following methods:
- `withdraw(self, amount)`: Overridden method to include restrictions for a savings account.
- `__str__(self)`: Overridden method to return a string representation of the `savingsAccount` object.

## Sample Program

A sample program is included to illustrate how to use the `bankAccount`, `checkingAccount`, and `savingsAccount` classes. The program creates instances of these classes and performs various operations, such as withdrawal, deposit, writing checks, and printing account information.

Feel free to customize the classes and the sample program according to your needs.
