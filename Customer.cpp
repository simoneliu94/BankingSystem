#include <iostream>
#include <string>

#include "Customer.h"

using namespace std;

Customer::Customer()
{
    id = "";
    name = "";
    address = "";
    phone = "";
    email = "";
}

Customer::Customer(string c_id, string c_name)
{
    id = c_id;
    name = c_name;
}

string Customer::get_id()
{
    return id;
}

string Customer::get_name()
{
    return name;
}

string Customer::get_address()
{
    return address;
}

string Customer::get_phone()
{
    return phone;
}

string Customer::get_email()
{
    return email;
}

void Customer::viewInfo()
{
    cout << "Customer id: " << id << endl;
    cout << "Customer name: " << name << endl;
    cout << "Customer address: " << address << endl;
    cout << "Customer phone: " << phone << endl;
    cout << "Customer email: " << email << endl;
    cout << "-------------------------------------------" << endl;
}

void Customer::addAccount(Account* acc)
{
    acc_list.push_back(acc);
}


int Customer::count_acc()
{
    cout << "Number accounts of customer "<< id <<"-"<< name <<": " << acc_list.size() << endl;
    cout << "-------------------------------------------" << endl;
    return acc_list.size();
}

void Customer::set_address(string addr)
{
    address = addr;
}

void Customer::set_email(string e_mail)
{
    email = e_mail;
}

void Customer::set_phone(string fone)
{
    phone = fone;
}

