#include "Vector.h"



bool Vector::operator!=(Vector &rhs)  {
    float fi1 = toRadians(this->fi);
    float fi2 = toRadians(rhs.fi);
    float O1 = toRadians(this->O);
    float O2 = toRadians(rhs.O);
    float vidnoshenya1 = (sin(O1)*cos(fi1))/(sin(O2)*cos(fi2));
    float vidnoshenya2 = (sin(O1)*sin(fi1))/(sin(O2)*sin(fi2));
    float vidnoshenya3 = cos(O1)/cos(O2);
    if(fabs(vidnoshenya1 - vidnoshenya2 ) <= 10e-3
        && fabs(vidnoshenya2 -vidnoshenya3) <= 10e-3)
        return false;
    else
        return true;
}

void Vector::operator+=(float p) {
    this->O+=p;
}

float Vector::toRadians(float a) {
    return a*M_PI/180;
}

Vector::Vector() {
    cout<<"Enter radial distance:";
    cin>>r;
    cout<<"Enter polar angle(degrees):";
    cin>>O;
    cout<<"Enter  azimuthal angle(degrees):";
    cin>>fi;

}

Vector::Vector(float x, float y, float z) {
    r = sqrt(x*x + y*y + z*z);
    O = atan((sqrt(x*x+y*y))/z) *180/M_PI;
    fi = atan(y/x) *180/M_PI;
}

Vector::Vector(float x1, float y1, float z1, float x2, float y2, float z2) {
    float x = x2-x1;
    float y = y2-y1;
    float z = z2-z1;
    r = sqrt(x*x + y*y + z*z);
    O = atan((sqrt(x*x+y*y))/z) *180/M_PI;
    fi = atan(y/x) *180/M_PI;
}

void Vector::getSquareCords() {
    float fi1 = toRadians(fi);
    float O1 = toRadians(O);
    float x = r*sin(O1)*cos(fi1);
    float y = r*sin(O1)*sin(fi1);
    float z = r*cos(O1);
    cout<<"Square cords: "<<endl;
    cout<<x<<' '<<y<<' '<<z<<endl;

}

float Vector::getR() const {
    return r;
}

float Vector::getFi() const {
    return fi;
}

float Vector::getO() const {
    return O;
}

void Vector::setR(float r) {
    Vector::r = r;
}

void Vector::setFi(float fi) {
    Vector::fi = fi;
}

void Vector::setO(float o) {
    O = o;
}

ostream &operator<<(ostream &os, const Vector &vector) {
    os << "r: " << vector.r << " O: " << vector.O << " fi: " << vector.fi;
    return os;
}
