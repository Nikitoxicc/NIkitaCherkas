#include <iostream>
#include <string>
#include <ctime>
#include <random>
using namespace std;

/**
 * \brief Проверка ввода размера массива.
 * \return Размер массива.
 */
size_t GetSize();

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
 * \param myArray массив.
 * \param size размер массива.
 */
void ArrayPrint(const int* myArray, size_t size);

/**
 * \brief Удаление нечетных элементов, кратных 3.
 * \param myArray массив.
 * \param size размер массива.
 * \return изменённый массив.
 */
int* IsOddAndMulpiples3(int* myArray, size_t size);

/**
 * \brief Создание нового массива по заданным формулам.
 * \param myArray массив.
 * \param size размер массива.
 * \return изменённый массив.
 */
int* ArrayChange(int* myArray, size_t size);

/**
 * \brief Замена минимального элемента массива на средний.
 * \param myArray массив.
 * \param size размер массива.
 * \param maxValue максимальное значение, которое может принимать элемент массива.
 */
int* MinToLastChange(int* myArray, const size_t size, const int maxValue);

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
    setlocale(LC_ALL, "Russian");
    size_t size = GetSize();

    if (size == 0)
        return 1;

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

    cout << "Массив с заменённым минимальным элементом: " << endl;

    int* newArray = new int[size];
    newArray = MinToLastChange(myArray, size, maxValue);
    ArrayPrint(newArray, size);

    if (newArray != nullptr) {

        delete[] newArray;
        newArray = nullptr;

    }

    int* newArray2 = new int[size];
    cout << "Массив с удалёнными нечетными элементами, кратными 3м" << endl;
    newArray2 = IsOddAndMulpiples3(myArray, size);
    ArrayPrint(newArray2, size);

    if (newArray2 != nullptr) {

        delete[] newArray2;
        newArray2 = nullptr;

    }

    int* newArray3 = new int[size];
    cout << "Заменённый массив по формулам A[i] = C[i] + i и A[i] = C[i] - i" << endl;
    newArray3 = ArrayChange(myArray, size);
    ArrayPrint(newArray3, size);

    if (newArray3 != nullptr) {

        delete[] newArray3;
        newArray3 = nullptr;

    }

    if (myArray != nullptr) {

        delete[] myArray;
        myArray = nullptr;

    }
    return 0;

}

size_t GetSize() {
    int size = 0;
    cout << "Введите размер массива" << endl;
    cin >> size;
    if (size <= 0)
    {
        cout << "Введён неверный размер";
        return 0;
    }
    else
        return size;
};

int* MinToLastChange(int* myArray, const size_t size, const int maxValue)
{
    int temprary = 0;
    if (myArray == nullptr) {
        cout << "Массив пуст";
        return nullptr;
    }

    auto minArrayValue = abs(maxValue);
    size_t minElementIndex;

    for (size_t index = 0; index < size; index++) {
        if (abs(myArray[index]) < minArrayValue) {
            minArrayValue = abs(myArray[index]);
            minElementIndex = index;
        }
    }

    temprary = myArray[minElementIndex];
    myArray[minElementIndex] = myArray[size - 1];
    myArray[size - 1] = temprary;

    return myArray;
}

int* ArrayChange(int* myArray, size_t size)
{
    int temprary = 0;
    if (myArray == nullptr) {
        cout << "Массив пуст";
        return nullptr;
    }

    int* newArray = new int[size];
    for (size_t index = 0, newindex = 0; index < size; index++) {
        if (myArray[index] % 2 == 1) {
            newArray[newindex] = myArray[index] - index;
        }
        else {
            newArray[newindex] = myArray[index] + index;
        }
        newindex++;
    }
    
    return newArray;
}

int* IsOddAndMulpiples3(int* myArray, size_t size)
{
    if (myArray == nullptr) {
        cout << "Массив пуст";
        return nullptr;
    }

    size_t count = 0;
    for (size_t index = 0; index < size; index++) {
        if (myArray[index] % 2 == 1 && myArray[index] % 3 == 0) {
            count++;
        }
    }

    int* newArray = new int[size - count];
    for (size_t index = 0, newindex = 0; index < size; index++) {
        if (!(myArray[index] % 2 == 1 && myArray[index] % 3 == 0)) {
            newArray[newindex] = myArray[index];
            newindex++;
        }
    }
    size = size - count;
    return newArray;
}

void ArrayPrint(const int* myArray, const size_t size)
{
    if (myArray == nullptr)
    {
        cout << "Массива не существует";
    }
    else {
        cout << "Массив:\n";
        for (size_t index = 0; index < size; index++) {
            cout << myArray[index] << " ";
        }
        cout << "\n";

    }
}

int* FillRandomArray(const size_t size, const int minValue, const int maxValue)
{
    random_device rd;

    mt19937 gen(rd());

    const std::uniform_int_distribution<> uniformIntDistribution(minValue, maxValue);

    auto* myArray = new int[size];

    for (size_t index = 0; index < size; index++)
    {
        myArray[index] = uniformIntDistribution(gen);
    }
    return myArray;
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
