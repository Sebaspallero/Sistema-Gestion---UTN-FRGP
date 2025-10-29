#include <iostream>
#include "../ManagerH/ManagerSala.h"
#include "../EntidadesH/Sala.h"


ManagerSala::ManagerSala(std::string nombreArchivo) : Manager<Sala>(nombreArchivo){}

 Sala ManagerSala :: buscarPorNombre(std::string nombre){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    Sala salaInvalida;
    if(pFile == nullptr) return salaInvalida;

    Sala sala;

    while(fread(&sala, sizeof(Sala), 1, pFile) == 1){
        if(sala.getNombre() == nombre){
            fclose(pFile);
            return sala;
        }
    }
    fclose(pFile);
    return salaInvalida;
 }

bool ManagerSala :: crearSala(std::string& nombre, int piso){
        int id = obtenerNuevoId();
        Sala sala;
        sala.setId(id);
        sala.setNombre(nombre);
        sala.setPiso(piso);
        sala.setDisponible(true);

        return guardar(sala);
}

bool ManagerSala :: modificarSala(std::string& nombre, int piso, bool disponible, int id){
        int posicion;
        posicion = buscar(id);
        if (posicion == -1) {
            return false;
        }

        Sala sala = leer(posicion);

        sala.setNombre(nombre);
        sala.setPiso(piso);
        sala.setDisponible(disponible);

        return modificar(sala, posicion);

}

