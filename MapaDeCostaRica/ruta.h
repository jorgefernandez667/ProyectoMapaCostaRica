#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

class Ruta {
public:
    std::string nombre;
    std::vector<sf::Vector2f> vertices;
    sf::Color color;
    bool visible;
    Ruta() {}
    Ruta(std::string nombre, sf::Color color)
        : nombre(nombre), color(color), visible(true) {}

    void agregarVertice(sf::Vector2f vertice);

    void dibujar(sf::RenderWindow& ventana) const;

    bool seleccionar(const sf::Vector2f& punto) const;

    bool operator==(const Ruta& otraRuta) const;
};
