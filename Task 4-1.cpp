#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

/**
 * \brief Заполнение массива случайными числами.
 * \param size размер массива.
 * \param minValue минимальное значение элементов массива.
 * \param maxValue максимальное значение элементов массива.
 * \return заполненный массив.
 */
int* FillRandomArray(size_t size, int minValue, int maxValue);

/**
 * \brief Вывод массива на консоль.
 * \param array массив.
 * \param size размер массива.
 */
void ArrayPrint(const int* array, size_t size);

/**
 * \brief Функция определяет, есть ли 2 пары соседних элементов с одинаковыми знаками.
 * \param array массив.
 * \param size размер массива.
 * \return true, если имеются 2 элемента с одинаковыми знаками, false если нет.
 */
bool isPairs(const int* array, const size_t size);

/**
 * \brief Замена минимального элемента массива на средний.
 * \param array массив.
 * \param size размер массива.
 * \param maxValue максимальное значение, которое может принимать элемент массива.
 */
void minToAverageChange(const int* array, const size_t size, const int maxValue);

/**
 * \brief Определяет, четность или нечетность числа.
 * \param element число.
 * \return если нечетное, то true. Если четное - false.
 */
bool IsOdd(int element);

/**
 * \brief Копирование исходного массива.
 * \param array исходный массив.
 * \param size размер массива.
 * \return новый массив со скопированными элементами.
 */
int* ArrayCopy(const int* array, size_t size);

/**
 * \brief Метод, возвращающий заполненный пользователем массив.
 * \param size размер массива.
 * \param minValue минимальное значение элементов массива.
 * \param maxValue максимальное значение элементов массива.
 * \return заполненный массив.
 */
int* FillUserArray(size_t size);

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
    cout << "Введите размер массива = ";
    size_t size;
    cin >> size;

    if (size == 0)
    {
        cout << "Введён неверный размер!\n";
    }

    cout << "Как вы хотите заполнить массив?\n";
    cout << static_cast<int>(ArrayInputWay::random) << " - random,\n";
    cout << static_cast<int>(ArrayInputWay::keyboard) << " - keyboard.\n";
    cout << "Ваш выбор: ";
    int choice;
    cin >> choice;
    
    const auto chosen = static_cast<ArrayInputWay>(choice);
    int* myArray = nullptr;

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
        myArray = FillRandomArray(size, minValue, maxValue);
        break;
    }
    case ArrayInputWay::keyboard:
    {
        myArray = FillUserArray(size);
        break;
    }
    }

    ArrayPrint( myArray, size);

    cout << "Массив с заменённым минимальным элементом: ";
    
    minToAverageChange(myArray, size, maxValue);

    if (isPairs(myArray, size)) {
        cout << "Есть 2 пары элементов, знаки которых одинаковы.";
    }
    else {
        cout << "Нет таких 2 пар соседних элементов, знаки которых одинаковы.";
    }
    cout << endl;
    return 0;
    
}

bool isPairs(const int* array, const size_t size ) {
    bool flag = false;
    int countPairs = 0;
    int previous = 0;
    const auto newArray = ArrayCopy(array, size);
    for (size_t index = 1; index < size; index=index + 2) {
        previous = newArray[index - 1];
        if (previous > 0 && newArray[index] > 0 || previous > 0 && newArray[index] > 0) {
            countPairs++;
        }
    }
    if (countPairs > 2) {
        flag = true;
    }
    
    return flag;
}

int* ArrayCopy(const int* array, const size_t size)
{
    if (array == nullptr)
        return nullptr;

    const auto copiedArray = new int[size];
    for (size_t index = 0; index < size; index++)
    {
        copiedArray[index] = array[index];
    }
    return copiedArray;
}

void minToAverageChange(const int* array, const size_t size, const int maxValue )
{
    if (array == nullptr)
        cout << "Массив пуст";

    const auto newArray = ArrayCopy(array, size);
    auto minArrayValue = maxValue;

    for (size_t index = 0; index < size; index++) {
        if (newArray[index] < minArrayValue) {
            minArrayValue = newArray[index];
        }
    }
    newArray[(size + 1) / 2] = minArrayValue;

    cout << "\nИзменённый массив:\n";

    for (size_t index = 0; index < size; index++) {
        cout << newArray[index];
        cout << " ";
    }
    cout << "\n";
}

bool IsOdd(const int element)
{
    return element % 2 != 0;
}

void ArrayPrint(const int* array, const size_t size)
{
    if (array == nullptr)
    {
        cout << "Массива не существует";
    }
    else {
        cout << "\nМассив:\n";
        for (size_t index = 0; index < size; index++) {
            cout << array[index] << " ";
        }
        cout << "\n";

    }
}

int* FillRandomArray(const size_t size, const int minValue, const int maxValue)
{
    const auto area = abs(minValue) + abs(maxValue) + 1;
    auto* array = new int[size];
    for (size_t index = 0; index < size; index++) {
        array[index] = rand() % area + minValue;
        cout << array[index] << endl;
    }

    return array;
}

int* FillUserArray(const size_t size)
{
    auto* array = new int[size];
    cout << "Введите элементы массива" << "\n";
    for (size_t index = 0; index < size; index++)
    {
        cin >> array[index];
    }
    return array;
}