#include <iostream>
#include <stdexcept>
#include "matrixops.hpp"

using namespace std;
Matrix::Matrix(vector<double> list, int l, int w) {
    
    length = l;
    width = w;
    matrix = {};
    vector<double>::iterator ptr = list.begin();
    for (int i = 0; i < length; i++) {
        matrix.push_back({});
        for (int j = 0; j < width; j++) {
            cout << "here\n";
            if (ptr < list.end())
                matrix[i].push_back(*ptr);
            else
                matrix[i].push_back(0);
            if (ptr < list.end())
                ptr++;
        }
    }
}


Matrix::Matrix(vector<vector<double>> list) {
    matrix = {};
    // Check if the matrix is rectangular
    int rowlength = list[0].size();
    for(int i = 1; i < list.size(); i++) {
        if (list[i].size() != rowlength)
            throw invalid_argument("2D Vector supplied is non-rectangular");
    }
    width = list[0].size();
    length = list.size();
    for (int i = 0; i < list.size(); i++) {
        matrix.push_back({});
        for (int j = 0; j < list[0].size(); j++) {
            matrix[i].push_back(list[i][j]);
        }
    }
}

int Matrix::getLength() {return length;}

int Matrix::getWidth() {return width;}

int Matrix::getValue(int row, int column) {return matrix[row][column];}

vector<double> Matrix::getRow(int row) {return matrix[row];}

vector<double> Matrix::getColumn(int column) {
    if (column >= length)
        throw invalid_argument("Column size is too great.");
    vector<double> out = {};
    for (int i = 0; i < matrix.size(); i++) {
        out.push_back(matrix[i][column]);
    }
    return out;
}

void Matrix::addMatrix(Matrix sumMatrix) {
    if(sumMatrix.getLength() != length || sumMatrix.getWidth() != width)
        throw invalid_argument("Matrices are not compatable for addition.");
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            matrix[i][j] += sumMatrix.getValue(i,j);
        }
    }
}

void Matrix::subtractMatrix(Matrix diffMatrix) {
    if(diffMatrix.getLength() != length || diffMatrix.getWidth() != width)
        throw invalid_argument("Matrices are not compatable for addition.");
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            matrix[i][j] -= diffMatrix.getValue(i,j);
        }
    }
}

void Matrix::scaleMatrix(int scalar) {
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < width; j++) {
            matrix[i][j] *= scalar;
        }
    }
}

void Matrix::printMatrix() {
    for (int i = 0; i < length; i++) {
        cout << "[ ";
        for (int j = 0; j < length; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "]\n";
    }
}

void Matrix::multiplyMatrix(Matrix prodMatrix) {
    // matrix multiplication is only compatable when the columns in the first matrix is equal to the number of rows in the second.
    if (length != prodMatrix.getWidth())
        throw invalid_argument("Matrices are not compatable for multiplication.");
    vector<vector<double>> newmatrix = {};
    for (int i = 0; i < length; i++) {
        newmatrix.push_back({});
        for (int j = 0; j < prodMatrix.getWidth(); j++) {
            double total = 0;
            vector<double> row = matrix[i];
            vector<double> column = prodMatrix.getColumn(j);
            for (int k = 0; k < row.size(); k++) {
                total += row[k] * column[k];
            }
            newmatrix[i].push_back(total);
        }
    }
    width = prodMatrix.getWidth();
    matrix = newmatrix;
}