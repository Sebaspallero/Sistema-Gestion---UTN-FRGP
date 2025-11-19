#include "../MenuH/MenuPaciente.h"
#include <iostream>

using namespace std;

MenuPaciente::MenuPaciente() : Menu("Menu de Pacientes"), servicioPaciente() {}


void MenuPaciente::ejecutar() {
    int opcion = 0;
    do {
        mostrarTitulo();
        cout << "1. Registrar nuevo paciente\n";
        cout << "2. Listar pacientes\n";
        cout << "3. Eliminar paciente\n";
        cout << "4. Buscar por DNI\n";
        cout << "5. Buscar por apellido\n";
        cout << "6. Modificar paciente\n";
        cout << "7. Ordenar pacientes por apellido\n";
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
                servicioPaciente.crearPaciente();
                break;

            case 2:
                servicioPaciente.listarPacientes(servicioPaciente.obtenerPacientes());
                break;

            case 3:
                servicioPaciente.eliminarPaciente();
                break;

            case 4:
                servicioPaciente.buscarPacientePorDNI();
                break;

            case 5:
                servicioPaciente.buscarPacientePorApellido();
                break;

            case 6:
                servicioPaciente.modificarPaciente();
                break;

            case 7:
                servicioPaciente.ordenarPacientesPorApellido();
                break;

            case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente" << endl;
                break;
            }
        }

    } while (opcion != 0);
}
