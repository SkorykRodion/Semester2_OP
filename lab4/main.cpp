#include <iostream>
#include "Vector.h"
using namespace std;
int main() {
    cout<<"Vector B1:"<<endl;
    Vector B1 = Vector();
    cout<<"Vector B2:"<<endl;
    cout<<"Enter x:";
    float x;
    cin>>x;
    cout<<"Enter y:";
    float y;
    cin>>y;
    cout<<"Enter z:";
    float z;
    cin>>z;
    Vector B2 = Vector(x, y, z);
    cout<<"Vector B3:"<<endl;
    cout<<"Enter x of start point:";
    float x1;
    cin>>x1;
    cout<<"Enter y of start point:";
    float y1;
    cin>>y1;
    cout<<"Enter z of start point:";
    float z1;
    cin>> z1;
    cout<<"Enter x of end point:";
    float x2;
    cin>>x2;
    cout<<"Enter y of end point::";
    float y2;
    cin>>y2;
    cout<<"Enter z of end point::";
    float z2;
    cin>>z2;
    Vector B3 = Vector(x1, y1, z1, x2, y2, z2);
    cout<<"Add to B1 polar angle:";
    float add;
    cin>>add;
    B1+=add;
    if(B2!=B3)
        cout<<"B1, B2 are not collinear"<<endl;
    else
        cout<<"B1, B2 are collinear"<<endl;
    cout<<"--------"<<endl;
    cout<<"B1"<<endl;
    B1.getSquareCords();
    cout<<B1<<endl;
    cout<<"B2";
    B2.getSquareCords();
    cout<<B2<<endl;
    cout<<"B3";
    B3.getSquareCords();
    cout<<B3<<endl;
}
