#include <cstdlib>
#include <prglib.h>
#include <iostream>
#include <string>
#include <fstream>
#include "Boletim.h"
#include "Menu.h"

using namespace std;
using prglib::lista;

int main(int argc, char** argv) {
   try{ string linha;
    int loop = 1;
    lista<Resultado> Lista = carregaBoletim("enem2.txt");
    Menu Menu(Lista);
    while(loop){
        loop = Menu.Exibe();
    }
   }catch(const char *e){cout << e<< endl;}
    return 0;
}