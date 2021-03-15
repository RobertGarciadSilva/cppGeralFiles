#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <algorithm> // Usado para o std::sort()
#include <string.h> //Usado para o memset(), verificar referência [1]
#include "Aresta.hpp"
#include <map>

class Grafo
{
    int numero_vertices;
    std::vector<Aresta> arestas;

public:
    Grafo(int numero_vertices); // Construtor
    void make_aresta(Aresta aresta);

    int get_numVertices();

    //As duas funções logo abaixo são usadas pelo algoritmo de Kruskal
    int kruskal_find(int subset[], int vertice1);
    void kruskal_union(int subset[], int vertice1, int vertice2);

    std::vector<Aresta> Algoritmo_Kraskal();
    std::vector<std::vector<int>> Algoritmo_Prim(int root, int& custo01_total, int& custo02_total, std::map<int, int>& cont_aresta_vertices);
    

    /*As funções a baixo são usadas para a aplicação do algoritmo
    de PRIM, esse algoritmo foi implementado no presente trabalho, 
    para teste, mas não está sendo usado para a saída definida, ele
    não ofereceu OUTPUT correto para todas as entradas de teste.*/

    int contar_vertices_adjacentes(int vertice_pai);
    std::vector<std::pair<int, int>> vertices_adjacentes(int vertice_pai);
};

#endif

/*
Referências
[1]http://www.cplusplus.com/reference/cstring/memset/


*/