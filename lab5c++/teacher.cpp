#include "teacher.h"


float teacher::countPayment() const {
    float res =0;
    for(int i=0; i<subjectsHours.size(); ++i)
        res+=subjectsHours[i]*paymentForEachHour;
    return res;
}

ostream &operator<<(ostream &os, const teacher &teacher) {

    string name = teacher.getFullname();
    tm date = teacher.getBirth();

    char *dateString = new char[100];
    strftime(dateString, 100, "date of birth: %x", &date);

    os <<name<<endl<< dateString<<endl<<"age: "<<teacher.getAge()<<endl;
    delete[] dateString;
    os<<"subjects: ";
    for(int i =0; i < teacher.subjects.size();++i)
        os<<teacher.subjects[i]<<", "<<teacher.subjectsHours[i]<<"; ";
    os<<"\npayment: "<<teacher.countPayment()<<endl;

    return os;
}

int findBiggestPaymentAge(teacher* a, int m) {
    float biggestPayment =0;
    int age =0;
    for(int i=0;i<m;++i)
    {
        float tmp = a[i].countPayment();
        if(tmp - biggestPayment > 0)
        {
            biggestPayment = tmp;
            age = a[i].getAge();
        }

    }
    return age;
}
