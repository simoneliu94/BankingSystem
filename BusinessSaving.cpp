#include "BusinessSaving.h"

using namespace std;


BusinessSaving::BusinessSaving()
{

}

//Create a business saving account with parameters id, balance, date and customer and pass them to Account class
BusinessSaving::BusinessSaving(string a_id, double a_bal, string a_date, Customer &a_cus):Account(a_id, a_bal, a_date, a_cus)
{

}

//Override the daily_interest function from Account class
//If the balance has more than $10,000 then earn 5% daily compounded interest to the account
void BusinessSaving::daily_interest()
{
    if(balance>=10000)
    {
        interest_rate = 0.05/365;
        balance = balance + interest_rate;
        string trans = "Account " + acc_id + ". Daily earn rate $" + to_string(interest_rate)+". Current balance: $"+to_string(balance);
        keep_transaction(trans);
    }
    else
    {
        cout << "Account "<< acc_id<< " has less than $10,000"<<". No interest earned" << endl;
        cout << "-------------------------------------------" << endl;
    }

}
