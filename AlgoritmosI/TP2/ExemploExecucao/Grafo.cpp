
#include "Grafo.hpp"

//Construtor
Grafo::Grafo(int numero_vertices)
{
    this->numero_vertices = numero_vertices;
}

int Grafo::get_numVertices()
{
    return this->numero_vertices;
}

void Grafo::make_aresta(Aresta aresta)
{
    arestas.push_back(aresta);
}

int Grafo::contar_vertices_adjacentes(int vertice_pai)
{
    int quantVAd = 0;
		for(int i = 0; i < arestas.size(); i++){
			if(arestas[i].getV1() == vertice_pai || arestas[i].getV2() == vertice_pai){
				quantVAd++;
			}
			
		}
		return quantVAd;
}

std::vector<std::pair<int, int>> Grafo::vertices_adjacentes(int vertice_pai)
{
    std::vector<std::pair<int,int>> vertices_adj;
		
		for(int i=0; i < arestas.size(); i++){
			if(arestas[i].getV1() == vertice_pai){
				vertices_adj.push_back(std::make_pair(arestas[i].getV2(), arestas[i].getPeso01()));
			}else{
				if(arestas[i].getV2() == vertice_pai){
					vertices_adj.push_back(std::make_pair(arestas[i].getV1(), arestas[i].getPeso01()));
				}
			}
		}
		return vertices_adj;
}

int Grafo::kruskal_find(int subset[], int i)
{
    if(subset[i] == -1){
        return i;
    }
    return kruskal_find(subset, subset[i]);
}

void Grafo::kruskal_union(int subset[], int vertice1, int vertice2)
{
    int vertice1_set, vertice2_set;
    vertice1_set = kruskal_find(subset, vertice1);
    vertice2_set = kruskal_find(subset, vertice2);
    subset[vertice1_set] = vertice2_set;
}

std::vector<Aresta> Grafo::Algoritmo_Kraskal()
{
    std::vector<Aresta> arvore_kraskal;
    int* subconjunto = new int[numero_vertices]; // Memória para criar um número de subconjuntos igual ao número de vértices
    memset(subconjunto, -1, sizeof(int)*numero_vertices); // Inicializa os subconjuntos para conjuntos de um único elemento
    
    std::sort(arestas.begin(), arestas.end());
    /*Ordena as arestas. O operado " < " foi sobrecarregado 
    na definição da classe Aresta, de modo que a organização das
    arestas é feita comparando primeiro o peso01 (custo), de modo que
    as arestas com menor custo sejam os primeiros valores, caso duas
    arestas possuam o mesmo peso01 (custo) a organização é feita então
    comprando o peso02 (atratividade) de modo que as arestas com
    menor peso01 e maior atratividade peso02 apareçam primeiro no vetor, 
    esse passo é muito importante para que o algortimo execute corretamente
    sobre o problema proposto.*/

    int vert1, vert2;
    for(int  i = 0; i < arestas.size(); i++){
        vert1 = kruskal_find(subconjunto, arestas[i].getV1());
        vert2 = kruskal_find(subconjunto, arestas[i].getV2());
        if(vert1 != vert2){
            arvore_kraskal.push_back(arestas[i]);
            kruskal_union(subconjunto, vert1, vert2);
        } 
    }

    return arvore_kraskal;
}


/*
 std::vector<std::vector<int>> Grafo::Algoritmo_Prim(int root, int& custo01_total, int& custo02_total, std::map<int, int>& cont_aresta_vertices)
 {
     const int INF = 2147483647; // Valor máximo para uma variável do tipo int 
		
	std::vector<int> S;
	std::vector<int> T;

    std::vector<int> custo(numero_vertices, INF);
	std::vector<int> pred(numero_vertices, -1);
	custo[root] = 0;

    std::vector<bool> selected(numero_vertices, false);
	selected[root] = true;

    std::vector<std::pair<int, int>> vertices_adj;

	std::vector<std::vector<int>> arvore_vertices;
	std::vector<int> vertice;
		
		
	// fila de prioridade minima pair(peso, vertice)
	std::multimap<int, int> pq;
	
	for(int i = 0; i < numero_vertices; i++){
		pq.insert(std::pair<int, int>(custo[i], i));
	}

	std::multimap<int,int>::iterator it;
	int u;
    while(!pq.empty()){
		it = pq.begin(); u = (*it).second; 
		pq.erase(it);

		S.push_back(u);
		T.push_back(pred[u]);

		vertice.push_back(pred[u]);
		vertice.push_back(u);

		for(int i = 0; i < arestas.size(); i++){
			if((arestas[i].getV1() == u && arestas[i].getV2() == pred[u]) || (arestas[i].getV2() == u && arestas[i].getV1() == pred[u])){
				vertice.push_back(arestas[i].getPeso01());
			}
		}

		arvore_vertices.push_back(vertice);
		vertice.clear(); 

		selected[u] = true;

		vertices_adj = vertices_adjacentes(u);

		int v, v_peso;
		for(int i = 0; i < vertices_adj.size(); i++){
			v = vertices_adj[i].first;
			v_peso = vertices_adj[i].second;
				
			if(selected[v] == false){
				if(v_peso < custo[v]){
					custo[v] = v_peso;
					pred[v] = u;
					for(it = pq.begin(); it != pq.end(); it++){ // Usado para atualizar "pq".
						if(it->second == v){
							pq.erase(it);
							pq.insert(std::pair<int, int>(v_peso, v));
						}
					}
				}
			}
		}
		vertices_adj.clear();	
	}
    arvore_vertices.erase(arvore_vertices.begin());

    //Retornando valores

    //Armazena a contagem (número de arestas que entram e saem) de cada vértice.
    std::map<int, int> cont_aresta_vertice;
    
    for(int i = 0; i < numero_vertices; i++){
		cont_aresta_vertice.insert(std::pair<int, int>(i,0));
	}

    int atr = 0; // Armazena o somatório da atratividade agregada 
	for(int i = 0; i < arvore_vertices.size(); i++){
		for(int j = 0; j < 2; j++){
			cont_aresta_vertice[arvore_vertices[i][j]] += 1; 
		}
        atr +=  arestas[i].getPeso02();
	}

    int custo01_tot = 0;
    for(int i = 0; i < custo.size(); i++){
		custo01_tot += custo[i];
	}

    custo02_total = atr;
    custo01_total = custo01_tot;
    cont_aresta_vertices = cont_aresta_vertice;


    return arvore_vertices;

 }
*/


