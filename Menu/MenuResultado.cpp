#include "../MenuH/Menu.h"
#include "../MenuH/MenuResultado.h"
#include "../ServicioH/ServicioResultado.h"

using namespace std;

MenuResultado::MenuResultado() : Menu("Menu de Resultados"), servicioResultado() {}

void MenuResultado::ejecutar(){
    int opcion = -1;

    do {
        system("cls");
        mostrarTitulo();
        cout << "1. Registrar nuevo resultado\n";
        cout << "2. Eliminar resultado\n";
        cout << "3. Modificar resultado\n";
        cout << "4. Listar resultados\n";
        cout << "------------------------------\n";
        cout << "5. Buscar por paciente\n";
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
        limpiarBuffer();
        switch (opcion) {
            case 1:
                servicioResultado.crearResultado();
                pausar();
                break;

            case 2:
                servicioResultado.eliminarResultado();
                pausar();
                break;

            case 3:
                servicioResultado.modificarResultado();
                pausar();
                break;

            case 4:
                servicioResultado.listarResultados(servicioResultado.obtenerResultado());
                pausar();
                break;

            case 5:
                servicioResultado.buscarPorPaciente();
                pausar();
                break;

            case 0:
                cout << "Volviendo al menú principal..." << endl;
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                pausar();
                break;
            }
        }

    } while (opcion != 0);

}
