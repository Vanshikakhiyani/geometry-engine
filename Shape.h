#pragma once
#include <string>
#include <iostream>
using namespace std;

class Shape {
protected:
    string name;
public:
    Shape(string n) : name(n) {}
    virtual ~Shape() {}

    string getName() const { return name; }

    virtual double volume()      const = 0;
    virtual double surfaceArea() const = 0;
    virtual void   display()     const = 0;

    void exportToFile(const string& filename) const;
};