#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include "ruta.h"

void Ruta::agregarVertice(sf::Vector2f vertice) {
    vertices.push_back(vertice);
}

void Ruta::dibujar(sf::RenderWindow& ventana) const {
    if (visible && vertices.size() > 1) {
        std::vector<sf::Vertex> lineas;
        lineas.reserve(vertices.size() * 2 - 2);

        for (size_t i = 1; i < vertices.size(); ++i) {
            lineas.push_back(sf::Vertex(vertices[i - 1], color));
            lineas.push_back(sf::Vertex(vertices[i], color));
        }

        ventana.draw(lineas.data(), lineas.size(), sf::Lines);
    }
}

bool Ruta::seleccionar(const sf::Vector2f& punto) const {
    for (const auto& vertice : vertices) {
        sf::FloatRect rect(vertice.x - 10, vertice.y - 10, 20, 20);
        if (rect.contains(punto)) {
            return true;
        }
    }
    return false;
}
bool Ruta::operator==(const Ruta& otraRuta) const {
    // Comparar las direcciones de memoria de los objetos Ruta
    return this == &otraRuta;
}