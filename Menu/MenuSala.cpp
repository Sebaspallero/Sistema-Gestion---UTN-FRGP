#include "../MenuH/MenuSala.h"
#include <iostream>
using namespace std;

MenuSala::MenuSala() : Menu("Menu de Salas"), manager("salas_laboratorio.dat") {}

void MenuSala::ejecutar() {
    int opcion = 0;
    do {
        mostrarTitulo();
        cout << "1. Registrar nueva sala\n";
        cout << "2. Listar todas las salas\n";
        cout << "3. Eliminar sala\n";
        cout << "4. Buscar por nombre\n";
        cout << "5. Modificar Sala\n";
        cout << "0. Volver al menu principal\n";
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            cout << "Entrada invalida. Intente de nuevo.\n";
            limpiarBuffer();
            continue;
        }

        switch (opcion) {
            case 1: {
                cout << "\n-- REGISTRAR SALA --\n";
                int piso;
                string nombre;

                cout << "Ingrese el nombre de la sala: ";
                limpiarBuffer();
                getline(cin, nombre);

                cout << "Ingrese el numero de piso: ";
                if (!(cin >> piso)) {
                    cout << "Error: El piso debe ser un numero.\n";
                    limpiarBuffer();
                    break;
                }

                if (manager.crearSala(nombre, piso)) {
                    cout << "Sala '" << nombre << "' registrada con exito!\n";
                } else {
                    cout << "Error al intentar guardar la sala.\n";
                }
                break;
            }

            case 2: {
                cout << "\n-- LISTADO DE SALAS --\n";
                vector<Sala> salas = manager.leerTodos();

                if (salas.empty()) {
                    cout << "No hay salas registradas.\n";
                } else {
                    for (const auto& sala : salas) {
                        cout << "ID: " << sala.getId()
                                  << " | Nombre: " << sala.getNombre()
                                  << " | Piso: " << sala.getPiso()
                                  << " | Disponible: " << (sala.isDisponible() ? "SI" : "NO")
                                  << "\n";
                    }
                }
                break;
            }

            case 3: {
                cout << "\n-- LISTADO DE SALAS --\n";
                vector<Sala> salas = manager.leerTodos();

                if (salas.empty()) {
                    cout << "No hay salas registradas.\n";
                } else {
                    for (const auto& sala : salas) {
                        cout << "ID: " << sala.getId()
                                  << " | Nombre: " << sala.getNombre()
                                  << " | Piso: " << sala.getPiso()
                                  << " | Disponible: " << (sala.isDisponible() ? "SI" : "NO")
                                  << "\n";
                    }
                }

                cout << "\n-- ESCRIBA EL ID DE LA SALA A ELIMINAR --\n";

                int eliminar;
                cin>>eliminar;

                 bool eliminado = manager.eliminar(eliminar);

                 if(eliminado){
                    cout << "\n-- ELIMINADO EXITOSAMENTE --\n";
                 }else{
                     cout << "\n-- OCURRIO UN ERROR AL ELIMINAR LA SALA --\n";
                }

                break;
            }

            case 4: {
                cout << "\n-- BUSCAR SALA POR NOMBRE --\n";

                cout << "\n-- ESCRIBA EL NOMBRE DE LA SALA A BUSCAR --\n";

                string nombre;
                cin>>nombre;

                 Sala sala = manager.buscarPorNombre(nombre);

                 if(sala.getId() > 0){
                     cout << "ID: " << sala.getId()
                                  << " | Nombre: " << sala.getNombre()
                                  << " | Piso: " << sala.getPiso()
                                  << " | Disponible: " << (sala.isDisponible() ? "SI" : "NO")
                                  << "\n";
                 }else{
                     cout << "\n-- OCURRIO UN ERROR AL BUSCAR LA SALA --\n";
                }

                break;
            }

            case 5: {
                cout << "\n-- LISTADO DE SALAS --\n";
                vector<Sala> salas = manager.leerTodos();

                if (salas.empty()) {
                    cout << "No hay salas registradas.\n";
                } else {
                    for (const auto& sala : salas) {
                        cout << "ID: " << sala.getId()
                                  << " | Nombre: " << sala.getNombre()
                                  << " | Piso: " << sala.getPiso()
                                  << " | Disponible: " << (sala.isDisponible() ? "SI" : "NO")
                                  << "\n";
                    }
                }

                cout << "\n-- ESCRIBA EL ID DE LA SALA A MODIFICAR --\n";
                int modificar;
                cin >> modificar;
                limpiarBuffer();

                string nombre;
                cout << "Ingrese el nombre de la sala: ";
                getline(cin, nombre);

                int piso;
                cout << "Ingrese el numero de piso: ";
                if (!(cin >> piso)) {
                    cout << "Error: El piso debe ser un numero.\n";
                    limpiarBuffer();
                    break;
                }

                limpiarBuffer();
                string opciond;
                cout << "Ingrese SI (disponible) o NO (ocupada): ";
                getline(cin, opciond);

                bool disponible = (opciond == "SI" || opciond == "Si" || opciond == "si");

                bool modificado = manager.modificarSala(nombre, piso, disponible, modificar);

                if (modificado) {
                    cout << "SE MODIFICO EXITOSAMENTE\n";
                } else {
                    cout << "OCURRIO UN ERROR AL MODIFICAR LA SALA\n";
                }

                break;
            }

            case 0:
                cout << "Volviendo al menu principal\n";
                limpiarBuffer();
                break;

            default:
                cout << "Opcion no reconocida. Por favor, elija entre 0 y 5.\n";
                break;
        }

    } while (opcion != 0);
}
