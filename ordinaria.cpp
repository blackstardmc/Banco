
#include "ordinaria.h"


Ordinaria::Ordinaria(QString id, QString name, int saldo):Cuenta(id,name,saldo)
{
    setType("Ordinaria");
}

float Ordinaria::calcularIntereses()
{
    return 0.027*getSaldo();
}

