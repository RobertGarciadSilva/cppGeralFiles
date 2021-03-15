
#include <iostream>
#include <vector>
#include <map>

#include "Grafo.hpp"


//Cabeçalho de funções
std::vector<int> str_split(std::string );
//void exec_display_PRIM(Grafo G);

int main(int argc, char* argv[])
{
    int quant_postos_interesse, quant_trechos_possiveis;
    std::vector<int> valores_turisticos;
    std::vector<int> temp_vector;
    std::string temp_s;

    std::getline(std::cin, temp_s);
    temp_vector = str_split(temp_s);

    quant_postos_interesse = temp_vector[0]; // armazenando quantidade postos de interesse
    quant_trechos_possiveis = temp_vector[1]; //armazenando quantidade de trechos possiveis

    std::getline(std::cin, temp_s);
    valores_turisticos = str_split(temp_s); // armazenando valores turisticos de cada vertice (cada posto de interesse)

    Grafo grafo(quant_postos_interesse); // instancia a modelagem do problema com grafo (instancia o grafo)
    //Postos de interesse representa o número de vértices.

    /* O laço abaixo adiciona as arestas no grafo instanciado logo acima.
        Para a adição da aresta no grafo são passados quatro informações,
        vertice1, vertice2 (ligando a aresta), peso01 (que represeta o custo)
        e peso02 (que representa a atratividade da aresta, a atratividade
        é calculado somando o valor turistico dos dois vertices que pertencem
        a aresta).
    */
    int atratividade = 0; //atratividade agregada de uma aresta com vertices v1 e v2
    for(int i = 0; i < quant_trechos_possiveis; i++){
        std::getline(std::cin, temp_s);
        temp_vector = str_split(temp_s);
		atratividade += valores_turisticos[temp_vector[0]] + valores_turisticos[temp_vector[1]];
        grafo.make_aresta(Aresta(temp_vector[0], temp_vector[1], temp_vector[2], atratividade));
		atratividade = 0;
    }

    std::vector<Aresta> arvore_kruskal;
    arvore_kruskal = grafo.Algoritmo_Kraskal();


    //calcula peso01 (custo) e peso02 (atratividade agregada) total.
    int custo_total = 0;
    int atratividade_agr_total = 0;
    for(int i = 0; i < arvore_kruskal.size(); i++){
        custo_total += arvore_kruskal[i].getPeso01();
        atratividade_agr_total += arvore_kruskal[i].getPeso02();
    }

    //Armazena a contagem (número de arestas que entram e saem) de cada vértice.
    std::map<int, int> cont_aresta_vertice;

    for(int i = 0; i < quant_postos_interesse; i++){
        cont_aresta_vertice.insert(std::pair<int, int>(i, 0));
    }

    for(int i = 0; i < arvore_kruskal.size(); i++){
        int v1 = arvore_kruskal[i].getV1(); //vertice1 da aresta
        int v2 = arvore_kruskal[i].getV2(); //vertice2 da aresta
        cont_aresta_vertice[v1] += 1;
        cont_aresta_vertice[v2] += 1;
    }



    //Display_kruskal

    std::cout << custo_total << " " << atratividade_agr_total << std::endl;

    for(int i = 0; i < cont_aresta_vertice.size(); i++){
        std::cout << cont_aresta_vertice[i] << " ";
    }

    std::cout << std::endl;
    for(int i = 0; i < arvore_kruskal.size(); i++){
        std::cout << arvore_kruskal[i].getV1() << " " << arvore_kruskal[i].getV2() << " " << arvore_kruskal[i].getPeso01() << std::endl;
    }

/*
    std::cout << std::endl;
    exec_display_PRIM(grafo);
*/  


    return 0;
}



std::vector<int> str_split(std::string str)
{
	std::vector<int> param;
	std::string temp;
	int pos0 = 0; 
	
	//exclui os espaços em branco no final de cada string linha.
	while(str[str.size()-2] == ' '){
		str.erase(str.end()-2);
	}

	if(str.find(' ') > str.size()){
		param.push_back(std::stoi(str));
		return param;	
	}

	while(true){
		if(str.find(' ') <= str.size()){
			pos0 = str.find(' ');
		}else{
			param.push_back(std::stoi(str));
			break;
		}
		temp = str.substr(0,pos0);
		param.push_back(std::stoi(temp));
		str = str.substr(str.find(' ')+1, str.size()-1);
	}
	return param;
}

/*
void exec_display_PRIM(Grafo G)
{
    /* Executa o algoritmo de prim sobre todos os vertices de G 
        e pega o que obtém o maior peso02 (atratividade)
    */
/*
   std::vector<std::vector<int>> arvore_prim, arvore_prim_min;
   int peso01 = 0, peso01_min = 0;
   int peso02 = 0, peso02_max = 0;
   std::map<int, int> conta_numArestas_vertices, conta_numArestas_vertices_min;

   for(int i = 0; i < G.get_numVertices(); i++){
        arvore_prim = G.Algoritmo_Prim(i, peso01, peso02, conta_numArestas_vertices); // int root, int& custo01_total, int& custo02_total, std::map<int, int>& cont_aresta_vertices
        if(i == 0){
            peso02_max = peso02;
            arvore_prim_min = arvore_prim;
            peso01_min = peso01;
            conta_numArestas_vertices_min = conta_numArestas_vertices;
        }
        if(peso02 > peso02_max){
            peso02_max = peso02;
            arvore_prim_min = arvore_prim;
            peso01_min = peso01;
            conta_numArestas_vertices_min = conta_numArestas_vertices;
        }
   }

   //Display

   std::cout << peso01_min << " " << peso02_max << std::endl;

   for(int i = 0; i < conta_numArestas_vertices_min.size(); i++){
       std::cout << conta_numArestas_vertices_min[i] << " ";
   }
   std::cout << std::endl;

   for(int i = 0; i < arvore_prim_min.size(); i++){
       for(int j = 0; j < arvore_prim_min[i].size(); j++){
           std::cout << arvore_prim_min[i][j] << " ";
       }
       std::cout << std::endl;
   }



}
*/


/*
REFERÊNCIAS

[1] Ime.usp.br, algoritmos para grafos. Algoritmo Kruskal https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/kruskal.html Acessado: Entre 10/02/2021 e 22/01/2021

[2] cplusplus.com, std::sort
https://www.cplusplus.com/reference/algorithm/sort/ Acessado: Entre 10/02/2021 e 22/01/2021

[3] Aulas – Jussara Almeida - DCC/UFMG
https://www.youtube.com/watch?v=j2POV6Qnrhs&feature=youtu.be Acessado: Entre 10/02/2021 e 22/01/2021

[4] Aulas – Jussara Almeida - DCC/UFMG
https://www.youtube.com/watch?v=0n_W55NtIjc&feature=youtu.be Acessado: Entre 10/02/2021 e 22/01/2021

[5] Wikipédia, STL
https://en.wikipedia.org/wiki/C%2B%2B_Standard_Library Acessado: Entre 10/02/2021 e 22/01/2021

[6] Youtube, Grafos - Algoritmo de Kruskal, Marcos Castro
https://www.youtube.com/watch?v=fziFDaQ1S5I&list=PL8eBmR3QtPL13Dkn5eEfmG9TmzPpTp0cV&index=74  Acessado: Entre 10/02/2021 e 22/01/2021

[7] Wikipédia, Algoritmo de Kruskal
https://pt.wikipedia.org/wiki/Algoritmo_de_Kruskal Acessado: Entre 10/02/2021 e 22/01/2021

[8] Wikipédia, Algoritmo de Prim
https://pt.wikipedia.org/wiki/Algoritmo_de_Prim Acessado: Entre 10/02/2021 e 22/01/2021

[9] Árvore geradora mínima - algoritmo de Prim
https://cp-algorithms-brasil.com/grafos/mst.html Acessado: Entre 10/02/2021 e 22/01/2021

[10] A Simple Makefile Tutorial
https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/ Acessado: Entre 10/02/2021 e 22/01/2021

[11] GeeksforGeeks, Multimap in C++
https://www.geeksforgeeks.org/multimap-associative-containers-the-c-standard-template-library-stl/
Acessado: Entre 10/02/2021 e 22/01/2021

[12] cplusplus.com, std::sort
http://www.cplusplus.com/reference/map/multimap/begin/
Acessado: Entre 10/02/2021 e 22/01/2021





*/