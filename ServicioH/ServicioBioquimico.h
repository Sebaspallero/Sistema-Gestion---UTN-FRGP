#pragma once
#include "../ManagerH/ManagerBioquimico.h"
#include "../EntidadesH/Bioquimico.h"
#include "../EntidadesH/Fecha.h"
#include <vector>

class ServicioBioquimico {
    private:
        ManagerBioquimico managerBioquimico;

        void limpiarBuffer() const;

    public:
        ServicioBioquimico();

        void crearBioquimico();
        void modificarBioquimico();
        void eliminarBioquimico();
        std::vector<Bioquimico> listarBioquimicos();
        std::vector<Bioquimico> ordenarBioquimicosPorApellido();
        std::vector<Bioquimico> ordenarBioquimicosPorLegajo();
};
