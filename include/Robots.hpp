#include <iostream>
#include <string>

namespace Controladores { // Etiqueta para los que "hacen" algo

    class RobotActuador {
        std::string nombre;
    public:
        RobotActuador(std::string n) : nombre(n) {}

        // Recibe el Estado que definimos en el otro namespace
        void reaccionar(Dispositivos::Estado nivel) {
            std::cout << "[Robot " << nombre << "]: ";
            switch (nivel) {
                case Dispositivos::Estado::CRITICO:
                    std::cout << "¡EMERGENCIA! Deteniendo maquinas. 🛑" << std::endl;
                    break;
                case Dispositivos::Estado::ALERTA:
                    std::cout << "Aviso: Incrementando ventilacion. 💨" << std::endl;
                    break;
                default:
                    std::cout << "Sistema estable. Vigilando... 👀" << std::endl;
                    break;
            }
        }
    };
}