#ifndef CREDIT_H
#define CREDIT_H

#include "Customer.h"
#include "Account.h"

class Credit:public Account
{
    public:
        Credit();
        Credit(string a_id, double a_bal, string a_date, Customer a_cus);
        virtual void daily_charge();
        virtual void trans_charge(double amt);
        virtual void zeroBal_charge();
        virtual void monthly_due();


    protected:

    private:
        double interest_rate;
        double min_due;
        double trans_fee;
};

#endif // CREDIT_H
