#include "../ManagerH/ManagerCategoria.h"
#include "../EntidadesH/Categoria.h"
#include "../ServicioH/ServicioCategoria.h"
#include "../ManagerH/Manager.h"
#include "../ManagerH/ManagerAnalisis.h"
#include <cstring>
#include <iostream>
#include <vector>
#include <limits>

ServicioCategoria::ServicioCategoria(): _managerCategoria("categorias.dat") {}

//CREAR CATEGORÍA
void ServicioCategoria::crearCategoria() {
    int id = _managerCategoria.obtenerNuevoId();
    std::string nombre;
    bool nombreValido;

    std::vector<Categoria> lista = _managerCategoria.leerTodos();

    do{
        std::cout<<"Ingrese el nombre de la categoria: "<<std::endl;
        std::getline(std::cin,nombre);

        if(nombre.empty() || nombre.find_first_not_of(' ') == std::string::npos){
            std::cout<<"El nombre no puede ser vacio. Intentelo nuevamente."<<std::endl;
            continue;
        }

        bool duplicado = false;

        for (int i = 0; i < (int) lista.size(); i++){
            if (lista[i].getNombre() == nombre) {
            duplicado = true;
            break;
            }
        }

        if (duplicado){
            std::cout << "Ya existe una categoria con ese nombre. Intente con otro. " << std::endl;
            continue;
        }

        nombreValido = true;

    }while(!nombreValido);

    Categoria categoria (id, nombre);

    if(_managerCategoria.guardar(categoria)){
        std::cout << "Categoria registrada con exito!\n";
    }else{
        std::cout << "Error al intentar guardar una categoria.\n";
    }
}

//MODIFICAR CATEGORIA
void ServicioCategoria::modificarCategoria() {
    std::vector<Categoria> lista = _managerCategoria.leerTodos();

    if(lista.empty()){
        std::cout << "\nNo hay categorias para modificar.\n";
        return;
    }

    int id;
    int posicion;
    std::string nombre;
    bool nombreValido = false;

    listarCategorias(lista);

    std::cout << "Ingrese el ID de la categoria a modificar: ";
    while (!(std::cin >> id)) {
        std::cout << "Error: Debe ingresar un número entero." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ingrese el ID: ";
    }
    std::cin.ignore();

    posicion = _managerCategoria.buscar(id);

    if (posicion == -1) {
        std::cout << "No se encontro una categoria activa con ese ID.\n";
        return;
    }

    do {
        std::cout << "Ingrese el nuevo nombre de la categoria: ";
        getline(std::cin, nombre);

        if (nombre.empty() || nombre.find_first_not_of(' ') == std::string::npos) {
            std::cout << "El nombre no puede estar vacio. Intente nuevamente.\n";
            continue;
        }

        bool duplicado =false;
        for(int i=0; i < (int)lista.size(); i++){
            if (lista[i].getId() != id && lista[i].getNombre() == nombre) {
                duplicado = true;
                break;
        }
    }

    if (duplicado){
        std::cout << "Ya existe una categoria con ese nombre. Intente con otro. " << std::endl;
        continue;
    }

    nombreValido = true;

    } while (!nombreValido);

    Categoria categoria = _managerCategoria.leer(posicion);
    categoria.setNombre(nombre);

    if (_managerCategoria.modificar(categoria, posicion)) {
        std::cout << "Categoria modificada con exito!\n";
    } else {
        std::cout << "Error al intentar modificar la categoria.\n";
    }
}

//OBTENER CATEGORIAS
 std::vector<Categoria> ServicioCategoria::obtenerCategorias(){
    return _managerCategoria.leerTodos();
}

//LISTAR CATEGORIAS
void ServicioCategoria::listarCategorias(const std::vector<Categoria>& categorias) {
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
    std::vector<Categoria> lista = _managerCategoria.leerTodos();

    if(lista.empty()){
        std::cout << "No hay categorias para eliminar." << std::endl;
        return;
    }

    listarCategorias(lista);

    int id;

    std::cout << std::endl << " Ingrese el ID a eliminar (0 para cancelar): ";
    std::cin >> id;

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
    bool encontro = false;
    std::string nombre;

    std::cout<<"Ingrese el nombre de la categoria que desea buscar: ";
    //std::cin.ignore();
    std::getline(std::cin,nombre);

    Categoria categoria = _managerCategoria.buscarPorNombre(nombre, encontro);

    if(encontro){
        std::cout<<"ID : "<<categoria.getId()<<" | Nombre: " <<categoria.getNombre()<<std::endl;
    }else{
        std::cout<<"No se encontro ninguna categoria con ese nombre. Intentelo nuevamente."<<std::endl;
    }

}

//BUSCAR POR ID
std::string ServicioCategoria::buscarPorId(int id){
    bool encontro = false;
    std::string nombreCategoria = _managerCategoria.buscarPorId(id, encontro);
    if (!encontro) {
        return "Desconocida";
    }
    return nombreCategoria;
}
