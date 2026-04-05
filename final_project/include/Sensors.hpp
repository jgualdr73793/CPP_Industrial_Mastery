#ifndef SENSORS_HPP
#define SENSORS_HPP

#include <iostream>
#include <string>
#include <stdexcept>

namespace IndustrialSystem {
    enum class Status { NORMAL, WARNING, CRITICAL };

    template <typename T>
    class Sensor {
    protected:
        int id;
        T value;
        std::string type;

    public:
        Sensor(int id, std::string type, T initial) : id(id), type(type), value(initial) {}
        virtual ~Sensor() = default;

        virtual Status evaluate() const = 0;

        void updateReading(T newValue) {
            if (newValue < -273.15) { // Absolute Zero check
                throw std::runtime_error("Physical impossibility: Reading below absolute zero.");
            }
            value = newValue;
        }

        T getValue() const { return value; }
        std::string getType() const { return type; }
    };

    class Thermometer : public Sensor<float> {
    public:
        Thermometer(int id, float init) : Sensor(id, "Thermometer", init) {}
        Status evaluate() const override {
            if (value > 100.0f) return Status::CRITICAL;
            if (value > 75.0f) return Status::WARNING;
            return Status::NORMAL;
        }
    };
}
#endif