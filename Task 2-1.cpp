#include <iostream>
/**
 * \brief Константы дней недели.
 */
enum class WEEK
{
    /**
     * \brief Понедельник.
     */
    Monday,

    /**
     * \brief Вторник.
     */
     Tuesday,

     /**
      * \brief Среда.
      */
      Wednesday,
      /**
        * \brief Четверг.
        */
        Thursday,
        /**
          * \brief Пятница.
          */
          Friday,
          /**
            * \brief Суббота.
            */
            Saturday,
            /**
              * \brief Воскресенье.
              */
              Sunday
};
/**
 * \brief Константы месяцов.
 */
enum class MONTH
{
    /**
     * \brief Январь.
     */
    January,

    /**
     * \brief Февраль.
     */
     February,

     /**
      * \brief Март.
      */
      March,
      /**
        * \brief Апрель.
        */
        April,
        /**
          * \brief Май
          */
          May,
          /**
            * \brief Июнь.
            */
            June,
            /**
              * \brief Июль.
              */
              July,
              /**
                * \brief Август.
                */
                August,
                /**
                  * \brief Сентябрь.
                  */
                  September,
                  /**
                    * \brief Октябрь.
                    */
                    October,
                    /**
                      * \brief Ноябрь.
                      */
                      November,
                      /**
                        * \brief Декабрь.
                        */
                        December
};

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успеха.
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    int a = 0;
    std::cout << "Что вы хотите узнать? \nДень недели - 1\nНазвание месяца - 2\n";
    std::cin >> a;
    if (a == 1) {
        std::cout << "Введите день недели "
            << "\n1й день - " << static_cast<int>(WEEK::Monday)
            << "\n2й день - " << static_cast<int>(WEEK::Tuesday)
            << "\n3й день - " << static_cast<int>(WEEK::Wednesday)
            << "\n4й день - " << static_cast<int>(WEEK::Thursday)
            << "\n5й день - " << static_cast<int>(WEEK::Friday)
            << "\n6й день - " << static_cast<int>(WEEK::Saturday)
            << "\n7й день - " << static_cast<int>(WEEK::Sunday)<<std::endl;

        int color;
        std::cin >> color;


        const auto week = static_cast<WEEK>(color);
        switch (week)
        {
        case WEEK::Monday:
            std::cout << "Понедельник\n";
            break;
        case WEEK::Tuesday:
            std::cout << "Вторник\n";
            break;
        case WEEK::Wednesday:
            std::cout << "Среда\n";
            break;
        case WEEK::Thursday:
            std::cout << "Четверг\n";
            break;
        case WEEK::Friday:
            std::cout << "Пятница\n";
            break;
        case WEEK::Saturday:
            std::cout << "Суббота\n";
            break;
        case WEEK::Sunday:
            std::cout << "Воскресенье\n";
            break;
        }
    }
    else {
        std::cout << "Введите месяц"
            << "\n1й месяц - " << static_cast<int>(MONTH::January)
            << "\n2й месяц - " << static_cast<int>(MONTH::February)
            << "\n3й месяц - " << static_cast<int>(MONTH::March)
            << "\n4й месяц - " << static_cast<int>(MONTH::April)
            << "\n5й месяц - " << static_cast<int>(MONTH::May)
            << "\n6й месяц - " << static_cast<int>(MONTH::June)
            << "\n7й месяц - " << static_cast<int>(MONTH::July)
            << "\n8й месяц - " << static_cast<int>(MONTH::August)
            << "\n9й месяц - " << static_cast<int>(MONTH::September)
            << "\n10й месяц - " << static_cast<int>(MONTH::October)
            << "\n11й месяц - " << static_cast<int>(MONTH::November)
            << "\n12й месяц - " << static_cast<int>(MONTH::December)<<std::endl;

        int month;
        std::cin >> month;


        const auto Month = static_cast<MONTH>(month);
        switch (Month)
        {
        case MONTH::January:
            std::cout << "Январь\n";
            break;
        case MONTH::February:
            std::cout << "Февраль\n";
            break;
        case MONTH::March:
            std::cout << "Март\n";
            break;
        case MONTH::April:
            std::cout << "Апрель\n";
            break;
        case MONTH::May:
            std::cout << "Май\n";
            break;
        case MONTH::June:
            std::cout << "Июнь\n";
            break;
        case MONTH::July:
            std::cout << "Июль\n";
            break;
        case MONTH::August:
            std::cout << "Август\n";
            break;
        case MONTH::September:
            std::cout << "Сентябрь\n";
            break;
        case MONTH::October:
            std::cout << "Октябрь\n";
            break;
        case MONTH::November:
            std::cout << "Ноябрь\n";
            break;
        case MONTH::December:
            std::cout << "Декабрь\n";
            break;
        }
    }
    return 0;
}