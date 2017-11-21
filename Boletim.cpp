#include "Boletim.h"
#include <cstdlib>
#include <prglib.h>
#include <iostream>
#include <string>
#include <fstream>


static lista<Resultado> Lista;

using namespace std;
 using prglib::lista;
 
lista<Resultado> carregaBoletim(const string & path) {
    lista<Resultado> Lista;
    string linha;

    ifstream arq;
    arq.open(path);
    
    while(not arq.eof()){
    
    getline(arq,linha);
        try{
            Resultado Enem (linha);
            Lista.anexa(Enem);
        } catch (...){
        }
    }
    return Lista;
}
void MostraResultado(const Resultado & R){
    cout << "Escola: " << R.Escola << endl;
    cout << "Estado: " << R.Estado << endl;
    cout << "Cidade: " << R.Cidade << endl;
    cout << "Média Geral: " << R.MedGeral << endl;
    cout << "Média Línguas: " << R.ling << endl;
    cout << "Média Matemática: " << R.mtm << endl;
    cout << "Média Ciências da Natureza: " << R.cn << endl;
    cout << "Média Ciências Humanas: " << R.ch << endl;
    cout << "Média Redação: " << R.red << endl << endl;
}
// Mostra as notas de uma Determinada Escola
void ResultadoEscolaNome(const string & nomeEscola,lista<Resultado> & Lista ){   
    Lista.inicia();
    // Proucura a Escola dentro da Lista
    while(not Lista.fim()){
        Resultado aux(Lista.proximo());
        
        //Mostra as medias, quando encontrado a Escola
        if(aux.Escola == nomeEscola){
            MostraResultado(aux);
            /* 
            cout << "Media Geral: " << aux.MedGeral << endl;
            cout << "Media Ciencias Humanas: " << aux.ch << endl;
            cout << "Media Ciencias da Natureza: " << aux.cn << endl;
            cout << "Media Linguas: " << aux.ling << endl;
            cout << "Media Matematica: " << aux.mtm << endl;
            cout << "Media Redação: " << aux.red << endl;*/
            break;
        }
    }
    
}

void ResultadoCidadeEstado(const string & nomeCidade,const string & nomeEstado,lista<Resultado> & Lista){
    lista<Resultado> porEstado;
    lista<Resultado> porCidade;

    Lista.inicia();
    while(not Lista.fim()){
        Resultado aux(Lista.proximo());
        if(aux.Estado == nomeEstado){
            porEstado.anexa(aux);
        }
    }
    
    porEstado.inicia();
    while(not porEstado.fim()){
        Resultado aux(porEstado.proximo());
        if(aux.Cidade == nomeCidade){
         porCidade.anexa(aux);   
        }
    }
    
    porCidade.inicia();
    while(not porCidade.fim()){    
        Resultado aux(porCidade.proximo());
        cout << "Nome Escola: " << aux.Escola << endl;
        cout << "Estado: " << aux.Estado << endl;
        cout << "Cidade: " << aux.Cidade << endl;
        cout << "Media Geral: " << aux.MedGeral << endl;
        cout << "Media Linguas: " << aux.ling << endl;
        cout << "Media Matematica: " << aux.mtm << endl;
        cout << "Meida Ciencias Naturais: " << aux.cn << endl;
        cout << "Media Ciencias Humanas: " << aux.ch << endl;
        cout << "Media Redação: " << aux.red << endl << endl;
    }
}

void MediaGeralCidadeEstado(const string & nomeCidade,const string & nomeEstado, lista<Resultado> & Lista){
    lista<Resultado> porEstado;
    lista<Resultado> porCidade;
    lista<float> MedGeral;
    float soma = 0;
    int tamanho;

    Lista.inicia();
    while(not Lista.fim()){
        Resultado aux(Lista.proximo());
        if(aux.Estado == nomeEstado){
            porEstado.anexa(aux);
        }
    }
    
    porEstado.inicia();
    while(not porEstado.fim()){
        Resultado aux(porEstado.proximo());
        if(aux.Cidade == nomeCidade){
         porCidade.anexa(aux);   
        }
    }
    
    tamanho = porCidade.comprimento();
    porCidade.inicia();
    while(not porCidade.fim()){    
        Resultado aux(porCidade.proximo());
        cout << aux.Escola <<": " << aux.MedGeral << endl;
        soma = soma + aux.MedGeral;
    }
    float media = soma/tamanho;
    
    cout.precision(5);
    cout << endl << "Média Geral de " << nomeCidade << "/"
            << nomeEstado << ": " << media << endl;
}

void MaioresNotasDecrescentes(int quantidade, lista<Resultado> & Lista){
    Lista.ordena();
    Lista.inverte();
    Lista.inicia();
    int n = 0;
    while(n<quantidade){
        Resultado aux(Lista.proximo());
        cout << aux.Escola << ": " << aux.MedGeral << endl;
        n++;
    }

}

void MenoresNotasCrescentes(int quantidade, lista<Resultado> & Lista){
    Lista.ordena();
    Lista.inicia();
    int n = 0;
    while(n<quantidade){
        Resultado aux(Lista.proximo());
        cout << aux.Escola << ": " << aux.MedGeral << endl;
        n++;
    }

}
