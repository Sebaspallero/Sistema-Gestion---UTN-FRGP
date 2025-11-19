#include "../ServicioH/ServicioAnalisis.h"
#include "../ManagerH/ManagerAnalisis.h"
#include "../ServicioH/ServicioCategoria.h"
#include <string>
#include <iostream>

ServicioAnalisis::ServicioAnalisis(): _managerAnalisis("analisis.dat"), _servicioCategoria() {}

//CREAR ANALISIS
void ServicioAnalisis::crearAnalisis() {

    int idCategoria;
    float valor;
    int id = _managerAnalisis.obtenerNuevoId();
    std::string nombre;

    std::vector<Categoria> categorias = _servicioCategoria.obtenerCategorias();
    bool categoriaValida = false;

    _servicioCategoria.listarCategorias(categorias);

    while (!categoriaValida) {
        std::cout << "Ingrese el ID de la categoría (0 para cancelar): ";
        std::cin >> idCategoria;

        if (idCategoria == 0) {
            std::cout << "Operación cancelada.\n";
            return;
        }

        for (int i = 0; i < categorias.size(); i++) {
            if (categorias[i].getId() == idCategoria) {
                categoriaValida = true;
                break;
            }
        }

        if (!categoriaValida) {
            std::cout << "ID inválido. Intente nuevamente.\n";
        }
    }

    std::cout<<"Ingrese el nombre del analisis: "<<std::endl;
    std::cin.ignore();
    std::getline(std::cin,nombre);

    std::cout<<"Ingrese el valor del analisis: $";std::cin>>valor;

    Analisis analisis(id, nombre, idCategoria, valor);

    if(_managerAnalisis.guardar(analisis)){
         std::cout << "Analisis creado con exito!\n";
    }else{
        std::cout << "Error al intentar crear el analisis.\n";
    }

}


void ServicioAnalisis::modificarAnalisis() {
   int posicion, id, idCategoria;
   float valor;
   bool estado;
   std::string nombre;

   std::vector<Analisis> lista = _managerAnalisis.leerTodos();

    if (lista.empty()) {
        std::cout << "\nNo hay analisis para modificar.\n";
        return;
    }

   std::cout<<"Ingrese el ID correspondiente al Analisis que desea modificar: ";
   std::cin>>id;

   posicion = _managerAnalisis.buscar(id);
   if (posicion == -1) {
        std::cout << "No se encontro un analisis con ese ID.\n";
        return;
   }

    Analisis analisis = _managerAnalisis.leer(posicion);

    std::vector<Categoria> categorias = _servicioCategoria.obtenerCategorias();

    if(categorias.empty()){
        std::cout << "La lista de categorias esta vacia.";
        return;
    }
    _servicioCategoria.listarCategorias(categorias);

    std::cout<<"Elija la Categoria que corresponde al Analisis: ";std::cin>>idCategoria;
    analisis.setIdCategoria(idCategoria);
    std::cin.ignore();

    std::cout<<"-Ingrese el nombre del Analisis: ";std::getline(std::cin,nombre);
    analisis.setNombre(nombre);

    std::cout<<"-Ingrese el valor del Analisis: ";std::cin>>valor;
    analisis.setValor(valor);


    if (_managerAnalisis.modificar(analisis, posicion)) {
        std::cout << "Análisis modificado correctamente."<<std::endl;
    } else {
        std::cout << "Error al intentar modificar el análisis."<<std::endl;
    }
}

 std::vector<Analisis> ServicioAnalisis::obtenerAnalisis(){
    return _managerAnalisis.leerTodos();
 }

void ServicioAnalisis::listarAnalisis(const std::vector<Analisis>& lista) {
    if (lista.empty()) {
        std::cout << "No hay analisis registrados.\n";
    } else {
        std::cout << "\n-- LISTADO DE ANALISIS --\n";
        for (int i = 0; i < lista.size(); i++) {
            Analisis analisis = lista[i];
            std::cout << "ID: " << analisis.getId()
                 << " | Nombre: " << analisis.getNombre()
                 << " | Categoria: " << analisis.getIdCategoria()
                 << " | Precio: " << analisis.getValor()
                 << "\n";
        }
    }
}

void ServicioAnalisis::eliminarAnalisis(){
    std::vector<Analisis> lista = _managerAnalisis.leerTodos();

    if (lista.empty()) {
        std::cout << "No hay Analisis para eliminar."<<std::endl;
        return;
    }

    std::cout << "Ingrese el ID del Analisis a eliminar: "<<std::endl;
    int id;
    std::cin>>id;

    bool eliminado = _managerAnalisis.eliminar(id);

    if (eliminado) {
        std::cout << "Analisis dado de baja correctamente."<<std::endl;
    } else {
        std::cout << "Ocurrio un error al eliminar el analisis."<<std::endl;
    }
}


void ServicioAnalisis::buscarPorCategoria(){
    int idCategoria;

     std::vector<Categoria> categorias =  _servicioCategoria.obtenerCategorias();

    if(categorias.empty()){
        std::cout << "La lista de categorias esta vacia.";
        return;
    }
    _servicioCategoria.listarCategorias(categorias);

    std::cout<<"Ingrese el ID de la categoria por la cual desea filtrar: ";std::cin>>idCategoria;std::cout<<std::endl;

    std::vector<Analisis> categoria = _managerAnalisis.buscarPorCategoria(idCategoria);
    std::cout<<"== Estudios Filtrados por Categoria "<<idCategoria<<" =="<<std::endl;

    for(int i = 0 ; i < categoria.size(); i ++){
        std::cout << "Categoria: " << categoria[i].getIdCategoria()
              << " | ID: " << categoria[i].getId()
              << " | Nombre: " << categoria[i].getNombre()
              << " | Valor: $" << categoria[i].getValor()
              << " | Estado: " << (categoria[i].getEstado() ? "Activo" : "Inactivo")
              << std::endl;

    }
    std::cout<<std::endl;
}

void ServicioAnalisis::listarPorNombre(){
    std::string nombre;
    std::cout<<"Ingrese el nombre del Analisis por el que quiere filtrar: ";
    std::cin.ignore();
    std::getline(std::cin,nombre);

    std::vector<Analisis> lista = _managerAnalisis.leerTodos();

    std::vector<Analisis> listaPorNombre = _managerAnalisis.buscarPorNombre(nombre);
    std::cout<<"Filtrado por: "<<nombre<<std::endl;
    for(int i = 0; i<listaPorNombre.size();i++){
        std::cout << "Categoria: " << listaPorNombre[i].getIdCategoria()
              << " | ID: " << listaPorNombre[i].getId()
              << " | Nombre: " << listaPorNombre[i].getNombre()
              << " | Valor: $" << listaPorNombre[i].getValor()
              << " | Estado: " << (listaPorNombre[i].getEstado() ? "Activo" : "Inactivo")
              << std::endl;
    }
}


void ServicioAnalisis::ordenarPorCategoria() {
    std::vector<Analisis> lista = _managerAnalisis.leerTodos();

    if (lista.size() == 0) {
        std::cout << "\nNo hay análisis cargados.\n";
        return;
    }
    for (int i = 0; i < (int)lista.size() - 1; i++) {
        for (int j = i + 1; j < (int)lista.size(); j++) {
            if (lista[i].getIdCategoria() > lista[j].getIdCategoria()) {
                Analisis aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
    // Mostrar la lista ordenada
    std::cout << "\n=== ANALISIS ORDENADOS POR CATEGORIA ===\n";
    for (int i = 0; i < (int)lista.size(); i++) {
        std::cout << "ID Analisis: " << lista[i].getId()
                  << " | ID Categoria: " << lista[i].getIdCategoria()
                  << " | Nombre: " << lista[i].getNombre()
                  << " | Valor: $" << lista[i].getValor()
                  << " | Estado: " << (lista[i].getEstado() ? "Activo" : "Inactivo")
                  << std::endl;
    }
}














