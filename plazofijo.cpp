
#include "plazofijo.h"

PlazoFijo::PlazoFijo(QString id, QString name, int saldo, QString periodoIngreso, int ingresoFrecuente):Cuenta(id,name,saldo)
{
    this->periodoIngreso=periodoIngreso;
    this->ingresoFrecuente=ingresoFrecuente;
    setType("Plazo Fijo");
}

float PlazoFijo::calcularIntereses()
{
    return (0.038*ingresoFrecuente)+(0.003*getSaldo());
}

QString PlazoFijo::getPeriodoIngreso() const
{
    return periodoIngreso;
}

void PlazoFijo::setPeriodoIngreso(const QString &newPeriodoIngreso)
{
    periodoIngreso = newPeriodoIngreso;
}

int PlazoFijo::getIngresoFrecuente() const
{
    return ingresoFrecuente;
}

void PlazoFijo::setIngresoFrecuente(int newIngresoFrecuente)
{
    ingresoFrecuente = newIngresoFrecuente;
}


