#include <iostream>
#include <string>
#include <ctime>

using namespace std;

/**
 * \brief Проверка ввода размера массива.
 * \return Размер массива.
 */
size_t GetSize();

/**
 * \brief Вывод элементов массива, значения которых больше значения предыдущего.
 * \param myArray массив.
 * \param size размер массива.
 */
void PrintBiggerElementsIndex(const int* myArray, const size_t size);

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
 * \brief Функция определяет, есть ли 2 пары соседних элементов с одинаковыми знаками.
 * \param myArray массив.
 * \param size размер массива.
 * \return true, если имеются 2 элемента с одинаковыми знаками, false если нет.
 */
bool ArePairs(const int* myArray, const size_t size);

/**
 * \brief Замена минимального элемента массива на средний.
 * \param myArray массив.
 * \param size размер массива.
 * \param maxValue максимальное значение, которое может принимать элемент массива.
 */
void MinToAverageChange(int* myArray, const size_t size, const int maxValue);

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
    
    ArrayPrint( myArray, size);
    
    cout << "Массив с заменённым минимальным элементом: ";
        
    MinToAverageChange(myArray, size, maxValue);
    ArrayPrint(myArray, size);
        
    PrintBiggerElementsIndex(myArray, size);
    
    if (ArePairs(myArray, size)) {
        cout << "Есть 2 пары элементов, знаки которых одинаковы.";
    }
    else{
        cout << "Нет таких 2 пар соседних элементов, знаки которых одинаковы.";
    }
    cout << endl;
        
    if (myArray != nullptr) { 
            
        delete[] myArray;
        myArray = nullptr;
        
    }
    return 0;
    
}

size_t GetSize(){
    int size = 0;
    cout << "Введите размер массива"<< endl;
    cin >> size;
    if (size <= 0)
    {
        cout<< "Введён неверный размер";
        return 0;
    }
    else 
     return size;
};

void PrintBiggerElementsIndex(const int* myArray, const size_t size){
    auto previous = 0;
    cout<<"Индексы элементов, значение которых больше значения предыдущего: ";
    for (size_t index = 1; index < size; index++){
        previous = myArray[index - 1];
        if (previous < myArray[index]){
            cout<<index << " ";
        }
    }
    cout<<"\n";
}

bool ArePairs(const int* myArray, const size_t size ) {
    int countPairs = 0;
    int previous = 0;
    for (size_t index = 1; index < size; index=index + 2) {
        previous = myArray[index - 1];
        if ((previous * myArray[index]) >= 0) {
            countPairs++;
        }
    }
    return countPairs >= 2;
    
}

void MinToAverageChange(int* myArray, const size_t size, const int maxValue )
{
    int temprary = 0;
    if (myArray == nullptr)
        cout << "Массив пуст";

    auto minArrayValue = maxValue;
    auto minElementIndex = 0;

    for (size_t index = 0; index < size; index++) {
        if (myArray[index] < minArrayValue) {
            minArrayValue = myArray[index];
            minElementIndex = index;
        }
    }
    
    temprary = myArray[minElementIndex];
    myArray[minElementIndex] = myArray[(size - 1) / 2];
    myArray[(size - 1) / 2] = temprary;
}

void ArrayPrint(const int* myArray, const size_t size)
{
    if (myArray == nullptr)
    {
        cout << "Массива не существует";
    }
    else {
        cout << "\nМассив:\n";
        for (size_t index = 0; index < size; index++) {
            cout << myArray[index] << " ";
        }
        cout << "\n";

    }
}

int* FillRandomArray(const size_t size, const int minValue, const int maxValue)
{
    srand(time(NULL));
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
