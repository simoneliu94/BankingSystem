#ifndef SAVING_H
#define SAVING_H

#include "Customer.h"
#include "Account.h"

using namespace std;

//Initialize the class, functions and variables
//Inherited from Account class
class Saving:public Account
{
public:
    Saving();
    Saving(string a_id, double a_bal, string a_date, Customer &a_cus);
    void daily_interest();

protected:

private:
    double interest_rate;
};

#endif // CHECKING_H
