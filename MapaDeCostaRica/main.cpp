#include "ventana.h"

int main() {
    Ventana ventana;

    while (ventana.ventana.isOpen()) {
        ventana.manejarEventos();
        ventana.dibujar();
    }

    return 0;
}
