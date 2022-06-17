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
    teacher():person(){
        bool flag = true;
        while(flag){
            cout<<"Enter subject:";
            string s;
            cin>>s;
            cout<<"Enter hours:";
            int n;
            cin>>n;
            subjects.push_back(s);
            subjectsHours.push_back(n);
            cout<<"Add another subject(y/n)?";
            string ans;
            cin>>ans;
            if(ans!="y")
                flag=false;
        }
    }
    float countPayment() const;

    friend ostream &operator<<(ostream &os, const teacher &teacher);
    friend int findBiggestPaymentAge(teacher* a, int m);
};


#endif //LAB5C___TEACHER_H
