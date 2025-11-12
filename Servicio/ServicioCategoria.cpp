#include "../ManagerH/ManagerCategoria.h"
#include "../EntidadesH/Categoria.h"
#include "../ServicioH/ServicioCategoria.h"
#include "../ManagerH/Manager.h"
#include <cstring>
#include <iostream>
#include <vector>

ServicioCategoria::ServicioCategoria(): _managerCategoria("categorias.dat") {}
//CREAR CATEGORÍA
bool ServicioCategoria::crearCategoria() {
    int id = _managerCategoria.obtenerNuevoId();
    std::string nombre;
    std::cout<<"Ingrese el nombre de la categoria: "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin,nombre);
    Categoria categoria (id, nombre);

    return _managerCategoria.guardar(categoria);

    ///revisar si se crea en true o false
}


//MODIFICAR CATEGORIA

bool ServicioCategoria::modificarCategoria() {
    int posicion;
    int id;
    std::vector<Categoria> listaCategorias = _managerCategoria.leerTodos();
    std::string nombre;
    std::cout<<"Elija el ID de la Categoria a modificar: "<<std::endl;
    std::cin>>id;
    std::cout<<"Ingrese el nuevo nombre de la categoria: "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin,nombre);
    posicion = _managerCategoria.buscar(id);
    if (posicion == -1) {
        return false;
    }

    Categoria categoria = _managerCategoria.leer(posicion);
    categoria.setNombre(nombre);

    return _managerCategoria.modificar(categoria, posicion);
}

void ServicioCategoria::listarCategoriasActivas() {
    std::vector<Categoria> lista = _managerCategoria.leerTodos();

    std::cout <<std::endl <<"-- LISTADO DE CATEGORIAS ACTIVAS --"<<std::endl;
    bool hay = false;
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i].getEstado()) {
            hay = true;
            std::cout << "ID: " << lista[i].getId()
                      << " | Nombre: " << lista[i].getNombre() << "\n";
        }
    }
    if (!hay) {
        std::cout << "No hay categorias activas.\n";
    }
}

bool ServicioCategoria::eliminarCategoria() {
    ServicioCategoria servicioCategoria;
    std::vector<Categoria> lista = _managerCategoria.leerTodos();
    if (lista.empty()) {
        std::cout << "No hay categorias cargadas."<<std::endl;
        return false;
    }
    servicioCategoria.listarCategoriasActivas();
    std::cout << "Ingrese el ID de la categoría a eliminar: "<<std::endl;
    int id;
    std::cin>>id;

    // (opcional: chequeos de existencia/estado)
    if (_managerCategoria.eliminar(id)) {
        std::cout << "Categoría dada de baja correctamente."<<std::endl;
        return true;
    } else {
        std::cout << "No se encontró la categoría o ya estaba inactiva."<<std::endl;
        return false;
    }
}


std::vector<Categoria> ServicioCategoria::obtenerCategoriasActivas() {
    std::vector<Categoria> lista = _managerCategoria.leerTodos();
    std::vector<Categoria> activas;
    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].getEstado()) {
            activas.push_back(lista[i]);
        }
    }
    return activas;
}


void ServicioCategoria::buscarPorNombre(){
bool encontro = false;
std::string nombre;
std::cout<<"Ingrese el nombre de la categoria que desea buscar: ";
std::cin.ignore();
std::getline(std::cin,nombre);
Categoria categoria = _managerCategoria.buscarPorNombre(nombre,encontro);
if(encontro){
    std::cout<<"ID : "<<categoria.getId()<<" | Nombre: "<<categoria.getNombre()<<" | Disponible: "<<(categoria.getEstado() ? "Activo" : "Inactivo") <<std::endl;
}else{
    std::cout<<"No se encontro ninguna categoria con ese nombre. Intentelo nuevamente."<<std::endl;
}

}
