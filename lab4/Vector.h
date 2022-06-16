#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;

class Vector {
    float r;
    float fi;
    float O;
    float toRadians(float a);
public:
    //from spherical coordinates
    Vector();
    //from square coordinates
    Vector(float x, float y, float z);
    //from 2 points square coordinates
    Vector(float x1, float y1, float z1, float x2, float y2, float z2);

    void getSquareCords();

    void operator+= (float p);

    bool operator!=(Vector &rhs);

    float getR() const;

    float getFi() const;

    float getO() const;

    void setR(float r);

    void setFi(float fi);

    void setO(float o);

    friend ostream &operator<<(ostream &os, const Vector &vector);
};