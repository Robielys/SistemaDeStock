#ifndef PROGRAMAPRINCIPAL_H
#define PROGRAMAPRINCIPAL_H
#include "ClienteMenu.h"
#include "ArticuloMenu.h"


class ProgramaPrincipal
{
    public:
        void Ejecutar();

    private:
        ClienteMenu MenuCliente;
        ArticuloMenu MenuArticulo;
};

#endif // PROGRAMAPRINCIPAL_H
