#include <iostream>
#include<array>
#include <vector>
#include "Stack.h"

using namespace std;

// Задание 1
// Опишите параметризованную функцию сортировки вставкой.
template<class T>
vector<T> insertionSort(vector<T> arr) {
    vector<T> array = arr;
    int n = array.size();
    for (int i = 1; i < n; i++)
        for (int j = i; j > 0 && array[j - 1] > array[j]; j--)
            swap(array[j - 1], array[j]);
    return array;
}

// Вспомогательная функция для печати векторов
template<class T>
void print(vector<T> arr) {
    for (auto i: arr) cout << i << " ";
}

int main() {
    //Задание 1
    vector<int> arr = {1, 9, 2, 4, 8, 3};
    print(insertionSort(arr));

    //Задание 2
    //Опишите оператор [] для разработанного класса-массива, обработайте ошибку выхода за границы массива.
    Stack stack;
    cout << stack[10];
}





