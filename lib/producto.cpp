#include "producto.h"
#include "./excepcionesProducto.h"
#include <string>

Producto::Producto(int idProducto, string nombreProducto, int Existencias){

    if (nombreProducto.length() == 0 || nombreProducto.length() > 20){
        throw ExcepcionNombreProducto();
    }
    else if (idProducto <= 0){
        throw ExcepcionNegativo();
    }
    else if (Existencias < 0){
        throw ExcepcionDisponibilidad();

    }
    else {
        this->idProducto = idProducto;
        strcpy(this->nombreProducto, nombreProducto.c_str());
        this->Existencias = Existencias;
    }
}

Producto::Producto(){
    this->idProducto = 0;
    strcpy(this->nombreProducto, "");
    this->Existencias = 0;
}

int Producto::GetID()
{
    return this->idProducto;
}


Producto::~Producto(){

}

// Metodo para modiciar el nombre del producto.
void Producto::ModificarNombre(string nuevoNombre){
    if (nuevoNombre.length() == 0 || nuevoNombre.length() > 20){
        throw ExcepcionNombreProducto();
    }
    strcpy(this->nombreProducto, nuevoNombre.c_str());
}
// Metodo para modiciar la existencia del producto.
void Producto::ModificarExistencias(int existencias)
{
    if (existencias < 0){
        throw ExcepcionDisponibilidad();
    }
    this->Existencias = existencias;
}

ostream& operator << (ostream &streamSalida, const Producto *producto){
    streamSalida 
    << "[ " 
    << producto->idProducto 
    << " ]" 
    << "` " 
    << producto->nombreProducto 
    << " `" 
    << " Stock: " 
    << producto->Existencias;

    return streamSalida;
}
