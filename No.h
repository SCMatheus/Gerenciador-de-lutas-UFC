#ifndef NO_H
#define NO_H

namespace ED1{
template <class tipo>
class No
{
private:
    tipo informacao;
    No<tipo> *proximo;
    No<tipo> *anterior;
public:
    No():proximo(0),anterior(0){}
    No(tipo informacao):informacao(informacao),proximo(0),anterior(0){}
    ~No(){proximo=0;}
    tipo getInformacao()const{return informacao;}
    void setInformacao(tipo informacao){this->informacao=informacao;}
    No<tipo>* getProximo()const{return proximo;}
    void setProximo(No<tipo>* proximo){this->proximo = proximo;}
    No<tipo>* getAnterior()const{return anterior;}
    void setAnterior(No<tipo>* anterior){this->anterior = anterior;}

};
}
#endif // NO_H
