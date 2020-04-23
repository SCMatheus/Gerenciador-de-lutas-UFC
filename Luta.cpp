#include "Luta.h"
namespace TP2 {
Luta::Luta(Lutador* lutador1, Lutador* lutador2, int raunds):
  resultado("indefinido"),
  status("indefinido"),
  raunds(0)
{
    if(raunds <= 0) throw QString("Quantidade de raunds inválida.");
    this->lutador1 = lutador1;
    this->lutador2 = lutador2;
    this->raunds = raunds;
}

void Luta::setRounds(int raunds){
    if(raunds <= 0) throw QString("Quantidade de raunds inválida.");
    this->raunds = raunds;
}

QString Luta::mostrarLuta(){
    QString luta = "";
    luta = lutador1->getNome() + "   X   " + lutador2->getNome() + "      " + getStatus() + "     " + getResultado() + "\n";
    return luta;
}

}
