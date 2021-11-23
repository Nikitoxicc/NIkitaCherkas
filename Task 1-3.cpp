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
double getE(const double mass, const double velocity);


int main() {
  double mass =0.0;
  double velocity = 0.0;

  cout << "Введите массу и скорость и нажмите Enter: \n";
  cin >> mass >> velocity;

	const auto e = getE(mass, velocity);

	cout << "Масса m = " << mass << "\nСкорость v = " << velocity << "\nКинетическая энергия = " << e;
	return 0;
}

double getE(const double mass, const double velocity) { 
  return (mass*0.001 * pow(velocity, 2)) / 2; } 