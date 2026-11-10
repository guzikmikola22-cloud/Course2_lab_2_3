#include <iostream>
#include <Windows.h>
#include "Point.h"

using namespace std;

// Структура для демонстрації #pragma pack(1)
#pragma pack(push, 1)
class PointPacked {
    double x;
    double y;
};
#pragma pack(pop)

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "Розмір класу Point без #pragma pack(1): " << sizeof(Point) << " байт" << endl;
    cout << "Розмір класу з #pragma pack(1): " << sizeof(PointPacked) << " байт" << endl;
    cout << "-------------------------------------------------" << endl;

    // Створення об'єктів
    Point p1;                 // За умовчанням
    Point p2(3.0, 4.0);       // Ініціалізації
    Point p3 = p2;            // Копіювання

    cout << "p1 (за умовчанням) : " << p1 << endl;
    cout << "p2 (ініціалізації) : " << p2 << endl;
    cout << "p3 (копіювання p2) : " << p3 << endl;
    cout << "-------------------------------------------------" << endl;

    // Демонстрація бізнес-логіки
    double r, phi;
    p2.toPolar(r, phi);
    cout << "Точка p2 " << p2 << " у полярних координатах:" << endl;
    cout << "Радіус (відстань) = " << p2.distanceToOrigin() << ", Кут (радіани) = " << phi << endl;
    cout << "-------------------------------------------------" << endl;

    // Демонстрація операторів інкременту/декременту
    cout << "Тестування інкрементів/декрементів:" << endl;
    cout << "Початкова p1: " << p1 << endl;
    cout << "++p1 (збільшує X) : " << ++p1 << endl;
    cout << "--p1 (зменшує X)  : " << --p1 << endl;

    cout << "p1++ (збільшує Y) : " << p1++ << " (значення до зміни)" << endl;
    cout << "Поточний стан p1  : " << p1 << endl;
    cout << "-------------------------------------------------" << endl;

    // Демонстрація вводу та масиву
    Point arr[2];
    cout << "Введіть дані для масиву точок:" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "Точка [" << i << "]:" << endl;
        cin >> arr[i];
    }

    cout << "\nВаш масив:" << endl;
    for (int i = 0; i < 2; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    return 0;
}