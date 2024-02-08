#include <iostream>
#include <string>

// Клас Двигун
class Engine 
{
private:
    int horsepower;
public:
    Engine(int power) : horsepower(power) {}
    int getHorsepower() const 
    { 
        return horsepower; 
    }
};

// Клас Кузов
class Body
{
private:
    std::string color;
public:
    Body(const std::string& c) : color(c) {}
    std::string getColor() const 
    { 
        return color; 
    }
};

// Клас Колесо
class Wheel 
{
private:
    int size;
public:
    Wheel(int s) : size(s) {}
    Wheel() : size(0) {} 
    int getSize() const 
    { 
        return size; 
    }
};

// Клас Автомобіль
class Car 
{
private:
    Engine engine;
    Body body;
    Wheel wheels[4]; 
public:
    // Конструктор
    Car(const Engine& e, const Body& b, const Wheel& w) : engine(e), body(b) 
    {
        for (int i = 0; i < 4; ++i)
            wheels[i] = w;
    }

    // Конструктор копіювання
    Car(const Car& other) : engine(other.engine), body(other.body) 
    {
        for (int i = 0; i < 4; ++i)
            wheels[i] = other.wheels[i];
    }

    // Метод для зміни кольору кузова
    void setColor(const std::string& newColor) 
    {
        body = Body(newColor);
    }

    // Метод для зміни потужності двигуна
    void setHorsepower(int newPower)
    {
        engine = Engine(newPower);
    }

    // Метод для виведення інформації про автомобіль
    void printInfo() const 
    {
        std::cout << "Характеристики автомобіля:" << std::endl;
        std::cout << "Двигун потужністю " << engine.getHorsepower() << " к.с." << std::endl;
        std::cout << "Кузов забарвлений в " << body.getColor() << " колір" << std::endl;
        std::cout << "Розмір коліс: " << wheels[0].getSize() << " дюймів" << std::endl;
    }
};

int main() 
{
    system("chcp 1251 > null");
    Engine engine(300); // Створюємо об'єкт двигуна потужністю 300 к.с.
    Body body("білий"); // Створюємо об'єкт кузова білого кольору
    Wheel wheel(15); // Створюємо об'єкт колеса діаметром 15 дюймів

    // Створюємо автомобіль
    Car myCar(engine, body, wheel);

    // Виводимо інформацію про автомобіль
    std::cout << "Інформація про мій автомобіль:" << std::endl;
    myCar.printInfo();

    // Змінюємо колір кузова
    myCar.setColor("чорний");

    // Виводимо оновлену інформацію про автомобіль
    std::cout << "\nІнформація про мій автомобіль після зміни кольору:" << std::endl;
    myCar.printInfo();

    // Змінюємо потужність двигуна
    myCar.setHorsepower(250);

    // Виводимо оновлену інформацію про автомобіль
    std::cout << "\nІнформація про мій автомобіль після зміни потужності двигуна:" << std::endl;
    myCar.printInfo();

    return 0;
}
