#include "Sensors.hpp"
#include "Robots.hpp"
#include <vector>
#include <memory>

int main() {
    using namespace IndustrialSystem;

    // Using Modern C++: Vector of unique pointers for memory safety
    std::vector<std::unique_ptr<Sensor<float>>> plantSensors;
    plantSensors.push_back(std::make_unique<Thermometer>(101, 25.0f));

    Controllers::ActuatorRobot guardBot("R2D2");

    std::cout << "--- Industrial Plant Log Started ---" << std::endl;

    try {
        for (auto& s : plantSensors) {
            s->updateReading(115.0f); // Simulate a critical event
            std::cout << s->getType() << " Current Value: " << s->getValue() << std::endl;
            
            guardBot.react(s->evaluate());
        }
        
        // This will trigger an Exception
        plantSensors[0]->updateReading(-500.0f);

    } catch (const std::exception& e) {
        std::cerr << "CRITICAL ERROR: " << e.what() << std::endl;
    }

    return 0;
}