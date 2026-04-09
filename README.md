# 3D Geometry Engine

A C++ CLI application to create, manipulate, and measure 3D geometric shapes.

## Features
- Create shapes: Sphere, Cylinder, Cuboid, Cone
- Calculate volume and surface area for each shape
- Transform 3D points: translation, rotation, scaling
- Vector operations: dot product, cross product, magnitude
- Export shape data to structured text file

## Tech Stack
C++ · OOP · Linear Algebra · File I/O

## How to Run
```bash
g++ main.cpp Shape.cpp -o geometry_engine -std=c++17
.\geometry_engine.exe
```

## Class Structure
- `Shape` — abstract base class with pure virtual functions
- `Sphere`, `Cylinder`, `Cuboid`, `Cone` — derived shape classes
- `Transform` — static utility class for vector math and transforms