#include <iostream>

using namespace std;

/**
 * \brief функция определения текущего элемента ряда.
 * param k - переменная для вычисления элемента ряда.
 * \return значение текущего элемент ряда.
*/
double getCurrent(const int k);

/**
 * \brief функция вычисления суммы первых n элементов ряда.
 * param n - количество элементов ряда.
 * param k - переменная для вычисления элемента ряда.
 * \return сумма первых n элементов ряда.
 */
double getSumm1(int n, int k);

/**
 * \brief вычисление суммы членов ряда не меньших числа e.
 * param e - константа по условию.
 * param k - переменная для вычисление элемента ряда.
 * \return сумма членов ряда не меньших числа e.
*/
double getSumm2(double e, int k);

/**
 * \brief точка входа в программу.
 * return 0 в случае успеха.
*/
int main()
{
    int n;
    double e = 0.0;
    int k = 0;
    cout<<"Введите количество членов ряда"<< endl;
    cin >> n;
    cout<< "Введите e ";
    cin>>e;
    cout<< getSumm1(n, k)<< endl;
    cout<< getSumm2(e, k);
    return 0;
}

double getCurrent(const int k){
    return 1.0 / (2.0 * k + 1);
}

double getSumm1(int n,int k){
    double sum;
    for (int i = 1; i <=  n; i++){
        sum = sum + getCurrent(k);
        k=k+1;
    }
return sum;
}

double getSumm2(double e, int k){
    double cur, sum;
    cur = getCurrent(k);
    while (cur > e){
        sum = sum + cur;
        k++;
        cur = getCurrent(k);
    }
    return sum;
}
