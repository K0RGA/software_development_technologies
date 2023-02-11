#include <iostream>
#include<array>
#include <vector>

using namespace std;

// Задание 1
// Выполнить задачу в соответствии с номером варианта. При выполнении задачи использовать функциональные объекты.
// Задание 2
// Повторить выполнение своего варианта задания, но с использованием параметризованных классов.

// Дан целочисленный вектор. Используя функцию transform умножить на масштабирующий
// коэффициент все элементы вектора, не превышающие заданного числа.

template<class T>
class Transform {
    vector<T> arr;
public:
    Transform(vector<T> arr) : arr(arr) {};

    vector<T> operator()(int coefficient, int threshold) {
        for (int i = 0; i < arr.size(); i++){
            if (arr[i] < threshold) arr[i] *= coefficient;
        }
        return arr;
    }
};

int main() {
    vector <char> arr = {'a', 'b', 'c', 'b'};
    vector <char> result = Transform(arr)(5,'c');
    for (auto  i : result) cout << i << " ";
}





