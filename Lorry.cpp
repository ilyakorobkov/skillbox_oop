#include "Lorry.h"

Lorry::Lorry() : Car(), payload(0) {}

Lorry::Lorry(const std::string& brand, int cylinders, int horsepower, int payload)
    : Car(brand, cylinders, horsepower), payload(payload) {}

Lorry::Lorry(const Lorry& other)
    : Car(other), payload(other.payload) {}

Lorry::~Lorry() {}

int Lorry::getPayload() const {
    return payload;
}

void Lorry::setPayload(int payload) {
    this->payload = payload;
}

Lorry& Lorry::operator=(const Lorry& other) {
    if (this != &other) {
        Car::operator=(other);
        payload = other.payload;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Lorry& lorry) {
    os << static_cast<const Car&>(lorry) << ", Payload: " << lorry.payload;
    return os;
}

std::istream& operator>>(std::istream& is, Lorry& lorry) {
    is >> static_cast<Car&>(lorry);
    std::cout << "Enter payload: ";
    is >> lorry.payload;
    return is;
}
