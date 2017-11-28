#ifndef SAVING_H
#define SAVING_H

#include "Customer.h"
#include "Account.h"

using namespace std;

class Saving:public Account
{
    public:
        Saving();
        Saving(string a_id, double a_bal, string a_date, Customer a_cus);
        virtual void daily_earn();

    protected:

    private:
        double interest_rate;
};

#endif // CHECKING_H
