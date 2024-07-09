#include "Car.h"

int Car::count_instances = 0;

Car::Car() : brand(""), cylinders(0), horsepower(0) {
    ++count_instances;
}

Car::Car(const std::string& brand, int cylinders, int horsepower)
    : brand(brand), cylinders(cylinders), horsepower(horsepower) {
    ++count_instances;
}

Car::Car(const Car& other)
    : brand(other.brand), cylinders(other.cylinders), horsepower(other.horsepower) {
    ++count_instances;
}

Car::~Car() {
    --count_instances;
}

std::string Car::getBrand() const {
    return brand;
}

void Car::setBrand(const std::string& brand) {
    this->brand = brand;
}

int Car::getCylinders() const {
    return cylinders;
}

void Car::setCylinders(int cylinders) {
    this->cylinders = cylinders;
}

int Car::getHorsepower() const {
    return horsepower;
}

void Car::setHorsepower(int horsepower) {
    this->horsepower = horsepower;
}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        brand = other.brand;
        cylinders = other.cylinders;
        horsepower = other.horsepower;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Car& car) {
    os << "Brand: " << car.brand << ", Cylinders: " << car.cylinders << ", Horsepower: " << car.horsepower;
    return os;
}

std::istream& operator>>(std::istream& is, Car& car) {
    std::cout << "Enter brand: ";
    is >> car.brand;
    std::cout << "Enter cylinders: ";
    is >> car.cylinders;
    std::cout << "Enter horsepower: ";
    is >> car.horsepower;
    return is;
}

int Car::count() {
    return count_instances;
}
