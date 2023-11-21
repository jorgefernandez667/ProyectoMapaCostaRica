#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include "paletacolores.h"

class Botones {
    PaletaColores paletaColores;
public:
    sf::Font fuente;
    sf::RectangleShape botonAgregarRuta;
    sf::Text etiquetaAgregarRuta;
    sf::RectangleShape botonFinRuta;
    sf::Text etiquetaFinRuta;
    sf::RectangleShape botonEditarRuta;
    sf::Text etiquetaEditarRuta;
    sf::RectangleShape botonEliminarRuta;
    sf::Text etiquetaEliminarRuta;
    sf::RectangleShape botonMostrarOcultarRuta;
    sf::Text etiquetaMostrarOcultarRuta;
    sf::RectangleShape botonGuardarRutas;
    sf::Text etiquetaGuardarRutas;
    sf::RectangleShape botonCargarRutas;
    sf::Text etiquetaCargarRutas;
    sf::RectangleShape botonSiguienteColor;
    sf::Text etiquetaSiguienteColor;
    sf::RectangleShape muestraColor;
    sf::Text etiquetamuestraColor;
    Botones();
};
