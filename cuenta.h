
#ifndef CUENTA_H
#define CUENTA_H
#include <qstring.h>
using namespace std;




class Cuenta
{
private:
    vector<int> lista;
    QString id;
    QString name;
    int saldo;
    QString type;
public:
    QString getHistory();
    bool withdraw(int ammount);
    int deposit(int ammount);
    virtual float calcularIntereses()=0;
    Cuenta(QString name,QString id,int saldo);
    int getSaldo() const;
    void setSaldo(int newSaldo);
    QString getName() const;
    void setName(const QString &newName);
    QString getId() const;
    void setId(const QString &newId);
    QString getType() const;
    void setType(const QString &newType);
};

#endif // CUENTA_H
