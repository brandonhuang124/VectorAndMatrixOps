#include <vector>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include "vectorops.hpp"

using namespace std;

// All vector ops will throw an invalid argument exception if the operations is compatable (vectors different lengths)
vector<double>addVector(vector<double>v1, vector<double>v2) {
    if (!samelength(v1,v2)) 
        throw invalid_argument("Vectors are not the same length.");
    vector<double>out = {};
    for(int i = 0; i < v1.size(); i++) {
        out.push_back(v1[i] + v2[i]);
    }
    return out;
}


vector<double>subtractVector(vector<double>v1, vector<double>v2) {
    if (!samelength(v1,v2)) 
        throw invalid_argument("Vectors are not the same length.");
    vector<double>out = {};
    for(int i = 0; i < v1.size(); i++) {
        out.push_back(v1[i] - v2[i]);
    }
    return out;
}


vector<double>scaleVector(vector<double>v1, double scalar) {
    for(int i = 0; i < v1.size(); i++) {
        v1[i] *= scalar;
    }
    return v1;
}


vector<double> scaleVector(vector<double> v1, int scalar) {
    for(int i = 0; i < v1.size(); i++) {
        v1[i] *= scalar;
    }
    return v1;
}


vector<double> scaleVector(vector<int> v1, double scalar) {
    vector<double> out = {};
    for(int i = 0; i < v1.size(); i++) {
        out.push_back(v1[i] * scalar);
    }
    return out;
}


bool samelength(vector<double>v1, vector<double>v2) {
    if (v1.size() == v2.size())
        return true;
    return false;
}


void printvector(vector<double>v1) {
    // Empty vectors still print empty brackets
    if (v1.size() == 0) {
        cout << "<>\n";
        return;
    }
    cout << "<";
    for(int i = 0; i < v1.size()-1; i++) {
        cout << v1[i] << ", ";
    }
    cout << v1[v1.size()-1] << ">\n";
}


double dotproduct(vector<double>v1, vector <double>v2) {
    // Could also use the cos formula, but less messy this way.
    if (!samelength(v1,v2)) 
        throw invalid_argument("Vectors are not the same length.");
    double out = 0;
    for (int i = 0; i < v1.size(); i++) {
        out += v1[i] * v2[i];
    }
    return out;
}


double magnitudeVector(vector<double>v1) {
    // Sum of the squares of all the components and squareroot.
    double out = 0;
    for (int i = 0; i < v1.size(); i++) {
        out += v1[i] * v1[i];
    }
    return sqrt(out);
}


// ONLY SUPPPORTS 3D VECTORS.
vector<double> crossproduct(vector<double>v1, vector<double>v2) {
    if (!samelength(v1,v2) || v1.size() != 3) 
        throw invalid_argument("Vectors are not the same length or are not 3D.");
    // Could use the sin formula, but we need to calculate the cross product for use in the angle for better precision.
    // So were gonna use the component form way instead.
    // Technically cross products exist in 7D space but probably not going to need that lol.
    vector<double> out = {};
    out.push_back(v1[1]*v2[2] - v1[2]*v2[1]);
    out.push_back(v1[2]*v2[0] - v1[0]*v2[2]);
    out.push_back(v1[0]*v2[1] - v1[1]*v2[0]);
    return out;
}


// ONLY SUPPORTS 2D AND 3D VECTORS.
double vectorAngle(vector<double>v1, vector<double>v2) {
    if (!samelength(v1,v2) || v1.size() < 2 || v1.size() > 3) 
        throw invalid_argument("Vectors are not the same length or are not a 2D or 3D vector.");
    
    // 2D
    // To use tangent, use the same formula as 3D but the z component for both is 0. This way we can use arctan which has better precision (see below approach)
    if (v1.size() == 2) {
        vector<double>v13d = {v1[0], v1[1], 0};
        vector<double>v23d = {v2[0], v1[0], 0};
        return atan2(magnitudeVector(crossproduct(v13d, v23d)), dotproduct(v1,v2));
    }

    // 3D
    // Approach 1: 
    // Uses the cosine formula to find the angle: cos(theta) = dotprod(u,v) / (||u|| * ||v||)
    // Take the arccos of this to find the angle.
    // This approach works great, but causes extra unecessary error when using high precision, since near zero the consine function does not move much.
    // Leaving it here but commented out for later reference.

    /*
    double out = dotproduct(v1,v2) / (magnitudeVector(v1) * magnitudeVector(v2));
    return acos(out);
    */

    // Approach 2:
    // arctan has much less error when working with floating points, so use that for better precision
    // Uses a different formula, take the arctan( magnitude of the cross product / dotproduct).
    // This can be derived from two formula.
    // 1: Geometry formula: dotproduct(v1,v2) = magnitude(v1) * magnitude(v2) * Cos(anglebetween)
    // This is just the cosine formula from earlier.
    // 2: magnitude(crossproduct(v1,v2)) = magnitude(v1) * magnitude(v2) * sin(anglebetween)
    // This is the sine formula, or the cross product formula.
    // Divide 1 by 2, cancel like terms and solve for theta and we get theta = arctan( magnitude(crossproduct(v1,v2)) / dotproduct(v1,v2))
    // Here's a blog post explaining this since future me will probably forget why this is needed: https://www.jwwalker.com/pages/angle-between-vectors.html

    return atan2(magnitudeVector(crossproduct(v1,v2)), dotproduct(v1,v2));
}


vector<double> getUnitVector(vector<double>v1) {
    // Just divide each of the fields by the magnitude of the vector.
    double magnitude = magnitudeVector(v1);
    for (int i = 0; i < v1.size(); i++) {
        v1[i] /= magnitude;
    }
    return v1;
}


// Projection of v1 onto v2. Uses the vector prection formula.
vector<double> vectorProjection(vector<double>v1, vector<double>v2) {
    double scalar = dotproduct(v1,v2) / dotproduct(v2,v2);
    for (int i = 0; i < v2.size(); i++) {
        v2[i] *= scalar;
    }
    return v2;
}