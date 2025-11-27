#include "../ManagerH/ManagerCategoria.h"
#include "../EntidadesH/Categoria.h"
#include "../ServicioH/ServicioCategoria.h"
#include "../ManagerH/Manager.h"
#include "../ManagerH/ManagerAnalisis.h"
#include "../ServicioH/ServiciosUtilidades.h"
#include <cstring>
#include <iostream>
#include <vector>
#include <limits>

ServicioCategoria::ServicioCategoria(): _managerCategoria("categorias.dat") {}

//CREAR CATEGORÍA
void ServicioCategoria::crearCategoria() {
    system("cls");
    int id = _managerCategoria.obtenerNuevoId();
    std::string nombre;
    std::vector<Categoria> lista = _managerCategoria.leerTodos();

    while (true) {
        std::cout << "Ingrese el nombre de la categoria (0 para cancelar): ";
        std::getline(std::cin, nombre);

        if (nombre == "0") return;

        if (nombre.empty() || nombre.find_first_not_of(' ') == std::string::npos) {
            std::cout << "El nombre no puede ser vacio.\n";
            continue;
        }

        bool duplicado = false;
        for (int i = 0; i < (int) lista.size(); i++){
            if (lista[i].getNombre() == nombre) {
                duplicado = true;
                break;
            }
        }
        if (duplicado) {
            std::cout << "Ya existe una categoria con ese nombre.\n";
            continue;
        }

        break;
    }

    Categoria categoria(id, nombre);

    if (_managerCategoria.guardar(categoria)) {
        std::cout << "Categoria registrada con exito!\n";
    } else {
        std::cout << "Error al intentar guardar la categoria.\n";
    }
}

//MODIFICAR CATEGORIA
void ServicioCategoria::modificarCategoria() {
    system("cls");
    std::vector<Categoria> lista = _managerCategoria.leerTodos();

    if (lista.empty()) {
        std::cout << "No hay categorias para modificar.\n";
        return;
    }

    listarCategorias(lista);

    int id;
    int posicion = -1;

    // Selección de ID
    while (true) {
        std::cout << "\nIngrese el ID de la categoria a modificar (0 para cancelar): ";
        if (std::cin >> id) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (id == 0) return;

            posicion = _managerCategoria.buscar(id);
            if (posicion != -1) break;

            std::cout << "No se encontro una categoria con ese ID.\n";

        } else {
            std::cout << "Error: Debe ingresar un numero.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    system("cls");
    Categoria categoria = _managerCategoria.leer(posicion);

    std::string nombre;

    while (true) {
        std::cout << "Nuevo nombre [" << categoria.getNombre() << "] (0 para cancelar): ";
        std::getline(std::cin, nombre);

        if (nombre == "0") return;

        if (nombre.empty()) {
            nombre = categoria.getNombre();
            break;
        }

        if (nombre.find_first_not_of(' ') == std::string::npos) {
            std::cout << "El nombre no puede ser vacio.\n";
            continue;
        }

        bool duplicado = false;
        for (int i = 0; i < (int) lista.size(); i++) {
            if (lista[i].getId() != id && lista[i].getNombre() == nombre) {
                duplicado = true;
                break;
            }
        }

        if (duplicado) {
            std::cout << "Ya existe otra categoria con ese nombre.\n";
            continue;
        }

        break;
    }

    categoria.setNombre(nombre);

    if (_managerCategoria.modificar(categoria, posicion)) {
        std::cout << "Categoria modificada con exito!\n";
    } else {
        std::cout << "Error al modificar la categoria.\n";
    }
}

//OBTENER CATEGORIAS
 std::vector<Categoria> ServicioCategoria::obtenerCategorias(){
    return _managerCategoria.leerTodos();
}

//LISTAR CATEGORIAS
void ServicioCategoria::listarCategorias(const std::vector<Categoria>& categorias) {
    system("cls");
    if (categorias.empty()) {
        std::cout << "No hay categorias registrados.\n";
    } else {
        std::cout << std::endl << "-- LISTADO DE CATEGORIAS --"<< std::endl;
        for (int i = 0; i < (int)categorias.size(); i++) {
            Categoria categoria = categorias[i];
            std::cout << "ID: " << categoria.getId()
                 << " | Nombre: " << categoria.getNombre()
                 << std::endl;
        }
    }
}

//ELIMINAR CATEGORIA
void ServicioCategoria::eliminarCategoria() {
    system("cls");
    std::vector<Categoria> lista = _managerCategoria.leerTodos();

    if(lista.empty()){
        std::cout << "No hay categorias para eliminar." << std::endl;
        return;
    }

    listarCategorias(lista);

    int id;
    id = pedirEntero(" Ingrese el ID a eliminar (0 para cancelar): ");

    if(id == 0){
        std::cout << "Operacion cancelada. " << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    int posicion = _managerCategoria.buscar(id);
    if(posicion == -1){
        std::cout << "No se encontro una categoria con ese ID. " << std::endl;
        return;
    }

    std::cout << "Esta seguro que desea eliminar esta categoria? (S/N): ";
    char confirma;
    std::cin >> confirma;

    if (confirma == 'S' || confirma == 's'){
            bool eliminado = _managerCategoria.eliminar(id);
                if(eliminado){
            std::cout << std::endl << "-- ELIMINADO EXITOSAMENTE --"<< std::endl;
            }else{
                std::cout << std::endl << "-- OCURRIO UN ERROR AL ELIMINAR LA CATEGORIA --"<< std::endl;
            }
        }

    else{
        std::cout << "Operacion cancelada. " << std::endl;
        return;
    }
}

//BUSCAR POR NOMBRE
void ServicioCategoria::buscarPorNombre(){
    system("cls");
    bool encontro = false;
    std::string nombre;

    std::cout<<"Ingrese el nombre de la categoria que desea buscar (0 para cancelar): ";
    std::getline(std::cin,nombre);

    if (nombre == "0") return;

    Categoria categoria = _managerCategoria.buscarPorNombre(nombre, encontro);

    if(encontro){
        std::cout<<"ID : "<<categoria.getId()<<" | Nombre: " <<categoria.getNombre()<<std::endl;
    }else{
        std::cout<<"No se encontro ninguna categoria con ese nombre. Intentelo nuevamente."<<std::endl;
    }

}

//BUSCAR POR ID
std::string ServicioCategoria::buscarPorId(int id){
    system("cls");
    bool encontro = false;
    std::string nombreCategoria = _managerCategoria.buscarPorId(id, encontro);
    if (!encontro) {
        return "Desconocida";
    }
    return nombreCategoria;
}
