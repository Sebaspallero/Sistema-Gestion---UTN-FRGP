#include "../MenuH/MenuMetodoDePago.h"
#include <iostream>

using namespace std;

MenuMetodoDePago::MenuMetodoDePago() : Menu("Menu de Metodos de Pago"), servicioMetodoDePago() {}

void MenuMetodoDePago::ejecutar() {
    int opcion = 0;
    do {
        mostrarTitulo();
        cout << "1. Registrar nuevo metodo de pago\n";
        cout << "2. Modificar metodo de pago\n";
        cout << "3. Eliminar metodo de pago\n";
        cout << "4. Listar metodos de pago\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";

        cin>> opcion;
        if (!opcion) {
            cout << "Entrada invalida." << endl;
            limpiarBuffer();
        }

        else{
        switch (opcion) {
            case 1:
                servicioMetodoDePago.crearMetodoDePago();
                break;

            case 2:
                servicioMetodoDePago.modificarMetodoDePago();
                break;

            case 3:
                servicioMetodoDePago.eliminarMetodoDePago();
                break;

            case 4:
                servicioMetodoDePago.listarMetodosDePago(servicioMetodoDePago.obtenerMetodosDePago());
                break;

            case 0: cout << "Volviendo al menu principal..." << endl;
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                break;
            }
        }

    } while (opcion != 0);
}
