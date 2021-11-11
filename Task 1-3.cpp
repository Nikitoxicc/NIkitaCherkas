#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

using namespace std;

/**
* \brief вычисление кинетической энергии
* \param сonst double m - константа данная по условию
* \param сonst double v - константа данная по условию
* \return - значение  кинетической энергии e
*/
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
  return (m*0.001 * pow(v, 2)) / 2; } 