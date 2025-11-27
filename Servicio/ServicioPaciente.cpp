#include "../ServicioH/ServicioPaciente.h"
#include "../ServicioH/ServiciosUtilidades.h"
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
    system("cls");
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
        cout << "Ingrese nombre: 0 para finalizar"<<endl;
        getline(cin, nombre);
        if(nombre == "0"){
            return;
        }
        if (nombre.empty() || nombre.find_first_not_of(' ')==string::npos){
            cout << "El nombre no puede estar vacio." << endl;
        }
    } while (nombre.empty() || nombre.find_first_not_of(' ')==string::npos);

    //APELLIDO
    do {
        cout << "Ingrese apellido: 0 para finalizar"<<endl;
        getline(cin, apellido);
        if(apellido == "0"){
            return;
        }
        if (apellido.empty() || apellido.find_first_not_of(' ')==string::npos){
             cout << "El apellido no puede estar vacio." << endl;
        }
    } while (apellido.empty() || apellido.find_first_not_of(' ')==string::npos);

    //FECHA DE NACIMIENTO
    Fecha fechaNacimiento = pedirFecha("Ingrese la fecha de nacimiento:", 1900, 2025);
    if (fechaNacimiento.getAnio() == 0) return;

    limpiarBuffer();

    //DNI
    while (true) {
        cout << "Ingrese DNI: 0 para finalizar"<<endl;

        if (cin >> dni) {
            if(dni==0){
                    return;
                }
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
            if(dni == 0){
                return;
            }
        } else {
            cout << "Error: Debe ingresar un numero.\n";
            limpiarBuffer();
        }
    }

    //EMAIL
    do {
        cout << "Ingrese email: 0 para finalizar"<<endl;
        getline(cin, email);
        if(email == "0"){
            return;
        }
        if (email.empty()) cout << "El email no puede estar vacio." << endl;
    } while (email.empty()|| email == "0");

    //TELEFONO
    do {
        cout << "Ingrese telefono: 0 para finalizar"<<endl;

        getline(cin, telefono);
        if(telefono == "0"){
            return;
        }
        if (telefono.empty()) cout << "El telefono no puede estar vacio.\n";
    } while (telefono.empty()||telefono=="0");

    // SELECCION DE OBRA SOCIAL
    servicioObraSocial.listarObrasSociales(lista);
    while (true) {
        cout << "Ingrese el codigo de la obra social: 0 para finalizar"<<endl;
        if (cin >> codigoObraSocial) {
            bool encontrada = false;
            if(codigoObraSocial==0){
                return;
            }
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
    system("cls");
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
    system("cls");
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

    int posicion = managerPaciente.buscar(id);

    if(posicion == -1){
        cout << "\n-- NO SE ENCONTRO ESE ID PACIENTE --\n";
        return;
    }

    // Confirmación
    cout << "Esta seguro que desea eliminar el paciente con ID " << id << "? (S/N): ";
    char confirma;
    cin >> confirma;
    if (confirma != 'S' && confirma != 's') {
        cout << "Operacion cancelada. No se elimino el paciente.\n";
        return;
    }

    if (managerPaciente.eliminar(id)) {
        cout << "\n-- ELIMINADO EXITOSAMENTE --\n";
    } else {
        cout << "\n-- NO SE ENCONTRO ESE ID --\n";
    }
}

//MODIFICAR PACIENTE
void ServicioPaciente::modificarPaciente() {
    system("cls");
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
    system("cls");
    cout << "\n-- MODIFICANDO DATOS (Presione ENTER en textos para mantener el actual) --\n";

    //NOMBRE
    cout << "Nombre actual [" << paciente.getNombre() << "] (0 para salir): ";
    getline(cin, nombre);
    if (nombre.empty()) {
        nombre = paciente.getNombre();
    }

    if(nombre == "0") return;

    //APELLIDO
    cout << "Apellido actual [" << paciente.getApellido() << "] (0 para salir): ";
    getline(cin, apellido);
    if (apellido.empty()) {
        apellido = paciente.getApellido();
    }

    if(apellido == "0") return;

    //FECHA
    cout << "\n-- Fecha de nacimiento actual (0 para salir): "
     << paciente.getFechaNacimiento().toString() << "\n";

    Fecha fechaNacimiento = pedirFecha("Ingrese nueva fecha:", 1900, 2025);
    if (fechaNacimiento.getAnio() == 0) return;

    //DNI -> HAY QUE VALIDAR QUE SEA UNICO PERO QUE SE PUEDA INGRESAR EL PROPIO
    while (true) {
        cout << "Nuevo DNI [" << paciente.getDNI() << "] (0 para salir): ";
        if (cin >> dni) {
            if(dni==0){
                return;
            }
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
    cout << "Nuevo email [" << paciente.getEmail() << "] (0 para salir): ";
    getline(cin, email);
    if (email.empty()) email = paciente.getEmail();

    if(email == "0") return;

    //TELEFONO
    cout << "Nuevo telefono [" << paciente.getTelefono() << "] (0 para salir): ";
    getline(cin, telefono);
    if (telefono.empty()) telefono = paciente.getTelefono();

    if(telefono == "0") return;

    //OBRA SOCIAL
    std::vector<ObraSocial> listaObras = servicioObraSocial.obtenerObrasSociales();
    if(listaObras.empty()){
         cout << "No hay obras sociales disponibles. Se mantiene la actual.\n";
         codigoObraSocial = paciente.getCodigoObraSocial();
    } else {
        servicioObraSocial.listarObrasSociales(listaObras);
        while (true) {
            cout << "Nuevo codigo de obra social [" << paciente.getCodigoObraSocial() << "] (0 para salir):  ";
            if (cin >> codigoObraSocial) {
                if(codigoObraSocial == 0) return;
                bool encontrada = false;
                for (int i = 0; i < (int)listaObras.size(); i++) {
                    if (listaObras[i].getId() == codigoObraSocial) {
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

    //GUARDADO
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
    system("cls");
    int dni;

    while (true) {
        cout << "\nIngrese el DNI a buscar (0 para salir): ";

        if (cin >> dni) {

            if (dni == 0) {
                limpiarBuffer();
                return;
            }

            limpiarBuffer();
            break;
        }

        cout << "Error: numero invalido.\n";
        limpiarBuffer();
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
    system("cls");
    string apellido;

    while(true){
        cout << "\nIngrese el apellido a buscar (0 para salir): ";

        getline(cin, apellido);

        if(apellido == "0") return;

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
    system("cls");
    std::vector<Paciente> listaOrdenada = managerPaciente.ordenarPorApellido();

    if(listaOrdenada.empty()){
        cout << "No se encontraron pacientes registrados.\n";
    }else{
        std::vector<ObraSocial> lista = servicioObraSocial.obtenerObrasSociales();
        cout << "\nPacientes ordenados por apellido:\n";
        cout << "-------------------------" << endl;
        for (int i = 0; i < (int)listaOrdenada.size(); i++) {
            cout << "Apellido: " << listaOrdenada[i].getApellido() << endl;
            cout << "Nombre: " << listaOrdenada[i].getNombre() << endl;
            cout << "DNI: " << listaOrdenada[i].getDNI() << endl;
            cout << "Obra Social: " << nombreObraPorId(listaOrdenada[i].getCodigoObraSocial(), lista)  << endl;
            cout << "-------------------------" << endl;
        }
    }
}

//BUSACR POR ID (USADO EN REPORTE)
bool ServicioPaciente::buscarPorId(int id, Paciente &paciente) {
    vector<Paciente> lista = managerPaciente.leerTodos();

    for (int i = 0; i < (int)lista.size(); i++) {
        if (lista[i].getId() == id) {
            paciente = lista[i];
            return true;
        }
    }

    return false;
}
