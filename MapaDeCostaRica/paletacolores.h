#pragma once
#include <SFML/Graphics.hpp>

class PaletaColores {
public:
    sf::Color colores[6]; // 6 colores: rojo, verde, azul, amarillo, negro, purpura
    int colorSeleccionado; // Índice del color seleccionado en el arreglo
    PaletaColores();
    sf::Color getColorSeleccionado() const {
        return colores[colorSeleccionado];
    }
    void siguienteColor();
};
