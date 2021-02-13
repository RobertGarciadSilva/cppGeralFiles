#ifndef GRAFO_H
#define GRAFO_H

//Containers, estruturas de dados
#include<list>
#include<map>
#include<queue>
#include<stack>
#include<queue>

class Grafo
{
    int numero_vertices;
    std::list<int> *lista_adjacencia;

public:

    Grafo(int numero_vertices); //construtor
    void adiciona_aresta(int vertice_pai, int vertice_filho);
    
    std::map<int, int> breadth_first_search(int vertice_root); //Busca em largura - bfs
    /*retorna um map, arvore contendo:  
        map<vertice, distancia_do_root>, distancia que cada vertice está 
        do vertice root.
    */
    
    bool depth_first_search(int vertice_root); //Busca em Profundidade - dfs
    /*Retorna true se existe alguma rota, iniciando por vertice_root, que
        atravessa um mesmo vertice mais de uma vez.
    */
};



#endif


