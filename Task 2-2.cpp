#include <iostream>
#include <cmath>
#include <tgmath.h>
#include <stdlib.h>

using namespace std;

/**
* \brief вычисление переменной y по заданному x
* \param сonst double x - переменная, которую вводит пользователь
* \param сonst double y - искомая переменная
* \param const double a - переменная, данная по условию
* \return - значение y
*/
double getY(const double x, const double a);

int main()
{
    const double a=20.3;
    double x=0;
    double y=0;
    cout<<"Введите значение переменной x"<<endl;
    cin>>x;
    y=getY(x,a);
    cout<<"Y = " << y <<endl;
    return 0;
}
double getY(const double x, const double a){
    if (x>1)
      return log10(x+1);
    else 
      return sin(2)*sqrt(abs(a*x));
}