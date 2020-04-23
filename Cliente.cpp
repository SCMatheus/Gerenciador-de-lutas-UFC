#include "Cliente.h"
namespace TP2 {


QString Cliente::getDataDeCadastro() const
{
    return dataDeCadastro;
}

void Cliente::setDataDeCadastro(const QString &value)
{
    dataDeCadastro = value;
}

float Cliente::getLimApostas() const
{
    return limApostas;
}

void Cliente::setLimApostas(float value)
{
    if(value <= 0) throw QString ("Renda Mensal inválida.");
    limApostas = value;
}

float Cliente::getSaldo() const
{
    return saldo;
}

void Cliente::setSaldo(float value)
{
    if(value < 0) throw QString ("Renda Mensal inválida.");
    saldo = value;
}

/*ED1::Lista<Aposta> *Cliente::getListaAposta() const
{
    return listaAposta;
}*/

void Cliente::checaIdade(int idade)
{
    if((idade < 25)||(idade > 85)) throw QString ("Idade inválida.");
}

/*void Cliente::setListaAposta(ED1::Lista<Aposta> *value)
{
    listaAposta = value;
}*/

Cliente::Cliente():
    dataDeCadastro(""),
    rendaMensal(0),
    limApostas(0),
    saldo(0)
{
    //listaAposta = new ED1::Lista<Aposta>();
}

Cliente::Cliente(float rendaMensal, float limApostas, float saldo)
{
    if(rendaMensal <= 0) throw QString ("Renda Mensal inválida.");
    if(limApostas <= 0) throw QString ("Renda Mensal inválida.");
    if(saldo < 0) throw QString ("Renda Mensal inválida.");
    this->rendaMensal = rendaMensal;
    this->limApostas = limApostas;
    this->saldo = saldo;
    //listaAposta = new ED1::Lista<Aposta>();

}

float Cliente::getRendaMensal() const
{
    return rendaMensal;
}

void Cliente::setRendaMensal(float value)
{
    if(value <= 0) throw QString ("Renda Mensal inválida.");
    rendaMensal = value;
}

void Cliente::descobreDataCadastro(){
    QDate dataSistema = QDate::currentDate();

    QString dataDeCadastro;

    dataDeCadastro = QString::number(dataSistema.day()) +"/" + QString::number(dataSistema.month())+"/"+QString::number(dataSistema.year());

    this->dataDeCadastro = dataDeCadastro;
}

}
