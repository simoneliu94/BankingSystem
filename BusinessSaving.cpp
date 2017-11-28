#include "BusinessSaving.h"

using namespace std;


BusinessSaving::BusinessSaving()
{

}

BusinessSaving::BusinessSaving(string a_id, double a_bal, string a_date, Customer a_cus):Account(a_id, a_bal, a_date, a_cus)
{

}


void BusinessSaving::daily_earn()
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
