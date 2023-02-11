#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Задание 1
// Выполнить задачу в соответствии с номером варианта. При выполнении задачи использовать лямбда-выражения (max – 3 балла).
// Задание 2
// Повторить выполнение своего варианта задания с использованием классов (max – 4 балла).
// Задание 3
// Повторить выполнение своего варианта задания, но с использованием параметризованных классов (max – 5 баллов).

// Дан целочисленный список. Используя функцию transform умножить каждый элемент списка,
// являющийся степенью двойки, на масштабирующий коэффициент.

bool isExpOf2(int n) {
    return (n & (n - 1)) == 0;
}

template<typename T>
class Transform {
    vector<T> &arr;
public:
    explicit Transform(vector<T> &arr) : arr(arr) {};

    void operator()(int coefficient) {
        for_each(arr.begin(), arr.end(), [coefficient](int &number) { if (isExpOf2(number)) number *= coefficient; });
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4};
    (Transform(arr)(5)); // дурдом, но без скобочек не работает
    for (auto i: arr) cout << i << " ";
    cout << endl;
}





