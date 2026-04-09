#pragma once
#include <iostream>
#include <cmath>
using namespace std;

const double MY_PI = 3.14159265358979;

struct Vector3 {
    double x, y, z;
    Vector3(double x=0, double y=0, double z=0): x(x), y(y), z(z) {}
    void print() const { cout << "(" << x << ", " << y << ", " << z << ")"; }
};

class Transform {
public:
    static Vector3 translate(Vector3 v, double dx, double dy, double dz) {
        return {v.x + dx, v.y + dy, v.z + dz};
    }

    static Vector3 rotateZ(Vector3 v, double deg) {
        double rad = deg * MY_PI / 180.0;
        return {
            v.x * cos(rad) - v.y * sin(rad),
            v.x * sin(rad) + v.y * cos(rad),
            v.z
        };
    }

    static Vector3 scale(Vector3 v, double factor) {
        return {v.x * factor, v.y * factor, v.z * factor};
    }

    static double dotProduct(Vector3 a, Vector3 b) {
        return a.x*b.x + a.y*b.y + a.z*b.z;
    }

    static Vector3 crossProduct(Vector3 a, Vector3 b) {
        return {
            a.y*b.z - a.z*b.y,
            a.z*b.x - a.x*b.z,
            a.x*b.y - a.y*b.x
        };
    }

    static double magnitude(Vector3 v) {
        return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
    }
};