#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

class Car {
public:
    Car();
    Car(const std::string& brand, int cylinders, int horsepower);
    Car(const Car& other);
    ~Car();

    std::string getBrand() const;
    void setBrand(const std::string& brand);

    int getCylinders() const;
    void setCylinders(int cylinders);

    int getHorsepower() const;
    void setHorsepower(int horsepower);

    Car& operator=(const Car& other);

    friend std::ostream& operator<<(std::ostream& os, const Car& car);
    friend std::istream& operator>>(std::istream& is, Car& car);

    static int count();

private:
    std::string brand;
    int cylinders;
    int horsepower;

    static int count_instances;
};

#endif 
