#include <iostream>
using namespace std;

//Знак корабля - "*"; знак пустоты - " ".
enum { SHIP = '*', NOTHING = '\0' };

// Класс "Точка".
class Point
{
private:
    int x; // Координата по "X".
    int y; // Координата по "Y".
    char sign; // Знак.
public:
    Point(int XCord, int YCord, char sign) : x{ XCord }, y{ YCord }, sign{ sign }{}; // Конструктор класса "Точка".
    int returnX() { return x; } // Возвращение значения координаты по "X".
    int returnY() { return y; } // Возвращение значения координаты по "Y".
    char returnSign() { return sign; } // Возвращение знака.
    friend bool operator==(Point& left, Point& right); // Перегрузка оператора "==" для объектов класса "Точка".
};

// Перегрузка оператора "==" для объектов класса "Точка".
bool operator==(Point& left, Point& right)
{
    if (left.returnSign() == right.returnSign())
        return true;
    else
        return false;
}

// Класс "Двухпалубный корабль".
class DoubleDeckShip
{
private:
    Point p1; // Первая точка корабля.
    Point p2; // Вторая точка корабля.
public:
    DoubleDeckShip(Point p1, Point p2) : p1{ p1 }, p2{ p2 }{}; // Конструктор класса "Двухпалубный корабль".
};

int main()
{
    int firstXCord = 1; // Координата по "X" первой точки.
    int secondXCord = 1; // Координата по "X" второй точки.
    int firstYCord = 1; // Координата по "Y" первой точки.
    int secondYCord = 2; // Координата по "Y" второй точки.

    Point point1(firstXCord, firstYCord, SHIP); // Объект "Точка-1".
    Point point2(secondXCord, secondYCord, SHIP); // Объект "Точка-2".

    if (point1 == point2 && (point1.returnX() + 1 == point2.returnX() || point1.returnY() + 1 == point2.returnY()))
    {
        DoubleDeckShip doubleShip1(point1, point2); // Если объект "Точка-1" схож по знаку с объектом "Точка-2" и находятся рядом, то обе точки передаются в конструктор класса "Двухпалубный корабль".
    }
}
