
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Задание 1
/*
 Разработать класс хэш-таблицы с закрытой адресацией.
 Реализовать операции вставки и удаления элемента.
 Используйте односвязный список для хранения элементов с одинаковым значением хэша.
*/

// Задание 2
/*
 Согласно варианту реализовать класс, наполнить его полями и методами.
 Использовать в реализации умные указатели.
 Протестировать в случаях, где вероятна утечка памяти
 (досрочный выход с помощью return или генерации исключения, циклическая зависимость указателей).

 Вариант 6 - Класс Работник
*/

//Задание 2

class Project {
public:
    string projectName;

    Project(string projectName) {
        this->projectName = projectName;
    }

    void doSmth() {
        cout << "I doing something\n";
    }
};

class Worker {
    shared_ptr<string> name;
    shared_ptr<Project> project;
public:
    Worker(string name, Project project) {
        this->name = make_unique<string>(name);
        this->project = make_unique<Project>(project);
    }

    void printInfo() {
        cout << "Name: " << *name << endl;
        cout << "Project: " << project->projectName << endl;
    }

};

class HashMap {
    int arraySize = 3;
public:
    string *array = new string[arraySize];
    string tmp = "";

    bool isOverFlow() {
        int counter = 0;
        for (auto i: *array) {
            if (i != NULL) counter++;
        }
        return counter / arraySize > 0.5;
    }
public:
    HashMap(string tmp) {
        this->tmp = tmp;
    }

    //void put(string key, string value) {
    void put() {
        if (isOverFlow()) resize();
    }

    void resize(){
        arraySize = arraySize * 2;
        string *newArray = new string[arraySize];
        array = newArray;
    }

    int size(){
        return array->end() - array->begin();
    }


};


int main() {
    Project firstProject("Delete server");
    Project secondProject("Create code");
    Worker a("Anton", firstProject);
    Worker b("Boris", firstProject);

    HashMap av("dfsdf");
    cout << av.size() << endl;
    av.array[0] = "asd";
    av.array[1] = "asd";
    av.array[2] = "asd";
    cout << av.size() << endl;
    av.put();
    cout << av.size() << endl;
    av.array[10] = "asd";
    cout << av.array[10] << endl;
}





