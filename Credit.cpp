#include "Credit.h"

using namespace std;

Credit::Credit()
{

}

Credit::Credit(string a_id, double a_bal, double lim, string a_date, Customer &a_cus):Account(a_id, a_bal, a_date, a_cus)
{
    limit = lim;
}

void Credit::deposit(double amt, string des)
{
    balance = balance - amt;
    trans_charge();
    string trans = "Account " + acc_id + ". Deposited $"+ to_string(amt)+". Current balance $"+to_string(balance) + ". Note: " + des;
    keep_transaction(trans);
}

void Credit::withdraw(double amt, string des)
{
    if(amt <= limit)
    {
        balance = balance + amt;
        trans_charge();
        string trans = "Account " + acc_id + ". Withdrew $"+ to_string(amt)+". Current balance $"+to_string(balance) + ". Note: " + des;
        keep_transaction(trans);
    }
    else
    {
        cout <<"Account "<< acc_id<< ". Insufficient funds to withdraw" << endl;
        cout << "-------------------------------------------" << endl;
    }
}

void Credit::daily_interest()
{
    interest_rate = 0.08/365;
    balance = balance + interest_rate;
    string trans = "Account " + acc_id + ". Daily charge rate $" + to_string(interest_rate)+". Current balance: $"+to_string(balance);
    keep_transaction(trans);
}

void Credit::trans_charge()
{
    trans_fee = 0.3;
    balance = balance + trans_fee;

}

void Credit::zeroBal_charge()
{
    if(balance==0)
    {
        balance = balance + 25;
    }
}

void Credit::monthly_fee()
{
    min_due = balance * 0.0025;
    balance = balance + min_due;
    string trans = "Account " + acc_id + ". Minimum due this month $" + to_string(min_due)+". Current balance: $"+to_string(balance);
    keep_transaction(trans);
}
