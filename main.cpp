#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include "numeric"

using namespace std;

// Задание 1
/*
С помощью функции iota() заполните вектор соответствующим вашему варианту образом.
Перемешайте содержимое вектора случайным образом.
Отсортируйте вектор по указанному для варианта принципу.

 Вариант 6 (1)
 Тип данных Int
 Кол-во элементов 23
 Значение первого элемента 12
 Правило сортировки По кратности 3
 */

// Задание 2
/*
При помощи функций библиотеки <algorithm> найти наибольшую последовательность из одинаковых символов в случайно
сгенерированном массиве char размером 1000 элементов.
*/

int comparator(const void *i, const void *j);

char randomSymbol();

int main() {
    // Задание 1
    // заполнение
    vector<int> arr(23);
    iota(arr.begin(), arr.end(), 12);
    random_shuffle(arr.begin(), arr.end());
    cout << "Original:" << endl;
    for (auto i: arr) { cout << i << " "; }
    cout << endl;

    // сортировка
    qsort(arr.begin().base(), size_t(arr.size()), sizeof(arr.at(0)), comparator);
    cout << "Sorted:" << endl;
    for (auto i: arr) { cout << i << " "; }
    cout << endl;
    cout << "Sorted % 3" << endl;
    for (auto i: arr) { cout << i % 3 << " "; }
    cout << "\n\n\n";

    // Задание 2
    // заполнение
    srand(unsigned(std::time(0)));
    vector<char> arrChar(1000);
    generate(arrChar.begin(), arrChar.end(), randomSymbol);

    // нахождение максимальной последовательности одинаковых символов
    /*
    просто идёт перебор символов и их длин
    потом вызывается функция search_n которая ищёт подрят последоватьность, состояющую из символа symbol и длиной length
    находится максимальная последовательность
     */
    int maxLength = 10;
    int currentMaxLength = 1;
    auto currentMaxIter = arrChar.end();
    for (char symbol = 'a'; symbol <= 'z'; symbol++)
        for (int length = 0; length < maxLength; length++) {
            auto currentFindingSequenceIter = search_n(arrChar.begin(), arrChar.end(), length, symbol);
            if (currentFindingSequenceIter != arrChar.end() && length > currentMaxLength) {
                currentMaxLength = length;
                currentMaxIter = currentFindingSequenceIter;
            }
        }
    cout << "Position: " << distance(arrChar.begin(), currentMaxIter) << endl;
    cout << "Symbol: " << *currentMaxIter << endl;
    cout << "Length: " << currentMaxLength << endl;
}

int comparator(const void *i, const void *j) {
    return *(int *) i % 3 - *(int *) j % 3;
}

char randomSymbol() {
    return (rand() % 26 + 97);
}





