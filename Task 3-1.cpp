#include <cmath>
#include <iostream>
using namespace std;

/**
 * \brief Проверка косинуса на равенство c 0.
 * \param x - аргумент функции.
 * \return - возвращает выполнение или невыполнение условия.
**/
bool isCalculated(const double x);

/**
 * \brief Расчет функции.
 * \param x - аргумент функции.
 * \return Возвращает значение функции y.
**/
double getY(const double x);
/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успешного выполнения.
 */
int main()
{
    const double x = 0;
    const double step = 0.05;
    const double border = 0.8;
    const double firstValue = 0.0;
    for (double x = firstValue; x <= border; x = x + step)
    {
        if (!isCalculated(x))
           cout << "y = " << getY(x) << endl;
        else cout<< "err"<< endl;
    }
    return 0;
}

bool isCalculated(const double x){
    const double epsilon = 0.001;
    return abs(cos(x)) <= epsilon;
}

double getY(const double x) {
    return tan(x) - 1.0 / 3.0 * pow(tan(x), 3 ) + 0.2 * pow(tan(x), 5 ) - 1.0 / 3.0;}
