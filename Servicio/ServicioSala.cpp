#include <iostream>
#include "../ServicioH/ServicioSala.h"
#include "../Sala.h"


    ServicioSala::ServicioSala(const std::string& nombreArchivo) :  _managerSalas(nombreArchivo) {}


    bool ServicioSala :: guardarSala(std::string& nombre, int piso){
        int id = _managerSalas.obtenerNuevoId();
        Sala sala;
        sala.setId(id);
        sala.setNombre(nombre);
        sala.setPiso(piso);
        sala.setDisponible(true);

        return _managerSalas.guardar(sala);
    }

    bool ServicioSala ::  eliminarSala(int id){
        bool eliminar;

        eliminar = _managerSalas.eliminar(id);

        return eliminar;
    }

    bool ServicioSala ::  modificarSala(std::string& nombre, int piso, bool disponible, int id){
        int posicion;
        posicion = _managerSalas.buscar(id);
        if (posicion == -1) {
            return false;
        }

        Sala sala = _managerSalas.leer(posicion);

        sala.setNombre(nombre);
        sala.setPiso(piso);
        sala.setDisponible(disponible);

        return _managerSalas.modificar(sala, posicion);

    }

    Sala ServicioSala :: leerSala(int posicion){
        //VERIFICAR SI SE USA EN EL SERVICIO
    }

    std::vector<Sala> ServicioSala ::  ListarSalas(){
        std::vector<Sala> listaSalas;
        return listaSalas = _managerSalas.leerTodos();
    }

    int ServicioSala ::  buscarPorId(int id){
        //VERIFICAR SI SE USA EN EL SERVICIO
    }

    Sala ServicioSala ::  buscarPorNombre(std::string nombre){
        Sala sala;
        sala = _managerSalas.buscarPorNombre(nombre);
        return sala;
        //ARREGLAR PROBLEMA ESPACIO
    }

    bool ServicioSala :: validarDisponibilidad(int id){
        int posicion;
        posicion = _managerSalas.buscar(id);
        if (posicion == -1) {
            return false;
        }
        Sala sala = _managerSalas.leer(posicion);
        return sala.isDisponible();
    }
