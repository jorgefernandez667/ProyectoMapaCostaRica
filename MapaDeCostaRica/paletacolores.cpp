#include "paletacolores.h"

PaletaColores::PaletaColores() {
    colores[0] = sf::Color::Red;
    colores[1] = sf::Color::Green;
    colores[2] = sf::Color::Blue;
    colores[3] = sf::Color::Yellow;
    colores[4] = sf::Color::Black;
    colores[5] = sf::Color(128, 0, 128); // Purpura
    colorSeleccionado = 0; // Color por defecto: rojo
}
void PaletaColores::siguienteColor() {
    colorSeleccionado = (colorSeleccionado + 1) % 6; // Ciclo entre los 6 colores
}