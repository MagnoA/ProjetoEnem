/* 
 * File:   pilha-impl.h
 * Author: msobral
 *
 * Created on 11 de Agosto de 2016, 13:59
 */

#ifndef PILHA_IMPL_H
#define	PILHA_IMPL_H

#include "pilha.h"
#include <iostream>
using namespace std;
namespace prglib {
    
template <typename T> pilha<T>::pilha(unsigned int umaCapacidade) {
  topo = 0;
  capacidad = umaCapacidade;

  buffer = new T[capacidad];
}
 
template <typename T> pilha<T>::pilha(const pilha& outra) {
    capacidad = 0;
    *this = outra;
}
 
template <typename T> pilha<T>::~pilha() {
     delete[] buffer;
}

template <typename T> pilha<T> & pilha<T>::operator=(const pilha<T> & outra) {
  topo = outra.topo;
  if (capacidad) delete[] buffer;
  capacidad = outra.capacidad;
   
 
  buffer = new T[capacidad];

 int novo = 0;
 while( novo <= topo){
	buffer[novo] = outra.buffer[novo];
	novo++;
  }
}
 
template <typename T> void pilha<T>::esvazia() {
    topo = 0;
}
 
template <typename T> void pilha<T>::push(const T & dado) {
  if( cheia() ) throw "Pilha Cheia!";
  buffer[topo] = dado;
  topo++;
  //aux=topo -1;
}
 
template <typename T> T pilha<T>::pop() {
    if(vazia()) throw "Pilha vazia!";
  T mostra;
  mostra = buffer[topo-1];
  topo -= 1;
  //aux--;
  return mostra;
}
 
template <typename T> const T& pilha<T>::top() const{
    if(not vazia())
    return buffer[topo-1];
    throw "Pilha Vazia!";
}

template <typename T> unsigned int pilha<T>::capacidade() const {
    return capacidad;
}

template <typename T> bool pilha<T>::cheia() const {
    return topo == capacidad;
}

template <typename T> bool pilha<T>::vazia() const {
    return topo == 0;
}

template <typename T> unsigned int pilha<T>::comprimento() const {
    return topo;
}

}

#endif	/* PILHA_IMPL_H */

