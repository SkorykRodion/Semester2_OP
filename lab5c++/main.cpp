#include <iostream>
#include "student.h"
#include "teacher.h"
int main() {
    int n;
    cout<<"Number of students:";
    cin>>n;
    student *arr1 = new student[n];
    int m;
    cout<<"Number of teachers:";
    cin>>m;
    teacher *arr2 = new teacher[m];
    cout<<"\n-------------\n";
    for(int i=0;i<n;++i)
        cout<<"student"<<i<<":"<<endl<<arr1[i]<<endl;
    delete [] arr1;
    for(int i=0;i<m;++i)
        cout<<"teacher"<<i<<":"<<endl<<arr2[i]<<endl;
    int age = findBiggestPaymentAge(arr2, m);
    cout<<"\n\n\nAge of teacher with biggest payment: "<<age;
    delete [] arr2;
}
