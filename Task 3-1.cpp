#include <cmath>
#include <iostream>

using namespace std;

/**
* \brief Математическая функция, рассчитывающая значение функции y
* \param const double x - константа, имеющая тип данных с плавающей точкой двойной точности
* \param const double q - константа, заданная по условию
* \return Возвращает значение функции y
**/

double gety(const double x, const double q);

/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успешного выполнения.
*/
int main()
{
    const double x = 0;
    const double q = 1/3;
    const auto y = gety(x,q);
}

double gety(const double x, const double q)
{
    for (double x = 0; x <= 0.8; x = x + 0.01)
    {
        cout << "y = " << tan(x)- q*pow(tan(x),3) + 0.2 * pow(tan(x),5) - q << endl;
    }
    return 1;
}