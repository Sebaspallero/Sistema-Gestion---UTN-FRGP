#pragma once
#include <cstring>

class Analisis{
    private:
       int _idAnalisis;
       char _nombre [30];
       int _idCategoria;
       float _valor;  //preguntar a que valor se refieren
       bool _estado;

    public:
        int getIDAnalisis() const;
        std::string getNombre() const;
        int getIDCategoria() const;
        float getValor() const;  //esta asociado con valor
        bool getEstado() const;

        void setIDAnalisis(int idAnalisis);
        void setNombre(std::string& nombre);
        void setIDCategoria(int idCategoria);
        void setValor(float valor);  //esta asociado con valor
        void setEstado(bool estado);
};
