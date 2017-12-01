#include "Credit.h"

using namespace std;

Credit::Credit()
{

}

//Create a credit account with parameters id, balance, date and customer and pass them to Account class
Credit::Credit(string a_id, double a_bal, double lim, string a_date, Customer &a_cus):Account(a_id, a_bal, a_date, a_cus)
{
    limit = lim;
    credit_score = 650;
}

//Set credit limit
void Credit::set_limit(double lim)
{
    limit = lim;
}

//Get credit limit
double Credit::get_limit()
{
    return limit;
}

//Set credit limit
void Credit::set_score(int sc)
{
    credit_score = sc;
}

//Get credit limit
int Credit::get_score()
{
    return credit_score;
}

int Credit::get_credit_score()
{
    return credit_score;
}

//Override deposit function from Account class
//Pay off the balance, charge fee to this transaction
void Credit::deposit(double amt, string des)
{
    balance = balance - amt;
    trans_charge();
    string trans = "Account " + acc_id + ". Deposited $"+ to_string(amt)+". Current balance $"+to_string(balance) + ". Note: " + des;
    keep_transaction(trans);
}

//Override withdraw function from Account class
//Withdraw money from account, charge fee to this transaction
void Credit::withdraw(double amt, string des)
{
    //Checking if the limit has been reached yet
    if(amt <= limit)
    {
        balance = balance + amt;
        trans_charge();
        string trans = "Account " + acc_id + ". Withdrew $"+ to_string(amt)+". Current balance $"+to_string(balance) + ". Note: " + des;
        keep_transaction(trans);
    }
    else
    {
        cout <<"Account "<< acc_id<< ". Insufficient funds to withdraw" << endl;
        cout << "-------------------------------------------" << endl;
    }
}

//Override the
//Charges 8% interest compounded daily
void Credit::daily_interest()
{
    interest_rate = 0.08/365;
    balance = balance + interest_rate;
    string trans = "Account " + acc_id + ". Daily charge rate $" + to_string(interest_rate)+". Current balance: $"+to_string(balance);
    keep_transaction(trans);
}

//Charge fees to transactions
void Credit::trans_charge()
{
    trans_fee = 0.3;
    balance = balance + trans_fee;

}

//Charges a fee of $25/mo if balance is $0.00.
void Credit::zeroBal_charge()
{
    if(balance==0)
    {
        balance = balance + 25;
    }
}

//Charge minimum due monthly at rate 0.25% of the current balance
//Call track_credit_score() function
void Credit::monthly_fee()
{
    min_due = balance * 0.0025;
    balance = balance + min_due;
    track_credit_score();
    string trans = "Account " + acc_id + ". Minimum due this month $" + to_string(min_due)+". Current balance: $"+to_string(balance);
    keep_transaction(trans);
}


//Keep track of the credit score each month
//If customer spend less than 30% of the limit each month, then add 5 points to their credit score
//Else, deduct 1 points
void Credit::track_credit_score()
{
    if (balance <= limit*0.3)
    {
        credit_score = credit_score + 5;
    }
    else
    {
        credit_score = credit_score - 1;
    }
}

//Print out the status based on credit score
void Credit::credit_status()
{
    if(credit_score>=800)
    {
        cout << "Credit score range: Excellent" << endl;
    }
    if((750<=credit_score) & (credit_score<=799))
    {
        cout << "Credit score range: Very good" << endl;
    }
    if((700<=credit_score) & (credit_score<=749))
    {
        cout << "Credit score range: Good" << endl;
    }
    if((650<=credit_score) & (credit_score<=699))
    {
        cout << "Credit score range: Fair" << endl;
    }
    if((600<=credit_score) & (credit_score<=649))
    {
        cout << "Credit score range: Poor" << endl;
    }
    if(credit_score<=599)
    {
        cout << "Credit score range: Very bad" << endl;
    }
}
