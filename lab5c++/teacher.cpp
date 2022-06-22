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

teacher::teacher(): person() {
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
