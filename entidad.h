
#ifndef ENTIDAD_H
#define ENTIDAD_H

#include "cuenta.h"

#include <QString>





class Entidad: public Cuenta
{
private:
    QString direccion;
public:
    Entidad(QString name,QString id,int saldo,QString direccion);
    QString getDireccion() const;
    void setDireccion(const QString &newDireccion);
    float calcularIntereses();
};

#endif // ENTIDAD_H
