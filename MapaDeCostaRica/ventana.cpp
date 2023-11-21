#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include "ventana.h"

std::string Ventana::mostrarVentanaDialogo() {
    std::string nombreRuta;

    // Muestra una ventana de diálogo simple
    MessageBoxA(NULL, "Ingrese el nombre de la ruta:", "Agregar Ruta", MB_ICONINFORMATION);

    // Usa std::getline para obtener la entrada del usuario
    std::getline(std::cin, nombreRuta);

    return nombreRuta;
}
sf::Font fuente;
void Ventana::generarVerticesPredefinidos(const std::vector<sf::Vector2f>& verticesPredefinidos) {
    vertices = verticesPredefinidos;
}
void Ventana::manejarEventos() {
    sf::Event evento;
    while (ventana.pollEvent(evento)) {
        if (evento.type == sf::Event::Closed) {
            ventana.close();
        }
        else if (evento.type == sf::Event::MouseButtonPressed) {
            manejarClick(evento.mouseButton.x, evento.mouseButton.y);
        }else if (evento.type == sf::Event::MouseButtonPressed) {
            manejarClickEnBotones(evento.mouseButton.x, evento.mouseButton.y);
        }
    }
}
void Ventana::manejarClickEnBotones(float x, float y) {
    // Lógica para manejar clicks en botones
    if (botones.botonAgregarRuta.getGlobalBounds().contains(x, y)) {
        // Lógica para el botón Agregar Ruta
        std::cout << "Botón Agregar Ruta presionado." << std::endl;
        
        dibujandoRuta = true;
        if (dibujandoRuta == true) {
            std::cout << "puedes dibujar." << std::endl;
        }
    }
    else if (botones.botonFinRuta.getGlobalBounds().contains(x, y)) {
        // Lógica para el botón Fin de la Ruta
        std::cout << "Botón Fin de la Ruta presionado." << std::endl;
        dibujandoRuta = false;

        if (rutaActual.vertices.size() > 1) {
            rutas.push_back(rutaActual);
        }
            // Limpiar la ruta actual
            rutaActual = Ruta("Nueva Ruta", paletaColores.getColorSeleccionado());
    }
    else if (botones.botonEditarRuta.getGlobalBounds().contains(x, y)) {
        // Lógica para el botón Editar Ruta
        std::cout << "Botón Editar Ruta presionado." << std::endl;
    }
    else if (botones.botonEliminarRuta.getGlobalBounds().contains(x, y)) {
        if (rutaSeleccionada != nullptr) {
            auto it = std::find(rutas.begin(), rutas.end(), *rutaSeleccionada);
            if (it != rutas.end()) {
                rutas.erase(it);
                std::cout << "Ruta eliminada: " << rutaSeleccionada->nombre << std::endl;
                rutaSeleccionada = nullptr;
            }
        }
        else if (dibujandoRuta) {
            // Si se está dibujando una ruta, limpiar la ruta actual
            std::cout << "Ruta dibujada eliminada." << std::endl;
            rutaActual = Ruta("Nueva Ruta", paletaColores.getColorSeleccionado());
        }
        else if (!rutas.empty()) {
            // Si no se está dibujando y hay rutas en el vector, borrar la última ruta
            std::cout << "Última ruta agregada eliminada." << std::endl;
            rutas.pop_back();
        }
        else {
            std::cout << "No hay ruta seleccionada para eliminar." << std::endl;
        }
    }
    else if (botones.botonMostrarOcultarRuta.getGlobalBounds().contains(x, y)) {
        // Lógica para el botón Editar Ruta
        std::cout << "Botón mostrar/ocultar ruta presionado." << std::endl;
    }
    else if (botones.botonGuardarRutas.getGlobalBounds().contains(x, y)) {
        std::cout << "Botón Guardar Rutas presionado." << std::endl;

        // Preguntar al usuario por el nombre de la ruta
        std::string nombreRuta = mostrarVentanaDialogo();
        if (!nombreRuta.empty()) {
            // Asignar el nombre a la ruta actual
            rutaActual.nombre = nombreRuta;

            // Guardar las coordenadas de la ruta actual en un archivo de texto
            std::ofstream archivo("vertices.txt");
            if (archivo.is_open()) {
                for (const auto& vertice : rutaActual.vertices) {
                    archivo << vertice.x << " " << vertice.y << std::endl;
                }
                archivo.close();
                std::cout << "Coordenadas de la ruta guardadas en vertices.txt" << std::endl;
            }
            else {
                std::cerr << "Error al abrir el archivo para guardar las coordenadas." << std::endl;
            }
        }
        else {
            std::cout << "No se proporcionó un nombre para la ruta." << std::endl;
        }
    
    
    }
    else if (botones.botonCargarRutas.getGlobalBounds().contains(x, y)) {
        std::cout << "Botón cargar ruta presionado." << std::endl;

        // Limpiar rutas actuales antes de cargar nuevas rutas
        rutas.clear();

        // Abrir el archivo para lectura
        std::ifstream archivo("vertices.txt");
        if (archivo.is_open()) {
            // Variables temporales para almacenar datos leídos del archivo
            std::string nombreRuta;
            float coordenadaX, coordenadaY;

            // Leer datos desde el archivo
            while (archivo >> coordenadaX >> coordenadaY) {
                // Crear un nuevo vértice con las coordenadas leídas
                sf::Vector2f vertice(coordenadaX, coordenadaY);

                // Si es el primer vértice, crear una nueva ruta
                if (rutaActual.vertices.empty()) {
                    rutaActual = Ruta("Nueva Ruta", paletaColores.getColorSeleccionado());
                }

                // Agregar el vértice a la ruta actual
                rutaActual.vertices.push_back(vertice);
            }

            // Cerrar el archivo
            archivo.close();

            // Agregar la ruta actual al vector de rutas si tiene vértices
            if (!rutaActual.vertices.empty()) {
                rutas.push_back(rutaActual);
                std::cout << "Ruta cargada desde vertices.txt." << std::endl;
            }
            else {
                std::cout << "No se encontraron datos en el archivo vertices.txt." << std::endl;
            }
        }
        else {
            std::cerr << "Error al abrir el archivo para cargar las coordenadas." << std::endl;
        }
    }else if (botones.botonSiguienteColor.getGlobalBounds().contains(x, y)) {
        // Lógica para el botón Siguiente Color
        paletaColores.siguienteColor();
        std::cout << "Siguiente color seleccionado." << std::endl;
    }
    
}
void Ventana::dibujarBotones() {

    ventana.draw(botones.botonAgregarRuta);
    ventana.draw(botones.etiquetaAgregarRuta);
    ventana.draw(botones.botonFinRuta);
    ventana.draw(botones.etiquetaFinRuta);
    ventana.draw(botones.botonEditarRuta);
    ventana.draw(botones.etiquetaEditarRuta);
    ventana.draw(botones.botonEliminarRuta);
    ventana.draw(botones.etiquetaEliminarRuta);
    ventana.draw(botones.botonMostrarOcultarRuta);
    ventana.draw(botones.etiquetaMostrarOcultarRuta);
    ventana.draw(botones.botonGuardarRutas);
    ventana.draw(botones.etiquetaGuardarRutas);
    ventana.draw(botones.botonCargarRutas);
    ventana.draw(botones.etiquetaCargarRutas);
    ventana.draw(botones.botonSiguienteColor);
    ventana.draw(botones.etiquetaSiguienteColor);
    ventana.draw(botones.muestraColor);
    ventana.draw(botones.etiquetamuestraColor);
}

void Ventana::manejarClick(float x, float y) {
    sf::Vector2f punto(x, y);

    // Lógica para manejar los clicks en los botones
    manejarClickEnBotones(x, y);

    // Si se está dibujando una ruta, agregar vértices
    if (dibujandoRuta && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        rutaActual.agregarVertice(punto);
    }
    // Lógica para manejar los clicks en las rutas
    for (auto& ruta : rutas) {
        if (ruta.seleccionar(punto)) {
            rutaSeleccionada = &ruta;
            std::cout << "Ruta seleccionada: " << ruta.nombre << std::endl;
            return;
        }
    }

    // Si no se ha seleccionado ninguna ruta, deseleccionar la actual
    rutaSeleccionada = nullptr;

    // Lógica para manejar los clicks en el mapa y agregar vértices a la ruta seleccionada
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && rutaSeleccionada != nullptr) {
        rutaSeleccionada->agregarVertice(punto);
    }
}


void Ventana::dibujar() {
    ventana.clear(sf::Color::White);

    // Crear una textura y cargar la imagen desde un archivo
    sf::Texture texturaMapa;
    if (!texturaMapa.loadFromFile("mapa.jpg")) {
        std::cerr << "Error al cargar la imagen del mapa." << std::endl;
        return;
    }

    // Crear un sprite y establecer la textura
    sf::Sprite spriteMapa(texturaMapa);

    // Definir el tamaño original del mapa
    float mapaOriginalWidth = static_cast<float>(texturaMapa.getSize().x);
    float mapaOriginalHeight = static_cast<float>(texturaMapa.getSize().y);

    // Definir el tamaño de la ventana
    float ventanaWidth = static_cast<float>(ventana.getSize().x);
    float ventanaHeight = static_cast<float>(ventana.getSize().y);

    // Calcular la escala para ajustar el mapa al tamaño de la ventana
    float escalaX = (ventanaWidth * 2.0f) / (3.0f * mapaOriginalWidth); // Dos tercios de la ventana
    float escalaY = ventanaHeight / mapaOriginalHeight;

    // Usar la escala más pequeña para mantener la proporción original del mapa
    float escala = std::min(escalaX, escalaY);

    // Establecer la posición y escala del sprite del mapa (dos tercios de la ventana)
    spriteMapa.setScale(escala, escala);
    spriteMapa.setPosition(0, (ventanaHeight - (mapaOriginalHeight * escala)) / 2.0f);

    // Dibujar el sprite del mapa en la ventana
    ventana.draw(spriteMapa);

    // Definir la posición y tamaño del panel de botones (un tercio de la ventana)
    float panelWidth = ventanaWidth / 3.0f;
    float panelHeight = ventanaHeight;
    float panelX = (ventanaWidth * 2.0f) / 3.0f; // Inicia después de dos tercios de la ventana
    float panelY = 0;
    sf::RectangleShape panel(sf::Vector2f(panelWidth, panelHeight));
    panel.setPosition(panelX, panelY);
    panel.setFillColor(sf::Color(100, 100, 100));

    // Dibujar el panel de botones en la ventana
    ventana.draw(panel);

    
    // Lógica para dibujar las rutas
    for (const auto& ruta : rutas) {
        ruta.dibujar(ventana);
    }

    // Si se está dibujando una ruta, dibujar la ruta actual
    if (dibujandoRuta) {
        rutaActual.dibujar(ventana);
    }
    
    dibujarBotones();

    // Dibujar los vértices en el mapa
    sf::CircleShape punto(5); // Puedes ajustar el tamaño del punto
    punto.setFillColor(sf::Color::Red); // Puedes ajustar el color del punto

    for (const auto& vertice : vertices) {
        punto.setPosition(vertice);
        ventana.draw(punto);
    }
    ventana.display();
}
