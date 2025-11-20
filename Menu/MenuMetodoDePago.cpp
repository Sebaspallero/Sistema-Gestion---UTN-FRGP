#include "../MenuH/MenuMetodoDePago.h"
#include <iostream>

using namespace std;

MenuMetodoDePago::MenuMetodoDePago() : Menu("Menu de Metodos de Pago"), servicioMetodoDePago() {}

void MenuMetodoDePago::ejecutar() {
    int opcion = -1;

    do {
        system("cls");
        mostrarTitulo();
        cout << "1. Registrar nuevo metodo de pago\n";
        cout << "2. Eliminar metodo de pago\n";
        cout << "3. Modificar metodo de pago\n";
        cout << "4. Listar metodos de pago\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";

        if (!(cin>>opcion)) {
            system("cls");
            cout << "Entrada invalida. Debe ingresar un numero. " << endl;
            limpiarBuffer();
            opcion = -1;
            pausar();
        }

        else{
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
                limpiarBuffer();
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                pausar();
                break;
            }
        }

    } while (opcion != 0);
}
