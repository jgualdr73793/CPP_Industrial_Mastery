#include <iostream>
#include <string>

// Concept: Encapsulation and Data Modeling
struct Reading {
    double value;
    long timestamp;
};

class BasicSensor {
private:
    int id;
    std::string type;
    double lastValue;

public:
    BasicSensor(int id, std::string type) : id(id), type(type), lastValue(0.0) {}

    // Method to update data with basic validation
    void updateValue(double newValue) {
        if (newValue >= 0) {
            lastValue = newValue;
        }
    }

    double getValue() const { return lastValue; }
};