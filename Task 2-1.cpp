#include <iostream>

using namespace std;
/**
* \brief замена переменных разными способами
* \param int c - переменная, вводимая пользователем
* \param int a - переменная вводимая пользователем
* \return - день недли/месяца
*/
void getA(const int c, const int a);
int main()
{
    int c=0;
    int a=0;
    cout<< "Что вы хотите узнать?"<<endl;
    cout<< "1.Название месяца \n2.Название дня недели" <<endl;
    cin>>c;
    if (c!=1 && c!=2)
     cout<<"error";
    else{
     cout<< "Введите номер дня недели/месяца"<<endl;
     cin>>a;
     if ((a>12 || a<1 and c==1) || ((a>7 || a<1 and c==2)))
      cout<<"error";
     getA(c,a);
    }
    return 0;
}
void getA(const int c, const int a){
    if (c==1)
     switch(a){
         case 1: cout<<"Январь";break;
         case 2: cout<<"Февраль";break;
         case 3: cout<<"Март";break;
         case 4: cout<<"Апрель";break;
         case 5: cout<<"Май";break;
         case 6: cout<<"Июнь";break;
         case 7: cout<<"Июль";break;
         case 8: cout<<"Август";break;
         case 9: cout<<"Сентябрь";break;
         case 10: cout<<"Октябрь";break;
         case 11: cout<<"Ноябрь";break;
         case 12: cout<<"Декабрь";break;
     }
    else
     switch(a){
         case 1: cout<<"Понедельник";break;
         case 2: cout<<"Вторник";break;
         case 3: cout<<"Среда";break;
         case 4: cout<<"Четверг";break;
         case 5: cout<<"Пятница";break;
         case 6: cout<<"Суббота";break;
         case 7: cout<<"Воскресенье";break;
     }
}