#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>


using namespace std;

/**
* \brief вычисление площади прямоугольнока по формуле
* \param сonst double side - сторона данная по условию
* \param сonst double coefficient - коэфицент данная по условию
* \return - значение Area
*/
double getArea(const double side, const double coefficient);

/**
* \brief вычисление периметр прямоугольника по формуле
* \param сonst double side - сторона данная по условию
* \param сonst double coefficient - коэфицент данный по условию
* \return - значение Perimetr
*/
double getPerimetr(const double side, const double coefficient);

int main() {
  double side, coefficient;

  cout << "Введите длину и коэффициент и нажмите Enter: \n";
  cin >> side >> coefficient;
	const auto Area = getArea(#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>


using namespace std;

/**
* \brief вычисление площади прямоугольнока по формуле
* \param сonst double side - сторона данная по условию
* \param сonst double coefficient - коэфицент данная по условию
* \return - значение Area
*/
double getArea(const double side, const double coefficient);

/**
* \brief вычисление периметр прямоугольника по формуле
* \param сonst double side - сторона данная по условию
* \param сonst double coefficient - коэфицент данный по условию
* \return - значение Perimetr
*/
double getPerimetr(const double side, const double coefficient);

int main() {
  double side, coefficient;

  cout << "Введите длину и коэффициент и нажмите Enter: \n";
  cin >> side >> coefficient;
	const auto Area = getArea(side, coefficient);
	const auto Perimetr = getPerimetr(side, coefficient);
	cout << "Стророна a = " << side << "\nКоэффициент coefficient = " << coefficient << "\nПериметр = " << Area << "\nПлощадь = " << Perimetr;
	return 0;
}
double getArea(const double side, const double coefficient) { return pow(side, 2) * coefficient; } 
double getPerimetr(const double side, const double coefficient) { return 2 * side * (1 + coefficient); }, coefficient);
	const auto Perimetr = getPerimetr(a, coefficient);
	cout << "Стророна a = " << side << "\nКоэффициент n = " << coefficient << "\nПериметр = " << Area << "\nПлощадь = " << Perimetr;
	return 0;
}
double getArea(const double side, const double coefficient) { return pow(side, 2) * coefficient; } 
double getPerimetr(const double side, const double coefficient) { return 2 * side * (1 + coefficient); }