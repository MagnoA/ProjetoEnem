/* 
 * File:   arvore-impl.h
 * Author: sobral
 *
 * Created on 8 de Outubro de 2016, 19:37
 */

#ifndef ARVORE_IMPL_H
#define	ARVORE_IMPL_H

#include "arvore.h"
#include "lista.h"
#include "fila.h"
#include "pilha.h"
#include <iostream>
#include <math.h>
using namespace std;
namespace prglib {

template <typename T> arvore<T>::~arvore() {    
}
    
template <typename T> arvore<T>::arvore() {
}

template <typename T> arvore<T>::arvore(const T & dado) :data(dado) { 
    esq = nullptr;
    dir = nullptr;
    //data = dado;
}

//template <typename T> arvore<T>::arvore(const arvore<T> & outra) : BasicTree(outra) {}

template <typename T> void arvore<T>::adiciona(const T & algo) {
    arvore<T> *p = this;
    
    //Recursivo
    /*if(algo == data){
        data = algo;
        return;
    }
    
    if(algo < data){
        if(esq) esq->adiciona(algo);
        else esq = new arvore<T>(algo);
    }else{
        if(dir) dir->adiciona(algo);
        else dir = new arvore<T>(algo);
    }*/
    
    //Nao recursivo
    while(true){
    if(algo == p->data){ p->data = algo; break;}
    if(p->data < algo){
        if(p->dir) p = p->dir;
        else {p->dir = new arvore<T>(algo); break;}
    }else{
        if(p->esq) p = p->esq;
        else {p->esq = new arvore<T>(algo); break;}
    }
    }
          
}

template <typename T> T& arvore<T>::obtem(const T & algo) {
    arvore<T> *p = this;
    
  /*  if(p->data == algo) return p->data;
    if(p->esq == nullptr) throw -1;
    else
    if(p->data < algo) p->dir->obtem(algo);
    if(p->dir == nullptr) throw -1;
    if(p->data > algo) p->esq->obtem(algo);*/
    
    while(p != nullptr){
     if(p->data == algo) return p->data;
     if(algo < p->data) p = p->esq;
     else p = p->dir;
     }
     throw -1;
}

template <typename T> void arvore<T>::listeInOrder(lista<T> & result) {
    if(esq) esq->listeInOrder(result);
    result.anexa(data);
    if(dir) dir->listeInOrder(result);
}

template <typename T> void arvore<T>::listePreOrder(lista<T> & result) {;
    result.anexa(data);
    if(esq) esq->listePreOrder(result);
    if(dir) dir->listePreOrder(result);    
}

template <typename T> void arvore<T>::listePostOrder(lista<T> & result) {
    if(esq) esq->listePostOrder(result);
    if(dir) dir->listePostOrder(result);
    result.anexa(data);
}
template <typename T> void arvore<T>::listeEmLargura(lista<T> & result){    
    arvore<T> *arv;
    lista<arvore<T>*> l;
    l.anexa(this);
    
    while(not l.vazia()){
        arv = l.remove(0);
        result.anexa(arv->data);
        if(arv->esq) l.anexa(arv->esq);
        if(arv->dir) l.anexa(arv->dir);
    }
}
template <typename T> unsigned int arvore<T>::tamanho() const {
    int tam = 0;
    if(esq) tam = tam + esq->tamanho();
    if(dir) tam = tam + dir->tamanho();
    return ++tam;
}

template <typename T> int arvore<T>::fatorB()  {
    int he = 0, hd= 0, fb = 0;
    if(not dir and not esq) return 0;
    if(esq) he = 1 + esq->altura();
    if(dir) hd = 1 + dir->altura();
    return fb = he-hd;
}

template <typename T> unsigned int arvore<T>::altura()  {
    int R = 0, L = 0, H = 0;
    if(not dir and not esq) return 0;
    if(dir) R = dir->altura();
    if(esq) L = esq->altura();
    
    if(R < L){
        H = L + 1;
    }else{
        H = R + 1;
    
}

    return H;
}

template <typename T> arvore<T>* arvore<T>::balanceia() {
    arvore<T> * arv = this;
    int fb;
    
    if(esq) esq = esq->balanceia();
    if(dir) dir = dir->balanceia();
    
    fb = arv->fatorB();

    while(fb < -1){
        if(arv->dir->fatorB() > 0){
            arv->dir = arv->dir->rotacionaR();
        }
        arv = arv->rotacionaL();
        fb = arv->fatorB();
    }
    
    while(fb > 1){
        if(arv->esq->fatorB() < 0){
            arv->esq = arv->esq->rotacionaL();
        }
        arv = arv->rotacionaR();
        fb = arv->fatorB();
    }
    
    return arv;
}

template <typename T> arvore<T>* arvore<T>::balanceia(bool otimo) {
    arvore<T> *arv = this;

    int h1 = arv->altura();
    arv = arv->balanceia();
    while(h1 > arv->altura()){
        h1 = arv->altura();
        arv = arv->balanceia();
    }
 
    return arv;
}
template <typename T> void arvore<T>::iniciaPeloFim() {
    if(p_stack) delete p_stack;
    p_stack = new pilha<arvore<T>*>(altura()+1);
  
    arvore<T> *arv = this;

    while(arv != nullptr) {
        p_stack->push(arv);
        arv= arv->dir;
    }
}

template <typename T> T& arvore<T>::anterior() {
    if(p_stack == nullptr) throw "Interação inválida";
    
    arvore<T> * arv = p_stack->pop();
    T& algo = arv->data;
    if(arv->esq){
        p_stack->push(arv->esq);
        arv = arv->esq;
        while(arv->dir){
            p_stack->push(arv->dir);
            arv = arv->dir;     
        } 
    }

    if(p_stack->vazia()) p_stack = nullptr;
    return algo;
}
template <typename T> void arvore<T>::inicia() {
    if(p_stack) delete p_stack;
    p_stack = new pilha<arvore<T>*>(altura()+1);
  
    arvore<T> *arv = this;

    while(arv != nullptr) {
        p_stack->push(arv);
        arv= arv->esq;
    }

}

template <typename T> T& arvore<T>::proximo() {
    if(p_stack == nullptr) throw "Interação inválida";
    
    arvore<T> * arv = p_stack->pop();
    T& algo = arv->data;
    if(arv->dir){
        p_stack->push(arv->dir);
        arv = arv->dir;
        while(arv->esq){
            p_stack->push(arv->esq);
            arv = arv->esq;     
        } 
    }

    if(p_stack->vazia()) p_stack = nullptr;
    return algo;
}

template <typename T> bool arvore<T>::fim() {
    return p_stack == nullptr;
}

template <typename T> bool arvore<T>::inicio() {
    return p_stack == nullptr;
}
template <typename T> T& arvore<T>::obtemMenor() const{
}

template <typename T> T& arvore<T>::obtemMaior() const{
}

template <typename T> void arvore<T>::obtemMenoresQue(lista<T> & result, const T & algo) {
}

template <typename T> void arvore<T>::obtemMaioresQue(lista<T> & result, const T & algo) {
    arvore<T> *arv = this;
    arv->inicia();
    while(not arv->fim()){
        T dado  = arv->proximo();
        
        if(dado > algo) result.anexa(dado); 
    }
}

template <typename T> void arvore<T>::obtemIntervalo(lista<T>& result, const T& start, const T& end) {

}
template <typename T> arvore<T>* arvore<T>::rotacionaL(){
    arvore<T> * arv = this, *aux, *aux2;
    aux = arv->dir;
    aux2 = aux->esq;
    arv->dir = aux2;
    aux->esq = arv;
     
    return aux;
}
template <typename T> arvore<T>* arvore<T>::rotacionaR(){
    arvore<T> * arv = this, *aux, *aux2;
    aux = arv->esq;
    aux2 = aux->dir;
    arv->esq = aux2;
    aux->dir = arv;
     
    return aux;
}
template <typename T> void arvore<T>::escrevaSe(ostream& out) const {
    static int nivel = -1;
    string prefixo;
 
    nivel++;
    prefixo.append(nivel, ' ');
 
    if (dir) dir->escrevaSe(out);
    out << prefixo << data << endl;
    if (esq) esq->escrevaSe(out);
    nivel--;
}

template <typename T> arvore<T>* arvore<T>::obtemMaioresQue(const T & algo){
 /*   arvore<T> *arv = this;
    lista<arvore<T>*> l;
    lista<T> l1;
    arv= arv->balanceia();
    
    if(arv->data < algo){
    while(arv->dir){      
        if(arv->data < algo){
            arv = arv->dir;
        }
        else{
            if(arv->dir){
                l.insere(arv->dir);
                arv = arv->dir;
                cout << arv->data << endl;
                break;
            }
            else throw "erro";
        }
    }
    }

    while(arv->esq){
        if(algo < arv->data){
        l.insere(arv);
        arv = arv->esq;
        break;
        }
    }

    cout << arv->data << endl;
    if(arv->dir != nullptr and arv->dir->data > algo)
        arv->dir->listePreOrder(l1);

    while(not l.vazia()){
        arvore<T> *arv2 = l.remove(0);
       // cout << arv2->data << endl;
        arv2->dir->listePreOrder(l1);  
    }   
    
    if(l1.vazia()) throw "erro";
    l1.inicia();
    auto aux = new arvore<T>(l1.proximo());
    while(not l1.fim()){
      aux->adiciona(l1.proximo());
    }

    return aux;*/
   
    arvore<T> *arv = this, *aux;
    lista<arvore<T>*> l;
    //l.insere(this);
     cout << "sdadsa" << endl;
    while(arv->dir){
        arv= arv->dir;
        l.insere(arv);
    }
    cout <<"..." << arv->data;
    while(arv->data > algo){
        cout << "..." << arv->data;
        arv = l.remove(0);
        aux->adiciona(arv->data);
        if( arv->esq){
            arv=arv->esq;
            l.insere(arv);
            while(arv->dir){
            arv= arv->dir;
            l.insere(arv);
            }
        }
    }
    
    return aux->balanceia(true);
}

 template <typename T> T& arvore<T>::obtemSucessor(const T & algo) {
    /* arvore<T> *arv = this;
     arv = arv->balanceia(true);
     lista<arvore<T>*> l;
     l.anexa(arv);
     if(algo > arv->data){
        if(arv->dir) T algo2 = arv->dir->obtemSucessor(algo);
     }
     if(algo < arv->data) {
        if(arv->esq) T algo2 = arv->esq->obtemSucessor(algo);
     }
     
     return l.remove(0)->data;*/
     arvore<T> * arv = this;
     lista<arvore<T>*> l;
     arv = arv->balanceira(true);
     while(algo < arv->data){
         if(arv->esq){
             l.anexa(arv->esq);
         }
         arv = arv->esq;
     }
 }
};

#endif	/* ARVORE_IMPL_H */

