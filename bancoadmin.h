
#ifndef BANCOADMIN_H
#define BANCOADMIN_H




#include "cuenta.h"
class BancoAdmin
{
private:
    std::vector<Cuenta*> listaCuentas;
public:
    void addAccount(Cuenta *cuenta);
    Cuenta* getCuenta(int position);
    QString getListString();
    QString getListBySaldo(int saldo);
    int posMayorSaldo();
    int cuentasOrdinarias();
    int cuentasPlazoFijo();
    int cuentasEntidad();
    QString getCantidadCuentas();
    bool isPlazoFijo(Cuenta *c);
    bool isOrdinaria(Cuenta *c);
    bool isEntidad(Cuenta *c);
    int posMayorInteresPlazoFijo();
    QString nameMayorPlazoFijo();
    int getAccountbyId(QString id);
    BancoAdmin();
};

#endif // BANCOADMIN_H
