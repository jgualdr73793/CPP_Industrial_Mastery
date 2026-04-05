#include <iostream>
#include <memory>

// Concept: Generic Programming (Templates) and RAII (Smart Pointers)
template <typename T>
class DataWrapper {
    T data;
public:
    DataWrapper(T d) : data(d) {}
    T getData() const { return data; }
};

void memoryExample() {
    // Concept: Ownership without 'delete'
    auto smartSensor = std::make_unique<DataWrapper<float>>(36.5f);
}