#include "../ServicioH/ServicioSala.h"
#include <iostream>
#include <limits>
using namespace std;

ServicioSala::ServicioSala() : managerSala("salas_laboratorio.dat") {}

void ServicioSala::limpiarBuffer() const{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


void ServicioSala :: crearSala(){
        cout << "\n-- REGISTRAR SALA --\n";

        int id = managerSala.obtenerNuevoId();
        int piso;
        string nombre;

        cout << "Ingrese el nombre de la sala: ";
        limpiarBuffer();
        getline(cin, nombre);

        cout << "Ingrese el numero de piso: ";
        if (!(cin >> piso)) {
            cout << "Error: El piso debe ser un numero.\n";
            limpiarBuffer();
            return;
        }

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
                      << " | Disponible: " << (sala.isDisponible() ? "SI" : "NO")
                      << "\n";
            }
        }
}

void ServicioSala :: eliminarSala(){
        std::vector<Sala> lista = obtenerSalas();

        if(lista.empty()){
            cout << "\nNo hay salas para eliminar.\n";
            return;
        }

        listarSalas(lista);

        cout << "\n-- ESCRIBA EL ID DE LA SALA A ELIMINAR --\n";
        int eliminar;
        while (!(cin >> eliminar)) {
            cout << "Entrada invalida. Por favor, ingresa un ID valido: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        bool eliminado = managerSala.eliminar(eliminar);

        if(eliminado){
            cout << "\n-- ELIMINADO EXITOSAMENTE --\n";
         }else{
             cout << "\n-- OCURRIO UN ERROR AL ELIMINAR LA SALA --\n";
        }
}


void ServicioSala :: buscarSalaPorNombre(){
        cout << "\n-- BUSCAR SALA POR NOMBRE --\n";

        string nombre;
        limpiarBuffer();
        getline(cin, nombre);

        Sala sala = managerSala.buscarPorNombre(nombre);

        if(sala.getId() > 0){
                cout << "ID: " << sala.getId()
                     << " | Nombre: " << sala.getNombre()
                     << " | Piso: " << sala.getPiso()
                     << " | Disponible: " << (sala.isDisponible() ? "SI" : "NO")
                     << "\n";
         }else{
             cout << "No se encontro ninguna sala con ese nombre.\n";
        }
}

void ServicioSala :: modificarSala(){
        std::vector<Sala> lista = obtenerSalas();

        if(lista.empty()){
            cout << "\nNo hay salas para eliminar.\n";
            return;
        }

        listarSalas(lista);

        cout << "\n-- ESCRIBA EL ID DE LA SALA A MODIFICAR --\n";
        int id;
        cin >> id;
        limpiarBuffer();

        string nombre;
        cout << "Ingrese el nombre de la sala: ";
        getline(cin, nombre);


        int piso;
        cout << "Ingrese el numero de piso: ";
        if (!(cin >> piso)) {
            cout << "Error: El piso debe ser un numero.\n";
            limpiarBuffer();
            return; //MODIFICAR Y PONER CICLO PARA QUE NO SALGA DE LA FUNCION
        }
        limpiarBuffer();

        string opciond;
        cout << "Ingrese SI (disponible) o NO (ocupada): ";
        getline(cin, opciond);

        bool disponible = (opciond == "SI" || opciond == "Si" || opciond == "si");

        int posicion = managerSala.buscar(id);
        if (posicion == -1) {
            cout << "\nNo se encontro una sala con ese ID.\n";
            return;
        }

        Sala sala = managerSala.leer(posicion);

        sala.setNombre(nombre);
        sala.setPiso(piso);
        sala.setDisponible(disponible);

        if(managerSala.modificar(sala, posicion)){
            cout << "Sala modificada con exito!\n";
        } else {
            cout << "Error al intentar modificar la sala.\n";
        }
}
