
#include <iostream>
#include <vector>
#include <memory>
#include "HashMap.h"

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



int main() {
    Project firstProject("Delete server");
    Project secondProject("Create code");
    Worker a("Anton", firstProject);
    Worker b("Boris", firstProject);


    HashMap<int, string> hmap;
    hmap.put(1, "val1");
    hmap.put(2, "val2");
    hmap.put(3, "val3");
    cout << hmap[3] << endl;
    hmap.remove(3);
    cout << hmap[3] << endl;
}





