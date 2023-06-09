#ifndef DETALLEDEMUESTRA_H
#define DETALLEDEMUESTRA_H
#include <string>
using namespace std;


class DetalleDeMuestra
{
    private:
        int _IDmuestra;
        int _IDproducto;
        char _Categoria[9];
        char _Modelo[5];
        char _TipoDeMaterial[5];
        int _Capacidad;
        int _Diametro;
        int _Stock;

    public:

        void setIDmuestra(int idmuestra);
        void setIDproducto(int idproducto);
        void setCategoria(const char *categoria);
        void setModelo(const char *modelo);
        void setTipoDeMaterial(const char *tipoDematerial);
        void setCapacidad(int capacidad);
        void setDiametro(int diametro);
        void setStock(int stock);

        int getIDmuestra();
        int getIDproducto();
        const char* getCategoria();
        const char* getModelo();
        const char* getTipoDeMaterial();
        int getCapacidad();
        int getDiametro();
        int getStock();

        void mostrar(int Aumentar);
};

#endif // DETALLEDEMUESTRA_H
