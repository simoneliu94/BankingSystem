#include "Account.h"

using namespace std;

Account::Account()
{
    acc_id = "";
    balance = 0;
    date = "";
    cust = Customer();
}

Account::Account(string a_id, double a_bal, string a_date, Customer a_cus)
{
    acc_id = a_id;
    balance = a_bal;
    date = a_date;
    cust = a_cus;
}

string Account::get_accountId()
{
    return acc_id;
}

double Account::get_balance()
{
    return balance;
}

string Account::get_date()
{
    return date;
}

Customer Account::get_customerAcc()
{
    return cust;
}

void Account::view_account()
{
    cout << "Account id: " << acc_id << endl;
    cout << "Account balance: $" << balance << endl;
    cout << "Opening date: " << date << endl;
    cout << "-------------------------------------------" << endl;
}

void Account::view_customer()
{
    cust.viewInfo();
}

void Account::deposit(double amt, string des)
{
    balance = balance + amt;
    string trans = "Account " + acc_id + ". Deposited $"+ to_string(amt)+". Current balance $"+to_string(balance) + ". Note: " + des;
    keep_transaction(trans);
}

void Account::withdraw(double amt, string des)
{
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

void Account::keep_transaction(string trans)
{
    list_trans.push_back(trans);
}

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


