#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

/**
* \brief вычисление площади по формуле
* \param сonst double a - константа данная по условию
* \param сonst double n - константа данная по условию
* \return - значение Area
*/
double getArea(const double a, const double n);

/**
* \brief вычисление периметр по формуле
* \param сonst double a - константа данная по условию
* \param сonst double n - константа данная по условию
* \return - значение Perimetr
*/
double getPerimetr(const double a, const double n);

int main() {
  double a, n;

  cout << "Введите длину и коэффициент и нажмите Enter: \n";
  cin >> a >> n;
	const auto Area = getArea(a, n);
	const auto Perimetr = getPerimetr(a, n);
	cout << "Стророна a = " << a << "\nКоэффициент n = " << n << "\nПериметр = " << S << "\nПлощадь = " << P;

	return 0;
}
double getArea(const double a, const double n) { return pow(a, 2) * n; } 
double getPerimetr(const double a, const double n) { return 2 * a * (1 + n); }