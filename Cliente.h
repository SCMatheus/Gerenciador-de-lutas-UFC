#ifndef CLIENTE_H
#define CLIENTE_H
#include<Pessoa.h>
#include <QString>
#include <Lista.h>
#include <Aposta.h>
#include <QDate>

namespace TP2 {

class Cliente : public Pessoa
{
private:
    //ED1::Lista<Aposta> *listaAposta;
    QString dataDeCadastro;
    float rendaMensal;
    float limApostas;
    float saldo;
public:
    Cliente();
    Cliente(float rendaMensal, float limApostas, float saldo);


    float getRendaMensal() const;
    void setRendaMensal(float value);
    QString getDataDeCadastro() const;
    void setDataDeCadastro(const QString &value);
    float getLimApostas() const;
    void setLimApostas(float value);
    float getSaldo() const;
    void setSaldo(float value);
    void descobreDataCadastro();
    //ED1::Lista<Aposta>* getListaAposta() const;

    void checaIdade(int idade);
    //void setListaAposta(ED1::Lista<Aposta> *value);
};
}
#endif // CLIENTE_H
