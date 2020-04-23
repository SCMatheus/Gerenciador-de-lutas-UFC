#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H
#include<Lista.h>
#include<QString>
#include<No.h>
#include<Lutador.h>
#include<fstream>
#include <QStringList>
#include <Evento.h>
#include<Cliente.h>
#include <Aposta.h>

namespace ED1 {
class Persistencia
{
private:
    std::string linha;
    QString linhaAux;
public:
    Persistencia();
    ~Persistencia();
    void gravarArquivoLutador(Lista<TP2::Lutador*> *listaLutador);
    //Lista* inclusaoInicio();
    Lista<TP2::Lutador*>* inclusaoFimLutadores();
    void gravaArquivoNomesEventos(Lista<TP2::Evento*> *listaEvento);
    void gravaArquivoEventos(Lista<TP2::Evento*> *listaEvento);
    void gravaArquivoListaLutasEvento(Lista<TP2::Evento*> *eventos);
    void gravaArquivoListaEventos(Lista<TP2::Evento*> *eventos);
    Lista<TP2::Evento*>* inclusaoFimEventos(Lista<TP2::Lutador *> *listaLutador);
    Lista<TP2::Luta*>* inclusaoFimLutas(TP2::Evento *evento, Lista<TP2::Lutador *> *listaLutador);
    void gravarArquivoCliente(Lista<TP2::Cliente*> *listaCliente);
    Lista<TP2::Cliente*>* inclusaoFimClientes();
    Lista<TP2::Aposta> *inclusaoFimApostas(TP2::Cliente *cliente, Lista<TP2::Evento*>* listaEvento);
    void gravaArquivoListaApostaCliente(Lista<TP2::Cliente*> *Clientes);

    //* inclusaoOrdenada();
};
}
#endif // PERSISTENCIA_H
