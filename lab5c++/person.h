#ifndef LAB5C___PERSON_H
#define LAB5C___PERSON_H
#include <iostream>
#include <string>
#include <time.h>
using namespace std;


class person {
protected:
    tm birth;
    string fullname;
    void getLocalDate(tm& dateRes) const;

public:
    person();
    int getAge() const;
    virtual float countPayment() const = 0 ;

    const tm &getBirth() const;

    const string &getFullname() const;
};


#endif //LAB5C___PERSON_H
