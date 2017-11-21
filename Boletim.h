/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boletim.h
 * Author: dougl
 *
 * Created on 8 de Abril de 2017, 20:55
 */

#ifndef BOLETIM_H
#define BOLETIM_H

#include <cstdlib>
#include <prglib.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
using prglib::lista;

struct Resultado {
    string Escola, Estado, Cidade;
    float mtm, ling, cn, ch, red, MedGeral;

    bool operator<(const Resultado & outro) {
        if (MedGeral < outro.MedGeral) {
            return 1;
        } else return 0;
    }
    
    bool operator>(const Resultado & outro) {
        if (MedGeral > outro.MedGeral) {
            return 1;
        } else return 0;
    }

    //construtor vazio
    Resultado();
    //Contrutor

    Resultado(string linha) {
        int posicao, posicaoNovo, marcador = 0, marcadorNovo = 0, iterador = 0, i = 0;
        float nota[6];

        posicao = linha.find_first_of(",", 0);
        while (posicao != -1) {
            //marcador = posicao + 1;  

            while (iterador == 0) {

                string novo = linha.substr(marcador, posicao);
                posicaoNovo = novo.find_first_of("/", marcadorNovo);

                Escola = novo.substr(marcadorNovo, posicaoNovo);
                marcadorNovo = posicaoNovo + 1;

                posicaoNovo = novo.find_first_of("/", marcadorNovo);

                Cidade = novo.substr(marcadorNovo, posicaoNovo - marcadorNovo);
                marcadorNovo = posicaoNovo + 1;

                posicaoNovo = novo.find_first_of(",", marcadorNovo);
                Estado = novo.substr(marcadorNovo, posicaoNovo);

                iterador++;
            }
            marcador = posicao + 1;
            posicao = linha.find_first_of(",", marcador);
            string no1 = linha.substr(marcador, posicao);
            float n1 = stof(no1);
            nota[i] = n1;
            i++;
        }
        MedGeral = nota[0];
        ling = nota[1];
        mtm = nota[2];
        cn = nota[3];
        ch = nota[4];
        red = nota[5];

    }
};

// inicia o bloco funcional, carregando os dados de um boletim que estão
// no arquivo dado pelo caminho "path"

//carregaBoletim(const string & path);
lista<Resultado> carregaBoletim(const string & path);

// Busca todas os resultados das escolas de uma cidade e estado
void ResultadoCidadeEstado(const string & nomeCidade, const string & nomeEstado, lista<Resultado> & Lista);

// Busca o resultado de uma escola específica
void ResultadoEscolaNome(const string & nomeEscola, lista<Resultado> & Lista);

//Media Geral Cidade/Estado
void MediaGeralCidadeEstado(const string & nomeCidade, const string & nomeEstado, lista<Resultado> & Lista);

// N Maiores notas
void MaioresNotasDecrescentes(int quantidade, lista<Resultado> & Lista);

//N Menores Notas
void MenoresNotasCrescentes(int quantidade, lista<Resultado> & Lista);


#endif /* BOLETIM_H */