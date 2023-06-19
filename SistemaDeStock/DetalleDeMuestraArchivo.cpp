#include "DetalleDeMuestraArchivo.h"
#include "DetalleDeMuestra.h"

bool DetalleDeMuestraArchivo::Guardar(DetalleDeMuestra obj){
FILE* pFile;
pFile= fopen("DetallesDeMuestras.dat", "ab");
if (pFile==NULL){
    return false;
}
fwrite(&obj, sizeof(DetalleDeMuestra),1,pFile);
fclose(pFile);
return true;
}

int DetalleDeMuestraArchivo::CantidadRegistros(){
    int cantidad =0;
    FILE* pFile;
    pFile= fopen("DetallesDeMuestras.dat", "ab");
    if (pFile == NULL){
        return false;
    }
fseek(pFile,0,SEEK_END);
cantidad= ftell(pFile)/sizeof(DetalleDeMuestra);
fclose(pFile);
return cantidad;
}


DetalleDeMuestra DetalleDeMuestraArchivo::Leer(int numero){
DetalleDeMuestra obj;
FILE* pFile;
pFile=fopen("DetallesDeMuestras.dat","rb");
if (pFile==NULL){
    return obj;
}
fseek(pFile,numero*sizeof(DetalleDeMuestra),SEEK_SET);
fread(&obj,sizeof(DetalleDeMuestra),1,pFile);
fclose(pFile);
return obj;

}
