#include"Grafo.hpp"

//Construtor
Grafo::Grafo(int numero_vertices)
{
    this->numero_vertices = numero_vertices;
    lista_adjacencia = new std::list<int>[numero_vertices];
}

void Grafo::adiciona_aresta(int vertice_pai, int vertice_filho)
{
    lista_adjacencia[vertice_pai].push_back(vertice_filho);
}

std::map<int, int> Grafo::breadth_first_search(int vertice)
{
    std::queue<int> fila;
    bool visitados[numero_vertices];
    std::map<int, int> distancia_root;

    //marca todos os vértices como não visitados
    for(int i = 0; i < numero_vertices; i++){
        visitados[i] = false;
    }

    //marca o vértice root como distancia zero
    distancia_root.insert(std::pair<int, int>(vertice,0));

    //marca o vértice root como já visitado
    visitados[vertice] = true;

    while(true){

        std::list<int>::iterator it;
        for(it = lista_adjacencia[vertice].begin(); it != lista_adjacencia[vertice].end(); it++){

            //Se o vértice não foi visitado
            if(!visitados[*it]){
                //se o vertice não foi visitado, sua distancia é a distancia de seu vertice pai somado 1.
                distancia_root.insert(std::pair<int, int>(*it, distancia_root[vertice]+1));
                visitados[*it] = true; //marca o vértice como visitado
                fila.push(*it);
            }
        }

        //Se a fila não estiver vazia faz v a frente da fila e logo em seguida tira esse vertice da fila.
        if(!fila.empty()){
            vertice = fila.front();
            fila.pop();
        }else{
            //se a fila estiver vazia é porque toos os vértices já foram verificados, logo, feche o laço.
            break;
        }
    }
    return distancia_root;
}


bool Grafo::depth_first_search(int vertice)
{
    std::stack<int> PILHA;
    bool vistitados[numero_vertices];
    bool pilha_2[numero_vertices]; //usado para verificar se um vertice ja esta na PILHA.

    //marca todos os vertices como nao visitados e como não estando na PILHA.
    for(int i = 0;i < numero_vertices; i++){
        vistitados[i] = false;
        pilha_2[i] = false;
    }

    while(true){

        bool achouVertice_vizinho = false; // verifica se o vertice pai possui um filho, vizinho.

        //se o vertice não foi visitado coloca ele na pilha, marca como visitado e adicionada ele na pilha
        //de ja visitados.
        if(!vistitados[vertice]){
            PILHA.push(vertice);
            vistitados[vertice] = true;
            pilha_2[vertice] = true;
        }

        std::list<int>::iterator it;
        for(it = lista_adjacencia[vertice].begin(); it != lista_adjacencia[vertice].end(); it++){

            /*Se o vertice vizinho já está na pilha é porque ele ja foi visitado no trajeto
            a partir da vertice root,logo, o grafo possui ciclo. Lembrando que se trata de 
            um grafo direcional.*/
            if(pilha_2[*it]){
                return true;
            }else if(!vistitados[*it]){ // se o vertice vizinho, filho nao foi visitado
                achouVertice_vizinho = true;
                break;
            }
        }

        if(achouVertice_vizinho){ // se o vértice possui filho
            vertice = *it;
        }else{
            pilha_2[PILHA.top()] = false; // marque o vértice como não estando na PILHA
            PILHA.pop(); 
            if(PILHA.empty()){ 
                break;
            }
            vertice = PILHA.top();
        }   
    }
    return false;
}