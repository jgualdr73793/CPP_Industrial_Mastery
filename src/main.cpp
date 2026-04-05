#include "sensores.hpp"
#include "robots.hpp"
#include <memory>
#include <vector>

// Podemos usar esto para no escribir Dispositivos:: cada vez, 
// pero solo dentro del main para mantener el orden.
using namespace Dispositivos; 

int main() {
    // Uso de Smart Pointers para gestionar la memoria del sensor
    std::vector<std::unique_ptr<Sensor<float>>> planta;
    
    // Al usar namespaces, evitamos colisiones de nombres
    planta.push_back(std::make_unique<Termometro>(101, 20.0f));
    
    // Llamamos al robot usando su "apellido" (Namespace)
    Controladores::RobotActuador guardia("R2D2");

    std::cout << "--- Log de la Planta Industrial ---" << std::endl;

    try {
        for (auto& s : planta) {
            s->setLectura(110.5f); // Forzamos un CRITICO
            
            std::cout << s->getTipo() << " ID " << " reporta: " << s->getValor() << std::endl;
            
            // El robot procesa el estado del sensor
            guardia.reaccionar(s->calcularEstado());
        }
        
        // Prueba de error: lectura imposible
        planta[0]->setLectura(-500.0f); 

    } catch (const std::exception& e) {
        std::cerr << "SISTEMA DETENIDO: " << e.what() << std::endl;
    }

    return 0;
}