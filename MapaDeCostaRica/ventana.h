#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include "ruta.h"
#include "botones.h"
#include "paletacolores.h"
#include <windows.h>

class Ventana {

Botones botones;
PaletaColores paletaColores;
bool dibujandoRuta=false;  // Variable para indicar si se está dibujando una ruta
Ruta rutaActual;     // Almacena temporalmente la ruta que se está dibujando
std::string mostrarVentanaDialogo();
private:
    std::vector<sf::Vector2f> vertices; // Agrega este miembro
public:
    sf::RenderWindow ventana;
    std::vector<Ruta> rutas;
    Ruta* rutaSeleccionada;
    sf::Text titulo;
    
    Ventana() : ventana(sf::VideoMode(800, 600), "Mapa de Costa Rica") {
        rutaSeleccionada = nullptr;

        std::vector<sf::Vector2f> verticesPredefinidos = {
    sf::Vector2f(100, 100),
    sf::Vector2f(200, 150),
    sf::Vector2f(300, 200),
    sf::Vector2f(400, 250),
    sf::Vector2f(300, 300),
    sf::Vector2f(200, 250),
    sf::Vector2f(200, 255),
    sf::Vector2f(100, 200),
    sf::Vector2f(350, 450),
    sf::Vector2f(285, 334)
        };

        generarVerticesPredefinidos(verticesPredefinidos);
    }

    void manejarClickEnBotones(float x, float y);

    void manejarEventos();

    void manejarClick(float x, float y);

    void dibujar();

    void dibujarBotones();

    void generarVerticesPredefinidos(const std::vector<sf::Vector2f>& verticesPredefinidos);

   
};
