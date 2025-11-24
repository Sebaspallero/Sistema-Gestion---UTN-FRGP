#include "../ServicioH/ServicioPaciente.h"
#include <iostream>
#include <limits>
using namespace std;

//CONSTRUCTOR
ServicioPaciente::ServicioPaciente() : managerPaciente("pacientes.dat"), servicioObraSocial() {}

//METODOS AUXILIARES
void ServicioPaciente::limpiarBuffer() const {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//COMPROBAR DNI UNICO
bool ServicioPaciente::existeDNI(int dni) {
    vector<Paciente> pacientes = managerPaciente.leerTodos();
    for (int i = 0; i < (int)pacientes.size(); i++) {
        if (pacientes[i].getDNI() == dni) {
            return true;
        }
    }
    return false;
}

//MOSTRAR NOMBRE OBRA SOCIAL EN VEZ DE ID EN LA LISTA
std::string ServicioPaciente::nombreObraPorId(int id, const vector<ObraSocial>& lista) {
    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].getId() == id) {
            return lista[i].getNombre();
        }
    }
    return "Desconocido";
}

//CREAR PACIENTE
void ServicioPaciente::crearPaciente() {
    cout << "\n-- REGISTRAR PACIENTE --\n";

    //PRIMERO VALIDAMOS QUE HAYA OBRAS SOCIALES
    std::vector<ObraSocial> lista = servicioObraSocial.obtenerObrasSociales();
    if (lista.empty()) {
        cout << "\nNo hay obras sociales registradas. No se puede registrar paciente.\n";
        return;
    }

    int id = managerPaciente.obtenerNuevoId();
    string nombre, apellido, email, telefono;
    int dia, mes, anio, dni, codigoObraSocial;

    // NOMBRE
    do {
        cout << "Ingrese nombre: ";
        getline(cin, nombre);
        if (nombre.empty() || nombre.find_first_not_of(' ')==string::npos){
            cout << "El nombre no puede estar vacio." << endl;
        }
    } while (nombre.empty() || nombre.find_first_not_of(' ')==string::npos);

    //APELLIDO
    do {
        cout << "Ingrese apellido: ";
        getline(cin, apellido);
        if (apellido.empty() || apellido.find_first_not_of(' ')==string::npos){
             cout << "El apellido no puede estar vacio." << endl;
        }
    } while (apellido.empty() || apellido.find_first_not_of(' ')==string::npos);

    //FECHA DE NACIMIENTO
    while (true) {
        cout << "Ingrese dia de nacimiento (1-31): ";
        if (cin >> dia) {
            if (dia >= 1 && dia <= 31) break;
            else cout << "Dia fuera de rango." << endl;
        } else {
            cout << "Error: Debe ingresar un numero." << endl;
            limpiarBuffer();
        }
    }

    while (true) {
        cout << "Ingrese mes de nacimiento (1-12): ";
        if (cin >> mes) {
            if (mes >= 1 && mes <= 12) break;
            else cout << "Mes fuera de rango." << endl;
        } else {
            cout << "Error: Debe ingresar un numero." << endl;
            limpiarBuffer();
        }
    }

    while (true) {
        cout << "Ingrese anio de nacimiento (1900-2024): ";
        if (cin >> anio) {
            if (anio >= 1900 && anio <= 2025) break;
            else cout << "Anio invalido.\n";
        } else {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
        }
    }

    limpiarBuffer();

    //DNI
    while (true) {
        cout << "Ingrese DNI: ";
        if (cin >> dni) {
            if (dni > 0) {
                if (!existeDNI(dni)) {
                        limpiarBuffer();
                    break;
                } else {
                    cout << "Error: Ya existe un paciente con ese DNI.\n";
                }
            } else {
                cout << "El DNI debe ser positivo.\n";
            }
        } else {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
        }
    }

    //EMAIL
    do {
        cout << "Ingrese email: ";
        getline(cin, email);
        if (email.empty()) cout << "El email no puede estar vacio." << endl;
    } while (email.empty());

    //TELEFONO
    do {
        cout << "Ingrese telefono: ";
        getline(cin, telefono);
        if (telefono.empty()) cout << "El telefono no puede estar vacio.\n";
    } while (telefono.empty());

    // SELECCION DE OBRA SOCIAL
    servicioObraSocial.listarObrasSociales(lista);
    while (true) {
        cout << "Ingrese el codigo de la obra social: ";
        if (cin >> codigoObraSocial) {
            bool encontrada = false;
            for (int i = 0; i < (int)lista.size(); i++) {
                if (lista[i].getId() == codigoObraSocial) {
                    encontrada = true;
                    break;
                }
            }
            if (encontrada) break;
            else cout << "ID de obra social no encontrado." << endl;
        } else {
            cout << "Error: Debe ingresar un numero." << endl;
            limpiarBuffer();
        }
    }

    Fecha fechaNacimiento(dia, mes, anio);
    Paciente paciente(id, nombre, apellido, fechaNacimiento, dni, email, telefono, codigoObraSocial);

    if (managerPaciente.guardar(paciente)) {
        cout << "Paciente creado con exito!" << endl;
    } else {
        cout << "Error al intentar crear el paciente." << endl;
    }
}

//OBTENER PACIENTES
std::vector<Paciente> ServicioPaciente :: obtenerPacientes(){
    return managerPaciente.leerTodos();
}

//LISTAR PACIENTES
void ServicioPaciente::listarPacientes(const std::vector<Paciente>& pacientes) {
    if (pacientes.empty()) {
        cout << "No hay pacientes registrados.\n";
    } else {
        std::vector<ObraSocial> lista = servicioObraSocial.obtenerObrasSociales();
        cout << "\n-- LISTADO DE PACIENTES --\n";
        for (int i = 0; i < (int)pacientes.size(); i++) {
            Paciente paciente = pacientes[i];
            cout << "ID: " << paciente.getId()
                 << " | Nombre: " << paciente.getNombre()
                 << " | Apellido: " << paciente.getApellido()
                 << " | DNI: " << paciente.getDNI()
                 << " | Obra Social: " << nombreObraPorId(paciente.getCodigoObraSocial(), lista)
                 << "\n";
        }
    }
}

//ELIMINAR PACIENTE
void ServicioPaciente::eliminarPaciente() {
    std::vector<Paciente> lista = obtenerPacientes();
    if (lista.empty()) {
        cout << "\nNo hay pacientes para eliminar.\n";
        return;
    }
    listarPacientes(lista);

    int id;
    while (true) {
        cout << "\nIngrese el ID a eliminar (0 para cancelar): ";
        if (cin >> id) {
            break;
        } else {
            cout << "Error: Ingrese un numero.\n";
            limpiarBuffer();
        }
    }
    if (id == 0) return;

    if (managerPaciente.eliminar(id)) {
        cout << "\n-- ELIMINADO EXITOSAMENTE --\n";
    } else {
        cout << "\n-- NO SE ENCONTRO ESE ID --\n";
    }
}

//MODIFICAR PACIENTE
void ServicioPaciente::modificarPaciente() {
    std::vector<Paciente> lista = obtenerPacientes();

    if (lista.empty()) {
        cout << "\nNo hay pacientes para modificar.\n";
        return;
    }

    listarPacientes(lista);

    int id;
    int posicion = -1;

    //SELECCIONAR ID DEL PACIENTE A MOD
    while (true) {
        cout << "\nIngrese el ID a modificar (0 para salir): ";
        if (cin >> id) {
            if (id == 0) return;

            posicion = managerPaciente.buscar(id);
            if (posicion != -1) {
                break; // ID Encontrado
            } else {
                cout << "No se encontro un paciente con ese ID.\n";
            }
        } else {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
        }
    }
    limpiarBuffer();

    Paciente paciente = managerPaciente.leer(posicion);

    string nombre, apellido, email, telefono;
    int dia, mes, anio, dni, codigoObraSocial;

    cout << "\n-- MODIFICANDO DATOS (Presione ENTER en textos para mantener el actual) --\n";

    //NOMBRE
    cout << "Nombre actual [" << paciente.getNombre() << "]: ";
    getline(cin, nombre);
    if (nombre.empty()) {
        nombre = paciente.getNombre();
    }

    //APELLIDO
    cout << "Apellido actual [" << paciente.getApellido() << "]: ";
    getline(cin, apellido);
    if (apellido.empty()) {
        apellido = paciente.getApellido();
    }

    //FECHA
    cout << "\n-- Reingrese la fecha de nacimiento --\n";

    //DIA
    while (true) {
        cout << "Nuevo dia (" << paciente.getFechaNacimiento().getDia() << "): ";
        if (cin >> dia) {
            if (dia >= 1 && dia <= 31) break;
            else cout << "Dia fuera de rango.\n";
        } else {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
        }
    }

    //MES
    while (true) {
        cout << "Nuevo mes (" << paciente.getFechaNacimiento().getMes() << "): ";
        if (cin >> mes) {
            if (mes >= 1 && mes <= 12) break;
            else cout << "Mes fuera de rango.\n";
        } else {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
        }
    }

    //ANIO
    while (true) {
        cout << "Nuevo anio (" << paciente.getFechaNacimiento().getAnio() << "): ";
        if (cin >> anio) {
            if (anio >= 1900 && anio <= 2025) break;
            else cout << "Anio invalido.\n";
        } else {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
        }
    }

    //DNI -> HAY QUE VALIDAR QUE SEA UNICO PERO QUE SE PUEDA INGRESAR EL PROPIO
    while (true) {
        cout << "Nuevo DNI [" << paciente.getDNI() << "]: ";
        if (cin >> dni) {
            if (dni > 0) {
                // Se ingresa el mismo DNI porque no hubo cambios, pasa
                if (dni == paciente.getDNI()) {
                    break;
                }
                // Si es distinto, verificamos que no lo tenga otro paciente
                else if (!existeDNI(dni)) {
                    break;
                } else {
                    cout << "Error: Ese DNI ya pertenece a otro paciente.\n";
                }
            } else {
                cout << "El DNI debe ser positivo.\n";
            }
        } else {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
        }
    }
    limpiarBuffer();

    //EMAIL
    cout << "Nuevo email [" << paciente.getEmail() << "]: ";
    getline(cin, email);
    if (email.empty()) email = paciente.getEmail();

    //TELEFONO
    cout << "Nuevo telefono [" << paciente.getTelefono() << "]: ";
    getline(cin, telefono);
    if (telefono.empty()) telefono = paciente.getTelefono();

    //OBRA SOCIAL
    std::vector<ObraSocial> listaObras = servicioObraSocial.obtenerObrasSociales();
    if(listaObras.empty()){
         cout << "No hay obras sociales disponibles. Se mantiene la actual.\n";
         codigoObraSocial = paciente.getCodigoObraSocial();
    } else {
        servicioObraSocial.listarObrasSociales(listaObras);
        while (true) {
            cout << "Nuevo codigo de obra social [" << paciente.getCodigoObraSocial() << "]: ";
            if (cin >> codigoObraSocial) {
                bool encontrada = false;
                for (int i = 0; i < (int)lista.size(); i++) {
                    if (lista[i].getId() == codigoObraSocial) {
                        encontrada = true;
                        break;
                    }
                }
                if (encontrada) break;
                else cout << "ID de obra social no encontrado.\n";
            } else {
                cout << "Error: Debe ingresar un numero.\n";
                limpiarBuffer();
            }
        }
    }

    // 8. GUARDADO
    Fecha fechaNacimiento(dia, mes, anio);

    paciente.setNombre(nombre);
    paciente.setApellido(apellido);
    paciente.setFechaNacimiento(fechaNacimiento);
    paciente.setDNI(dni);
    paciente.setEmail(email);
    paciente.setTelefono(telefono);
    paciente.setCodigoObraSocial(codigoObraSocial);

    if(managerPaciente.modificar(paciente, posicion)){
        cout << "Paciente modificado con exito!\n";
    } else {
        cout << "Error al intentar modificar el paciente.\n";
    }
}

//BUSCAR PACIENTE POR DNI
void ServicioPaciente::buscarPacientePorDNI() {
    int dni;

    while(true){
        cout << "\nIngrese el DNI a buscar: ";
        if(cin >> dni){
            limpiarBuffer();
            break;
        }
        else {
            cout << "Error: numero invalido.\n";
            limpiarBuffer();
        }
    }

    Paciente paciente = managerPaciente.buscarPorDNI(dni);

    if (paciente.getId() > 0) {
        cout << "ID: " << paciente.getId()
             << " | Nombre: " << paciente.getNombre()
             << " | Apellido: " << paciente.getApellido()
             << " | DNI: " << paciente.getDNI()
             << "\n";
    } else {
        cout << "No se encontro el paciente.\n";
    }
}

//BUSCAR PACIENTE POR APELLIDO
void ServicioPaciente::buscarPacientePorApellido() {
    string apellido;

    while(true){
        cout << "\nIngrese el apellido a buscar: ";

        getline(cin, apellido);

        if (apellido.empty()) {
            cout << "El apellido no puede estar vacio. Intente nuevamente.\n";
        } else {
            break;
        }
    }

    vector<Paciente> resultados = managerPaciente.buscarPorApellido(apellido);

    if (resultados.empty()) {
        cout << "No se encontraron pacientes con ese apellido.\n";
    } else {
        for (int i = 0; i < (int)resultados.size(); i++) {
            Paciente paciente = resultados[i];
            cout << "ID: " << paciente.getId()
                 << " | Nombre: " << paciente.getNombre()
                 << " | Apellido: " << paciente.getApellido()
                 << " | DNI: " << paciente.getDNI()
                 << " | Obra Social: " << paciente.getCodigoObraSocial()
                 << "\n";
        }
    }
}

//ORDENAR PACIENTES POR APELLIDO
void ServicioPaciente::ordenarPacientesPorApellido() {
    std::vector<Paciente> listaOrdenada = managerPaciente.ordenarPorApellido();

    if(listaOrdenada.empty()){
        cout << "No se encontraron pacientes registrados.\n";
    }else{
        std::vector<ObraSocial> lista = servicioObraSocial.obtenerObrasSociales();
        cout << "\nPacientes ordenados por apellido:\n";
        for (int i = 0; i < (int)listaOrdenada.size(); i++) {
            cout << "Apellido: " << listaOrdenada[i].getApellido() << endl;
            cout << "Nombre: " << listaOrdenada[i].getNombre() << endl;
            cout << "DNI: " << listaOrdenada[i].getDNI() << endl;
            cout << "Obra Social: " << nombreObraPorId(listaOrdenada[i].getCodigoObraSocial(), lista)  << endl;
            cout << "-------------------------" << endl;
        }
    }
}
