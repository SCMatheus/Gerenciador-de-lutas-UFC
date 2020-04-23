#ifndef LUTA_H
#define LUTA_H
#include<QString>
#include <Lutador.h>

namespace TP2 {

class Luta
{
private:
    Lutador *lutador1 = 0;
    Lutador *lutador2 = 0;
    int raunds;
    QString resultado;
    QString status;
public:
    Luta():raunds(0),resultado("indefinido"),status("indefinido"){}
    Luta(Lutador *lutador1, Lutador *lutador2, int raunds);

    //Métodos set

    void setLutador1(Lutador* lutador1){this->lutador1 = lutador1;}
    void setLutador2(Lutador* lutador2){this->lutador2 = lutador2;}
    void setRounds(int raunds);
    void setResultado(QString resultado){this->resultado = resultado;}
    void setStatus(QString status){this->status = status;}


    //Métodos get

    Lutador* getLutador1(){return lutador1;}
    Lutador* getLutador2(){return lutador2;}
    int getRounds(){return raunds;}
    QString getResultado(){return resultado;}
    QString getStatus(){return status;}

    //Métodos de operações

    QString mostrarLuta();
};
}

#endif // LUTA_H
