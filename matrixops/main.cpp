#include <iostream>
#include "matrixops.hpp"

using namespace std;

int main() {
    vector<double> data = {1,2,3,4,5,6,7,8,9};
    Matrix matrix(data, 3, 3);
    matrix.printMatrix();
    cout << matrix.getLength() << " " << matrix.getWidth() << "\n";

    vector<vector<double>> data2 = {{1,2,3},{4,5,6},{7,8,9}};
    Matrix matrix2(data2);
    matrix2.printMatrix();
    cout << matrix2.getLength() << " " << matrix2.getWidth() << "\n";
    cout << matrix.getValue(0,0) << "\n";
    //matrix.addMatrix(matrix2);
    //matrix.printMatrix();
    matrix.multiplyMatrix(matrix2);
    matrix.printMatrix();
    matrix.scaleMatrix(-1);
    matrix.printMatrix();
    return 0;
}