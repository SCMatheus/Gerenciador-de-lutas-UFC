#ifndef LISTA_H
#define LISTA_H
#include<No.h>
#include<QString>
namespace ED1 {
template <class tipo>
class Lista
{
private:
    int quantidadeDeElementos;
    No<tipo> *inicio;
    No<tipo> *fim;
public:
    Lista():quantidadeDeElementos(0),inicio(0){}
    ~Lista();
    bool listaVazia()const{return quantidadeDeElementos==0;}
    int getQuantidadeDeElementos()const{return quantidadeDeElementos;}
    void inserirInicio(tipo elemento);
    tipo retirarInicio();
    void inserirFim(tipo elemento);
    tipo retirarFim();
    void inserirNoMeio(tipo elemento, int posicao);
    tipo operator[] (int posicao);
    tipo retirarDoMeio(int posicao);
    void inserirOrdenado(tipo elemento);
    tipo retirarElemento(tipo elemento);
    tipo acessarElemento(tipo elemento);
};

template<class tipo>
void Lista<tipo>::inserirInicio(tipo elemento){
    No<tipo> *pt = 0;
    try {
        pt = new No<tipo>(elemento);
    } catch(std::bad_alloc&){
        throw QString("falta espaço na memória");
    }
    if(quantidadeDeElementos == 0){
        pt->setProximo(pt);
        pt->setAnterior(pt);
        inicio = fim = pt;
        quantidadeDeElementos++;
        return;
    }
    pt->setProximo(inicio);
    inicio->setAnterior(pt);
    inicio = pt;
    fim->setProximo(inicio);
    inicio->setAnterior(fim);
    quantidadeDeElementos++;
    return;
}
template<class tipo>
tipo Lista<tipo>::retirarInicio(){
    if(listaVazia()) throw QString("Lista Vazia");
    No<tipo> *aux = 0;
    tipo valor;
    if(quantidadeDeElementos == 1){
        aux = inicio;
        inicio = fim = 0;
        aux->setProximo(0);
        aux->setAnterior(0);
        valor = aux->getInformacao();
        delete aux;
        quantidadeDeElementos--;
        return valor;
    }
    aux = inicio;
    inicio = aux->getProximo();
    fim->setProximo(inicio);
    inicio->setAnterior(fim);
    aux->setAnterior(0);
    aux->setProximo(0);
    valor = aux->getInformacao();
    delete aux;
    quantidadeDeElementos--;
    return valor;
}

template <class tipo>
void Lista<tipo>::inserirFim(tipo elemento){
    No<tipo> *pt = 0;
    try {
        pt = new No<tipo>(elemento);
    } catch(std::bad_alloc&){
        throw QString("falta espaço na memória");
    }
    if(quantidadeDeElementos == 0){
        pt->setProximo(pt);
        pt->setAnterior(pt);
        inicio = fim = pt;
        quantidadeDeElementos++;
        return;
    }
    pt->setAnterior(fim);
    fim->setProximo(pt);
    fim = pt;
    fim->setProximo(inicio);
    inicio->setAnterior(fim);
    quantidadeDeElementos++;
    return;
}

template <class tipo>
tipo Lista<tipo>::retirarFim(){
    if(listaVazia()) throw QString("Lista Vazia");
    No<tipo> *aux = 0;
    tipo valor;
    if(quantidadeDeElementos == 1){
        aux = fim;
        inicio = fim = 0;
        aux->setProximo(0);
        aux->setAnterior(0);
        valor = aux->getInformacao();
        delete aux;
        quantidadeDeElementos--;
        return valor;
    }
    aux = fim;
    fim = aux->getAnterior();
    fim->setProximo(inicio);
    inicio->setAnterior(fim);
    aux->setAnterior(0);
    aux->setProximo(0);
    valor = aux->getInformacao();
    delete aux;
    quantidadeDeElementos--;
    return valor;
}

template <class tipo>
void Lista<tipo>::inserirNoMeio(tipo elemento, int posicao){
    if((posicao > (quantidadeDeElementos)) || (posicao < 0)) throw QString ("Posição iválida");
    if(posicao == 0){
        inserirInicio(elemento);
        return;
    }
    if(posicao == (quantidadeDeElementos)){
        inserirFim(elemento);
        return;
    }
    No<tipo> *pt = 0;
    No<tipo> *aux1 = 0;
    No<tipo> *aux2 = 0;
    try{
        pt = new No<tipo>(elemento);
    }catch(std::bad_alloc&){
        throw QString ("falta espaço na memória");
    }
    aux1 = inicio->getProximo();
    aux2 = inicio;
    posicao--;
    while(posicao != 0){
        aux1 = aux1->getProximo();
        posicao--;
    }
    pt->setProximo(aux1);
    aux2->setProximo(pt);
    quantidadeDeElementos++;
}
template <class tipo>
tipo Lista<tipo>::operator[] (int posicao){
    if((posicao >= (quantidadeDeElementos)) || (posicao < 0)) throw QString ("Posição iválida");
    if(listaVazia()) throw QString ("Lista Vazia");
    if(posicao == 0){return inicio->getInformacao();}
    if(posicao == (quantidadeDeElementos - 1)){return fim->getInformacao();}
    No<tipo> *aux = inicio;

    while(posicao != 0){
        aux = aux->getProximo();
        posicao--;
    }
    return aux->getInformacao();
}
template <class tipo>
tipo Lista<tipo>::retirarDoMeio(int posicao){
    if((posicao >= (quantidadeDeElementos)) || (posicao < 0)) throw QString ("Posição iválida");
    if(listaVazia()) throw QString ("Lista Vazia");
    if(posicao == 0){return retirarInicio();}
    if(posicao == (quantidadeDeElementos - 1)){return retirarFim();}
    No<tipo> *aux1 = inicio->getProximo();
    No<tipo> *aux2 = inicio;
    tipo valor;
    posicao--;
    while(posicao != 0){
        aux1 = aux1->getProximo();
        aux2 = aux2->getProximo();
        posicao--;
    }
    aux2->setProximo(aux1->getProximo());
    valor = aux1->getInformacao();
    aux1->setProximo(0);
    delete aux1;
    quantidadeDeElementos--;
    return valor;
}
template <class tipo>
void Lista<tipo>::inserirOrdenado(tipo elemento){
    if(listaVazia()){
        inserirInicio(elemento);
        return;
    }
    if((fim == inicio) && (elemento < inicio->getInformacao())){
        inserirInicio(elemento);
        return;
    }else if(elemento <= inicio->getInformacao()){
        inserirInicio(elemento);
        return;
    }else if(fim == inicio){
        inserirFim(elemento);
        return;
    }
    No<tipo> *pt = 0;
    No<tipo> *aux1 = 0;
    No<tipo> *aux2 = 0;
    try{
        pt = new No<tipo>(elemento);
    }catch(std::bad_alloc&){
        throw QString ("falta espaço na memória");
    }
    aux1 = inicio->getProximo();
    aux2 = inicio;
    while((aux2->getProximo() != fim) && (elemento > aux1->getInformacao())){
        aux1 = aux1->getProximo();
        aux2 = aux2->getProximo();
    }

    pt->setProximo(aux1);
    aux2->setProximo(pt);
    quantidadeDeElementos++;

}
template <class tipo>
tipo Lista<tipo>::retirarElemento(tipo elemento){
    if(listaVazia()) throw QString ("Lista Vazia");
    if(elemento == inicio->getInformacao()){return retirarInicio();}
    if(elemento == fim->getInformacao()){return retirarFim();}
    No<tipo> *aux1 = inicio->getProximo();
    No<tipo> *aux2 = inicio;
    tipo valor;
    while((elemento != aux1->getInformacao()) && (aux1 != fim)){
        aux1 = aux1->getProximo();
        aux2 = aux2->getProximo();
    }

    if((aux1 == fim) && (elemento != aux1->getInformacao())) throw QString ("Elemento não encontrado");

    aux2->setProximo(aux1->getProximo());
    valor = aux1->getInformacao();
    aux1->setProximo(0);
    delete aux1;
    quantidadeDeElementos--;
    return valor;
}
template <class tipo>
tipo Lista<tipo>::acessarElemento(tipo elemento){
    if(listaVazia()) throw QString ("Lista Vazia");
    No<tipo> *aux1 = inicio;
    while((elemento != aux1->getInformacao()) && (aux1 != fim)){
        aux1 = aux1->getProximo();
    }

    if((aux1 == fim) && (elemento != aux1->getInformacao())) throw QString ("Elemento não encontrado");

    return aux1->getInformacao();
}
template <class tipo>
Lista<tipo>::~Lista(){
    while(!listaVazia()){
        retirarInicio();
    }
}


}
#endif // LISTA_H
