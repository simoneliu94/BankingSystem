#include "Account.h"

using namespace std;

//Initialize the class
Account::Account()
{
    acc_id = "";
    balance = 0;
    date = "";
    limit = 0;
}

//Initialize the class
Account::Account(string a_id, double a_bal, string a_date, Customer &a_cus)
{
    acc_id = a_id;
    balance = a_bal;
    date = a_date;
    cust = &a_cus;
}

//Return the account id
string Account::get_accountId()
{
    return acc_id;
}

//Return the account balance
double Account::get_balance()
{
    return balance;
}

//Return the opening date
string Account::get_date()
{
    return date;
}

//Print out the account information
void Account::view_account()
{
    cout << "Account id: " << acc_id << endl;
    cout << "Account balance: $" << balance << endl;
    cout << "Opening date: " << date << endl;
    cout << "-------------------------------------------" << endl;
}

//Print out the bank account's owner information
void Account::view_customer()
{
    cust->viewInfo();
}

//Deposit money to an account
void Account::deposit(double amt, string des)
{
    balance = balance + amt;
    string trans = "Account " + acc_id + ". Deposited $"+ to_string(amt)+". Current balance $"+to_string(balance) + ". Note: " + des;
    keep_transaction(trans);
}

//Withdraw money from an account
void Account::withdraw(double amt, string des)
{
    //Check if the account has enough money to withdraw
    if(balance >= amt)
    {
        balance = balance - amt;
        string trans = "Account " + acc_id + ". Withdrew $"+ to_string(amt)+". Current balance $"+to_string(balance) + ". Note: " + des;
        keep_transaction(trans);
    }
    else
    {
        cout <<"Account "<< acc_id<< ". Insufficient funds to withdraw" << endl;
        cout << "-------------------------------------------" << endl;
    }
}

void Account::monthly_fee()
{

}

void Account::daily_interest()
{

}

void Account::trans_charge()
{

}


void Account::zeroBal_charge()
{

}

//Keep track of all transactions
void Account::keep_transaction(string trans)
{
    list_trans.push_back(trans);
}

//Print out transactions of an account
void Account::print_all_trans()
{
    if (!list_trans.empty())
    {
        for (list<string>::iterator it=list_trans.begin(); it != list_trans.end(); ++it)
        {
            cout << *it << endl;
        }
    }

    else
    {
        cout << "Account "<< acc_id <<". No transactions have been made."<< endl;
    }

}


