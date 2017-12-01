#include "Checking.h"
#include "ctime"


using namespace std;

Checking::Checking()
{
    charge_rate = 18;
    overdraft_fee = 18;
}

//Create a checking account with parameters id, balance, date and customer and pass them to Account class
Checking::Checking(string a_id, double a_bal, string a_date, Customer &a_cus):Account(a_id, a_bal, a_date, a_cus)
{
    charge_rate = 18;
    overdraft_fee = 18;
}

//Override the monthly_fee function from Account class
//Charge $18 fees every month
void Checking::monthly_fee()
{
    balance = balance - charge_rate;
    string trans = "Account " + acc_id + ". Monthly charge rate $" + to_string(charge_rate)+". Current balance: $"+to_string(balance);
    keep_transaction(trans);
}

//Link the checking account to saving account
void Checking::link_saving(Account &saving)
{
    saving_acc = &saving;
}

//Override withdraw function from Account class
//Do overdraft here
void Checking::withdraw(double amt, string des)
{
    //If the account has enough money to withdraw from
    if(balance >= amt)
    {
        balance = balance - amt;
        string trans = "Account " + acc_id + ". Withdrew $"+ to_string(amt)+". Current balance $"+to_string(balance) + ". Note: " + des;
        keep_transaction(trans);
    }
    //If the checking account does not have enough money, withdraw the remaining funds from saving account and charge $18 fees
    else
    {
        double remaining = amt - balance;
        if (saving_acc->get_balance() >= remaining+overdraft_fee)
        {
            balance = balance - (amt - remaining);

            saving_acc->withdraw(remaining+overdraft_fee,"Remaining funds + $18 overdraft fees");
            string trans = "Account " + acc_id + ". Withdrew $"+ to_string(amt-remaining)+". Current balance $"+to_string(balance) + ". Note: " + des;

            keep_transaction(trans);
        }
        else
        {
            cout <<"Overdraft. Insufficient funds to withdraw" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
}



