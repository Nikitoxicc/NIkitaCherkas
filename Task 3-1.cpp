#include <cmath>
#include <iostream>
using namespace std;

/**
 * \brief Проверка косинуса на равенство 0.
 *\param x - константа, имеющая тип данных с плавающей точкой двойной точности.
 * return 0 - в случае неравенства 0.
**/
double isCalculated(const double x);

/**
* \brief Математическая функция, рассчитывающая значение функции y.
* \param x - константа, имеющая тип данных с плавающей точкой двойной точности.
* \return Возвращает значение функции y.
**/
double getY(const double x);
/**
* \brief Точка входа в программу.
* \param step - шаг.
* \param border - Максимальное значение x.
* \param value1 - Начальное значение x.
* \return Возвращает 0 в случае успешного выполнения.
*/
int main()
{
    const double x = 0;
    const double step = 0.05;
    const double border = 0.8;
    const int value1 = 0;
    for (double x = value1; x <= border; x = x + step)
    {
        cout << "y = " << getY(x) << endl;
    }
}

double isCalculated(const double x){
    const double epsilon = 0.001;
    if ((cos(x) - 0) <= epsilon)
      return 0;
}

double getY(const double x) {
    if (isCalculated(x) == 0)
     return tan(x) - 1.0 / 3.0 * pow(tan(x), 3 ) + 0.2 * pow(tan(x), 5 ) - 1.0 / 3.0;}
