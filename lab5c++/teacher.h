#ifndef LAB5C___TEACHER_H
#define LAB5C___TEACHER_H
#include "person.h"
#include <vector>
#include <ostream>

class teacher:public person {
    float paymentForEachHour = 250;
public:
    vector<string> subjects;
    vector<int> subjectsHours;

    teacher();

    float countPayment() const;

    friend ostream &operator<<(ostream &os, const teacher &teacher);
    friend int findBiggestPaymentAge(teacher* a, int m);
};


#endif //LAB5C___TEACHER_H
