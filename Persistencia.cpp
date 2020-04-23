#include "Persistencia.h"
namespace ED1 {
Persistencia::Persistencia():
    linha(""),
    linhaAux("")
{
}
Lista<TP2::Lutador*>* Persistencia::inclusaoFimLutadores(){
    linha = "";
    linhaAux = "";
    TP2::Lutador *lutador = 0;
    Lista<TP2::Lutador*> *listaLutador = 0;
    QString nomeDoArquivo = "C:/Users/Matheus/OneDrive/Documents/ArquivosUFC/listaDeLutadores.txt";
    std::ifstream arquivo;
    QStringList informacao;

    // abrindo um arquivo de entrada
    arquivo.open(nomeDoArquivo.toStdString().c_str());

    // verificando erro de abertura do arquivo de entrada
    if(!arquivo.is_open()){
        throw QString("ERRO Arquivo nao pode ser aberto");
    }
    try{
        listaLutador = new Lista<TP2::Lutador*>();
    }catch(std::bad_alloc){
       throw QString("falta espaço na memória");
    }
    getline(arquivo,linha);

    std::ofstream arquivoErro;
    arquivoErro.open("Erro.csv", std::fstream::out);

    while(!arquivo.eof()){

        try{
           lutador = new TP2::Lutador();
        }catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }

        //if(linha == "") throw QString("Arquivo Vazio");

        linhaAux = QString::fromStdString(linha);

        informacao = linhaAux.split(';');

        if(informacao.size() != 13){

            arquivoErro<<linha<<std::endl;

        }else{
            lutador->setCodigo(informacao[0].toInt());
            lutador->setNome(informacao[1]);
            lutador->setPeso(informacao[2].toFloat());
            lutador->setAltura(informacao[3].toFloat());
            lutador->setIdade(informacao[4].toInt());
            lutador->setNacionalidade(informacao[5]);
            lutador->setVitorias(informacao[6].toInt());
            lutador->setDerrotas(informacao[7].toInt());
            lutador->setEmpates(informacao[8].toInt());
            lutador->setCategoria(informacao[9]);
            lutador->setDataNascimento(informacao[10]);
            lutador->setCadastro(informacao[11].toInt());
            lutador->setCPF(informacao[12].toInt());

            listaLutador->inserirFim(lutador);
        }
        getline(arquivo,linha);
        //break;
    }
    arquivo.close();
    arquivoErro.close();
    return listaLutador;
}

void Persistencia::gravarArquivoLutador(Lista<TP2::Lutador*> *listaLutador){
    QString nomeDoArquivo = "C:/Users/Matheus/OneDrive/Documents/ArquivosUFC/listaDeLutadores.txt";
    QString texto = "";
    TP2::Lutador *lutador;
    std::fstream arquivo;

    // abrindo o arquivo no final
    arquivo.open(nomeDoArquivo.toStdString().c_str(),std::ios::out);

    // verificando erro de abertura do arquivo de entrada
    if(!arquivo.is_open()){
        throw QString("ERRO Arquivo nao pode ser Criado");
    }

    while(!listaLutador->listaVazia()){
        lutador = listaLutador->retirarInicio();
        texto+= QString::number(lutador->getCodigo()) + ";" +lutador->getNome() + ";" + QString::number(lutador->getPeso()) + ";" + QString::number(lutador->getAltura()) + ";"
                + QString::number(lutador->getIdade()) + ";" + lutador->getNacionalidade() + ";" + QString::number(lutador->getVitorias()) + ";" + QString::number(lutador->getDerrotas()) +";"+ QString::number(lutador->getEmpates()) + ";"+ (lutador->getCategoria()) + ";"+ (lutador->getDataNascimento()) + ";"+ QString::number(lutador->getCadastro()) + ";" + QString::number(lutador->getCPF()) +"\n";
    }
    arquivo<<texto.toStdString().c_str();
    arquivo.close();
}

void Persistencia::gravaArquivoListaLutasEvento(Lista<TP2::Evento*> *eventos){
    QString nomeDoArquivo = "";
    QString texto = "";
    TP2::Luta *luta;
    ED1::Lista<TP2::Luta*> *lutas;
    std::fstream arquivo;
    int cont = 0;
    while(cont != eventos->getQuantidadeDeElementos()){
        texto = "";
        nomeDoArquivo = "C:/Users/Matheus/OneDrive/Documents/ArquivosUFC/" + (eventos->operator [](cont))->getNome() + "Lutas.txt";

        lutas = (eventos->operator [](cont))->getListaLutas();

        // abrindo o arquivo no final
        arquivo.open(nomeDoArquivo.toStdString().c_str(),std::ios::out);

        // verificando erro de abertura do arquivo de entrada
        if(!arquivo.is_open()){
            throw QString("ERRO Arquivo nao pode ser Criado");
        }


        while(lutas->getQuantidadeDeElementos() != 0){
            luta = lutas->retirarInicio();
            texto += (luta->getLutador1())->getNome() + ";" + (luta->getLutador2())->getNome() + ";" + QString::number(luta->getRounds()) + ";" + luta->getStatus() +";"+ luta->getResultado() +"\n";
        }
        arquivo<<texto.toStdString().c_str();
        arquivo.close();
        cont++;
    }

}

void Persistencia::gravaArquivoListaEventos(Lista<TP2::Evento*> *eventos){
    QString nomeDoArquivo = "";
    QString texto = "";
    TP2::Evento *evento;
    std::fstream arquivo;
    int cont = 0;

    nomeDoArquivo = "C:/Users/Matheus/OneDrive/Documents/ArquivosUFC/listaDeEventos.txt";

    // abrindo o arquivo no final
    arquivo.open(nomeDoArquivo.toStdString().c_str(),std::ios::out);

    // verificando erro de abertura do arquivo de entrada
    if(!arquivo.is_open()){
        throw QString("ERRO Arquivo nao pode ser Criado");
    }

    while(!eventos->listaVazia()){

        evento = eventos->retirarInicio();
        texto += evento->getNome() + ";" + evento->getLocal() + ";" + QString::number(evento->getDia()) + ";" + QString::number(evento->getMes()) +";"+ QString::number(evento->getAno()) +";"+
                QString::number(evento->getHora())+";"+ QString::number(evento->getMinutos()) +";"+ QString::number(evento->getQuantidadeDeLutas()) + ";"+(evento->getSituacao()) +"\n";

    }

    arquivo<<texto.toStdString().c_str();
    arquivo.close();
    cont++;
}

Lista<TP2::Evento*>* Persistencia::inclusaoFimEventos(Lista<TP2::Lutador*> *listaLutador){
    linha = "";
    linhaAux = "";
    TP2::Evento *evento = 0;
    Lista<TP2::Evento*> *listaEventos = 0;
    QString nomeDoArquivoEventos = "C:/Users/Matheus/OneDrive/Documents/ArquivosUFC/listaDeEventos.txt";
    std::ifstream arquivoEventos;
    QStringList informacao;
    std::ofstream arquivoErroEventos;

    // abrindo um arquivo de entrada
    arquivoEventos.open(nomeDoArquivoEventos.toStdString().c_str());

    // verificando erro de abertura do arquivo de entrada
    if(!arquivoEventos.is_open()){
        throw QString("ERRO Arquivo nao pode ser aberto");
    }
    try{
        listaEventos = new Lista<TP2::Evento*>();
    }catch(std::bad_alloc){
       throw QString("falta espaço na memória");
    }
    getline(arquivoEventos,linha);

    arquivoErroEventos.open("Erro.csv", std::fstream::out);

    while(!arquivoEventos.eof()){

        try{
           evento = new TP2::Evento();
        }catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }

        //if(linha == "") throw QString("Arquivo Vazio");

        linhaAux = QString::fromStdString(linha);

        informacao = linhaAux.split(';');

        if(informacao.size() != 9){

            arquivoErroEventos<<linha<<std::endl;

        }else{
            evento->setNome(informacao[0]);
            evento->setLocal(informacao[1]);
            evento->setDia(informacao[2].toInt());
            evento->setMes(informacao[3].toInt());
            evento->setAno(informacao[4].toInt());
            evento->setHora(informacao[5].toInt());
            evento->setMinutos(informacao[6].toInt());
            evento->setQuantidadeDeLutas(informacao[7].toInt());
            evento->setSituacao(informacao[8]);

            evento->setListaLutas(inclusaoFimLutas(evento, listaLutador));

            listaEventos->inserirFim(evento);
        }
        getline(arquivoEventos,linha);
        //break;
    }
    arquivoEventos.close();
    arquivoErroEventos.close();
    return listaEventos;
}

Lista<TP2::Luta*>* Persistencia::inclusaoFimLutas(TP2::Evento *evento, Lista<TP2::Lutador*> *listaLutador){
    linha = "";
    linhaAux = "";
    TP2::Luta *lutas = 0;
    Lista<TP2::Luta*> *listaLutas = 0;
    QString nomeDoArquivoLutas = "C:/Users/Matheus/OneDrive/Documents/ArquivosUFC/" + evento->getNome() + "Lutas.txt";
    std::ifstream arquivoLutas;
    QStringList informacao;
    std::ofstream arquivoErroLutas;
    int aux = 0;

    // abrindo um arquivo de entrada
    arquivoLutas.open(nomeDoArquivoLutas.toStdString().c_str());

    // verificando erro de abertura do arquivo de entrada
    if(!arquivoLutas.is_open()){
        throw QString("ERRO Arquivo nao pode ser aberto");
    }
    try{
        listaLutas = new Lista<TP2::Luta*>();
    }catch(std::bad_alloc){
       throw QString("falta espaço na memória");
    }
    getline(arquivoLutas,linha);

    arquivoErroLutas.open("Erro.csv", std::fstream::out);

    while(!arquivoLutas.eof()){

        try{
           lutas = new TP2::Luta();
        }catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }

        //if(linha == "") throw QString("Arquivo Vazio");

        linhaAux = QString::fromStdString(linha);

        informacao = linhaAux.split(';');

        if(informacao.size() != 5){

            arquivoErroLutas<<linha<<std::endl;

        }else{

            while(aux != listaLutador->getQuantidadeDeElementos()){
                if(informacao[0] == (listaLutador->operator [](aux))->getNome()){
                    lutas->setLutador1(listaLutador->operator [](aux));
                }
                if(informacao[1] == (listaLutador->operator [](aux))->getNome()){
                    lutas->setLutador2(listaLutador->operator [](aux));
                }
                aux++;
            }
            lutas->setRounds(informacao[2].toInt());
            lutas->setStatus(informacao[3]);
            lutas->setResultado(informacao[4]);

            listaLutas->inserirFim(lutas);
        }
        getline(arquivoLutas,linha);
        aux = 0;
        //break;
    }
    arquivoLutas.close();
    arquivoErroLutas.close();
    return listaLutas;
}

void Persistencia::gravarArquivoCliente(Lista<TP2::Cliente*> *listaCliente){
    QString nomeDoArquivo = "C:/Users/Matheus/OneDrive/Documents/ArquivosUFC/listaDeClientes.txt";
    QString texto = "";
    TP2::Cliente *cliente;
    std::fstream arquivo;

    // abrindo o arquivo no final
    arquivo.open(nomeDoArquivo.toStdString().c_str(),std::ios::out);

    // verificando erro de abertura do arquivo de entrada
    if(!arquivo.is_open()){
        throw QString("ERRO Arquivo nao pode ser Criado");
    }

    while(!listaCliente->listaVazia()){
        cliente = listaCliente->retirarInicio();
        texto+= QString::number(cliente->getCodigo()) + ";" +cliente->getNome() + ";" + QString::number(cliente->getSaldo()) + ";" + QString::number(cliente->getLimApostas()) + ";"
                + QString::number(cliente->getIdade()) + ";" + QString::number(cliente->getRendaMensal()) + ";"+ (cliente->getDataDeCadastro()) + ";"+ (cliente->getDataNascimento()) + ";" + QString::number(cliente->getCPF()) +"\n";
    }
    arquivo<<texto.toStdString().c_str();
    arquivo.close();
}

Lista<TP2::Cliente*>* Persistencia::inclusaoFimClientes(){
    linha = "";
    linhaAux = "";
    TP2::Cliente *cliente = 0;
    Lista<TP2::Cliente*> *listaCliente = 0;
    QString nomeDoArquivo = "C:/Users/Matheus/OneDrive/Documents/ArquivosUFC/listaDeClientes.txt";
    std::ifstream arquivo;
    QStringList informacao;

    // abrindo um arquivo de entrada
    arquivo.open(nomeDoArquivo.toStdString().c_str());

    // verificando erro de abertura do arquivo de entrada
    if(!arquivo.is_open()){
        throw QString("ERRO Arquivo nao pode ser aberto");
    }
    try{
        listaCliente = new Lista<TP2::Cliente*>();
    }catch(std::bad_alloc){
       throw QString("falta espaço na memória");
    }
    getline(arquivo,linha);

    std::ofstream arquivoErro;
    arquivoErro.open("Erro.csv", std::fstream::out);

    while(!arquivo.eof()){

        try{
           cliente = new TP2::Cliente();
        }catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }

        //if(linha == "") throw QString("Arquivo Vazio");

        linhaAux = QString::fromStdString(linha);

        informacao = linhaAux.split(';');

        if(informacao.size() != 9){

            arquivoErro<<linha<<std::endl;

        }else{
            cliente->setCodigo(informacao[0].toInt());
            cliente->setNome(informacao[1]);
            cliente->setSaldo(informacao[2].toFloat());
            cliente->setLimApostas(informacao[3].toFloat());
            cliente->setIdade(informacao[4].toInt());
            cliente->setRendaMensal(informacao[5].toFloat());
            cliente->setDataDeCadastro(informacao[6]);
            cliente->setDataNascimento(informacao[7]);
            cliente->setCPF(informacao[8].toInt());

            listaCliente->inserirFim(cliente);
        }
        getline(arquivo,linha);
        //break;
    }
    arquivo.close();
    arquivoErro.close();
    return listaCliente;
}

/*Lista<TP2::Aposta>* Persistencia::inclusaoFimApostas(TP2::Cliente *cliente, Lista<TP2::Evento*>* listaEvento){
    linha = "";
    linhaAux = "";
    TP2::Aposta apostas;
    Lista<TP2::Aposta> *listaApostas = 0;
    QString nomeDoArquivoApostas = "C:/Users/Matheus/OneDrive/Documents/ArquivosUFC/" + cliente->getNome() + "Apostas.txt";
    std::ifstream arquivoApostas;
    QStringList informacao;
    std::ofstream arquivoErroApostas;
    Lista<TP2::Luta*>* listaAux = 0;

    // abrindo um arquivo de entrada
    arquivoApostas.open(nomeDoArquivoApostas.toStdString().c_str());

    // verificando erro de abertura do arquivo de entrada
    if(!arquivoApostas.is_open()){
        throw QString("ERRO Arquivo nao pode ser aberto");
    }
    try{
        listaApostas = new Lista<TP2::Aposta>();
    }catch(std::bad_alloc){
       throw QString("falta espaço na memória");
    }
    getline(arquivoApostas,linha);

    arquivoErroApostas.open("Erro.csv", std::fstream::out);

    while(!arquivoApostas.eof()){

       /* try{
           apostas = new TP2::Aposta();
        }catch(std::bad_alloc){
           throw QString("falta espaço na memória");
        }*/

        //if(linha == "") throw QString("Arquivo Vazio");

       /* linhaAux = QString::fromStdString(linha);

        informacao = linhaAux.split(';');

        if(informacao.size() != 6){

            arquivoErroApostas<<linha<<std::endl;

        }else{
            for(int i = 0; i < listaEvento->getQuantidadeDeElementos();i++){
                listaAux = (listaEvento->operator [](i))->getListaLutas();
                for(int j = 0; j < listaAux->getQuantidadeDeElementos();j++){
                    if((informacao[0] == (listaAux->operator [](j))->getLutador1()->getNome()) && (informacao[1] == (listaAux->operator [](j))->getLutador2()->getNome())){
                        apostas.setLuta(listaAux->operator [](j));
                        listaAux = 0;
                        break;
                    }
                    if(listaAux == 0){
                        break;
                    }
                }
            }
            apostas.setVencedor(informacao[2]);
            apostas.setDataAposta(informacao[3]);
            apostas.setAposta(informacao[4].toFloat());
            apostas.setCliente(informacao[5]);

            listaApostas->inserirFim(apostas);
        }
        getline(arquivoApostas,linha);
        //break;
    }
    arquivoApostas.close();
    arquivoErroApostas.close();
    return listaApostas;
}*/

/*void Persistencia::gravaArquivoListaApostaCliente(Lista<TP2::Cliente*> *Clientes){
    QString nomeDoArquivo = "";
    QString texto = "";
    TP2::Aposta aposta;
    ED1::Lista<TP2::Aposta> *ListaAposta;
    std::fstream arquivo;
    int cont = 0;
    while(cont != Clientes->getQuantidadeDeElementos()){
        nomeDoArquivo = "C:/Users/Matheus/OneDrive/Documents/ArquivosUFC/" + (Clientes->operator [](cont))->getNome() + "Aposta.txt";

        ListaAposta = (Clientes->operator [](cont))->getListaAposta();

        // abrindo o arquivo no final
        arquivo.open(nomeDoArquivo.toStdString().c_str(),std::ios::out);

        // verificando erro de abertura do arquivo de entrada
        if(!arquivo.is_open()){
            throw QString("ERRO Arquivo nao pode ser Criado");
        }


        while(ListaAposta->getQuantidadeDeElementos() != 0){
            aposta = ListaAposta->retirarInicio();
            texto += (aposta.getLuta())->getLutador1()->getNome() + ";" + (aposta.getLuta())->getLutador2()->getNome() + ";" + aposta.getVencedor() + ";" + aposta.getDataAposta() +";"+ QString::number(aposta.getAposta())+";"+ aposta.getCliente() +"\n";
        }
        arquivo<<texto.toStdString().c_str();
        arquivo.close();
        cont++;
    }

}*/

Persistencia::~Persistencia(){
}

}


