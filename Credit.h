#ifndef CREDIT_H
#define CREDIT_H

#include "Customer.h"
#include "Account.h"

class Credit:public Account
{
    public:
        Credit();
        Credit(string a_id, double a_bal, string a_date, Customer a_cus);
        void deposit(double amt, string des);
        void withdraw(double amt, string des);
        void daily_interest();
        void trans_charge();
        void zeroBal_charge();
        void monthly_fee();


    protected:

    private:
        double interest_rate;
        double min_due;
        double trans_fee;
};

#endif // CREDIT_H
