#ifndef PROGRAMAPRINCIPAL_H
#define PROGRAMAPRINCIPAL_H
#include "ClienteMenu.h"
#include "ArticuloMenu.h"
#include "MuestraMenu.h"


class ProgramaPrincipal
{
    public:
        void Ejecutar();

    private:
        ClienteMenu MenuCliente;
        ArticuloMenu MenuArticulo;
        MuestraMenu MenuMuestra;
};

#endif // PROGRAMAPRINCIPAL_H
