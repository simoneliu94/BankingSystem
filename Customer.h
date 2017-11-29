#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Account;

class Customer
{
public:
    Customer();
    Customer(string id, string name);
    string get_id();
    string get_name();
    string get_address();
    string get_phone();
    string get_email();
    int count_acc();
    void viewInfo();
    void addAccount(Account* acc);
    void set_address(string addr);
    void set_phone(string fone);
    void set_email(string e_mail);
private:
    string id;
    string name;
    string address;
    string phone;
    string email;
    list<Account*> acc_list;
    Account* acc;
    int num_acc;
};

#endif // CUSTOMER_H
