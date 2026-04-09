#include "Shape.h"
#include <fstream>
#include <iomanip>

void Shape::exportToFile(const string& filename) const {
    ofstream file(filename, ios::app);
    if (!file) { cerr << "Error opening file.\n"; return; }
    file << fixed << setprecision(4);
    file << "SHAPE: " << name << "\n";
    file << "  Volume      : " << volume()     << "\n";
    file << "  Surface Area: " << surfaceArea()<< "\n";
    file << "---\n";
    file.close();
    cout << "Exported to " << filename << "\n";
}