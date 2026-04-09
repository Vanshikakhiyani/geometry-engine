#pragma once
#include "Shape.h"
#include <cmath>
#define PI 3.14159265358979

class Sphere : public Shape {
    double radius;
public:
    Sphere(double r) : Shape("Sphere"), radius(r) {}
    double volume()      const override { return (4.0/3.0) * PI * radius * radius * radius; }
    double surfaceArea() const override { return 4 * PI * radius * radius; }
    void   display()     const override {
        cout << "\n--- Sphere ---\n";
        cout << "Radius      : " << radius      << "\n";
        cout << "Volume      : " << volume()     << "\n";
        cout << "Surface Area: " << surfaceArea()<< "\n";
    }
};

class Cylinder : public Shape {
    double radius, height;
public:
    Cylinder(double r, double h) : Shape("Cylinder"), radius(r), height(h) {}
    double volume()      const override { return PI * radius * radius * height; }
    double surfaceArea() const override { return 2 * PI * radius * (radius + height); }
    void   display()     const override {
        cout << "\n--- Cylinder ---\n";
        cout << "Radius      : " << radius      << "\n";
        cout << "Height      : " << height      << "\n";
        cout << "Volume      : " << volume()     << "\n";
        cout << "Surface Area: " << surfaceArea()<< "\n";
    }
};

class Cuboid : public Shape {
    double l, w, h;
public:
    Cuboid(double l, double w, double h) : Shape("Cuboid"), l(l), w(w), h(h) {}
    double volume()      const override { return l * w * h; }
    double surfaceArea() const override { return 2 * (l*w + w*h + l*h); }
    void   display()     const override {
        cout << "\n--- Cuboid ---\n";
        cout << "L x W x H   : " << l << " x " << w << " x " << h << "\n";
        cout << "Volume      : " << volume()     << "\n";
        cout << "Surface Area: " << surfaceArea()<< "\n";
    }
};

class Cone : public Shape {
    double radius, height;
public:
    Cone(double r, double h) : Shape("Cone"), radius(r), height(h) {}
    double slantHeight()  const { return sqrt(radius*radius + height*height); }
    double volume()       const override { return (1.0/3.0) * PI * radius * radius * height; }
    double surfaceArea()  const override { return PI * radius * (radius + slantHeight()); }
    void   display()      const override {
        cout << "\n--- Cone ---\n";
        cout << "Radius      : " << radius      << "\n";
        cout << "Height      : " << height      << "\n";
        cout << "Volume      : " << volume()     << "\n";
        cout << "Surface Area: " << surfaceArea()<< "\n";
    }
};