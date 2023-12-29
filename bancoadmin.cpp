
#include "bancoadmin.h"
#include "entidad.h"
#include "ordinaria.h"
#include "plazofijo.h"
#include <typeinfo>

void BancoAdmin::addAccount(Cuenta *cuenta)
{
    this->listaCuentas.push_back(cuenta);
}

Cuenta* BancoAdmin::getCuenta(int position)
{
    return listaCuentas[position];
}

QString BancoAdmin::getListString()
{
    QString a="";
    for (size_t var = 0; var < listaCuentas.size(); ++var) {
        if (isOrdinaria(listaCuentas[var])) {
            a+=" \n Ordinaria "+listaCuentas[var]->getName();
        }
        else if (isPlazoFijo(listaCuentas[var])) {
            a+=" \n Plazo Fijo "+listaCuentas[var]->getName();
        }else if (isEntidad(listaCuentas[var])) {
            a+=" \n Entidad "+listaCuentas[var]->getName();
        }
    }
    return a;
}

QString BancoAdmin::getListBySaldo(int saldo)
{
    QString a="";
    for (size_t var = 0; var < listaCuentas.size(); ++var) {
        if(listaCuentas[var]->getSaldo()>saldo){
            a+=" \n "+listaCuentas[var]->getId();
           }
      }
    return a;
}

int BancoAdmin::posMayorSaldo()
{
    size_t position=0;
    int mayor=listaCuentas[0]->getSaldo();
    for (size_t var = 0; var < listaCuentas.size(); ++var) {
        if(listaCuentas[var]->getSaldo()>mayor){
            position=var;
            mayor=listaCuentas[var]->getSaldo();
        }
    }
    return position;

}

int BancoAdmin::cuentasOrdinarias()
{
    int sum=0;
    for (size_t var = 0; var < listaCuentas.size(); ++var) {
        if (isOrdinaria(listaCuentas[var])) {
            sum+=1;
        }
    }
    return  sum;
}

int BancoAdmin::cuentasPlazoFijo()
{
    int sum=0;
    for (size_t var = 0; var < listaCuentas.size(); ++var) {
        if (isPlazoFijo(listaCuentas[var])) {
            sum+=1;
        }
    }
    return  sum;
}

int BancoAdmin::cuentasEntidad()
{
    int sum=0;
    for (size_t var = 0; var < listaCuentas.size(); ++var) {
        if (isEntidad(listaCuentas[var])) {
            sum+=1;
        }
    }
    return  sum;
}

QString BancoAdmin::getCantidadCuentas()
{
    QString a="";
    a+="Ordinaria "+QString::number(cuentasOrdinarias())+"\n";
     a+="Plazo Fijo "+QString::number(cuentasPlazoFijo())+"\n";
     a+="Entidad "+QString::number(cuentasEntidad());
     return a;
}

bool BancoAdmin::isPlazoFijo(Cuenta *c)
{
    return c->getType()=="Plazo Fijo";
}

bool BancoAdmin::isOrdinaria(Cuenta *c)
{
    return c->getType()=="Ordinaria";
}

bool BancoAdmin::isEntidad(Cuenta *c)
{
    return c->getType()=="Entidad";
}

int BancoAdmin::posMayorInteresPlazoFijo()
{
    size_t position=-1;
    int mayor=0;
    for (size_t var = 0; var < listaCuentas.size(); ++var) {
        if(listaCuentas[var]->calcularIntereses()>mayor && isPlazoFijo(listaCuentas[var])){
            position=var;
            mayor=listaCuentas[var]->calcularIntereses();
        }
    }
    return position;
}

QString BancoAdmin::nameMayorPlazoFijo()
{
    if(posMayorInteresPlazoFijo()==-1){
        return "No existen cuentas de plazo Fijo";
    }else{
        return listaCuentas[posMayorInteresPlazoFijo()]->getName();
    }
}

int BancoAdmin::getAccountbyId(QString id)
{
    size_t position=-1;

    for (size_t var = 0; var < listaCuentas.size(); ++var) {
        if(listaCuentas[var]->getId()==id){
            position=var;

      }
    }
    return position;
}



BancoAdmin::BancoAdmin()
{
    addAccount(new Ordinaria("Julio","AS24",23));
    addAccount(new Ordinaria("Miguel","23S24",123));
    addAccount(new Ordinaria("Alejandro","23F24",67));
    addAccount(new Entidad("Bodega","2F24",567,"Santiago"));
    addAccount(new Entidad("Reataurante","235",234,"Maso"));
    addAccount(new Entidad("Farmacia","9536",900,"Cauto Cristo"));
    addAccount(new PlazoFijo("Miguel", "231",432,"Mensual",752));
    addAccount(new PlazoFijo("Rusia", "231",432,"Mensual",20));
    addAccount(new PlazoFijo("Arcangel", "231",432,"Mensual",34));



}

