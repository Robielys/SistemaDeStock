#ifndef DETALLEDEMUESTRAARCHIVO_H
#define DETALLEDEMUESTRAARCHIVO_H
#include "DetalleDeMuestra.h"


class DetalleDeMuestraArchivo
{

    public:
       bool Guardar(DetalleDeMuestra detalle);
       int CantidadRegistros();
       DetalleDeMuestra Leer(int numeroDeRegistro);





};

#endif // DETALLEDEMUESTRAARCHIVO_H
