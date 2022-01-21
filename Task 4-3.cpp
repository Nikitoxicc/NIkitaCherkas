#include <iostream>
#include <string>
#include <ctime>
#include <random>
using namespace std;

/**
 * \brief Проверка ввода количества строчек.
 * \return Размер массива.
 */
size_t GetSize();

/**
 * \brief Проверка ввода количества столбцов.
 * \return Размер массива.
 */
size_t GetSize2();

/**
 * \brief Вычисление нового размера массива.
 * \param myArray Массив.
 * \param size Количество строк.
 * \param size2 Количество столбцов.
 * \return Количество строк нового массива.
*/
size_t NewSize(int** myArray, const size_t size, const size_t size2);

/**
 * \brief Замена максимального элемента столбца на 0.
 * \param myArray Массив.
 * \param size Количество строк.
 * \param size2 Количество столбцов.
 * \param minValue Минимальное значение массива.
 * \return Изменённый массив.
*/
int** MaxToZeroChange(int** myArray, const size_t size, const size_t size2, const int minValue);

/**
 * \brief Добавление строк в массив, в случае выполнения условия.
 * \param myArray Массив.
 * \param size Количество строк.
 * \param size2 Количество столбцов.
 * \return Изменённый массив.
*/
int** StrAddIfTwoZeros(int** myArray, int** newArray, size_t size, size_t size2);

/**
 * \brief Заполнение массива случайными числами.
 * \param size количество строчек.
 * \param size2 количество столбцов.
 * \param minValue минимальное значение элементов массива.
 * \param maxValue максимальное значение элементов массива.
 * \return заполненный массив.
 */
int** FillRandomArray(const size_t size, const size_t size2, int minValue, int maxValue);

/**
 * \brief Вывод массива на консоль.
 * \param myArray массив.
 * \param size количество строчек.
 * \param size2 количество столбцов.
 */
void ArrayPrint(int** myArray, const size_t size, const size_t size2);

/**
 * \brief Метод, возвращающий заполненный пользователем массив.
 * \param size количество строчек.
 * \param size2 количество столбцов.
 * \param minValue минимальное значение элементов массива.
 * \param maxValue максимальное значение элементов массива.
 * \return заполненный массив.
 */
int** FillUserArray(const size_t size, const size_t size2);

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
    size_t size = GetSize();
    size_t size2 = GetSize2();

    if (size == 0 || size2 == 0)
        return 1;

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
        myArray = FillRandomArray(size, size2, minValue, maxValue);
        break;
    }
    case ArrayInputWay::keyboard:
    {
        myArray = FillUserArray(size, size2);
        break;
    }
    }

    ArrayPrint(myArray, size, size2);

    myArray = MaxToZeroChange( myArray, size, size2, minValue);
    ArrayPrint(myArray, size, size2);

    int** newArray = new int*[NewSize(myArray, size, size2)];
    cout << "Массив с добавленными строками: ";
    newArray = StrAddIfTwoZeros(myArray,newArray, size, size2);
    ArrayPrint(newArray, NewSize(myArray, size, size2), size2);
    
    if (newArray != nullptr) {

        delete[] newArray;
        newArray = nullptr;

    }

    if (myArray != nullptr) {

        delete[] myArray;
        myArray = nullptr;

    }
    return 0;

}

size_t GetSize() {
    size_t size = 0;
    cout << "Введите количество строк " << endl;
    cin >> size;
    if (size <= 0)
    {
        cout << "Введён неверный размер";
        return 0;
    }
    else
        return size;
};

size_t GetSize2() {
    size_t size2 = 0;
    cout << "Введите количество столбцов" << endl;
    cin >> size2;
    if (size2 <= 0)
    {
        cout << "Введён неверный размер";
        return 0;
    }
    else
        return size2;
};

size_t NewSize(int** myArray, const size_t size, const size_t size2) {

    int k = 0, c;
    for (size_t i = 0; i < size; i++) {
        c = 0;
        for (size_t j = 0; j < size2; j++) {
            if (myArray[i][j] == 0)
                c++;
        }
    if (c >= 2)
        k++;
    }

    return size + k;
}

int** MaxToZeroChange(int** myArray, const size_t size,const size_t size2, const int minValue) {

    int max = minValue;

    for (size_t j = 0; j < size; j++)
    {
        max = minValue;

        for (size_t i = 0; i < size2; i++)
        {
            if (myArray[i][j] > max){
                max = myArray[i][j];
            }
        }

        for (size_t i = 0; i < size2; i++)
        {
            if (myArray[i][j] == max) {
                myArray[i][j] = 0;
            }
        }
    }
    return myArray;
}

int** StrAddIfTwoZeros(int** myArray, int** newArray,  size_t size, size_t size2) {
    
    size_t k = NewSize(myArray, size, size2);
    int c = 0;
    

    for (size_t i = 0; i < k; i++) {

        newArray[i] = new int[size2];
    }

    for (size_t i = 0, index = 0; i < size; i++, index++) {
        c = 0;

        for (size_t j = 0; j < size2; j++) {

            newArray[index][j] = myArray[i][j];

        }
        for (size_t j = 0; j < size2; j++) {
            if (myArray[i][j] == 0)
                c++;
        }
        if (c >= 2) {

            index++;

            for (size_t j = 0; j < size2; j++) {

                newArray[index][j] = myArray[0][j];

            }
        }
    }

    return newArray;
}

void ArrayPrint(int** myArray, const size_t size, const size_t size2)
{
    if (myArray == nullptr)
    {
        cout << "Массива не существует";
    }
    else {
        cout << "Массив:\n";
        for (size_t i = 0; i < size; i++) {
            for (size_t j = 0; j < size2; j++) {
                cout << myArray[i][j] << " ";
            }
            cout << endl;
        }
        cout << "\n";

    }
}

int** FillRandomArray(const size_t size, const size_t size2, const int minValue, const int maxValue)
{
    random_device rd;

    mt19937 gen(rd());

    const std::uniform_int_distribution<> uniformIntDistribution(minValue, maxValue);

    int** myArray = new int* [size];

    for (size_t index = 0; index < size; index++) {
        myArray[index] = new int[size2];
    }
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size2; j++)
        {
            myArray[i][j] = uniformIntDistribution(gen);
        }
    }
    return myArray;
}

int** FillUserArray(const size_t size, const size_t size2)
{
    int** myArray = new int* [size];

    for (size_t index = 0; index < size; index++) {
        myArray[index] = new int[size2];
    }
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size2; j++)
        {
            cin>> myArray[i][j];
        }
    }
    return myArray;
}