#include <cmath>
#include <iostream>

using namespace std;

/**
* \brief Математическая функция, рассчитывающая значение функции y
* \param x - константа, имеющая тип данных с плавающей точкой двойной точности
* \param q - константа, заданная по условию
* \return Возвращает значение функции y
**/

double getY(const double x, const double q);

/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успешного выполнения.
*/
int main()
{
    const double x = 0;
    const double q = 1.0 / 3;
    for (double x = 0; x <= 0.8; x = x + 0.01)
    {
        cout << "y = " << getY(x,q) << endl;
    }
}

double getY(const double x, const double q)
{
    return tan(x) - q * pow(tan(x), 3 ) + 0.2 * pow(tan(x), 5 ) - q;
}
