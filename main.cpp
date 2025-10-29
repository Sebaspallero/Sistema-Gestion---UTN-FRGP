#include <iostream>
#include "ManagerH/ManagerSala.h"
#include <limits>

using namespace std;

void limpiarBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void mostrarMenu(ManagerSala& manager) {
    int opcion;
    std::string nombre;
    int piso;

    do {
        std::cout << "\n--- MENU GESTION DE SALAS ---\n";
        std::cout << "1. Registrar nueva sala\n";
        std::cout << "2. Listar todas las salas\n";
        std::cout << "3. Eliminar Sala\n";
        std::cout << "4. Buscar por nombre\n";
        std::cout << "5. Modificar Sala\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opcion: ";

        if (!(std::cin >> opcion)) {
            std::cout << "Entrada invalida. Intente de nuevo.\n";
            limpiarBuffer();
            continue;
        }

        switch (opcion) {
            case 1: {
                std::cout << "\n-- REGISTRAR SALA --\n";


                std::cout << "Ingrese el nombre de la sala: ";
                limpiarBuffer();
                std::getline(std::cin, nombre);

                std::cout << "Ingrese el numero de piso: ";
                if (!(std::cin >> piso)) {
                    std::cout << "Error: El piso debe ser un numero.\n";
                    limpiarBuffer();
                    break;
                }

                if (manager.crearSala(nombre, piso)) {
                    std::cout << "Sala '" << nombre << "' registrada con exito!\n";
                } else {
                    std::cout << "Error al intentar guardar la sala.\n";
                }
                break;
            }

            case 2: {
                std::cout << "\n-- LISTADO DE SALAS --\n";
                std::vector<Sala> salas = manager.leerTodos();

                if (salas.empty()) {
                    std::cout << "No hay salas registradas.\n";
                } else {
                    for (const auto& sala : salas) {
                        std::cout << "ID: " << sala.getId()
                                  << " | Nombre: " << sala.getNombre()
                                  << " | Piso: " << sala.getPiso()
                                  << " | Disponible: " << (sala.isDisponible() ? "SI" : "NO")
                                  << "\n";
                    }
                }
                break;
            }

            case 3: {
                std::cout << "\n-- LISTADO DE SALAS --\n";
                std::vector<Sala> salas = manager.leerTodos();

                if (salas.empty()) {
                    std::cout << "No hay salas registradas.\n";
                } else {
                    for (const auto& sala : salas) {
                        std::cout << "ID: " << sala.getId()
                                  << " | Nombre: " << sala.getNombre()
                                  << " | Piso: " << sala.getPiso()
                                  << " | Disponible: " << (sala.isDisponible() ? "SI" : "NO")
                                  << "\n";
                    }
                }

                std::cout << "\n-- ESCRIBA EL ID DE LA SALA A ELIMINAR --\n";

                int eliminar;
                cin>>eliminar;

                 bool eliminado = manager.eliminar(eliminar);

                 if(eliminado){
                    std::cout << "\n-- ELIMINADO EXITOSAMENTE --\n";
                 }else{
                     std::cout << "\n-- OCURRIO UN ERROR AL ELIMINAR LA SALA --\n";
                }

                break;
            }

            case 4: {
                std::cout << "\n-- BUSCAR SALA POR NOMBRE --\n";

                std::cout << "\n-- ESCRIBA EL NOMBRE DE LA SALA A BUSCAR --\n";

                std::string nombre;
                cin>>nombre;

                 Sala sala = manager.buscarPorNombre(nombre);

                 if(sala.getId() > 0){
                     std::cout << "ID: " << sala.getId()
                                  << " | Nombre: " << sala.getNombre()
                                  << " | Piso: " << sala.getPiso()
                                  << " | Disponible: " << (sala.isDisponible() ? "SI" : "NO")
                                  << "\n";
                 }else{
                     std::cout << "\n-- OCURRIO UN ERROR AL BUSCAR LA SALA --\n";
                }

                break;
            }

            case 5: {
                std::cout << "\n-- LISTADO DE SALAS --\n";
                std::vector<Sala> salas = manager.leerTodos();

                if (salas.empty()) {
                    std::cout << "No hay salas registradas.\n";
                } else {
                    for (const auto& sala : salas) {
                        std::cout << "ID: " << sala.getId()
                                  << " | Nombre: " << sala.getNombre()
                                  << " | Piso: " << sala.getPiso()
                                  << " | Disponible: " << (sala.isDisponible() ? "SI" : "NO")
                                  << "\n";
                    }
                }

                std::cout << "\n-- ESCRIBA EL ID DE LA SALA A MODIFICAR --\n";
                int modificar;
                std::cin >> modificar;
                limpiarBuffer();

                std::string nombre;
                std::cout << "Ingrese el nombre de la sala: ";
                std::getline(std::cin, nombre);

                int piso;
                std::cout << "Ingrese el numero de piso: ";
                if (!(std::cin >> piso)) {
                    std::cout << "Error: El piso debe ser un numero.\n";
                    limpiarBuffer();
                    break;
                }

                limpiarBuffer();
                std::string opciond;
                std::cout << "Ingrese SI (disponible) o NO (ocupada): ";
                std::getline(std::cin, opciond);

                bool disponible = (opciond == "SI" || opciond == "Si" || opciond == "si");

                bool modificado = manager.modificarSala(nombre, piso, disponible, modificar);

                if (modificado) {
                    std::cout << "SE MODIFICO EXITOSAMENTE\n";
                } else {
                    std::cout << "OCURRIO UN ERROR AL MODIFICAR LA SALA\n";
                }

                break;
            }

            case 0:
                std::cout << "Saliendo del programa. Hasta luego!\n";
                break;

            default:
                std::cout << "Opcion no reconocida. Por favor, elija entre 0 y 5.\n";
                break;
        }

    } while (opcion != 0);
}

int main()
{
    ManagerSala gestorSalas("salas_laboratorio.dat");

    mostrarMenu(gestorSalas);

    return 0;
}
