#ifndef ARESTA_H
#define ARESTA_H

class Aresta
{
    int v1, v2, peso01, peso02;

public:

    Aresta(int vertice1, int vertice2, int peso01, int peso2); //Construtor
    int getV1();
    int getV2();
    int getPeso01();
    int getPeso02();
    bool operator < (const Aresta& v2) const; // sobrescrevendo operador
};


#endif