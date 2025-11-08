#include "../ServicioH/ServicioObraSocial.h"
#include <iostream>
#include <limits>
using namespace std;

ServicioObraSocial::ServicioObraSocial() : managerObraSocial("obras_sociales.dat") {}

void ServicioObraSocial::limpiarBuffer() const {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void ServicioObraSocial::crearObraSocial() {
    cout << "\n-- REGISTRAR OBRA SOCIAL --\n";

    int id = managerObraSocial.obtenerNuevoId();
    string nombre;
    float descuento;

    cout << "Ingrese el nombre: ";
    limpiarBuffer();
    getline(cin, nombre);

    cout << "Ingrese el porcentaje de descuento: ";
    if (!(cin >> descuento)) {
        cout << "Error: debe ingresar un número válido.\n";
        limpiarBuffer();
        return; //MODIFICAR PARA BUCLE
    }

    ObraSocial obraSocial(id, nombre, descuento);

    if (managerObraSocial.guardar(obraSocial)) {
        cout << "Obra social registrada con exito!\n";
    } else {
        cout << "Error al intentar guardar la obra social.\n";
    }
}

std::vector <ObraSocial> ServicioObraSocial::listarObrasSociales() {
    cout << "\n-- LISTADO DE OBRAS SOCIALES --\n";

    vector<ObraSocial> obrasSociales = managerObraSocial.leerTodos();

    if (obrasSociales.empty()) {
        cout << "No hay obras sociales registradas.\n";
    } else {
        for (int i = 0; i < obrasSociales.size(); i++) {
            ObraSocial obraSocial = obrasSociales[i];
            cout << "ID: " << obraSocial.getId()
                 << " | Nombre: " << obraSocial.getNombre()
                 << " | Descuento: " << obraSocial.getDescuento()
                 << "\n";
        }
    }

    return obrasSociales;
}

void ServicioObraSocial::eliminarObraSocial() {
    std::vector<ObraSocial> lista = listarObrasSociales();

    if(lista.empty()){
        cout << "\nNo hay obras sociales para eliminar.\n";
        return;
    }

    cout << "\nIngrese el ID a eliminar: ";
    int id;
    cin >> id;

    bool eliminado = managerObraSocial.eliminar(id);

    if(eliminado){
        cout << "\n-- ELIMINADO EXITOSAMENTE --\n";
     }else{
         cout << "\n-- OCURRIO UN ERROR AL ELIMINAR LA OBRA SOCIAL --\n";
    }
}

void ServicioObraSocial::modificarObraSocial() {
    std::vector <ObraSocial> lista = listarObrasSociales();

    if(lista.empty()){
        cout << "\nNo hay obras sociales para modificar.\n";
        return;
    }

    cout << "\nIngrese el ID a modificar: ";
    int id;
    cin >> id;
    limpiarBuffer();

    string nombre;
    float descuento;

    cout << "Nuevo nombre: ";
    getline(cin, nombre);

    cout << "Nuevo descuento (%): ";
    cin >> descuento;

    int posicion = managerObraSocial.buscar(id);
    if (posicion == -1) {
        cout << "No se encontro una obra social con ese ID.\n";
        return;
    }

    ObraSocial obraSocial = managerObraSocial.leer(posicion);
    obraSocial.setNombre(nombre);
    obraSocial.setDescuento(descuento);

    if (managerObraSocial.modificar(obraSocial, posicion)) {
        cout << "Obra social modificada con exito!\n";
    } else {
        cout << "Error al intentar modificar la obra social.\n";
    }
}

void ServicioObraSocial::buscarObraSocialPorNombre() {
    cout << "\nIngrese el nombre a buscar: ";

    string nombre;
    limpiarBuffer();
    getline(cin, nombre);

    ObraSocial obraSocial = managerObraSocial.buscarPorNombre(nombre);
    if (obraSocial.getId() > 0) {
        cout << "ID: " << obraSocial.getId()
             << " | Nombre: " << obraSocial.getNombre()
             << " | Descuento: " << obraSocial.getDescuento() << "%\n";
    } else {
        cout << "No se encontro la obra social.\n";
    }
}


