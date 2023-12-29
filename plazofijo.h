
#ifndef PLAZOFIJO_H
#define PLAZOFIJO_H

#include "cuenta.h"





class PlazoFijo: public Cuenta
{
private:
    QString periodoIngreso;int ingresoFrecuente;
public:
    PlazoFijo(QString name,QString id,int saldo,QString periodoIngreso,int ingresoFrecuente);
    float calcularIntereses();
    QString getPeriodoIngreso() const;
    void setPeriodoIngreso(const QString &newPeriodoIngreso);
    int getIngresoFrecuente() const;
    void setIngresoFrecuente(int newIngresoFrecuente);
};

#endif // PLAZOFIJO_H
