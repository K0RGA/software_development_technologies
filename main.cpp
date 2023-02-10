#include <iostream>
#include <random>
#include "cmath"

using namespace std;

// Создать класс- интерфейс пространственной фигуры, который содержит три элемента с модификатором доступа protected.
// Создать производные классы: тор, правильная усеченная пирамида с пятиугольным основанием, прямой круговой конус.
// Для каждой из фигур предусмотреть вывод ее названия и вычисление площади поверхности.
// Случайным образом выбрать фигуру и с помощью оператора typeid определить ее тип.

class Figure {
protected:
    int x;
    int y;
    int z;

public:
    virtual void printNameAndSquare() {};
};

class Tor : public Figure {
public:
    Tor(int r_l, int r_b) {
        this->x = r_l;  // внутренний радиус тора
        this->y = r_b;  // радиус тора в разрезе
    }

    void printNameAndSquare() override {
        double square = x * M_PI * M_PI * 2 * y;
        cout << "Tor = " << square;
    }
};

class TruncatedPyramid : public Figure {
public:
    TruncatedPyramid(int littleSide, int bigSide, int h) {
        this->x = littleSide; // сторона малого пятиугольника
        this->y = bigSide; // сторона большого пятиугольника
        this->z = h; // высота
    }

    void printNameAndSquare() override {
        double littlePentagon = x * x * sqrt(25 + 10 * sqrt(5)) / 4;
        double bigPentagon = y * y * sqrt(25 + 10 * sqrt(5)) / 4;
        double sideSurface = (5 * x + 5 * y) / (2 * z);
        double square = littlePentagon + bigPentagon + sideSurface;
        cout << "TruncatedPyramid = " << square;
    }
};

class Cone : public Figure {
public:
    Cone(int r, int l) {
        this->x = r; // радиус
        this->y = l; // боковая длина
    }

    void printNameAndSquare() override {
        double sideSurface = M_PI * x * y;
        double base = M_PI * x * x;
        double square = sideSurface + base;
        cout << "Cone = " << square;
    }
};

Figure* generator();

int main() {

    Figure* fig = generator();

    cout << typeid(*fig).name() << endl;
    fig->printNameAndSquare();
}

Figure* generator() {
    time_t t;
    srand((int)time (&t));
    switch (rand() % 3) {
        case 0:
            return new Tor(1, 2);
        case 1:
            return new TruncatedPyramid(1,2,3);
        case 2:
            return new Cone(1, 2);
    }
    return NULL;
}





