#ifndef LORRY_H
#define LORRY_H

#include "Car.h"

class Lorry : public Car {
public:
    Lorry();
    Lorry(const std::string& brand, int cylinders, int horsepower, int payload);
    Lorry(const Lorry& other);
    ~Lorry();

    int getPayload() const;
    void setPayload(int payload);

    Lorry& operator=(const Lorry& other);

    friend std::ostream& operator<<(std::ostream& os, const Lorry& lorry);
    friend std::istream& operator>>(std::istream& is, Lorry& lorry);

private:
    int payload;
};

#endif // LORRY_H
