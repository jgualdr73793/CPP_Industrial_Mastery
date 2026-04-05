#include <iostream>
#include <string>
#include <stdexcept>

namespace Dispositivos { // Nuestra "etiqueta" para sensores

    enum class Estado { NORMAL, ALERTA, CRITICO };

    template <typename T>
    class Sensor {
    protected:
        int id;
        T valor;
        std::string tipo;

    public:
        Sensor(int id, std::string tipo, T inicial) : id(id), tipo(tipo), valor(inicial) {}
        virtual ~Sensor() = default;

        virtual Estado calcularEstado() const = 0;

        void setLectura(T nueva) {
            if (nueva < -273.15) { // Cero absoluto, físicamente imposible
                throw std::invalid_argument("Error: Lectura por debajo del cero absoluto.");
            }
            valor = nueva;
        }

        T getValor() const { return valor; }
        std::string getTipo() const { return tipo; }
    };

    class Termometro : public Sensor<float> {
    public:
        Termometro(int id, float ini) : Sensor(id, "Termometro", ini) {}

        Estado calcularEstado() const override {
            if (valor > 100.0f) return Estado::CRITICO;
            if (valor > 75.0f) return Estado::ALERTA;
            return Estado::NORMAL;
        }
    };
}