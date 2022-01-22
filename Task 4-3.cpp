#include <iostream>
#include <string>
#include <ctime>
#include <random>
using namespace std;

/**
 * \brief Вычисление нового размера массива.
 * \param myArray Массив.
 * \param rows Количество строк.
 * \param columns Количество столбцов.
 * \return Количество строк нового массива.
*/
size_t NewSize(int** myArray, const int rows, const int columns);

/**
 * \brief Замена максимального элемента столбца на 0.
 * \param myArray Массив.
 * \param rows Количество строк.
 * \param columns Количество столбцов.
 * \param minValue Минимальное значение массива.
 * \return Изменённый массив.
*/
void MaxToZeroChange(int** myArray, const int rows, const int columns, const int minValue);

/**
 * \brief Добавление строк в массив, в случае выполнения условия.
 * \param myArray Массив.
 * \param newArray Новый изменённый массив.
 * \param rows Количество строк.
 * \param columns Количество столбцов.
 * \return Изменённый массив.
*/
int** StrAddIfTwoZeros(int** myArray, int rows, int columns);

/**
 * \brief Заполнение массива случайными числами.
 * \param rows количество строчек.
 * \param columns количество столбцов.
 * \param minValue минимальное значение элементов массива.
 * \param maxValue максимальное значение элементов массива.
 * \return заполненный массив.
 */
int** FillRandomArray(const int rows, const int columns, int minValue, int maxValue);

/**
 * \brief Вывод массива на консоль.
 * \param myArray массив.
 * \param rows количество строчек.
 * \param columns количество столбцов.
 */
void ArrayPrint(int** myArray, const int rows, const int columns);

/**
 * \brief Метод, возвращающий заполненный пользователем массив.
 * \param rows количество строчек.
 * \param columns количество столбцов.
 * \param minValue минимальное значение элементов массива.
 * \param maxValue максимальное значение элементов массива.
 * \return заполненный массив.
 */
int** FillUserArray(const int rows, const int columns);

/**
 * \brief Варианы ввода массива.
 */
enum class ArrayInputWay
{
    random,
    keyboard
};

/**
 * \brief Точка входа в программу.
 * \return 0, в случае успеха.
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    int rows = 0;
    int columns = 0;
    cout << "Введите количество строк и столбцов" << endl;
    cin >> rows >> columns;

    if (rows <= 0 || columns <= 0) {
        cout << "Err";
        return 1;
    }

    cout << "Как вы хотите заполнить массив?\n";
    cout << static_cast<int>(ArrayInputWay::random) << " - random,\n";
    cout << static_cast<int>(ArrayInputWay::keyboard) << " - keyboard.\n";
    cout << "Ваш выбор: ";
    int choice;
    cin >> choice;

    const auto chosen = static_cast<ArrayInputWay>(choice);
    int** myArray = nullptr;

    auto minValue = 0;
    auto maxValue = 0;
    cout << "Введите диапазон чисел массива (сначала минимум, потом максимум) " << endl;
    cin >> minValue >> maxValue;
    if (maxValue <= minValue)
    {
        cout << "Введен неправильный диапазон!" << endl;
    }

    switch (chosen)
    {
    case ArrayInputWay::random:
    {
        myArray = FillRandomArray(rows, columns, minValue, maxValue);
        break;
    }
    case ArrayInputWay::keyboard:
    {
        myArray = FillUserArray(rows, columns);
        break;
    }
    }

    ArrayPrint(myArray, rows, columns);

    MaxToZeroChange( myArray, rows, columns, minValue);

    int** newArray2 = new int*[NewSize(myArray, rows, columns)];

    size_t k = NewSize(myArray, rows, columns);

    for (size_t i = 0; i < k; i++) {

        newArray2[i] = new int[columns];
    }

    cout << "Массив с добавленными строками: ";
    newArray2 = StrAddIfTwoZeros(myArray, rows, columns);
    ArrayPrint(newArray2, NewSize(myArray, rows, columns), columns);
    
    if (newArray2 != nullptr) {

        delete[] newArray2;
        newArray2 = nullptr;

    }

    if (myArray != nullptr) {

        delete[] myArray;
        myArray = nullptr;

    }
    return 0;

}


size_t NewSize(int** myArray, const int rows, const int columns) {

    int countRows = 0;
    int countZeros = 0;
    for (size_t i = 0; i < rows; i++) {
        countZeros = 0;
        for (size_t j = 0; j < columns; j++) {
            if (myArray[i][j] == 0)
                countZeros++;
        }
    if (countZeros >= 2)
        countRows++;
    }

    return rows + countRows;
}

void MaxToZeroChange(int** myArray, const int rows,const int columns, const int minValue) {

    int max = minValue;

    for (size_t j = 0; j < rows; j++)
    {
        max = minValue;

        for (size_t i = 0; i < columns; i++)
        {
            if (myArray[i][j] > max){
                max = myArray[i][j];
            }
        }

        for (size_t i = 0; i < columns; i++)
        {
            if (myArray[i][j] == max) {
                myArray[i][j] = 0;
            }
        }
    }
    ArrayPrint(myArray, rows, columns);
}

int** StrAddIfTwoZeros(int** myArray,  int rows, int columns) {
    
    int c = 0;
    size_t k = NewSize(myArray, rows, columns);

    int** newArray = new int* [NewSize(myArray, rows, columns)];

    for (size_t i = 0; i < k; i++) {

        newArray[i] = new int[columns];
    }

    for (size_t i = 0, index = 0; i < rows; i++, index++) {
        c = 0;

        for (size_t j = 0; j < columns; j++) {

            newArray[index][j] = myArray[i][j];

        }
        for (size_t j = 0; j < columns; j++) {
            if (myArray[i][j] == 0)
                c++;
        }
        if (c >= 2) {

            index++;

            for (size_t j = 0; j < columns; j++) {

                newArray[index][j] = myArray[0][j];

            }
        }
    }

    return newArray;
}

void ArrayPrint(int** myArray, const int rows, const int columns)
{
    if (myArray == nullptr)
    {
        cout << "Массива не существует";
    }
    else {
        cout << "Массив:\n";
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < columns; j++) {
                cout << myArray[i][j] << " ";
            }
            cout << endl;
        }
        cout << "\n";

    }
}

int** FillRandomArray(const int rows, const int columns, const int minValue, const int maxValue)
{
    random_device rd;

    mt19937 gen(rd());

    const std::uniform_int_distribution<> uniformIntDistribution(minValue, maxValue);

    int** myArray = new int* [rows];

    for (size_t index = 0; index < rows; index++) {
        myArray[index] = new int[columns];
    }
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            myArray[i][j] = uniformIntDistribution(gen);
        }
    }
    return myArray;
}

int** FillUserArray(const int rows, const int columns)
{
    int** myArray = new int* [rows];

    for (size_t index = 0; index < rows; index++) {
        myArray[index] = new int[columns];
    }
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            cin>> myArray[i][j];
        }
    }
    return myArray;
}
