#pragma once
#include "../ManagerH/ManagerBioquimico.h"
#include "../EntidadesH/Bioquimico.h"
#include "../EntidadesH/Fecha.h"
#include <vector>

class ServicioBioquimico {
    private:
        ManagerBioquimico managerBioquimico;
        void limpiarBuffer() const;
        bool existeDNI(int dni);
        bool existeMatricula(int matricula);

    public:
        ServicioBioquimico();

        void crearBioquimico();
        void modificarBioquimico();
        void eliminarBioquimico();
        std::vector<Bioquimico> obtenerBioquimicos();
        void listarBioquimicos(const std::vector<Bioquimico>& bioquimicos);
        void ordenarBioquimicosPorApellido();
        void ordenarBioquimicosPorLegajo();
        void buscarPorMatricula();
};
