
#include <ostream>
#include "person.h"
#include <cmath>
#ifndef LAB5C___STUDENT_H
#define LAB5C___STUDENT_H
typedef  enum { increased, ordinary, none } stypendium;


class student:public person {
    string groupnumber;
    float raiting;
    stypendium styp;
    void findStyp();
public:
    student();
    float countPayment() const;

    friend ostream &operator<<(ostream &os, const student &student);



};


#endif //LAB5C___STUDENT_H
