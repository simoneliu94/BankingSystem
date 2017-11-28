#include "BusinessChecking.h"

using namespace std;

BusinessChecking::BusinessChecking()
{
    charge_rate = 14;
}

BusinessChecking::BusinessChecking(string a_id, double a_bal, string a_date, Customer a_cus):Account(a_id, a_bal, a_date, a_cus)
{
    charge_rate = 14;
}

void BusinessChecking::monthly_charge()
{
    if(balance<3000)
    {
        balance = balance - charge_rate;
        string trans = "Account " + acc_id + ". Monthly charge rate $" + to_string(charge_rate)+". Current balance: $"+to_string(balance);
        keep_transaction(trans);
    }
    else
    {
        cout << "Account " << acc_id<< " has more than $3,000. "<<"No monthly charged" << endl;
        cout << "-------------------------------------------" << endl;
    }
}
