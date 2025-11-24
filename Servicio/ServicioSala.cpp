#include "../ServicioH/ServicioSala.h"
#include <iostream>
#include <limits>
using namespace std;

ServicioSala::ServicioSala() : managerSala("salas_laboratorio.dat") {}

void ServicioSala::limpiarBuffer() const{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//CREAR SALA
void ServicioSala::crearSala() {
    system("cls");
    cout << "\n-- REGISTRAR SALA --\n";

    int id = managerSala.obtenerNuevoId();
    int piso;
    string nombre;

    //NOMBRE
    do {
        cout << "Ingrese el nombre de la sala: ";
        getline(cin, nombre);
        if (nombre.empty()) cout << "El nombre no puede estar vacio.\n";
    } while (nombre.empty());

    //PISO
    while (true) {
        cout << "Ingrese el numero de piso: ";
        if (cin >> piso) {
            limpiarBuffer();
            break;
        } else {
            cout << "Error: El piso debe ser un numero.\n";
            limpiarBuffer();
        }
    }

    //Revisar que hacer con atributo dispoinible, complicado de implementar
    Sala sala(id, nombre, piso, true);

    if(managerSala.guardar(sala)){
        cout << "Sala creada con exito!\n";
    } else {
        cout << "Error al intentar crear la sala.\n";
    }
}

std::vector<Sala> ServicioSala :: obtenerSalas(){
    return managerSala.leerTodos();
}

void ServicioSala :: listarSalas(const std::vector<Sala>& salas){
        if (salas.empty()) {
                cout << "No hay salas registradas.\n";
        } else {
            cout << "\n-- LISTADO DE SALAS --\n";
            for (int i = 0; i < salas.size(); i++) {
                const Sala &sala = salas[i];
                cout  << "ID: " << sala.getId()
                      << " | Nombre: " << sala.getNombre()
                      << " | Piso: " << sala.getPiso()
                      << "\n";
            }
        }
}

//ELIMINAR SALA
void ServicioSala::eliminarSala(){
    std::vector<Sala> lista = obtenerSalas();

    if(lista.empty()){
        cout << "\nNo hay salas para eliminar.\n";
        return;
    }

    listarSalas(lista);

    int id;
    while (true) {
        cout << "\nIngrese el ID de la sala a eliminar (0 para cancelar): ";
        if (cin >> id) {
            limpiarBuffer();
            break;
        } else {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
        }
    }

    if (id == 0) return;

    if(managerSala.eliminar(id)){
        cout << "\n-- SALA ELIMINADA EXITOSAMENTE --\n";
    } else {
        cout << "\n-- NO SE ENCONTRO ESE ID --\n";
    }
}


void ServicioSala::buscarSalaPorNombre(){
    cout << "\n-- BUSCAR SALA POR NOMBRE --\n";

    string nombre;
    cout << "Ingrese nombre a buscar: ";
    getline(cin, nombre);

    Sala sala = managerSala.buscarPorNombre(nombre);

    if(sala.getId() > 0){
        cout << "ID: " << sala.getId()
             << " | Nombre: " << sala.getNombre()
             << " | Piso: " << sala.getPiso()
             << "\n";
    } else {
        cout << "No se encontro ninguna sala con ese nombre.\n";
    }
}

//MODIFICAR SALA
void ServicioSala::modificarSala(){
    std::vector<Sala> lista = obtenerSalas();

    if(lista.empty()){
        cout << "\nNo hay salas para modificar.\n";
        return;
    }

    listarSalas(lista);

    int id;
    int posicion = -1;

    // SELECCION DE ID
    while (true) {
        cout << "\nIngrese el ID de la sala a modificar (0 para salir): ";
        if (cin >> id) {
            if (id == 0) return;
            posicion = managerSala.buscar(id);
            if (posicion != -1) {
                limpiarBuffer();
                break;
            }
            cout << "\nNo se encontro una sala con ese ID.\n";
        } else {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
        }
    }

    Sala sala = managerSala.leer(posicion);
    string nombre;
    int piso;

    cout << "\n-- MODIFICANDO DATOS (Presione ENTER para mantener actual) --\n";

    // NOMBRE
    cout << "Nombre actual [" << sala.getNombre() << "]: ";
    getline(cin, nombre);
    if (nombre.empty()) nombre = sala.getNombre();

    // PISO
    while (true) {
        cout << "Nuevo piso [" << sala.getPiso() << "]: ";
        if (cin >> piso) {
            limpiarBuffer();
            break;
        } else {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
        }
    }

    //Revisar que hacemos con disponible, sugerencia eliminarlo
    sala.setNombre(nombre);
    sala.setPiso(piso);
    sala.setDisponible(true);

    if(managerSala.modificar(sala, posicion)){
        cout << "Sala modificada con exito!\n";
    } else {
        cout << "Error al intentar modificar la sala.\n";
    }
}
