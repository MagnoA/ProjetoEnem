#include "Menu.h"
#include <string>
#include <iostream>
#include "prglib.h"
#include "Boletim.h"
#include <cstdlib>

using namespace std;
using prglib::lista;

Menu::Menu(lista<Resultado> lista) {
    Lista = lista;
}

int Menu::Exibe() {
    cout << "Selecione uma opção" << endl
            << "(1) Resultado por escola;" << endl
            << "(2) Resultado por Cidade/Estado;" << endl
            << "(3) Média Geral por Cidade/Estado;" << endl
            << "(4) Escolas com maiores ídices de aproveitamento" << endl
            << "(5) Escolas com menores índices de aproveitamento" << endl
            << "(0) Sair " << endl
            << "Opção: ";

    int opc;
    cin >> opc;
    switch (opc) {
        case 0: return 0;
        case 1:
            while (true) {
                string nome;
                cin.ignore(1024, '\n');
                cout << "Instituição: ";
                getline(cin, nome);
                ResultadoEscolaNome(nome, Lista);
                cout << endl << "Voltar ao menu principal?" << endl
                        << "(S) Sim" << endl << "(N) Não" << endl;
                char decisao;
                cin >> decisao;
                if (decisao == 'S') break;
            }
            break;

        case 2:
            while (true) {
                string cidade, estado;
                cin.ignore(1024, '\n');
                cout << "Cidade: ";
                getline(cin, cidade);
                cout << "Estado: ";
                cin >> estado;
                ResultadoCidadeEstado(cidade, estado, Lista);
                cout << endl << "Voltar ao menu principal?" << endl
                        << "(S) Sim" << endl << "(N) Não" << endl;
                char decisao;
                cin >> decisao;
                if (decisao == 'S') break;
            }
            break;

        case 3:
            while (true) {
                string cidade, estado;
                cin.ignore(1024, '\n');
                cout << "Cidade: ";
                getline(cin, cidade);
                cout << "Estado: ";
                cin >> estado;
                MediaGeralCidadeEstado(cidade, estado, Lista);
                cout << endl << "Voltar ao menu principal?" << endl
                        << "(S) Sim" << endl << "(N) Não" << endl;
                char decisao;
                cin >> decisao;
                if (decisao == 'S') break;
            }
            break;

        case 4:
            while (true) {
                int qtd;
                cin.ignore(1024, '\n');
                cout << "Número de amostras: ";
                cin >> qtd;
                MaioresNotasDecrescentes(qtd, Lista);
                cout << endl << "Voltar ao menu principal?" << endl
                        << "(S) Sim" << endl << "(N) Não" << endl;
                char decisao;
                cin >> decisao;
                if (decisao == 'S') break;
            }
            break;

        case 5:
            while (true) {
                int qtd;
                cin.ignore(1024, '\n');
                cout << "Número de amostras: ";
                cin >> qtd;
                MenoresNotasCrescentes(qtd, Lista);
                cout << endl << "Voltar ao menu principal?" << endl
                        << "(S) Sim" << endl << "(N) Não" << endl;
                char decisao;
                cin >> decisao;
                if (decisao == 'S') break;
            }
            break;
        default:
            cout << endl << "Opção inválida" << endl << endl;
            break;
    }
}