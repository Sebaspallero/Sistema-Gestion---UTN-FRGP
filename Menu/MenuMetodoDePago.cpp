#include "../MenuH/MenuMetodoDePago.h"
#include <iostream>
#include "../ServicioH/ServiciosUtilidades.h"

using namespace std;

MenuMetodoDePago::MenuMetodoDePago() : Menu("Menu de Metodos de Pago"), servicioMetodoDePago() {}

void MenuMetodoDePago::ejecutar() {
    int opcion;

    do {
        system("cls");
        mostrarTitulo();
        cout << "1. Registrar nuevo metodo de pago\n";
        cout << "2. Eliminar metodo de pago\n";
        cout << "3. Modificar metodo de pago\n";
        cout << "4. Listar metodos de pago\n";
        cout << "0. Volver al menu principal\n";
        opcion = pedirEntero("Seleccione una opcion: ");

        limpiarBuffer();
        switch (opcion) {
            case 1:
                servicioMetodoDePago.crearMetodoDePago();
                pausar();
                break;

            case 2:
                servicioMetodoDePago.eliminarMetodoDePago();
                pausar();
                break;

            case 3:
                servicioMetodoDePago.modificarMetodoDePago();
                pausar();
                break;

            case 4:
                servicioMetodoDePago.listarMetodosDePago(servicioMetodoDePago.obtenerMetodosDePago());
                pausar();
                break;

            case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                pausar();
                break;
            }


    } while (opcion != 0);
}
