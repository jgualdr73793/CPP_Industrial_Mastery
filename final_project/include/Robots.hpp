#ifndef ROBOTS_HPP
#define ROBOTS_HPP

#include "Sensors.hpp"

namespace Controllers {
    class ActuatorRobot {
        std::string model;
    public:
        ActuatorRobot(std::string m) : model(m) {}

        void react(IndustrialSystem::Status level) {
            std::cout << "[Robot " << model << "]: ";
            switch (level) {
                case IndustrialSystem::Status::CRITICAL:
                    std::cout << "EMERGENCY! Shutting down system. 🛑" << std::endl;
                    break;
                case IndustrialSystem::Status::WARNING:
                    std::cout << "Warning: Adjusting cooling parameters. 💨" << std::endl;
                    break;
                default:
                    std::cout << "System stable. Monitoring... 👀" << std::endl;
                    break;
            }
        }
    };
}
#endif