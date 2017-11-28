#ifndef BUSINESSSAVING_H
#define BUSINESSSAVING_H

#include "Customer.h"
#include "Account.h"

using namespace std;

class BusinessSaving:public Account
{
    public:
        BusinessSaving();
        BusinessSaving(string a_id, double a_bal, string a_date, Customer a_cus);
        virtual void daily_earn();

    protected:

    private:
        double interest_rate;
};


#endif // BUSINESSSAVING_H
