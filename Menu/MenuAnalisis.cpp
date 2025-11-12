#include "../MenuH/Menu.h"
#include "../MenuH/MenuAnalisis.h"
#include "../ServicioH/ServicioAnalisis.h"
#include <iostream>

MenuAnalisis::MenuAnalisis() : Menu("Menu de Análisis"), _servicioAnalisis() {}

void MenuAnalisis::ejecutar() {
    int opcion = 0;

    do {
        mostrarTitulo();
        std::cout << "1. Registrar nuevo Análisis" << std::endl;
        std::cout << "2. Modificar Análisis" << std::endl;
        std::cout << "3. Eliminar Análisis" << std::endl;
        std::cout << "4. Listar Análisis activos" << std::endl;
        std::cout << "5. Buscar por nombre" << std::endl;
        std::cout << "6. Buscar por categoria" << std::endl;
        std::cout << "7. Ordenar por nombre" << std::endl;
        std::cout << "0. Volver al menú principal" << std::endl;
        std::cout << "Seleccione una opción: ";

        if (!(std::cin >> opcion)) {
            std::cout << "Entrada inválida." << std::endl;
            limpiarBuffer();
            continue;
        }

        switch (opcion) {
            case 1:
                _servicioAnalisis.crearAnalisis();
                break;

            case 2:
                _servicioAnalisis.modificarAnalisis();
                break;

            case 3:
                _servicioAnalisis.eliminarAnalisis();
                break;

            case 4:
                _servicioAnalisis.listarAnalisisActivos();
                break;

            case 5:
                _servicioAnalisis.listarPorNombre();
                break;

            case 6:
                _servicioAnalisis.buscarPorCategoria();
                break;

            case 7:
                _servicioAnalisis.ordenarPorCategoria();
                break;

            case 0:
                std::cout << "Volviendo al menú principal..." << std::endl;
                break;

            default:
                std::cout << "Opción inválida. Intente nuevamente." << std::endl;
                break;
        }
    } while (opcion != 0);
}

