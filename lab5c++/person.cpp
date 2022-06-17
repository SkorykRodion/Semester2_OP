
#include "person.h"

void person::getLocalDate(tm &dateRes) const
{
    time_t secounds = (time(NULL));
    localtime_s(&dateRes, &secounds);
}

int person::getAge() const
{
    tm now;
    getLocalDate(now);
    int res = now.tm_year - birth.tm_year -1;
    int months = now.tm_mon - birth.tm_mon;
    int days = now.tm_mday - birth.tm_mday;
    if (months > 0 || (months == 0 && days > 0)) {
        res++;
    }

    if (res > 100)
        res = 100;

    return res;
}

person::person() {
    cout<<"Enter full name:";
    cin.ignore();
    getline(cin, fullname);
    int day, month, year;
    tm now;
    getLocalDate(now);
    cout << "Enter day of birth: ";
    cin >> day;
    cout << "Enter month of birth: ";
    cin >> month;
    cout << "Enter year of birth: ";
    cin >> year;
    birth = now;
    birth.tm_year = year - 1900;
    if (month <= 12 && month >= 1)
        birth.tm_mon = month - 1;
    if (day <= 31 && day >= 1)
        birth.tm_mday = day;
}

const tm &person::getBirth() const {
    return birth;
}

const string &person::getFullname() const {
    return fullname;
}

