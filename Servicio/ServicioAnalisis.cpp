#include "../ServicioH/ServicioAnalisis.h"
#include "../ManagerH/ManagerAnalisis.h"
#include "../ServicioH/ServicioCategoria.h"
#include <string>
#include <iostream>
#include <limits>

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
        std::cout << "Ingrese el ID de la categoria (0 para cancelar): ";
        std::cin >> idCategoria;

        if (idCategoria == 0) {
            std::cout << "Operacion cancelada."<<std::endl;
            return;
        }

        for (int i = 0; i < (int)categorias.size(); i++) {
            if (categorias[i].getId() == idCategoria) {
                categoriaValida = true;
                break;
            }
        }

        if (!categoriaValida) {
            std::cout << "ID invalido. Intente nuevamente."<<std::endl;
        }
    }

    std::cin.clear();
    std::cin.ignore();

    do{
        std::cout<<"Ingrese el nombre del analisis: "<<std::endl;
        std::getline(std::cin,nombre);
        if(nombre.empty() || nombre.find_first_not_of(' ') == std::string::npos){
            std::cout<<"El nombre no puede ser vacio. Intentelo nuevamente."<<std::endl;
        }
    }while(nombre.empty() || nombre.find_first_not_of(' ') == std::string::npos);

    do{
        std::cout<<"Ingrese el valor del analisis: $";
        std::cin>>valor;

        if(std::cin.fail() || valor<=0){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"El valor ingresado no es correcto. No puede haber letras, negativos o 0."<<std::endl;
            valor = -1;
        }
    }while(valor<=0);

    std::cout << "Valor aceptado $" << valor << std::endl;
    Analisis analisis(id, nombre, idCategoria, valor); //CREAMOS ANALISIS

    if(_managerAnalisis.guardar(analisis)){
         std::cout << "Analisis creado con exito!"<<std::endl;
    }  else{
            std::cout << "Error al intentar crear el analisis."<<std::endl;
        }
}

//MODIFICAR ANALISIS
void ServicioAnalisis::modificarAnalisis() {
    int posicion, id, idCategoria;
    float valor;
    std::string nombre;
    std::vector<Analisis> lista = _managerAnalisis.leerTodos();

    if (lista.empty()) {
        std::cout << "No hay analisis para modificar." << std::endl;
        return;
    }

    listarAnalisis(lista);

    std::cout << std::endl << "Ingrese el ID correspondiente al analisis que desea modificar: ";

    while (!(std::cin >> id)) {
        std::cout << "Error: debe ingresar un número entero."<<std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ingrese el ID: ";
    }

    posicion = _managerAnalisis.buscar(id);
    if (posicion == -1) {
        std::cout << "No se encontro un analisis activo con ese ID."<<std::endl;
        return;
    }

    Analisis analisis = _managerAnalisis.leer(posicion);
    std::vector<Categoria> categorias = _servicioCategoria.obtenerCategorias();

    if (categorias.empty()) {
        std::cout << "La lista de categorias esta vacia. No se puede modificar el analisis."<<std::endl;
        return;
    }
    _servicioCategoria.listarCategorias(categorias);

    bool categoriaValida = false;
    while (!categoriaValida) {
        std::cout << "Elija el ID de la categoría que corresponde al analisis: ";
        if (!(std::cin >> idCategoria)) {
            std::cout << "Error: debe ingresar un numero entero."<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        for (int i = 0; i < (int)categorias.size(); i++) {
            if (categorias[i].getId() == idCategoria) {
                categoriaValida = true;
                break;
            }
        }

        if (!categoriaValida) {
            std::cout << "ID de categoria invalido. Intente nuevamente." << std::endl;
        }
    }

    analisis.setIdCategoria(idCategoria);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    do {
        std::cout << "- Ingrese el nuevo nombre del analisis: ";
        std::getline(std::cin, nombre);

        if (nombre.empty() || nombre.find_first_not_of(' ') == std::string::npos) {
            std::cout << "El nombre no puede estar vacio ni ser solo espacios. Intente nuevamente." << std::endl;
        }
    } while (nombre.empty() || nombre.find_first_not_of(' ') == std::string::npos);

    analisis.setNombre(nombre);

    bool valorValido = false;
    while (!valorValido) {
        std::cout << "- Ingrese el nuevo valor del analisis: ";
        if (!(std::cin >> valor)) {
            std::cout << "Error: debe ingresar un numero." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (valor <= 0) {
            std::cout << "El valor debe ser mayor a 0." << std::endl;
            continue;
        }
        valorValido = true;
    }

    analisis.setValor(valor);

    if (_managerAnalisis.modificar(analisis, posicion)) {
        std::cout << "Analisis modificado correctamente.\n";
    } else {
        std::cout << "Error al intentar modificar el analisis.\n";
    }
}

//OBTENER ANÁLISIS
std::vector<Analisis> ServicioAnalisis::obtenerAnalisis(){
    return _managerAnalisis.leerTodos();
}

//LISTAR ANÁLISIS
void ServicioAnalisis::listarAnalisis(const std::vector<Analisis>& lista) {
    _managerAnalisis.listarAnalisis(lista);
}

//ELIMINAR ANALISIS
void ServicioAnalisis::eliminarAnalisis(){
    std::vector<Analisis> lista = _managerAnalisis.leerTodos();

    if (lista.empty()) {
        std::cout << "No hay analisis para eliminar." << std::endl;
        return;
    }
    listarAnalisis(lista);

    int id;
    std::cout << std::endl << "Ingrese el ID del analisis a eliminar: ";

    // Validar que se ingrese un número
    while (!(std::cin >> id)) {
        std::cout << "Error: debe ingresar un numero entero."<< std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ingrese el ID del analisis a eliminar: ";
    }

    // Verificar que el ID exista (y esté activo, porque buscar mira getEstado())
    int posicion = _managerAnalisis.buscar(id);
    if (posicion == -1) {
        std::cout << "No se encontro un analisis activo con ese ID." << std::endl;
        return;
    }

    char confirma;
    std::cout << "Esta seguro que desea dar de baja el analisis con ID? (S/N): " << std::endl;
    std::cin >> confirma;

    if (confirma == 'S' && confirma == 's') {

    bool eliminado = _managerAnalisis.eliminar(id);

    if (eliminado) {
        std::cout << "Analisis dado de baja correctamente." << std::endl;
    } else {
        std::cout << "Ocurrio un error al eliminar el analisis." << std::endl;
        }
    }

    else{
        std::cout << "Operacion cancelada. No se elimino el analisis." << std::endl;
        return;
    }
}

//BUSCAR x CATEGORÍA
void ServicioAnalisis::buscarPorCategoria(){
    int idCategoria;
    bool encontro = false;
    std::vector<Categoria> categorias =  _servicioCategoria.obtenerCategorias();


    if(categorias.empty()){
        std::cout << "La lista de categorias esta vacia.";
        return;
    }
    _servicioCategoria.listarCategorias(categorias);
    std::cout<<"Ingrese el ID de la categoria por la cual desea filtrar: ";
    std::cin>>idCategoria;std::cout<<std::endl;
    std::vector<Analisis> categoria = _managerAnalisis.buscarPorCategoria(idCategoria,encontro);
    while(!encontro){
        std::cout<<"No se encontro ningun estudio categorizado con ese ID. Intentelo nuevamente."<<std::endl;
        std::cout<<"Ingrese el ID de la categoria por la cual desea filtrar: ";
        std::cin>>idCategoria;std::cout<<std::endl;
        categoria = _managerAnalisis.buscarPorCategoria(idCategoria,encontro);

    };
    std::cout<<"== Estudios Filtrados por Categoria "<<_servicioCategoria.buscarPorId(idCategoria)<<" =="<<std::endl;
    listarAnalisis(categoria);
}

//LISTAR x NOMBRE
void ServicioAnalisis::listarPorNombre(){
    std::string nombre;
    std::vector<Analisis> lista = _managerAnalisis.leerTodos();
     _managerAnalisis.listarAnalisis(lista);
    std::cout<<"Ingrese el nombre del Analisis por el que quiere filtrar: ";
    std::cin.ignore();
    std::getline(std::cin,nombre);
    std::vector<Analisis> listaPorNombre = _managerAnalisis.buscarPorNombre(nombre);
    while(listaPorNombre.empty()){
        std::cout<<"--No se encontro ese nombre de Analisis. Intentelo nuevamente."<<std::endl;
        std::cout<<"Ingrese el nombre del Analisis por el que quiere filtrar: ";
        std::getline(std::cin,nombre);
        listaPorNombre = _managerAnalisis.buscarPorNombre(nombre);
    }
    std::cout<<"Filtrado por: "<<nombre<<std::endl;
    _managerAnalisis.listarAnalisis(listaPorNombre);
}

//ORDENAR x CATEGORIA
void ServicioAnalisis::ordenarPorCategoria() {
    std::vector<Analisis> lista = _managerAnalisis.leerTodos();

    if (lista.size() == 0) {
        std::cout << std::endl << "No hay analisis cargados." << std::endl;
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
    std::cout << std::endl << "=== ANALISIS ORDENADOS POR CATEGORIA ===" << std::endl;
    for (int i = 0; i < (int)lista.size(); i++) {
        std::cout << "ID Analisis: " << lista[i].getId()
                  << " | ID Categoria: " <<lista[i].getIdCategoria()
                  << " | Nombre Categoria: " << _servicioCategoria.buscarPorId(lista[i].getIdCategoria())
                  << " | Nombre: " << lista[i].getNombre()
                  << " | Valor: $" << lista[i].getValor()
                  << std::endl;
    }
}
