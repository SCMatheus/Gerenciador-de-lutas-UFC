#ifndef EVENTO_H
#define EVENTO_H
#include<Luta.h>
#include <Lista.h>
namespace TP2 {

class Evento
{
private:
    ED1::Lista<Luta*> *lutas;
    QString nome;
    QString local;
    int dia;
    int mes;
    int ano;
    int quantidadeDeLutas;
    int hora;
    int minutos;
    QString situacao;
public:
    Evento():local(""),dia(0),mes(0),ano(0),hora(-1),minutos(-1),quantidadeDeLutas(0),nome(""),situacao("Agendado"){lutas = new ED1::Lista<Luta*>();}
    Evento(QString local, int dia, int mes, int ano,int hora, int minutos, int quantidadeDeLutas, QString nome);

    //

    void setLocal(QString local){this->local = local;}
    void setDia(int dia);
    void setMes(int mes);
    void setAno(int ano);
    void setHora(int hora);
    void setMinutos(int minutos);
    void setQuantidadeDeLutas(int quantidadeDeLutas);
    void setNome(QString nome){this->nome = nome;}
    void setListaLutas(ED1::Lista<Luta*> *lutas){this->lutas = lutas;}

    //

    QString getLocal(){return local;}
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAno(){return ano;}
    int getHora(){return hora;}
    int getMinutos(){return minutos;}
    int getQuantidadeDeLutas(){return quantidadeDeLutas;}
    QString getNome(){return nome;}
    Luta* getLuta(int posicao){return lutas->operator [](posicao - 1);}
    ED1::Lista<Luta*>* getListaLutas(){return lutas;}
    int getQuantidadedeLutasCadastradas();

    //

    void listaLutas(Luta *luta);
    QString exibeLutas();

    QString getSituacao() const;
    void setSituacao(const QString &value);

    void verificaSituacao();
};
}
#endif // EVENTO_H
