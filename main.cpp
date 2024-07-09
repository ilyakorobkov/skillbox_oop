#include <iostream>
#include "Car.h"
#include "Lorry.h"

int main() {
    Car car1;
    Car car2("Toyota", 4, 150);
    Lorry lorry1;
    Lorry lorry2("Volvo", 6, 300, 5000);

    std::cout << "Enter details for car1:\n";
    std::cin >> car1;
    std::cout << "car1: " << car1 << "\n";

    std::cout << "car2: " << car2 << "\n";

    std::cout << "Enter details for lorry1:\n";
    std::cin >> lorry1;
    std::cout << "lorry1: " << lorry1 << "\n";

    std::cout << "lorry2: " << lorry2 << "\n";

    std::cout << "Total cars and lorries created: " << Car::count() << "\n";

    return 0;
}
