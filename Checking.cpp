#include "Checking.h"
#include "ctime"


using namespace std;

Checking::Checking()
{
    charge_rate = 18;
}

Checking::Checking(string a_id, double a_bal, string a_date, Customer a_cus):Account(a_id, a_bal, a_date, a_cus)
{
    charge_rate = 18;
}

void Checking::monthly_fee()
{
    balance = balance - charge_rate;
    string trans = "Account " + acc_id + ". Monthly charge rate $" + to_string(charge_rate)+". Current balance: $"+to_string(balance);
    keep_transaction(trans);
}



