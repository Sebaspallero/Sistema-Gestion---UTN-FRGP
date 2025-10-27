#pragma once
#include "../ManagerSala.h"
#include "../Sala.h"


class ServicioSala{

    private:
        ManagerSala _managerSalas;

    public:
        ServicioSala(const std::string& nombreArchivo = "sala.dat");

        bool guardarSala(std::string& nombre, int piso);
        bool eliminarSala(int id);
        bool modificarSala(std::string& nombre, int piso, bool disponible, int id);
        Sala leerSala(int posicion);
        std::vector<Sala> ListarSalas();
        int buscarPorId(int id);
        Sala buscarPorNombre(std::string nombre);
        bool validarDisponibilidad(int id);
};
