#include "Saving.h"
#include "time.h"

using namespace std;


Saving::Saving()
{

}

Saving::Saving(string a_id, double a_bal, string a_date, Customer a_cus):Account(a_id, a_bal, a_date, a_cus)
{

}


void Saving::daily_interest()
{
    interest_rate = 0.05/365;
    balance = balance + interest_rate;
    string trans = "Account " + acc_id + ". Daily earn rate $" + to_string(interest_rate)+". Current balance: $"+to_string(balance);
    keep_transaction(trans);
}



