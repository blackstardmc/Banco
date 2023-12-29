
#include "cuenta.h"

#include <QString>

QString Cuenta::getName() const
{
    return name;
}

void Cuenta::setName(const QString &newName)
{
    name = newName;
}


QString Cuenta::getId() const
{
    return id;
}

void Cuenta::setId(const QString &newId)
{
    id = newId;
}

QString Cuenta::getType() const
{
    return type;
}

void Cuenta::setType(const QString &newType)
{
    type = newType;
}

QString Cuenta::getHistory()
{
    QString a="";
    foreach (int number, lista) {
        if(number<0){
            a+="\n Extraccion  "+QString::number(number);
        }else{
            a+="\n Deposito  "+QString::number(number);
        }
    }
    return a;
}

bool Cuenta::withdraw(int ammount)
{
    if(ammount>saldo){
        return false;
    }
    else{

        saldo-=ammount;
        lista.push_back(ammount*-1);
        return true;
    }
}

int Cuenta::deposit(int ammount)
{
    saldo+=ammount;
    lista.push_back(ammount);
    return saldo;
}

Cuenta::Cuenta( QString name,QString id, int saldo)
{
    this->id=id;
    this->name=name;
    this->saldo=saldo;
}

int Cuenta::getSaldo() const
{
    return saldo;
}

void Cuenta::setSaldo(int newSaldo)
{
    saldo = newSaldo;
}


