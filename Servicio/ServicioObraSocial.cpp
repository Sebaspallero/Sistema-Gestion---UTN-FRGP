#include "../ServicioH/ServicioObraSocial.h"
#include "../ServicioH/ServiciosUtilidades.h"
#include <iostream>
#include <limits>
using namespace std;

ServicioObraSocial::ServicioObraSocial() : managerObraSocial("obras_sociales.dat") {}

void ServicioObraSocial::limpiarBuffer() const {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//CREAR OBRA SOCIAL
void ServicioObraSocial::crearObraSocial() {
    cout << "\n-- REGISTRAR OBRA SOCIAL --\n";

    int id = managerObraSocial.obtenerNuevoId();
    string nombre;
    float descuento;

    vector<ObraSocial> lista =managerObraSocial.leerTodos();

    bool nombreValido = false;
    do{
    nombre = pedirString("Ingrese el nombre: ");

        if(nombre.empty() || nombre.find_first_not_of(' ') == string::npos){
            cout<< "El nombre no puede estar vacio ni ser solo espacios. " << endl;
            continue;
        }

        bool duplicado = false;
        for (int i = 0; i < (int) lista.size(); i++){
            if (lista[i].getNombre() == nombre) {
            duplicado = true;
            break;
        }
    }

    if(duplicado){
        cout << "Ya existe una obra social con ese nombre. Intente con otro. " << endl;
        continue;
    }

    nombreValido = true;
    }while(!nombreValido);

    bool descuentoValido = false;
    while(!descuentoValido){
        cout << "Ingrese el porcentaje de descuento (0-100): ";
        if (!(cin >> descuento)) {
            cout << "Error: debe ingresar un numero valido." << endl;
            limpiarBuffer();
            continue;
        }
        if(descuento < 0 || descuento > 100){
            cout << "El descuento debe ser mayor a 0 y menor o igual a 100. " << endl;
            continue;
        }
        descuentoValido = true;
        }

    ObraSocial obraSocial(id, nombre, descuento);

    if (managerObraSocial.guardar(obraSocial)) {
        cout << "Obra social registrada con exito!" << endl;
    } else {
        cout << "Error al intentar guardar la obra social." << endl;
    }
}

//OBTENER OBRAS SOCIALES
std::vector<ObraSocial> ServicioObraSocial :: obtenerObrasSociales(){
    return managerObraSocial.leerTodos();
}

//LISTAR OBRAS SOCIALES
void ServicioObraSocial::listarObrasSociales(const std::vector<ObraSocial>& obrasSociales) {
    if (obrasSociales.empty()) {
        cout << "No hay obras sociales registradas." << endl;
    } else {
        cout << "\n-- LISTADO DE OBRAS SOCIALES --\n";
        for (int i = 0; i < obrasSociales.size(); i++) {
            ObraSocial obraSocial = obrasSociales[i];
            cout << "ID: " << obraSocial.getId()
                 << " | Nombre: " << obraSocial.getNombre()
                 << " | Descuento: " << obraSocial.getDescuento() << "% "
                 << endl;
        }
    }
}

//ELIMINAR OBRA SOCIAL
void ServicioObraSocial::eliminarObraSocial() {
    std::vector<ObraSocial> lista = obtenerObrasSociales();

    if(lista.empty()){
        cout << "No hay obras sociales para eliminar. " << endl;
        return;
    }

    listarObrasSociales(lista);

    int id = pedirEntero("\nIngrese el ID a eliminar (0 para cancelar): ");
    if (id == 0) {
        std::cout << "Operacion cancelada." << endl;
        return;
    }

    int posicion = managerObraSocial.buscar(id);
    if (posicion == -1){
        cout << "No se encontro una obra social con ese ID. " << endl;
        return;
    }

    cout << "Esta seguro que desea eliminar esta obra social? (S/N): ";
    char confirma;
    cin >> confirma;
    if (confirma == 'N' || confirma == 'n'){
        cout << "Operacion cancelada." << endl;
        return;
    }

    bool eliminado = managerObraSocial.eliminar(id);

    if(eliminado){
        cout << "\n-- ELIMINADO EXITOSAMENTE --\n";
     }else{
         cout << "\n-- OCURRIO UN ERROR AL ELIMINAR LA OBRA SOCIAL --\n";
    }
}

//MODIFICAR OBRA SOCIAL
void ServicioObraSocial::modificarObraSocial() {
    std::vector <ObraSocial> lista = obtenerObrasSociales();

    if(lista.empty()){
        cout << "\nNo hay obras sociales para modificar.\n";
        return;
    }

    listarObrasSociales(lista);

    int id = pedirEntero("\nIngrese el ID a modificar (0 para cancelar): ");
    if (id == 0) {
    std::cout << "Operacion cancelada.\n";
    return;
    }

    int posicion = managerObraSocial.buscar(id);
    if (posicion == -1) {
    cout << "No se encontro una obra social con ese ID.\n";
    return;
    }

    ObraSocial obraSocial = managerObraSocial.leer(posicion);

    string nombre;
    bool nombreValido = false;
    do{
       cout << "Nuevo nombre: ";
       limpiarBuffer();
       getline(cin, nombre);

        if (nombre.empty() || nombre.find_first_not_of(' ') == string::npos){
            cout << "El nombre no puede estar vacio ni ser solo espacios. " << endl;
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
        cout << "Ya existe una obra social con ese nombre. Intente con otro. " << endl;
        continue;
    }

    nombreValido = true;
    }while(!nombreValido);

    float descuento;
    bool descuentoValido = false;
    while(!descuentoValido){
        cout << "Nuevo descuento (%): ";
        if (!(cin >> descuento)){
            cout << "Error: Debe ingresar un numero valido. " << endl;
            limpiarBuffer();
            continue;
        }
        if (descuento < 0 || descuento > 100){
            cout << "El descuento debe ser mayor a 0 y menor o igual a 100. " << endl;
            continue;
        }
        descuentoValido = true;
    }

    obraSocial.setNombre(nombre);
    obraSocial.setDescuento(descuento);

    if (managerObraSocial.modificar(obraSocial, posicion)) {
        cout << "Obra social modificada con exito!\n";
    } else {
        cout << "Error al intentar modificar la obra social.\n";
    }
}

//BUSCAR OBRA SOCIAL x NOMBRE
void ServicioObraSocial::buscarObraSocialPorNombre() {
    cout << "\nIngrese el nombre a buscar: ";

    string nombre;
    getline(cin, nombre);

    if (nombre.empty() || nombre.find_first_not_of(" \t\n\r") == string::npos) {
        cout << "Debe ingresar un nombre valido.\n";
        return;
    }

    ObraSocial obraSocial = managerObraSocial.buscarPorNombre(nombre);
    if (obraSocial.getId() > 0) {
        cout << "ID: " << obraSocial.getId()
             << " | Nombre: " << obraSocial.getNombre()
             << " | Descuento: " << obraSocial.getDescuento() << "%\n";
    } else {
        cout << "No se encontro la obra social.\n";
    }
}
