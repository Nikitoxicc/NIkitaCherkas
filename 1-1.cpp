#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

double getA(const double x, const double y, const double z);
double getB(const double x, const double y, const double z);
int main() {
	const double x = 1.426;
	const double y = -1.22;
	const double z = 3.5;
	const auto a = getA(x, y, z);
	const auto b = getB(x, y, z);
	cout << " x = " << x << "\n y = " << y << "\n z = " << z << "\n a = " << a << "\n b = " << b;

	return 0;
}

double getA(const double x, const double y, const double z) {
  return (2 * cos (x - M_PI/6)) / (1/2 + (pow(sin(y),2)));
}

double getB(const double x, const double y, const double z) {
  return 1 + ((pow(z, 2)) / 3 + (pow(z,2) / 5));
}  