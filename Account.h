#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <list>

#include "Customer.h"
using namespace std;

////Initialize the class, objects, functions and variables
class Account
{
public:
    Account();
    Account(string a_id, double a_bal, string a_date, Customer &a_cus);
    string get_accountId();
    double get_balance();
    string get_date();

    void view_account();
    void view_customer();

    virtual void deposit(double amt, string des);
    virtual void withdraw(double amt, string des);

    virtual void monthly_fee();
    virtual void daily_interest();

    virtual void trans_charge();
    virtual void zeroBal_charge();

    void keep_transaction(string trans);
    void print_all_trans();

protected:
    string acc_id;
    double balance;
    double limit;
    string date;
    Customer* cust;
    list<string> list_trans;
};

#endif // ACCOUNT_H
