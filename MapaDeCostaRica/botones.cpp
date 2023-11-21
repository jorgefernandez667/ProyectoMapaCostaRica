#include "botones.h"

Botones::Botones() {
        float panelX = 600; // Ajusta según tus necesidades
        float botonAncho = 150;
        float botonAltura = 30;
        float espacioEntreBotones = 10;
        float botonYInicio = 220;

        if (!fuente.loadFromFile("arial.ttf")) {
            // Manejar el error si no se puede cargar la fuente
            std::cerr << "Error al cargar la fuente." << std::endl;
            // Puedes lanzar una excepción o hacer algo más en caso de error
        }

        botonAgregarRuta.setSize(sf::Vector2f(botonAncho, botonAltura));
        botonAgregarRuta.setPosition(panelX + 10, botonYInicio);
        botonAgregarRuta.setFillColor(sf::Color::Green);

        etiquetaAgregarRuta.setFont(fuente);  // Asegúrate de tener la fuente cargada
        etiquetaAgregarRuta.setString("Agregar Ruta");
        etiquetaAgregarRuta.setCharacterSize(14);
        etiquetaAgregarRuta.setFillColor(sf::Color::Black);

        // Posiciona la etiqueta en el centro del botón
        sf::FloatRect etiquetaBounds = etiquetaAgregarRuta.getLocalBounds();
        etiquetaAgregarRuta.setOrigin(etiquetaBounds.left + etiquetaBounds.width / 2.0f,
            etiquetaBounds.top + etiquetaBounds.height / 2.0f);
        etiquetaAgregarRuta.setPosition(botonAgregarRuta.getPosition().x + botonAgregarRuta.getSize().x / 2.0f,
            botonAgregarRuta.getPosition().y + botonAgregarRuta.getSize().y / 2.0f);

        botonFinRuta.setSize(sf::Vector2f(botonAncho, botonAltura));
        botonFinRuta.setPosition(panelX + 10, botonYInicio + botonAltura + espacioEntreBotones);
        botonFinRuta.setFillColor(sf::Color::Red);

        etiquetaFinRuta.setFont(fuente);  // Asegúrate de tener la fuente cargada
        etiquetaFinRuta.setString("fin de ruta");
        etiquetaFinRuta.setCharacterSize(14);
        etiquetaFinRuta.setFillColor(sf::Color::Black);

    etiquetaBounds = etiquetaFinRuta.getLocalBounds();
    etiquetaFinRuta.setOrigin(etiquetaBounds.left + etiquetaBounds.width / 2.0f,
        etiquetaBounds.top + etiquetaBounds.height / 2.0f);
    etiquetaFinRuta.setPosition(botonFinRuta.getPosition().x + botonFinRuta.getSize().x / 2.0f,
        botonFinRuta.getPosition().y + botonFinRuta.getSize().y / 2.0f);

        botonEditarRuta.setSize(sf::Vector2f(botonAncho, botonAltura));
        botonEditarRuta.setPosition(panelX + 10, botonYInicio + 2 * (botonAltura + espacioEntreBotones));
        botonEditarRuta.setFillColor(sf::Color::Blue);

        etiquetaEditarRuta.setFont(fuente);  // Asegúrate de tener la fuente cargada
        etiquetaEditarRuta.setString("editar ruta");
        etiquetaEditarRuta.setCharacterSize(14);
        etiquetaEditarRuta.setFillColor(sf::Color::Black);

        etiquetaBounds = etiquetaEditarRuta.getLocalBounds();
        etiquetaEditarRuta.setOrigin(etiquetaBounds.left + etiquetaBounds.width / 2.0f,
            etiquetaBounds.top + etiquetaBounds.height / 2.0f);
        etiquetaEditarRuta.setPosition(botonEditarRuta.getPosition().x + botonEditarRuta.getSize().x / 2.0f,
            botonEditarRuta.getPosition().y + botonEditarRuta.getSize().y / 2.0f);

        botonEliminarRuta.setSize(sf::Vector2f(botonAncho, botonAltura));
        botonEliminarRuta.setPosition(panelX + 10, botonYInicio + 3 * (botonAltura + espacioEntreBotones));
        botonEliminarRuta.setFillColor(sf::Color::Yellow);

        etiquetaEliminarRuta.setFont(fuente);  // Asegúrate de tener la fuente cargada
        etiquetaEliminarRuta.setString("Eliminar ruta");
        etiquetaEliminarRuta.setCharacterSize(14);
        etiquetaEliminarRuta.setFillColor(sf::Color::Black);

        // Posiciona la etiqueta en el centro del botón
       etiquetaBounds = etiquetaEliminarRuta.getLocalBounds();
        etiquetaEliminarRuta.setOrigin(etiquetaBounds.left + etiquetaBounds.width / 2.0f, etiquetaBounds.top + etiquetaBounds.height / 2.0f);
        etiquetaEliminarRuta.setPosition(botonEliminarRuta.getPosition().x + botonEliminarRuta.getSize().x / 2.0f,
            botonEliminarRuta.getPosition().y + botonEliminarRuta.getSize().y / 2.0f);

        botonMostrarOcultarRuta.setSize(sf::Vector2f(botonAncho, botonAltura));
        botonMostrarOcultarRuta.setPosition(panelX + 10, botonYInicio + 4 * (botonAltura + espacioEntreBotones));
        botonMostrarOcultarRuta.setFillColor(sf::Color::Magenta);

        etiquetaMostrarOcultarRuta.setFont(fuente);  // Asegúrate de tener la fuente cargada
        etiquetaMostrarOcultarRuta.setString("mostrar/ocultar ruta");
        etiquetaMostrarOcultarRuta.setCharacterSize(14);
        etiquetaMostrarOcultarRuta.setFillColor(sf::Color::Black);

        // Posiciona la etiqueta en el centro del botón
        etiquetaBounds = etiquetaMostrarOcultarRuta.getLocalBounds();
        etiquetaMostrarOcultarRuta.setOrigin(etiquetaBounds.left + etiquetaBounds.width / 2.0f, etiquetaBounds.top + etiquetaBounds.height / 2.0f);
        etiquetaMostrarOcultarRuta.setPosition(botonMostrarOcultarRuta.getPosition().x + botonMostrarOcultarRuta.getSize().x / 2.0f,
            botonMostrarOcultarRuta.getPosition().y + botonMostrarOcultarRuta.getSize().y / 2.0f);

        botonGuardarRutas.setSize(sf::Vector2f(botonAncho, botonAltura));
        botonGuardarRutas.setPosition(panelX + 10, botonYInicio + 5 * (botonAltura + espacioEntreBotones));
        botonGuardarRutas.setFillColor(sf::Color::Cyan);

        etiquetaGuardarRutas.setFont(fuente);  // Asegúrate de tener la fuente cargada
        etiquetaGuardarRutas.setString("Guardar rutas");
        etiquetaGuardarRutas.setCharacterSize(14);
        etiquetaGuardarRutas.setFillColor(sf::Color::Black);

        // Posiciona la etiqueta en el centro del botón
        etiquetaBounds = etiquetaGuardarRutas.getLocalBounds();
        etiquetaGuardarRutas.setOrigin(etiquetaBounds.left + etiquetaBounds.width / 2.0f, etiquetaBounds.top + etiquetaBounds.height / 2.0f);
        etiquetaGuardarRutas.setPosition(botonGuardarRutas.getPosition().x + botonGuardarRutas.getSize().x / 2.0f,
            botonGuardarRutas.getPosition().y + botonGuardarRutas.getSize().y / 2.0f);

        botonCargarRutas.setSize(sf::Vector2f(botonAncho, botonAltura));
        botonCargarRutas.setPosition(panelX + 10, botonYInicio + 6 * (botonAltura + espacioEntreBotones));
        botonCargarRutas.setFillColor(sf::Color::White);

        etiquetaCargarRutas.setFont(fuente);  // Asegúrate de tener la fuente cargada
        etiquetaCargarRutas.setString("Cargar rutas");
        etiquetaCargarRutas.setCharacterSize(14);
        etiquetaCargarRutas.setFillColor(sf::Color::Black);

        // Posiciona la etiqueta en el centro del botón
        etiquetaBounds = etiquetaCargarRutas.getLocalBounds();
        etiquetaCargarRutas.setOrigin(etiquetaBounds.left + etiquetaBounds.width / 2.0f, etiquetaBounds.top + etiquetaBounds.height / 2.0f);
        etiquetaCargarRutas.setPosition(botonCargarRutas.getPosition().x + botonCargarRutas.getSize().x / 2.0f,
            botonCargarRutas.getPosition().y + botonCargarRutas.getSize().y / 2.0f);

        botonSiguienteColor.setSize(sf::Vector2f(100, 50));
        botonSiguienteColor.setPosition(panelX + 10, botonYInicio + 7 * (botonAltura + espacioEntreBotones));
        botonSiguienteColor.setFillColor(sf::Color::White);

        etiquetaSiguienteColor.setFont(fuente);  // Asegúrate de tener la fuente cargada
        etiquetaSiguienteColor.setString("siguiente color");
        etiquetaSiguienteColor.setCharacterSize(14);
        etiquetaSiguienteColor.setFillColor(sf::Color::Black);

        // Posiciona la etiqueta en el centro del botón
        etiquetaBounds = etiquetaSiguienteColor.getLocalBounds();
        etiquetaSiguienteColor.setOrigin(etiquetaBounds.left + etiquetaBounds.width / 2.0f, etiquetaBounds.top + etiquetaBounds.height / 2.0f);
        etiquetaSiguienteColor.setPosition(botonSiguienteColor.getPosition().x + botonSiguienteColor.getSize().x / 2.0f,
            botonSiguienteColor.getPosition().y + botonSiguienteColor.getSize().y / 2.0f);

        muestraColor.setSize(sf::Vector2f(50, 50));
        muestraColor.setPosition(panelX + 10, botonYInicio - 60); // Ajusta según tus necesidades
        muestraColor.setFillColor(paletaColores.getColorSeleccionado());

        etiquetamuestraColor.setFont(fuente);  // Asegúrate de tener la fuente cargada
        etiquetamuestraColor.setString("muestra color actual");
        etiquetamuestraColor.setCharacterSize(14);
        etiquetamuestraColor.setFillColor(sf::Color::Black);

        // Posiciona la etiqueta en el centro del botón
        etiquetaBounds = etiquetamuestraColor.getLocalBounds();
        etiquetamuestraColor.setOrigin(etiquetaBounds.left + etiquetaBounds.width / 2.0f, etiquetaBounds.top + etiquetaBounds.height / 2.0f);
        etiquetamuestraColor.setPosition(muestraColor.getPosition().x + muestraColor.getSize().x / 2.0f,
            muestraColor.getPosition().y + muestraColor.getSize().y / 2.0f);
    

}