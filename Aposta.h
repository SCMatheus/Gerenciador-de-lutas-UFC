#ifndef APOSTA_H
#define APOSTA_H
#include <Cliente.h>
#include <Luta.h>
#include <Lutador.h>
#include <QString>

namespace TP2 {

class Aposta
{
private:
    QString cliente;
    Luta* luta = 0;
    QString vencedor;
    QString dataAposta;
    float aposta;
public:
    Aposta():dataAposta(""), aposta(0){}
    QString getCliente() const;
    void setCliente(const QString &value);
    Luta *getLuta() const;
    void setLuta(Luta *value);
    QString getVencedor() const;
    void setVencedor(const QString &value);
    QString getDataAposta() const;
    void setDataAposta(const QString &value);
    float getAposta() const;
    void setAposta(float value);
};
}
#endif // APOSTA_H
