/* 
 * File:   Menu.h
 * Author: magno
 *
 * Created on 11 de Abril de 2017, 11:15
 */

#ifndef MENU_H
#define	MENU_H
#include "prglib.h"
#include "Boletim.h"

using prglib::lista;

class Menu{
private:
    lista<Resultado> Lista;
    
public:
    Menu(lista<Resultado> lista);
    int Exibe();
};

#endif	/* MENU_H */

