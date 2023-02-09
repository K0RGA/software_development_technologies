#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> addDelimiterToBeginning(vector<int>);

vector<string> splitStringIntoWords(string);

void fiveBiggestWords(vector<string>);

void wordsStartingWithA(vector<string>);

int main() {

    // Задание 1
    // В начало вектора целого типа записать элементы, являющиеся делителями максимального элемента этого файла.
    cout << "Task 1" << endl;
    vector<int> arr = {1, 5, 3, 2, 6};
    for (auto i: addDelimiterToBeginning(arr)) cout << i << " ";
    cout << endl;

    // Задание 2
    // Дана строка слов, разделенных пробелами, запятыми, точками.
    // Сформи-руйте новую строку из пяти самых длинных слов.
    // Определите количество слов, начинающихся первой буквой алфавита (русского или латинского).
    cout << "Task 2" << endl;
    string input = "Pete and Ellen, my former classmates, got married a week ago.";
    vector<string> words = splitStringIntoWords(input);
    fiveBiggestWords(words);
    wordsStartingWithA(words);

}

//Задание 1
vector<int> addDelimiterToBeginning(vector<int> arr) {
    vector<int> arrSorted = arr;
    sort(arrSorted.begin(), arrSorted.end());
    int maxValue = arrSorted.back();
    for (int i = maxValue; i > 0; i--) {
        if (maxValue % i == 0) arr.insert(arr.begin(), i);
    }
    return arr;
}

//Задание 2
vector<string> splitStringIntoWords(string input) {
    string dividers = " ,.";
    string word;
    vector<string> result;
    for (auto symbol: input) {
        if (dividers.find(symbol) != string::npos) {
            result.push_back(word);
            word = "";
        } else {
            word += symbol;
        }
    }
    //очистка от лишних пробелов
    for (int i = 0; i < result.size(); i++) {
        if (result[i].empty()) result.erase(result.cbegin() + i);
    }
    return result;
}

void fiveBiggestWords(vector<string> input) {
    sort(input.begin(), input.end(),
         [](const string &a, const string &b) { return a.length() > b.length(); });
    for (int i = 0; i < 5; i++)
        cout << input[i] << " ";
    cout << endl;
}

void wordsStartingWithA(vector<string> input){
    for (auto i : input){
        if (i[0] == 'A' or i[0] == 'a'){
            cout << i << " ";
        }
    }
    cout << endl;
}






