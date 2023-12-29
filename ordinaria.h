
#ifndef ORDINARIA_H
#define ORDINARIA_H

#include "cuenta.h"





class Ordinaria:public Cuenta
{
public:
    Ordinaria(QString name,QString id,int saldo);

    // Cuenta interface
public:
    float calcularIntereses();
};

#endif // ORDINARIA_H
