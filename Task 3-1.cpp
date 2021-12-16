#include <cmath>
#include <iostream>
using namespace std;

/**
 * \brief Проверка косинуса на равенство c 0.
 * \param x - константа, имеющая тип данных с плавающей точкой двойной точности.
 * \param flag - логическая переменная,указывающая на истинность или ложность условия. 
 * \return flag - возвращает выполнение или невыполнение условия.
**/
bool isCalculated(const double x);

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
        if (isCalculated(x))
           cout << "y = " << getY(x) << endl;
        else cout<< "err"<< endl;
    }
    return 0;
}

bool isCalculated(const double x){
    bool flag = true;
    const double epsilon = 0.001;
    if (abs(cos(x)) <= epsilon)
      flag = false;
    return flag;
}

double getY(const double x) {
    return tan(x) - 1.0 / 3.0 * pow(tan(x), 3 ) + 0.2 * pow(tan(x), 5 ) - 1.0 / 3.0;}
