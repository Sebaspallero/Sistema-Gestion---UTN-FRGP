#include "../MenuH/MenuPrincipal.h"
#include <iostream>
using namespace std;

MenuPrincipal::MenuPrincipal() : Menu("Menu Principal") {}

void MenuPrincipal::ejecutar() {
    int opcion = 0;
    do {
        mostrarTitulo();
        cout << "1. Gestionar Salas" << endl;
        //AGREGAR OPCIONES DE LOS MENUS
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuSala.ejecutar();
                limpiarBuffer();
                break;
            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }

    } while (opcion != 0);
}
