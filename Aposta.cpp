#include "Aposta.h"
namespace TP2 {

Luta *Aposta::getLuta() const
{
    return luta;
}

void Aposta::setLuta(Luta *value)
{
    luta = value;
}

QString Aposta::getVencedor() const
{
    return vencedor;
}

void Aposta::setVencedor(const QString &value)
{
    vencedor = value;
}

QString Aposta::getDataAposta() const
{
    return dataAposta;
}

void Aposta::setDataAposta(const QString &value)
{
    dataAposta = value;
}

float Aposta::getAposta() const
{
    return aposta;
}

void Aposta::setAposta(float value)
{
    aposta = value;
}

QString Aposta::getCliente() const
{
    return cliente;
}

void Aposta::setCliente(const QString &value)
{
    cliente = value;
}

}
