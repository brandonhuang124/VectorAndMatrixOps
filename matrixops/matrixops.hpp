#include <vector>

using namespace std;
class Matrix {
    int length, width;
    vector<std::vector<double>> matrix;

    public:
        Matrix(vector<double> list, int length, int width);
        Matrix(vector<vector<double>> matrix);
        Matrix(double list[], int length, int width);
        void printMatrix();
        int getWidth();
        int getLength();
        int getValue(int row, int column);
        vector<double> getRow(int row);
        vector<double> getColumn(int column);
        vector<vector<double>> getMatrix();
        void addMatrix(Matrix sumMatrix);
        void subtractMatrix(Matrix diffMatrix);
        void scaleMatrix(int scalar);
        void multiplyMatrix(Matrix prodMatrix);
};