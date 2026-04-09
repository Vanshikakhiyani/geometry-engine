#include <iostream>
#include <vector>
#include <memory>
#include "Shapes.h"
#include "Transform.h"
using namespace std;

void showMenu() {
    cout << "\n====== 3D Geometry Engine ======\n";
    cout << "1. Create Sphere\n";
    cout << "2. Create Cylinder\n";
    cout << "3. Create Cuboid\n";
    cout << "4. Create Cone\n";
    cout << "5. Show all shapes\n";
    cout << "6. Export all to file\n";
    cout << "7. Transform a point (Vector3)\n";
    cout << "8. Vector operations\n";
    cout << "0. Exit\n";
    cout << "Choice: ";
}

int main() {
    vector<unique_ptr<Shape>> shapes;
    int choice;

    do {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            double r; cout << "Enter radius: "; cin >> r;
            shapes.push_back(make_unique<Sphere>(r));
            cout << "Sphere created.\n";
        }
        else if (choice == 2) {
            double r, h; cout << "Radius: "; cin >> r; cout << "Height: "; cin >> h;
            shapes.push_back(make_unique<Cylinder>(r, h));
            cout << "Cylinder created.\n";
        }
        else if (choice == 3) {
            double l, w, h;
            cout << "Length: "; cin >> l;
            cout << "Width : "; cin >> w;
            cout << "Height: "; cin >> h;
            shapes.push_back(make_unique<Cuboid>(l, w, h));
            cout << "Cuboid created.\n";
        }
        else if (choice == 4) {
            double r, h; cout << "Radius: "; cin >> r; cout << "Height: "; cin >> h;
            shapes.push_back(make_unique<Cone>(r, h));
            cout << "Cone created.\n";
        }
        else if (choice == 5) {
            if (shapes.empty()) { cout << "No shapes yet.\n"; continue; }
            for (auto& s : shapes) s->display();
        }
        else if (choice == 6) {
            string fname = "shapes_export.txt";
            for (auto& s : shapes) s->exportToFile(fname);
        }
        else if (choice == 7) {
            double x, y, z;
            cout << "Enter point x y z: "; cin >> x >> y >> z;
            Vector3 v(x, y, z);
            cout << "Original: "; v.print(); cout << "\n";

            Vector3 t = Transform::translate(v, 1, 2, 3);
            cout << "Translated (+1,+2,+3): "; t.print(); cout << "\n";

            Vector3 r = Transform::rotateZ(v, 45);
            cout << "Rotated Z 45deg: "; r.print(); cout << "\n";

            Vector3 sc = Transform::scale(v, 2);
            cout << "Scaled x2: "; sc.print(); cout << "\n";
        }
        else if (choice == 8) {
            double x1,y1,z1,x2,y2,z2;
            cout << "Vector A (x y z): "; cin >> x1 >> y1 >> z1;
            cout << "Vector B (x y z): "; cin >> x2 >> y2 >> z2;
            Vector3 a(x1,y1,z1), b(x2,y2,z2);

            cout << "Dot product    : " << Transform::dotProduct(a,b) << "\n";
            Vector3 cross = Transform::crossProduct(a,b);
            cout << "Cross product  : "; cross.print(); cout << "\n";
            cout << "Magnitude of A : " << Transform::magnitude(a) << "\n";
        }

    } while (choice != 0);

    cout << "Goodbye!\n";
    return 0;
}