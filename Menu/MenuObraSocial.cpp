#include "../MenuH/MenuObraSocial.h"
#include <iostream>
#include "../ServicioH/ServiciosUtilidades.h"

using namespace std;

MenuObraSocial::MenuObraSocial() : Menu("Menu de Obras Sociales"), servicioObraSocial() {}

void MenuObraSocial::ejecutar() {
    int opcion;

    do {
        system("cls");
        mostrarTitulo();
        cout << "1. Registrar nueva obra social\n";
        cout << "2. Eliminar obra social\n";
        cout << "3. Modificar obra social\n";
        cout << "4. Listar obras sociales\n";
        cout << "------------------------------\n";
        cout << "5. Buscar por nombre\n";
        cout << "0. Volver al menu principal\n";
        opcion = pedirEntero("Seleccione una opcion: ");


        limpiarBuffer();
        switch (opcion) {
            case 1:
                servicioObraSocial.crearObraSocial();
                pausar();
                break;

            case 2:
                servicioObraSocial.eliminarObraSocial();
                pausar();
                break;

            case 3:
                servicioObraSocial.modificarObraSocial();
                pausar();
                break;

            case 4:
                servicioObraSocial.listarObrasSociales(servicioObraSocial.obtenerObrasSociales());
                pausar();
                break;

            case 5:
                servicioObraSocial.buscarObraSocialPorNombre();
                pausar();
                break;

            case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente" << endl;
                pausar();
                break;
            }


    } while (opcion != 0);
}
