
#include "Aresta.hpp"

//Construtor
Aresta::Aresta(int vertice1, int vertice2, int peso01, int peso02)
{
    v1 = vertice1;
    v2 = vertice2;
    this->peso01 = peso01;
    this->peso02 = peso02;
}

int Aresta::getV1()
{
    return v1;
}

int Aresta::getV2()
{
    return v2;
}

int Aresta::getPeso01()
{
    return peso01;
}

int Aresta::getPeso02()
{
    return peso02;
}

bool Aresta::operator < (const Aresta& aresta02) const
{
    if(peso01 == aresta02.peso01){
        return (peso02 > aresta02.peso02);
    }
    return (peso01 < aresta02.peso01);

    /*
        Essa sobrescrita de operador e essencial para garantir 
        uma ordem (ao usar std::sort) antes de se usar o algoritmo de 
        Kraskul para o problema proposto;
        Verifica se o peso01 (Custo) de uma aresta é menor que o custo de outra,
        se o for, retorna verdadeira, caso as dias arestas tenham pesos iguais
        então a ordem é dada para qual das duas arestas tenha o maior peso02
        que representa o atratividade agregada da aresta.
    */
}