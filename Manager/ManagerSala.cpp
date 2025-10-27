#include <iostream>
#include "../ManagerSala.h"
#include "../Sala.h"


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
