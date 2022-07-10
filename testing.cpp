#include <iostream>
#include <vector>
#include "vectorops.hpp"

using namespace std;

int main() {
    vector<double> v1 = {1,1,1};
    vector<double> v2 = {1,2,4};
    vector<double> v3 = {};
    if (v1 == v2) {
        cout << "same\n";
    }
    try {
        cout << dotproduct(v1,v2) << "\n";
        cout << magnitudeVector(v1) << "\n";
        cout << vectorAngle(v1,v2) << "\n";
        cout << vectorAngle(v2,v1) << "\n";
        v3 = vectorProjection(v1,v2);
    } catch (invalid_argument &e){
        cerr << e.what();
        return -1;
    }
    
    printvector(v1);
    printvector(v2);
    printvector(v3);
}