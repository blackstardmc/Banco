
#include "entidad.h"

Entidad::Entidad(QString id, QString name, int saldo, QString direccion):Cuenta(id,name,saldo)
{
    this->direccion=direccion;
    setType("Entidad");
}

QString Entidad::getDireccion() const
{
    return direccion;
}

void Entidad::setDireccion(const QString &newDireccion)
{
    direccion = newDireccion;
}

float Entidad::calcularIntereses()
{
    return 0.008*getSaldo();
}


