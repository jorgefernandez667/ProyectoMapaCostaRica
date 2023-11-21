#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include "ventana.h"

std::string Ventana::mostrarVentanaDialogo() {
    std::string nombreRuta;

    // Muestra una ventana de di�logo simple
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
    // L�gica para manejar clicks en botones
    if (botones.botonAgregarRuta.getGlobalBounds().contains(x, y)) {
        // L�gica para el bot�n Agregar Ruta
        std::cout << "Bot�n Agregar Ruta presionado." << std::endl;
        
        dibujandoRuta = true;
        if (dibujandoRuta == true) {
            std::cout << "puedes dibujar." << std::endl;
        }
    }
    else if (botones.botonFinRuta.getGlobalBounds().contains(x, y)) {
        // L�gica para el bot�n Fin de la Ruta
        std::cout << "Bot�n Fin de la Ruta presionado." << std::endl;
        dibujandoRuta = false;

        if (rutaActual.vertices.size() > 1) {
            rutas.push_back(rutaActual);
        }
            // Limpiar la ruta actual
            rutaActual = Ruta("Nueva Ruta", paletaColores.getColorSeleccionado());
    }
    else if (botones.botonEditarRuta.getGlobalBounds().contains(x, y)) {
        // L�gica para el bot�n Editar Ruta
        std::cout << "Bot�n Editar Ruta presionado." << std::endl;
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
            // Si se est� dibujando una ruta, limpiar la ruta actual
            std::cout << "Ruta dibujada eliminada." << std::endl;
            rutaActual = Ruta("Nueva Ruta", paletaColores.getColorSeleccionado());
        }
        else if (!rutas.empty()) {
            // Si no se est� dibujando y hay rutas en el vector, borrar la �ltima ruta
            std::cout << "�ltima ruta agregada eliminada." << std::endl;
            rutas.pop_back();
        }
        else {
            std::cout << "No hay ruta seleccionada para eliminar." << std::endl;
        }
    }
    else if (botones.botonMostrarOcultarRuta.getGlobalBounds().contains(x, y)) {
        // L�gica para el bot�n Editar Ruta
        std::cout << "Bot�n mostrar/ocultar ruta presionado." << std::endl;
    }
    else if (botones.botonGuardarRutas.getGlobalBounds().contains(x, y)) {
        std::cout << "Bot�n Guardar Rutas presionado." << std::endl;

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
            std::cout << "No se proporcion� un nombre para la ruta." << std::endl;
        }
    
    
    }
    else if (botones.botonCargarRutas.getGlobalBounds().contains(x, y)) {
        std::cout << "Bot�n cargar ruta presionado." << std::endl;

        // Limpiar rutas actuales antes de cargar nuevas rutas
        rutas.clear();

        // Abrir el archivo para lectura
        std::ifstream archivo("vertices.txt");
        if (archivo.is_open()) {
            // Variables temporales para almacenar datos le�dos del archivo
            std::string nombreRuta;
            float coordenadaX, coordenadaY;

            // Leer datos desde el archivo
            while (archivo >> coordenadaX >> coordenadaY) {
                // Crear un nuevo v�rtice con las coordenadas le�das
                sf::Vector2f vertice(coordenadaX, coordenadaY);

                // Si es el primer v�rtice, crear una nueva ruta
                if (rutaActual.vertices.empty()) {
                    rutaActual = Ruta("Nueva Ruta", paletaColores.getColorSeleccionado());
                }

                // Agregar el v�rtice a la ruta actual
                rutaActual.vertices.push_back(vertice);
            }

            // Cerrar el archivo
            archivo.close();

            // Agregar la ruta actual al vector de rutas si tiene v�rtices
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
        // L�gica para el bot�n Siguiente Color
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

    // L�gica para manejar los clicks en los botones
    manejarClickEnBotones(x, y);

    // Si se est� dibujando una ruta, agregar v�rtices
    if (dibujandoRuta && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        rutaActual.agregarVertice(punto);
    }
    // L�gica para manejar los clicks en las rutas
    for (auto& ruta : rutas) {
        if (ruta.seleccionar(punto)) {
            rutaSeleccionada = &ruta;
            std::cout << "Ruta seleccionada: " << ruta.nombre << std::endl;
            return;
        }
    }

    // Si no se ha seleccionado ninguna ruta, deseleccionar la actual
    rutaSeleccionada = nullptr;

    // L�gica para manejar los clicks en el mapa y agregar v�rtices a la ruta seleccionada
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

    // Definir el tama�o original del mapa
    float mapaOriginalWidth = static_cast<float>(texturaMapa.getSize().x);
    float mapaOriginalHeight = static_cast<float>(texturaMapa.getSize().y);

    // Definir el tama�o de la ventana
    float ventanaWidth = static_cast<float>(ventana.getSize().x);
    float ventanaHeight = static_cast<float>(ventana.getSize().y);

    // Calcular la escala para ajustar el mapa al tama�o de la ventana
    float escalaX = (ventanaWidth * 2.0f) / (3.0f * mapaOriginalWidth); // Dos tercios de la ventana
    float escalaY = ventanaHeight / mapaOriginalHeight;

    // Usar la escala m�s peque�a para mantener la proporci�n original del mapa
    float escala = std::min(escalaX, escalaY);

    // Establecer la posici�n y escala del sprite del mapa (dos tercios de la ventana)
    spriteMapa.setScale(escala, escala);
    spriteMapa.setPosition(0, (ventanaHeight - (mapaOriginalHeight * escala)) / 2.0f);

    // Dibujar el sprite del mapa en la ventana
    ventana.draw(spriteMapa);

    // Definir la posici�n y tama�o del panel de botones (un tercio de la ventana)
    float panelWidth = ventanaWidth / 3.0f;
    float panelHeight = ventanaHeight;
    float panelX = (ventanaWidth * 2.0f) / 3.0f; // Inicia despu�s de dos tercios de la ventana
    float panelY = 0;
    sf::RectangleShape panel(sf::Vector2f(panelWidth, panelHeight));
    panel.setPosition(panelX, panelY);
    panel.setFillColor(sf::Color(100, 100, 100));

    // Dibujar el panel de botones en la ventana
    ventana.draw(panel);

    
    // L�gica para dibujar las rutas
    for (const auto& ruta : rutas) {
        ruta.dibujar(ventana);
    }

    // Si se est� dibujando una ruta, dibujar la ruta actual
    if (dibujandoRuta) {
        rutaActual.dibujar(ventana);
    }
    
    dibujarBotones();

    // Dibujar los v�rtices en el mapa
    sf::CircleShape punto(5); // Puedes ajustar el tama�o del punto
    punto.setFillColor(sf::Color::Red); // Puedes ajustar el color del punto

    for (const auto& vertice : vertices) {
        punto.setPosition(vertice);
        ventana.draw(punto);
    }
    ventana.display();
}
