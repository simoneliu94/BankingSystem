#ifndef CHECKING_H
#define CHECKING_H

#include "Customer.h"
#include "Account.h"

using namespace std;


class Checking:public Account
{
    public:
        Checking();
        Checking(string a_id, double a_bal, string a_date, Customer a_cus);
        void monthly_fee();

    protected:

    private:
        double charge_rate;
};

#endif // CHECKING_H
