#include <iostream>

// Concept: Abstract Base Classes and Polymorphism
class Sensor {
public:
    virtual ~Sensor() = default; // Essential for memory safety in inheritance
    virtual void checkStatus() const = 0; // Pure virtual function (Interface)
};

class TemperatureSensor : public Sensor {
public:
    void checkStatus() const override {
        std::cout << "Checking thermal levels... OK" << std::endl;
    }
};