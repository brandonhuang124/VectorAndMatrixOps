// All vector ops will throw an invalid argument exception if the operations is compatable (vectors different lengths)
using namespace std;

/* 
Adds two vectors together. Throws an invalidargument exception if they aren't the same length. Returns a vector of the same length as the input.
*/
vector<double> addVector(vector<double> v1, vector<double> v2);

/*
Subtracts vector v2 from v1. Throws an invalidargument exception if they aren't the same length. Returns a vector of the same length as the input.
*/
vector<double> subtractVector(vector<double> v1, vector<double> v2);

/*
Scales vector by a given scalar. Returns a new vector of doubles which is scaled.
*/
vector<double> scaleVector(vector<double> v1, double scale);

vector<double> scaleVector(vector<int> v1, double scalar);

vector<double> scaleVector(vector<double> v1, int scalar);

/*
Mostly for internal use. Returns true if vectors are the same length and false otherwise.
*/
bool samelength(vector<double> v1, vector<double> v2);

/*
Prints vector in the form: <a,b,c,...>\n
*/
void printvector(std::vector<double> v1);

/*
Computes the dot product of two vectors.
*/
double dotproduct(vector<double> v1, vector <double> v2);

/*
Computes the magnitude of a vector.
*/
double magnitudeVector(vector<double> v1);

/*
Computes the angle between v1 and v2. Uses arctan for better precision near 0.
*/
double vectorAngle(vector<double> v1, vector<double> v2);

/*
Get the cross product of v1 x v2. Don't forget cross product is non-communative!
*/
vector<double> crossproduct(vector<double>v1, vector<double>v2);

/*
Get a unit vector in the direction of v1.
*/
vector<double> getUnitVector(vector<double> v1);

/*
Gets the vector projection of v1 onto v2.
*/
vector<double> vectorProjection(vector<double> v1, vector<double> v2);