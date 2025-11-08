#pragma once
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>

template <typename T>
class Manager
{
protected:
    std::string _nombreArchivo;

public:
    Manager(std::string nombreArchivo);

    bool guardar(const T& entidad);
    bool eliminar(int id);
    bool modificar(const T& entidad, int posicion);
    T leer(int posicion);
    int cantidadDeRegistros();
    int buscar(int id);
    std::vector<T> leerTodos();
    int obtenerNuevoId();
};

// Constructor
template <typename T>
Manager<T>::Manager(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
}

// Guardar
template <typename T>
bool Manager<T>::guardar(const T& entidad) {
    FILE *pFile = fopen(_nombreArchivo.c_str(), "ab");
    if(!pFile) return false;

    bool creado = fwrite(&entidad, sizeof(T), 1, pFile) == 1;
    fclose(pFile);
    return creado;
}

// Eliminar
template <typename T>
bool Manager<T>::eliminar(int id) {
    FILE *pFileOriginal = fopen(_nombreArchivo.c_str(), "rb");
    if(!pFileOriginal) return false;

    FILE *pFileCopia = fopen("ArchivoCopia.dat", "wb");
    if(!pFileCopia) {
        fclose(pFileOriginal);
        return false;
    }

    T entidad;
    bool eliminado = false;
    while(fread(&entidad, sizeof(T), 1, pFileOriginal) == 1){
        if(entidad.getId() != id){
            fwrite(&entidad, sizeof(T), 1, pFileCopia);
        } else {
            eliminado = true;
        }
    }

    fclose(pFileOriginal);
    fclose(pFileCopia);

    remove(_nombreArchivo.c_str());
    rename("ArchivoCopia.dat", _nombreArchivo.c_str());

    return eliminado;
}

// Modificar
template <typename T>
bool Manager<T>::modificar(const T& entidad, int posicion){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if(!pFile) return false;

    fseek(pFile, sizeof(T) * posicion, SEEK_SET);
    bool modificado = fwrite(&entidad, sizeof(T), 1, pFile) == 1;
    fclose(pFile);
    return modificado;
}

// Leer
template <typename T>
T Manager<T>::leer(int posicion){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    T entidad; //VERIFICAR SI FALTA AGREGAR LLAVES
    if(!pFile) return entidad;

    fseek(pFile, sizeof(T) * posicion, SEEK_SET);
    fread(&entidad, sizeof(T), 1, pFile);
    fclose(pFile);
    return entidad;
}

// Cantidad de registros
template <typename T>
int Manager<T>::cantidadDeRegistros(){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(!pFile) return 0;

    fseek(pFile, 0, SEEK_END);
    int cantidad = ftell(pFile) / sizeof(T);
    fclose(pFile);
    return cantidad;
}

// Leer todos
template <typename T>
std::vector<T> Manager<T>::leerTodos(){
    std::vector<T> lista;
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(!pFile) return lista;

    T registro;
    while(fread(&registro, sizeof(T), 1, pFile) == 1){
        lista.push_back(registro);
    }

    fclose(pFile);
    return lista;
}

// Buscar
template <typename T>
int Manager<T>::buscar(int id){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(!pFile) return -1;

    T entidad;
    int i = 0;
    while(fread(&entidad, sizeof(T), 1, pFile) == 1){
        if(entidad.getId() == id){
            fclose(pFile);
            return i;
        }
        i++;
    }
    fclose(pFile);
    return -1;
}

// Obtener nuevo ID
template <typename T>
int Manager<T>::obtenerNuevoId() {
    int cantidad = cantidadDeRegistros();
    if(cantidad == 0) return 1;
    T ultimo = leer(cantidad - 1);
    return ultimo.getId() + 1;
}


