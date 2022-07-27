#ifndef ExcepcionesTienda_H
#define ExcepcionesTienda_H

#include <exception>
#include "excepcionesProducto.h"

using namespace std;

class ExcepcionNombre : public exception
{
public:
    ExcepcionNombre() noexcept = default;
    ~ExcepcionNombre() = default;

    virtual const char *what() const noexcept{
        return "ERROR: Ingresar un nombre de no más de 24 caracteres";
    }
};

class ExcepcionDireccionWeb : public exception
{
public:
    ExcepcionDireccionWeb() noexcept = default;
    ~ExcepcionDireccionWeb() = default;

    virtual const char *what() const noexcept{
        return "ERROR: No ingresar más de 24 caracteres.";
    }
};

class ExcepcionDireccionFisica : public exception
{
public:
    ExcepcionDireccionFisica() noexcept = default;
    ~ExcepcionDireccionFisica() = default;

    virtual const char *what() const noexcept
    {
        return "ERROR: No ingresar más de 8 caracteres.";
    }
};

class ExcepcionTelefono : public exception
{
public:
    ExcepcionTelefono() noexcept = default;
    ~ExcepcionTelefono() = default;

    virtual const char *what() const noexcept
    {
        return "ERROR: No ingresar más de 8 dígitos.";
    }
};

#endif