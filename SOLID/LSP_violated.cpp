/*
LSP stands for Liskov substution principle, subclass should be substitutable  for their base class.
example: A(base class) ----> B(sub class). if a client is demanding class A but it should work even if class B's reference is passed.
that means when we are using a base class reference, we should be able to use any of its subclass objects without breaking the functionality of the program. like if class B is inheriting class A, then it must have all the properties and methods of class A, and additionally it can have its own properties and methods. but if class B is not able to do that, then it is violating LSP.
*/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Account {
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

class SavingAccount:public Account{
private:
    double balance;

public:
    SavingAccount(){
        balance=0;
    }

    void deposit(double amount){
        balance+=amount;
        cout<<"Deposited: "<<amount<<" in savings account, New balance: "<<balance<<endl;
    };

    void withdraw(double amount){
        if(balance>=amount){
            balance-=amount;
            cout<<"withdrawn: "<<amount<<" from Savings account, New balance: "<<balance<<endl;
        } else {
            cout<<"insufficient balance in your account to withdrawn the entered amount."<<endl;
        };
    };
};


class CurrentAccount : public Account{
    private:
    double balance;

public:
    CurrentAccount(){
        balance=0;
    }

    void deposit(double amount){
        balance+=amount;
        cout<<"Deposited: "<<amount<<" in savings account, New balance: "<<balance<<endl;
    };

    void withdraw(double amount){
        if(balance>=amount){
            balance-=amount;
            cout<<"withdrawn: "<<amount<<" from Savings account, New balance: "<<balance<<endl;
        } else {
            cout<<"insufficient balance in your account to withdrawn the entered amount."<<endl;
        };
    };
};

class FixedAccount : public Account{
    private:
    double balance;

public:
    FixedAccount(){
        balance=0;
    }

    void deposit(double amount){
        balance+=amount;
        cout<<"Deposited: "<<amount<<" in savings account, New balance: "<<balance<<endl;
    };

    void withdraw(double amount){
        throw logic_error("Withdrawal not allowed in fixed term account!!");
    };
};

class BankClient {
private:
    vector<Account*> accounts;
public:
    BankClient(vector<Account*>accounts){
        this->accounts = accounts;
    };

    void processTransactions(){
        for(Account* acc:accounts){
            acc->deposit(1000); // all accounts allow deposits


            // assuming all accounts support withdrawal (LSP violation)
            try {
                acc->withdraw(500);
            } catch(const logic_error& e){
                cout<<"Exception: "<<e.what()<<endl;
            }
        }
    }
};

int main(){
    vector<Account*> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedAccount());

    BankClient* client = new BankClient(accounts);
    client->processTransactions(); // Throws exception when withdrawing from fixedtermaccount
    return 0;
}