#pragma once
#include <cstring>
#include <string>

class Analisis{
    private:
       int _id;
       char _nombre [30];
       int _idCategoria;
       float _valor;  //preguntar a que valor se refieren
       bool _estado;

    public:
        Analisis();
        Analisis(int id, std::string nombre, int idCategoria, float valor);

        int getId() const;
        std::string getNombre() const;
        int getIdCategoria() const;
        float getValor() const;  //esta asociado con valor
        bool getEstado() const;

        void setId(int idAnalisis);
        void setNombre(std::string& nombre);
        void setIdCategoria(int idCategoria);
        void setValor(float valor);  //esta asociado con valor
        void setEstado(bool estado);
};
