/* 
 * File:   fila-imp.h
 * Author: msobral
 *
 * Created on 11 de Agosto de 2016, 13:59
 */

#ifndef FILA_IMP_H
#define	FILA_IMP_H
#include <iostream>

#include "fila.h"

using namespace std;
namespace prglib {
    
template <typename T> fila<T>::fila(unsigned int N) {
    // inicia os atributos da fila: inicialmente
    // ela está vazia

    cap = N;
    inicio = 0;
    fim = 0;
    itens = 0;
 
    // aloca memória para guardar "capacidade" dados do tipo "T"
    buffer = new T[cap];

}

template <typename T> fila<T>::fila(const fila& outra) {
  itens = outra.itens;
  cap = outra.cap;
  inicio = outra.inicio;


  buffer = new T[cap];

  for(int j = 0; j < cap; j++){
     int pos = (outra.inicio + j) % outra.cap;
     buffer[j] = outra.buffer[pos];
  }
  fim = outra.fim;
}

template <typename T> fila<T>::~fila() {
    delete[] buffer;
}

template <typename T> fila<T>& fila<T>::operator=(const fila& outra) {
  itens = outra.itens;
  if(cap < outra.cap) cap = outra.cap;
  inicio = 0;
  fim = cap;

  delete[] buffer;

  buffer = new T[cap];

  for(int j = 0; j < cap; j++){
     int pos = (outra.inicio + j) % outra.cap;
     buffer[j] = outra.buffer[pos];
  }
  return *this;
}

template <typename T> void fila<T>::enfileira(const T& algo) {
  if(cheia()) throw "Fila cheia!";
 
  buffer[fim] = algo;
  fim = (fim + 1) % cap;
  itens++;
}

template <typename T> void fila<T>::enfileiraInicio(const T & algo) {
    if(cheia()) throw "fila cheia";
    if(inicio == 0){
        buffer[cap-1] = algo;
        inicio = cap-1;
        itens++;
    }else{
        inicio--;
        buffer[inicio] = algo;
        itens++;
    }
}


template <typename T> T fila<T>::desenfileira() {
    if (itens == 0) throw "Fila vazia";
    if(cap > 0){
    int pos = inicio;
    if(inicio == cap-1) {
        inicio = 0;
        }
    else{
        inicio++;
    } 
    itens--;

  return buffer[pos];
  }
}

template <typename T> T fila<T>::desenfileiraFim() {
    if (itens == 0) throw "Fila vazia";
    if(cap > 0){
    if(fim == 0)fim = cap-1;
    else fim--;
    itens--;

  return buffer[fim]; 
    }
}
template <typename T> const T & fila<T>::frente() const {
    if(vazia()) throw "Fila Vazia!";
    return buffer[inicio];
}

template <typename T> bool fila<T>::vazia() const {
    return itens == 0;
}

template <typename T> bool fila<T>::cheia() const {
     return itens == cap;
}

template <typename T> unsigned int fila<T>::capacidade() const {
    return cap;
}

template <typename T> unsigned int fila<T>::comprimento() const {
    return itens;
}
template <typename T> void fila<T>::esvazia(){
    itens = 0;
}

} // fim namespace

#endif	/* FILA_IMP_H */

