#include "Point.h"
#include <sstream> 
#include <cmath>   

// Конструктор за умовчанням
Point::Point() {
    setX(0.0); // ініціалізація X нулем
    setY(0.0); // ініціалізація Y нулем
}

// Конструктор ініціалізації
Point::Point(double x, double y) {
    setX(x); // безпечний запис X
    setY(y); // безпечний запис Y
}

// Конструктор копіювання
Point::Point(const Point& other) {
    x = other.x; // копіювання X
    y = other.y; // копіювання Y
}

// Стандартний деструктор
Point::~Point() {}

// Отримати координату X
double Point::getX() const { return x; }

// Змінити координату X (з контролем діапазону)
void Point::setX(double val) {
    if (val >= -100.0 && val <= 100.0) x = val; // перевірка коректності
    else x = 0.0;
}

// Отримати координату Y
double Point::getY() const { return y; }

// Змінити координату Y (з контролем діапазону)
void Point::setY(double val) {
    if (val >= -100.0 && val <= 100.0) y = val; // перевірка коректності
    else y = 0.0;
}

// Обчислення відстані до початку координат (0,0)
double Point::distanceToOrigin() const {
    return sqrt(x * x + y * y); // теорема Піфагора
}

// Перетворення у полярні координати
void Point::toPolar(double& r, double& phi) const {
    r = distanceToOrigin(); // радіус (відстань)
    phi = atan2(y, x);      // кут у радіанах
}

// Перевантаження операції присвоєння
Point& Point::operator=(const Point& other) {
    if (this != &other) { // захист від самоприсвоєння
        x = other.x;
        y = other.y;
    }
    return *this;
}

// Перетворення об'єкта в текст (формат: (X, Y))
Point::operator string() const {
    stringstream ss;
    ss << "(" << x << ", " << y << ")"; // формування рядка
    return ss.str();
}

// Префіксний інкремент (збільшує X)
Point& Point::operator++() {
    ++x; // модифікація поточного об'єкта
    return *this;
}

// Префіксний декремент (зменшує X)
Point& Point::operator--() {
    --x; // модифікація поточного об'єкта
    return *this;
}

// Постфіксний інкремент (збільшує Y)
Point Point::operator++(int) {
    Point temp(*this); // збереження старого стану
    y++;               // зміна координати
    return temp;       // повертаємо старий стан
}

// Постфіксний декремент (зменшує Y)
Point Point::operator--(int) {
    Point temp(*this); // збереження старого стану
    y--;               // зміна координати
    return temp;       // повертаємо старий стан
}

// Порівняння: чи рівні дві точки
bool operator==(const Point& a, const Point& b) {
    return (a.x == b.x) && (a.y == b.y); // збіг обох координат
}

// Порівняння: чи не рівні дві точки
bool operator!=(const Point& a, const Point& b) {
    return !(a == b); // інверсія рівності
}

// Перевантаження оператора виводу (<<)
ostream& operator<<(ostream& out, const Point& p) {
    out << string(p); // виведення на екран
    return out;
}

// Перевантаження оператора вводу (>>)
istream& operator>>(istream& in, Point& p) {
    double tempX, tempY;
    cout << " Введіть X: ";
    in >> tempX; // зчитування X
    cout << " Введіть Y: ";
    in >> tempY; // зчитування Y

    p.setX(tempX); // запис через сетер
    p.setY(tempY); // запис через сетер
    return in;
}