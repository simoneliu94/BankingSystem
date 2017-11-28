#include <ctime>
#include <iostream>
using namespace std;


int main()
{
    // initialize
    int y=2016, m=2, d=29;
    tm date = {};
    date.tm_year = y-1900;
    date.tm_mon  = m-1;
    date.tm_mday = d;
    // modify
    date.tm_mday += 1;
    mktime(&date);
    // show result
    char* nextMonth = asctime(&date);
    cout << nextMonth; // prints: Sun Mar 16 00:00:00 1980
    cout << "date of year = " << mktime(&date) << endl;

    time_t  timev;
    time(&timev);
    cout << "date of year = " << time(&timev) << endl;


    time_t t = time(NULL);
	tm* timePtr = localtime(&t);
    cout << "date of year = " << timePtr->tm_mday << endl;
    cout << "month of year = " << timePtr->tm_mon+1 << endl;
    cout << "year = " << timePtr->tm_year + 1900 << endl;






        int y = atoi(date.substr(0,4).c_str());
    int m = atoi(date.substr(5,2).c_str());
    int d = atoi(date.substr(8,2).c_str());

    tm dates = {};
    dates.tm_year = y-1900;
    dates.tm_mon  = m-1;
    dates.tm_mday = d;
    dates.tm_mday += 30;
    mktime(&dates);

    cout << "timestamp = " << mktime(&dates) << endl;

    time_t  times;
    time(&times);
    cout << "current timestamp = " << time(&times) << endl;

    if (time(&times)==mktime(&dates))
    {
        balance = balance - charge_rate;

    }
}
