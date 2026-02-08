#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class DepositOnlyAccount {
    public:
    virtual void deposit(double amount) = 0;
};

class WithdrawableAccout : public DepositOnlyAccount{
    public:
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public WithdrawableAccout{
    private:
        double balance;
    public:
        SavingAccount(){
            balance=0;
        };

        void deposit(double amount){
            balance+=amount;
            cout<<"Deposited: "<<amount<<" in savings account, New balance: "<<balance<<endl;
        }

        void withdraw(double amount){
            if(balance>=amount){
                balance-=amount;
                cout<<"Withdrawn: "<<amount<<" from savings amount, New Balance: "<< balance<<endl;
            } else {
                cout<<"insufficient balance to withdrawn "<<amount<<endl;
            };
        };
};

class CurrentAccount : public WithdrawableAccout{
        private:
        double balance;
    public:
        CurrentAccount(){
            balance=0;
        };

        void deposit(double amount){
            balance+=amount;
            cout<<"Deposited: "<<amount<<" in current account, New balance: "<<balance<<endl;
        }

        void withdraw(double amount){
            if(balance>=amount){
                balance-=amount;
                cout<<"Withdrawn: "<<amount<<" from current amount, New Balance: "<< balance<<endl;
            } else {
                cout<<"insufficient balance to withdrawn "<<amount<<endl;
            };
        };
};

class FixedTermAccount : public DepositOnlyAccount{
    private:
        double balance;
    public:
        FixedTermAccount(){
            balance = 0;
        };
        void deposit(double amount){
            balance+=amount;
            cout<<"deposited: "<<amount<<" in fixed term account, New balance: "<<balance<<endl;
        }
};

class BankClient{
    private:
        vector<WithdrawableAccout*> WithdrawableAccouts;
        vector<DepositOnlyAccount*> DepositOnlyAccouts;
    public:
        BankClient(vector<WithdrawableAccout*> WithdrawableAccouts, vector<DepositOnlyAccount*> DepositOnlyAccouts){
            this->WithdrawableAccouts = WithdrawableAccouts;
            this->DepositOnlyAccouts = DepositOnlyAccouts;
        };
        void processTransactions(){
            for(WithdrawableAccout* account: WithdrawableAccouts){
                account->deposit(1000);
                account->withdraw(500);
            }
            for(DepositOnlyAccount* account: DepositOnlyAccouts){
                account->deposit(1000);
            }
        };
};

int main(){
    vector<WithdrawableAccout*> WithdrawableAccouts;
    WithdrawableAccouts.push_back(new SavingAccount());
    WithdrawableAccouts.push_back(new CurrentAccount());

    vector<DepositOnlyAccount*> DepositOnlyAccounts;
    DepositOnlyAccounts.push_back(new FixedTermAccount());

    BankClient* client = new BankClient(WithdrawableAccouts, DepositOnlyAccounts);
    client->processTransactions();

    return 0;
}
