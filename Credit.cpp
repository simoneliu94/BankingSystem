#include "Credit.h"

using namespace std;

Credit::Credit()
{

}

Credit::Credit(string a_id, double a_bal, string a_date, Customer a_cus):Account(a_id, a_bal, a_date, a_cus)
{

}


void Credit::daily_charge()
{
    interest_rate = 0.08/365;
    balance = balance - interest_rate;
}

void Credit::trans_charge(double amt)
{
    trans_fee = 0.3;
}

void Credit::zeroBal_charge()
{
    if(balance=0)
    {
        balance = balance - 25;
    }
}

void Credit::monthly_due()
{
    min_due = balance * 0.0025;
    balance = balance - min_due;
}
