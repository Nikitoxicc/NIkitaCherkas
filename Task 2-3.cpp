#include <iostream>
/**
 * \brief Константы фигур.
 */
enum class FIGURE
{
    /**
     * \brief Параллелограмм.
     */
    Parallelogram,

    /**
     * \brief Ромб.
     */
     Rhombus,

     /**
      * \brief Трапеция.
      */
      Trapezoid,
    /**
      * \brief Четырёхугольник.
      */
      Quadrilateral,
    /**
      * \brief Круг.
      */
      Circle,
    /**
      * \brief Эллипс.
      */
      Ellipse,
};


/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успеха.
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Площадь какой фигуры вы хотите узнать? "
        << "\nПараллелограмм - " << static_cast<int>(FIGURE::Parallelogram)
        << "\nРомб - "<< static_cast<int>(FIGURE::Rhombus)
        << "\nТрапеция - "<< static_cast<int>(FIGURE::Trapezoid)
        << "\nЧетырёхугольник - "<< static_cast<int>(FIGURE::Quadrilateral)
        << "\nКруг - "<< static_cast<int>(FIGURE::Circle)
        << "\nЭллипс - "<< static_cast<int>(FIGURE::Ellipse)<<std::endl;
    
    int figure;
    std::cin >> figure;
    
    
    const auto Figure = static_cast<FIGURE>(figure);
    switch (Figure)
    {
    case FIGURE::Parallelogram:
        std::cout << "Параллелограмм: S = a · h\n S = a · b · sin α\nS= (d1 · d2 · sin y)/2\n";
        break;
    case FIGURE::Rhombus:
        std::cout << "Ромб: S = a · h\n S = a^2 · sin α'\n(d1 · d2)/2\n";
        break;
    case FIGURE::Trapezoid:
    std::cout << "Трапеция: S= sqrt( p*(p-a) * (p-b) * (p-c) )\np=( a+b+c )/ 2\nS= ( h* ( a+b ) )/ 2\n";
        break;
    case FIGURE::Quadrilateral:
        std::cout << "Четырехугольник: S = √(p - a)(p - b)(p - c)(p - d) - abcd cos2θ\nS = p · r\nS= (d1 · d2 · sin y)/2\n";
        break;
    case FIGURE::Circle:
        std::cout << "Круг: S = π * r ^ 2\nS= (π * d ^ 2)/4";
        break;
    case FIGURE::Ellipse:
        std::cout << "Элипс: S = π · a · b\n";
        break;
        }
    return 0;
}
