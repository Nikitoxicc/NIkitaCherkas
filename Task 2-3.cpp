#include <iostream>
#include <cmath>
using namespace std;

/**
* \brief Вывод формулы площади по заданной фигуре
* \param сonst int a - номер фигуры по списку
* \return - формулу фигуры
*/
void getFigure(const int a);

int main()
{
int a = 0;
cout<<"Введите цифру, под которой назначена фигура"<<endl;
cout<<"\n 1.Параллелограм \n 2.Ромб \n 3.Трапеция \n 4.Четырёхугольник \n 5.Круг \n 6.Элипс\n";
cin>>a;
getFigure(a);
return 0;
}

void getFigure(const int a) {
switch(a) {
case 1: cout<<"Параллелограмм: S = a · h\n S = a · b · sin α\nS= (d1 · d2 · sin y)/2\n"; break;
case 2: cout<<"Ромб: S = a · h\n S = a^2 · sin α'\n(d1 · d2)/2\n"; break;
case 3: cout<<"Трапеция: S= sqrt( p*(p-a) * (p-b) * (p-c) )\np=( a+b+c )/ 2\nS= ( h* ( a+b ) )/ 2"; break;
case 4: cout<<"Четырехугольник: S = √(p - a)(p - b)(p - c)(p - d) - abcd cos2θ\nS = p · r\nS= (d1 · d2 · sin y)/2"; break;
case 5: cout<<"Круг: S = π * r ^ 2\nS= (π * d ^ 2)/4"; break;
case 6: cout<<"Элипс: S = π · a · b"; break;
}
}