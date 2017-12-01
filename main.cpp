/*
Author: Y Liu (Simone)
Project: C++ Banking System
*/

#include <vector>
#include <iostream>
#include <string>


#include "Customer.h"
#include "Account.h"
#include "Checking.h"
#include "Saving.h"
#include "BusinessChecking.h"
#include "BusinessSaving.h"
#include "Credit.h"

using namespace std;

int main()
{
    cout << "Written by Y Liu" << endl;
    cout << "Welcome to Liu's Banking System" << endl;
    cout << "-------------------------------------------" << endl;

    //Creates a customer
    //To create a customer, the account should have at least ID and Name, the account can also have address, phone and email
    Customer c1("12345", "Simone");
    c1.set_address("123 Market St.");
    c1.set_phone("910-000-1234");
    c1.set_email("simone@gmail.com");

    Customer c2("77488", "Will");
    c2.set_address("456 College St.");
    c2.set_phone("808-000-0001");
    c2.set_email("will@gmail.com");

    //Views customers' information
    c1.viewInfo();
    c2.viewInfo();

    //Creates different types of accounts
    //To create a Checking, Saving, Business account, the account should have at least ID, balance, limit, opening date, and a customer
    //To create a Credit account, the account should have at least ID, balance, limit, opening date, and a customer
    Checking checking1("C123", 127.25, "2017-11-26", c1);
    Checking checking2("C489", 85.55, "2017-11-22", c1);
    Saving saving3("S4811", 1000, "2017-11-20", c1);
    BusinessChecking b_checking1("BC1234", 2850, "2017-10-18",c2);
    BusinessSaving b_saving1("BS4841",12500,"2017-12-01",c2);
    Credit credit1("CRE123", 0, 5000, "2017-01-30", c2);

    //Views the accountID, balance and opening date
    checking1.view_account();
    checking2.view_account();
    saving3.view_account();
    b_checking1.view_account();
    b_saving1.view_account();
    credit1.view_account();

    //Adds accounts to the customers
    c1.addAccount(&checking1);
    c1.addAccount(&checking2);
    c1.addAccount(&saving3);
    c2.addAccount(&b_checking1);
    c2.addAccount(&b_saving1);
    c2.addAccount(&credit1);

    //Counts the number of accounts that the customer has
    c1.count_acc();
    c2.count_acc();

    //Add customers to Customers array
    vector<Customer> Customers;
    Customers.push_back(c1);

    //Add bank accounts to Accounts array
    vector<Account> Accounts;
    Accounts.push_back(checking1);

    //Links checking account to saving account
    checking1.link_saving(saving3);

    //Tests all the interest earnings and fees
    checking1.monthly_fee();
    saving3.daily_interest();
    b_checking1.monthly_fee();
    b_saving1.daily_interest();
    credit1.daily_interest();
    credit1.monthly_fee();

    //Tests deposit and withdraw functions
    checking1.deposit(20, "Deposit Testing");
    checking2.deposit(92.25, "More money");
    checking1.withdraw(800, "Overdraft testing");
    checking1.withdraw(215, "overdraft again");
    credit1.deposit(10, "Credit money");
    credit1.withdraw(25, "Pizza money");

    //Prints out all transactions of the selected account
    checking1.print_all_trans();
    checking2.print_all_trans();
    saving3.print_all_trans();
    b_checking1.print_all_trans();
    b_saving1.print_all_trans();
    credit1.print_all_trans();

    cout << "-------------------------------------------" << endl;
    cout << "Extra credit - Keep track of credit score every month" <<endl;
    //If customer spends less than 30% of the limit each month then add 5 points to their credit score, else deduct 1 point
    cout <<"Account "<< credit1.get_accountId()<< ". Credit score: "<<credit1.get_credit_score() << endl;
    credit1.credit_status();
}
