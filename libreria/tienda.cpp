#include "tienda.h"
#include <sstream>
#include "./excepcionesTienda.h"

using namespace std;

Tienda::Tienda(string nombre, string direccionWeb, string direccionFisica, string telefono){

    if (nombre.length() == 0 || nombre.length() > 15){
         throw ExcepcionNombre();
    }
    else if (direccionWeb.length() == 0 || direccionWeb.length() > 24){
        throw ExcepcionDireccionWeb();
    }
    else if (direccionFisica.length() == 0 || direccionFisica.length() > 24){
        throw ExcepcionDireccionFisica();

    }
    else if (telefono.length() == 0 || telefono.length() > 8){
        throw ExcepcionTelefono();
    }
    else{
        strcpy(this->nombre, nombre.c_str());
        strcpy(this->direccionWeb, direccionWeb.c_str());
        strcpy(this->direccionFisica, direccionFisica.c_str());
        strcpy(this->telefono, telefono.c_str());
    }

}

void Tienda::ConstructorIU(string nombre, string direccionWeb, string direccionFisica, string telefono)
{
    strcpy(this->nombre, nombre.c_str());
    strcpy(this->direccionWeb, direccionWeb.c_str());
    strcpy(this->direccionFisica, direccionFisica.c_str());
    strcpy(this->telefono, telefono.c_str());
}

Tienda::Tienda(){
    strcpy(this->nombre, "");
    strcpy(this->direccionWeb, "");
    strcpy(this->direccionFisica, "");
    strcpy(this->telefono, "");
}

Tienda::~Tienda(){
    for (Producto *producto : this->productos){
        delete producto;
    }
}

void Tienda::Agregar(Producto *producto){
    this->productos.push_back(producto);
}

void Tienda::Borrar(int idProducto){
    this->productos.erase(this->productos.begin()+(idProducto -1));
}

Producto* Tienda::GetProducto(int idProducto){
    return this->productos.at(idProducto -1);
}

void Tienda::Cambiar(int idProducto, string nuevoNombreProducto){
    this->productos.at(idProducto -1)->ModificarNombre(nuevoNombreProducto);
}

void Tienda::Existencias(int idProducto, int existencias){
    this->productos.at(idProducto -1)->ModificarExistencias(existencias);
}

void Tienda::StreamEntrada(istream *streamEntrada){
    streamEntrada->read(this->nombre, 15);
    streamEntrada->read(this->direccionWeb, 24);
    streamEntrada->read(this->direccionFisica, 24);
    streamEntrada->read(this->telefono, 8);

    streamEntrada->seekg(0, ios::end);
    int bytes = streamEntrada->tellg();
    int numeroProductos = (bytes - 71) / sizeof(Producto);

    streamEntrada->seekg(71);
    for (int i = 0; i < numeroProductos; i++){
        Producto *producto = new Producto();
        streamEntrada->read((char *)producto, sizeof(Producto));

        this->Agregar(producto);
    }
}

void Tienda::StreamSalida(ostream *streamSalida){
    streamSalida->write(this->nombre, 15);
    streamSalida->write(this->direccionWeb, 24);
    streamSalida->write(this->direccionFisica, 24);
    streamSalida->write(this->telefono, 8);

    for (Producto *producto : this->productos){
        streamSalida->write((char *)producto, sizeof(Producto));
    }
}

ostream& operator << (ostream &o, const Tienda *tienda)
{
    o << tienda->nombre<< endl
      << tienda->direccionWeb << endl
      << tienda->direccionFisica<< endl
      << tienda->telefono<< endl;

    for (Producto *producto : tienda->productos){
        o << producto << endl;
    }
    
    return o;
}
