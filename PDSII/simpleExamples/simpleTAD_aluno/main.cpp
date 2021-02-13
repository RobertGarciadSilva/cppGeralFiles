#include <iostream>
#include <vector>
//#include <algorithm>

#include <bits/stdc++.h>

#include "Estudante.hpp"

#define quantAlunos 10
#define quantNotas 5
#define quantDisplay 3


bool compareEstudantes(Estudante a, Estudante b)
{   
    float rsgA = a.calcularRSG();
    float rsgB = b.calcularRSG();
    
    if(rsgA != rsgB){
        return rsgA < rsgB; // suponha {5,9,4}, isso oganiza a lista como : {4,5,9}, ou seja, estudantes com maior rsg são colocados mais a direita
    }

    return (a.matricula > b.matricula); // suponha {5,9,4}, isso organiza a lista como: {9,5,4}, ou seja, estudantes com menor matrícula são colocadas mais a esquerda.

    // imagina notas iguais {80,80,80}, sendo assim, essas notas não entram no primeiro if, entrando no segundo,
    // o segundo faz a classificação baseado nas matrículas, logo, estudantes com memso rsg são classificados colocando
    // os de menor matrícula mais a direita.
    //dupla classificação, primeiro por rsg depois pela matrícula, 
    // mais detalhes consulte as referêcias: [1], [5]

}

int main(){

    std::vector<Estudante> estudantes;
    Estudante tempEst;

    for(int i=0; i < quantAlunos; i++){
        std::cin >> tempEst.matricula >> tempEst.nome;
        for(int j = 0; j < quantNotas; j++){
            std::cin >> tempEst.notas[j];
        }
        estudantes.push_back(tempEst);
    }

    std::sort(estudantes.begin(), estudantes.end(), compareEstudantes);

    std::cout << "\n ---- Rank ----\n" << std::endl;
    std::cout << std::fixed; std::cout.precision(2); //limitar casas decimais [2]
    
    for(int i = quantAlunos-1; i >= quantAlunos-(quantDisplay); i--){
        std::cout << estudantes[i].matricula << " " << estudantes[i].nome << " " << estudantes[i].calcularRSG() << std::endl;
    }

    return 0;
}


/*
---- REFERÊNCIAS

[1]Structure Sorting (By Multiple Rules) in C++
Disponível em: https://www.geeksforgeeks.org/structure-sorting-in-c/
Acesso: 20/08/2020

[2]Como limitar casas decimais?
Disponível em: https://pt.stackoverflow.com/questions/94564/como-limitar-casas-decimais
Acesso: 20/08/2020

[3]Por que o std :: getline () pula a entrada após uma extração formatada?
Disponível:https://www.it-swarm.dev/pt/c%2B%2B/por-que-o-std-getline-pula-entrada-apos-uma-extracao-formatada/1043647283/
Acesso: 20/08/2020

[4] std::vector
Disponível em: http://www.cplusplus.com/reference/vector/vector/
Acesso: 20/08/2020

[5] std::sort
Disponível em: http://www.cplusplus.com/reference/algorithm/sort/
Acesso: 20/08/2020

*/

