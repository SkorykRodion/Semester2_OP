
#include "student.h"

float student::countPayment() const {
    float payment;
    if(styp == 0)
        payment = 2500;
    else if(styp == 1)
        payment = 2000;
    else
        payment = 0;
    return payment;
}

void student::findStyp() {
    if(raiting - 95 > 0 || fabs(raiting - 95)<10e-3)
        styp = increased;
    else if(raiting - 85 > 0 || fabs(raiting - 85)<10e-3)
        styp = ordinary;
    else
        styp = none;
}

ostream &operator<<(ostream &os, const student &student) {
    string name = student.getFullname();
    tm date = student.getBirth();

    char *dateString = new char[100];
    strftime(dateString, 100, "date of birth: %x", &date);

    os <<name<<endl<< dateString<<endl<<"age: "<<student.getAge()<<endl
        <<"group number: " << student.groupnumber <<endl
        << "raiting: "<<student.raiting<<endl;

    delete[] dateString;

    if(student.styp == 0)
        os<< "stypendium: increased"<<endl;
    else if(student.styp == 1)
        os<< "stypendium: ordinary"<<endl;
    else
        os<< "stypendium: none"<<endl;
    os<<"payment: "<<student.countPayment()<<endl;

    return os;
}

student::student():person(){
    cout<<"Enter student's groupnumber:";
    cin>>groupnumber;
    cout<<"Enter student's raiting:";
    cin>>raiting;
    findStyp();
}
