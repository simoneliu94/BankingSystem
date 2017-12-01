#ifndef BUSINESSSAVING_H
#define BUSINESSSAVING_H

#include "Customer.h"
#include "Account.h"

using namespace std;

//Initialize the class, functions and variables
//Inherited from Account class
class BusinessSaving:public Account
{
public:
    BusinessSaving();
    BusinessSaving(string a_id, double a_bal, string a_date, Customer &a_cus);
    void daily_interest();

protected:

private:
    double interest_rate;
};


#endif // BUSINESSSAVING_H
