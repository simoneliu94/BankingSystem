#ifndef BUSINESSCHECKING_H
#define BUSINESSCHECKING_H

#include "Customer.h"
#include "Account.h"

using namespace std;


class BusinessChecking:public Account
{
    public:
        BusinessChecking();
        BusinessChecking(string a_id, double a_bal, string a_date, Customer a_cus);
        virtual void monthly_charge();

    protected:

    private:
        double charge_rate;
};

#endif // BUSINESSCHECKING_H
