/* 
 * File:   fila.h
 * Author: msobral
 *
 * Created on 11 de Agosto de 2016, 13:58
 */

#ifndef FILA_H
#define	FILA_H

namespace prglib {
    
template <typename T> class fila {
public:
    fila(unsigned int N);
    fila(const fila<T>& outra);
    ~fila();
    fila<T>& operator=(const fila<T> & outra);
    void enfileira(const T & algo);
    void enfileiraInicio(const T & algo);
    T desenfileira();
    T desenfileiraFim();
    void esvazia();
    const T & frente() const;
    bool vazia() const;
    bool cheia() const;
    unsigned int comprimento() const;
    unsigned int capacidade() const;
private:
    unsigned int cap, itens;
    T * buffer;
    unsigned int inicio, fim, marc;
};

}

#include <libs/fila-impl.h>

#endif	/* FILA_H */

