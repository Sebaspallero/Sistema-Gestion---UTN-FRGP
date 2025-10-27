#pragma once
#include <string>

class Sala {

private:
    int _id;
    char _nombre[20];
    int _piso;
    bool _disponible;

public:

    Sala();
    Sala(int id, std::string& nombre, int piso, bool disponible);

    // Getters
    int getId() const;
    std::string getNombre() const;
    int getPiso() const;
    bool isDisponible() const;

    // Setters
    void setNombre(std:: string& nombre);
    void setPiso(int piso);
    void setDisponible(bool disponible);
    void setId(int id);

};
