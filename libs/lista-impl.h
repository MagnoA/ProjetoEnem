//#ifndef LISTA2_IMPL_H
#define	LISTA2_IMPL_H

#include "lista.h"
#include <iostream>
#include <time.h>
using namespace std;
namespace prglib {


template <typename T> lista<T>::lista() {
    primeiro = nullptr;
    ultimo = nullptr;
    len = 0;
}

template <typename T> lista<T>::lista(const lista<T> & outra) {
}

template <typename T> lista<T>::~lista() {
}

template <typename T> void lista<T>::insere(const T& algo) { 
    if(len>0){
	  Nodo *nodo = new Nodo(algo);
	  nodo->proximo = primeiro;
          primeiro->anterior = nodo;
	  primeiro = nodo;
	  len++;
    }
    else{
	  Nodo *nodo = new Nodo(algo);
	  primeiro = nodo;
	  ultimo = nodo;
	  len++;
    }
}

template <typename T> void lista<T>::anexa(const T& algo) {
    Nodo* nodo = new Nodo(algo);
    if(len == 0){
       primeiro = nodo;
       ultimo = nodo;
    }else{
        ultimo->proximo = nodo;
        nodo->anterior = ultimo;
    }
    
    ultimo = nodo;
    len++;
}

template <typename T> int lista<T>::comprimento() const {
    return len;
}

template <typename T> void lista<T>::esvazia() {
    primeiro = nullptr;
    ultimo = nullptr;
    len = 0;
}

template <typename T> void lista<T>::insere(const T& algo, int posicao) {
    if(posicao>len) throw "Posição superior ao permitido";
    
    if(posicao==0)
    insere(algo);

    if(posicao == len)
    anexa(algo);
    else{


    Nodo *aux, *temp, * nodo = new Nodo(algo);
    aux = primeiro;
    for(int i=0; i < posicao; i++){
    temp = aux;
    aux = aux->proximo;
    }

    temp->proximo = nodo;
    nodo->anterior = temp;
    nodo->proximo = aux;
    aux->anterior = nodo;
    len++;
    }
    
}

template <typename T> T& lista<T>::obtem(int posicao) const {
 if(len <= posicao) throw "Posição inválida";
    Nodo *aux = primeiro;
    for(int pos = 0; pos < posicao; pos++)
        aux = aux->proximo;
    return aux->dado;
}

template <typename T> T& lista<T>::operator[](int pos) const {
    return obtem(pos);
}

template <typename T> void lista<T>::escrevaSe(std::ostream& out) const {
    Nodo *aux, *temp;
    aux = primeiro;
    int pos = 0;
    while(pos < len){
	temp = aux;
	out << temp->dado << endl;
	aux = aux->proximo;
	pos++;
    }
}

template <typename T> void lista<T>::escrevaSe(std::ostream& out, const std::string & delim) const {
    Nodo *aux, *temp;
    aux = primeiro;
    int pos = 0;
    while(pos < len){
	temp = aux;
        if(temp == ultimo){
            out << temp->dado;
            break;
        }
	out << temp->dado << delim;
	aux = aux->proximo;
	pos++;
    }
}

template <typename T> T lista<T>::remove(int posicao) {
  
    if(len < posicao) throw "Posição Inválida";
    if(posicao == 0){
        T algo = primeiro->dado;
        primeiro = primeiro->proximo;
        len--;
        return algo;
    }
    Nodo* deletar;
    Nodo* sucessor = primeiro;
    for(int pos = 0; pos < posicao; pos++){
        deletar = sucessor;
        sucessor = sucessor->proximo;
    }
    T algo = sucessor->dado;
    if(sucessor == ultimo){
        ultimo = deletar;
        deletar->proximo = nullptr;
        ultimo->proximo = nullptr;
        len--;
    }else{
    deletar->proximo = sucessor->proximo;
    sucessor->proximo->anterior = deletar;
    len--;
    }
    return algo;
}

template <typename T> void lista<T>::retira(const T& algo) {
    for(int i = 0; i<len; i++){
        if(obtem(i) == algo){
            remove(i);
            i--;
        }
    }
}

template <typename T> bool lista<T>::vazia() const {
    return len == 0;
}

template <typename T> void lista<T>::insereOrdenado(const T & algo) {
}

template <typename T> void lista<T>::ordenaBolha() {

    Nodo *aux, *aux2, *aux3;
    T mostra;
    for(aux3 = ultimo;aux3!=primeiro;aux3=aux3->anterior){
        aux=primeiro;
        aux2=aux->proximo;
    
    for(aux2;aux2!=ultimo;aux2=aux2->proximo){
        if(aux2->dado<aux->dado){
            mostra=aux->dado;
            aux->dado=aux2->dado;
            aux2->dado=mostra;
	}
    aux=aux->proximo;
    }
    }
}

template <typename T> void lista<T>::SelectionSort(){
    /* for (j=0; j < 4; j++) {
    int menor = j;
    for (k=j+1; k < 5; k++) {
      if (v[menor] > v[k]) menor = k;
    }*  /
    if (menor != j) {
      string aux = v[j];
      v[j] = v[menor];
      v[menor] = aux;
    }
  }
    Nodo* aux = inicio;
    Nodo* aux2 = ultimo;
    for(aux; aux != ultimo; aux =  aux->proximo){
        for(aux2; aux2 != ultimo; aux2->proximo){
            if(aux2->dado < aux->dado) aux = aux2;
        }
     //   if()
    }*/
}

template <typename T> void lista<T>::merge(Nodo * n1, Nodo * n2, int n){
    int meio = n/2;
   
    Nodo *aux = n1, *aux2;
    int k = 0;

    if(meio == 0) return;
    while(k < meio-1){
        aux = aux->proximo;
        k++;
    }
    
    merge(n1,  aux, meio);
    aux2 = aux->proximo;
    merge(aux2, n2, n-meio);
    
    lista<T> l;
    
    int i = 0, j = meio;
    
    aux = n1;
    for(i, j; i<meio and j < n;){
        if(aux->dado > aux2->dado){
            l.anexa(aux2->dado);
            aux2 = aux2->proximo;
            j++;
        }else{
            l.anexa(aux->dado);
            aux= aux->proximo;
            i++;
        }
        
    }

    for( ; i < meio; aux = aux->proximo, i++) l.anexa(aux->dado);
    for( ; j < n; aux2 = aux2->proximo, j++) l.anexa(aux2->dado);

    l.inicia();
    while(not l.fim()) {
        n1->dado = l.proximo();
        n1 = n1->proximo;
    }
        
}

template <typename T> void lista<T>::ordena(){
  if (len < 2) return;
  merge(primeiro, ultimo, len);   
}

template <typename T> T& lista<T>::procura(const T& algo) const {
    	Nodo * aux;
	lista<T> * iguais = new lista<T>;
	for (aux=inicio; aux != NULL; aux=aux->proximo) {
		if(algo==aux->dado){
			iguais->anexa(aux->dado);
		}
	}
	return iguais;
}

template <typename T> lista<T>& lista<T>::procuraMuitos(const T& algo, lista<T>& outra) const {
}

template <typename T> std::shared_ptr<lista<T>> lista<T>::procuraMuitos(const T& algo) const {
}

template <typename T> lista<T>& lista<T>::operator=(const lista<T>& outra) {
    primeiro = ultimo = nullptr;

    Nodo* aux = outra.primeiro;
    while(aux){
    anexa(aux->dado);
    aux = aux->proximo;
    }
}

template <typename T> bool lista<T>::operator==(const lista<T>& outra) const {
}

template <typename T> void lista<T>::inverte() {
    lista<T> aux;
    inicia();
    while(not fim()){
     aux.insere(proximo());   
    }
    esvazia();
    aux.inicia();
    while(not aux.fim()){
    anexa(aux.proximo());   
    }
}

template <typename T> bool lista<T>::inicio() const {
    return atual == nullptr;
}

template <typename T> bool lista<T>::fim() const {
   return atual == nullptr;
}

template <typename T> void lista<T>::inicia() {
    if(vazia()) throw "Erro: lista vazia";
    atual = primeiro;
}

template <typename T> void lista<T>::iniciaPeloFim() {
    atual = ultimo;
    interador = true;
}

template <typename T> T& lista<T>::proximo() {
    T *algo;
    if(atual == nullptr) throw "Erro na interação";
    algo = &(atual->dado);
    atual = atual->proximo;
    return *algo;
}

template <typename T> T& lista<T>::anterior() {
    if(not interador) throw "erro na interação";
    T *algo;
    if(atual == nullptr) throw "Erro";
    algo = &(atual->dado);
    atual = atual->anterior;
    if(atual == primeiro->anterior) interador = false;
    return *algo;
}

template <typename T> lista<T>& lista<T>::sublista(unsigned int pos1, unsigned int pos2, lista<T> & outra) const {   
}

template <typename T> lista<T>* lista<T>::sublista(unsigned int pos1, unsigned int pos2) const {   
}

template <class T> void lista<T>::embaralha() {
   /* int n = len;
    while(n > 0){
        anexa(remove(rand() % n));
        n--;
    }*/
   
   int meio = len/2, k=0;
   Nodo *aux = primeiro, *aux2;
    while(k < meio-1){
        aux = aux->proximo;
        k++;
    }
    aux2 = aux->proximo;
    aux = primeiro;
    int i=0, j=len-meio;
    for(i, j; i<meio and j < len;){
        if(rand()%len < 5){
            T algo = aux2->dado; 
            aux2->dado = aux->dado;
            aux->dado = algo;
            aux2 = aux2->proximo;
            j++;
        }else{
            T algo = aux->dado;
            aux->dado = aux2->dado;
            aux2->dado = algo;
            aux= aux->proximo;
            i++;
        }
        
    }

 /*   for( ; i < meio; aux = aux->proximo, i++){
        if(rand()%len < 9){
            T algo = aux->anterior->dado;
            aux->anterior->dado = aux->dado;
            aux->dado = algo;
        }
    }
  for( ; j < len; aux2 = aux2->proximo, j++)
      if(rand()%len < 7){
            T algo = aux2->anterior->dado;
            aux2->anterior->dado = aux2->dado;
            aux2->dado = algo;
      }*/
}

template <typename T> void lista<T>::uniq() {
if(len > 0){
    inicia();
    while(not fim()){
        T mostra = proximo();
        retira(mostra);
        insere(mostra);
    }
} 
}
  
  
} // fim namespace