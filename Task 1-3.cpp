#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

using namespace std;

double gete(const double m, const double v);


int main() {
  double m, v;

  cout << "Введите массу и скорость и нажмите Enter: \n";
  cin >> m >> v;

	const auto e = gete(m, v);

	cout << "Масса m = " << m << "\nСкорость v = " << v << "\nКинетическая энергия = " << e;
	return 0;
}

double gete(const double m, const double v) { 
  return (m * pow(v, 2)) / 2; } 