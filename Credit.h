#ifndef CREDIT_H
#define CREDIT_H

#include "Customer.h"
#include "Account.h"


//Initialize the class, functions and variables
//Inherited from Account class
class Credit:public Account
{
public:
    Credit();
    Credit(string a_id, double a_bal, double lim, string a_date, Customer &a_cus);
    void set_limit(double lim);
    double get_limit();
    void set_score(int sc);
    int get_score();
    void deposit(double amt, string des);
    void withdraw(double amt, string des);
    void daily_interest();
    void trans_charge();
    void zeroBal_charge();
    void monthly_fee();
    void track_credit_score();
    int get_credit_score();
    void credit_status();

protected:

private:
    double limit;
    double interest_rate;
    double min_due;
    double trans_fee;
    int credit_score;
};

#endif // CREDIT_H
