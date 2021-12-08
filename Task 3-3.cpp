#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

/**
 * \brief Расчет функции exp в степени x.
 * \param x Показатель степени.
 * \return Значение exp в степени x.
 */
double GetEPowerX(const double x);

/**
 * \brief Вычисление рекуррентного члена ряда.
 * \param x Параметр функции, аппроксимируемой рядом.
 * \param n Индекс члена ряда.
 * \return Значение рекуррентного члена.
 */
double GetRecurrent(const double x, const unsigned int n);

/**
 * \brief Вычисление суммы ряда от x, до того момента пока |x_i - x_{x-1}| >= e
 * \param x Показатель степени.
 * \param e Погрешность вычислений.
 * \return Значение 3 в степени x.
 */
double GetSumOfSeries(const double x, const double e);

/**
 * \brief Форматный вывод в поток вывода out.
 * \param argument Аргумент табулируемой функции.
 * \param function Значение табулируемой функции.
 * \param series Аппроксимация табулируемой функции.
 */
void FormatOutput(const double argument, const double function, const double series, ostream& out = cout);

/**
 * \brief Точка входа в программу.
 * \return Код ошибки (0 - успех).
 */
int main()
{
    const auto leftBound = 0.1;
    const auto rightBound = 1.0;
    const auto e = 0.0001;
    const auto h = 0.01;

    auto x = leftBound;
    while (x <= rightBound + e)
    {
        const auto function = GetEPowerX(x);
        const auto series = GetSumOfSeries(x, e);

        FormatOutput(x, function, series);

        x += h;
    }

    return 0;
}

double GetEPowerX(const double x)
{
    return (exp(x) + exp(-x)) / 2.0;
}

double GetRecurrent(const double x, const unsigned int n)
{
    return pow(x, 2 * n) / tgamma(2 * n + 1);
}

double GetSumOfSeries(const double x, const double e)
{
    auto previous = 0.0;
    auto current = 1.0;
    auto sum = current;
    unsigned int n = 0;

    do
    {
        previous = current;
        current = previous * GetRecurrent(x, n);
        sum += current;
        n++;
    } while (abs(previous - current) >= e);

    return sum;
}

void FormatOutput(const double argument, const double function, const double series, std::ostream&)
{
    cout << setw(10) << argument << " | ";
    cout << setw(15) << function << " | ";
    cout << setw(15) << series << "\n";
}