#include <iostream>
#include <string>

#include "Customer.h"

using namespace std;

//Initialize the class
Customer::Customer()
{
    id = "";
    name = "";
    address = "";
    phone = "";
    email = "";
}

//Initialize the class with parameters id and name
Customer::Customer(string c_id, string c_name)
{
    id = c_id;
    name = c_name;
}

//Return customer id
string Customer::get_id()
{
    return id;
}

//Return customer name
string Customer::get_name()
{
    return name;
}

//Return customer address
string Customer::get_address()
{
    return address;
}

//Return customer phone number
string Customer::get_phone()
{
    return phone;
}

string Customer::get_email()
{
    return email;
}

//Print out customer information
void Customer::viewInfo()
{
    cout << "Customer id: " << id << endl;
    cout << "Customer name: " << name << endl;
    cout << "Customer address: " << address << endl;
    cout << "Customer phone: " << phone << endl;
    cout << "Customer email: " << email << endl;
    cout << "-------------------------------------------" << endl;
}

//Add bank accounts to customer
void Customer::addAccount(Account* acc)
{
    acc_list.push_back(acc);
}


//Count how many account the customer owns
int Customer::count_acc()
{
    cout << "Number accounts of customer "<< id <<"-"<< name <<": " << acc_list.size() << endl;
    cout << "-------------------------------------------" << endl;
    return acc_list.size();
}

//Set the customer address
void Customer::set_address(string addr)
{
    address = addr;
}

//Set the customer email
void Customer::set_email(string e_mail)
{
    email = e_mail;
}

//Set the customer phone number
void Customer::set_phone(string fone)
{
    phone = fone;
}

