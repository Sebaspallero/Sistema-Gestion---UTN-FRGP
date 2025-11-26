#include "../MenuH/MenuPaciente.h"
#include <iostream>
#include "../ServicioH/ServiciosUtilidades.h"

using namespace std;

MenuPaciente::MenuPaciente() : Menu("Menu de Pacientes"), servicioPaciente() {}


void MenuPaciente::ejecutar() {
    int opcion;

    do {
        system("cls");
        mostrarTitulo();
        cout << "1. Registrar nuevo paciente\n";
        cout << "2. Eliminar paciente\n";
        cout << "3. Modificar paciente\n";
        cout << "4. Listar pacientes\n";
        cout << "------------------------------\n";
        cout << "5. Buscar por apellido\n";
        cout << "6. Buscar por DNI\n";
        cout << "7. Ordenar pacientes por apellido\n";
        cout << "0. Volver al menu principal\n";
        opcion = pedirEntero("Seleccione una opcion: ");
        limpiarBuffer();
        switch (opcion) {
            case 1:
                servicioPaciente.crearPaciente();
                pausar();
                break;

            case 2:
                servicioPaciente.eliminarPaciente();
                pausar();
                break;

            case 3:
                servicioPaciente.modificarPaciente();
                pausar();
                break;

            case 4:
                servicioPaciente.listarPacientes(servicioPaciente.obtenerPacientes());
                pausar();
                break;

            case 5:
                servicioPaciente.buscarPacientePorApellido();
                pausar();
                break;

            case 6:
                servicioPaciente.buscarPacientePorDNI();
                pausar();
                break;

            case 7:
                servicioPaciente.ordenarPacientesPorApellido();
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
