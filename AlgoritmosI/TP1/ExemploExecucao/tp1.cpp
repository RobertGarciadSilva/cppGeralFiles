// TP1, Algoritmos I

//----- Módulos

//Conteiners, estruturas de dados
#include<vector>

//Input, Output, arquivos
#include<fstream>

//Aloritmos báisicos
#include<algorithm> // std::sort
#include<iostream>

//Classe Grafo
#include"Grafo.hpp"

using namespace std;


//------ Cabeçalho de funções
std::vector<std::vector<int>> leituraArquivo(int, int, std::string);
std::vector<int> str_split(string);
void escritaArquivo(std::vector<int>, bool);
bool estaNaLista(int, std::vector<int>);
void displayPadrao(std::vector<int>, bool);



int main(int argc, char *argv[])
{
	int CD, PV, X, numVertices, distMaxima;
	std::vector<int> temp;
	std::vector<vector<int>> CDs;
	std::vector<vector<int>> PVs;

    /* realiza a leitura da primeira linha do arquivo de entrada, contendo o numero
    de Centros de distribuição (CD), número de postos de vacinação (PV) e a temperatura
    perdita ao passar um vertice.*/
	std::string s;
	std::getline(std::cin, s);
	temp = str_split(s);

    CD = temp[0]; //número de centros de distribuição
	PV = temp[1]; //número postos de vacinação
	X = temp[2]; //temperatura perdida ao atravessar um vertice.
	
	distMaxima = (-60 -(-90))/X; //distancia máxima que pode ser percorrida.
    
    numVertices = CD + PV +1; //adiconado 1 para compensar os vertices que começam a ser representados por 1.
	

    Grafo grafo(numVertices); //Cria uma instancia da classe Grafo.

	//faz a leitura de todas as linhas representando centros de distribuição.
	s.clear();
	for(int i = 0; i < CD; i++){
		std::getline(std::cin, s);
		CDs.push_back(str_split(s));
		s.clear();
	}

	//faz a leitura de todas as linhas representando os centros de distribuição.
	for(int i = 0; i < PV; i++){
		std::getline(std::cin, s);
		PVs.push_back(str_split(s));
		s.clear();
	}

	
	//CDs = leituraArquivo(1,CD+1, argv[2]);//faz a leitura de todas as linhas representando centros de distribuição.
	//PVs = leituraArquivo(CD+1,1+CD+PV, argv[2]); //faz a leitura de todas as linhas representando os centros de distribuição.



    // -- Adicionando as arestas que representam os centros de distribuição e os postos de vacinação.

    //Arestas que representam os postos de vacinação.
    for(int i=0;i < PVs.size(); i++){
		for(int j=0; j < PVs[i].size(); j++){
			if(PVs[i][j] != 0){
				grafo.adiciona_aresta(i+1,PVs[i][j]); 
			}else{
				grafo.adiciona_aresta(i+1,0); 
			}
		}
	}

    //Arestas que representam os centros de distribuição.
    for(int i=0;i < CDs.size(); i++){
		for(int j=0; j < CDs[i].size(); j++){
			if(CDs[i][j] != 0){
				grafo.adiciona_aresta(i+1+PV,CDs[i][j]); // representando os CD com números a cima da quantidade de PVs
			}else{
				grafo.adiciona_aresta(i+1+PV,0);
			}
		}
	}


    std::vector<int> postosAlcancados; // armazena os postos que foram alcançados

    /*verifica, usando busca em largura, todos os postos que possuem distancia menor que a distancia maxima,
    e mair que zero, verifica se já estão na lista de postos alcançados, caso contrário
    o posto é adicionado na lista de postos alcançados.
    */
	std::map<int, int> arvore_bfs;
    for(int i = 1; i <= CD; i++){
		arvore_bfs = grafo.breadth_first_search(PV+i);
		for(int j = 1; j < arvore_bfs.size(); j++){
			if(arvore_bfs[j] <= distMaxima && arvore_bfs[j] > 0 && !estaNaLista(j, postosAlcancados)){
				postosAlcancados.push_back(j);
			}
		}
	}

    //Organiza o vetor de postos alcançados por ordem crescente.
    std::sort(postosAlcancados.begin(), postosAlcancados.end()); 

    //Verifica, usando busca em profundidade, se a rota a partir de cada centro de distribuição
    // é ciclica, passa por um mesmo vértice mais de uma vez.
    bool Ehciclico = false;
	for(int i = 1; i <= CD; i++){
		if(grafo.depth_first_search(PV+i)){
			Ehciclico = true;
			break;
		}
	}

	//Saída padrão
	displayPadrao(postosAlcancados, Ehciclico);


    //realiza a escrita no arquivo.
    //escritaArquivo(postosAlcancados, Ehciclico);

    return 0;
}








// ------- Funções definidas

//leitura de arquivo.
vector<vector<int>> leituraArquivo(int linhaIni, int linhaFin, std::string nomeArquivo)
{
    std::ifstream fin;
    std::string str;
	vector<vector<int>> param;
    
    fin.open(nomeArquivo);
    
    if(fin.is_open() && fin.good()){
        
        for(int i = 0; i < linhaFin; i++){
			std::getline(fin,str); //obtem as linhas do arquivo
			if(i >= linhaIni){
				//cout << str << endl;
				param.push_back(str_split(str));
			}
            str.clear();
        }
        
        
    }else{
		cout << "Não foi possível abrir o arquivo.";
	}
    fin.close();
	return param;
    
}



//escrita no arquivo
void escritaArquivo(vector<int> postosAlcancados, bool rotaCiclica)
{
    
    std::ofstream fout;
    
    fout.open("output.txt");
    
    if(fout.is_open() && fout.good()){
		if(postosAlcancados.size() == 0){
			fout << 0 << endl;
			fout << "*" << endl;
			fout << 0 << endl;
		}else{
			fout << postosAlcancados.size() << endl;
			for(int i=0; i < postosAlcancados.size(); i++){
				if(i == postosAlcancados.size()-1){
					fout << postosAlcancados[i] << endl;
				}else{
					fout << postosAlcancados[i] << " ";
				}
			}
			fout << rotaCiclica << endl;
		}
    }
    
    
    fout.close();
}



//OutputPadrão, cout
void displayPadrao(vector<int> postosAlcancados, bool rotaCiclica)
{
    
	if(postosAlcancados.size() == 0){
		std::cout << 0 << endl;
		std::cout << "*" << endl;
		std::cout << 0 << endl;
	}else{
		std::cout << postosAlcancados.size() << endl;
		for(int i=0; i < postosAlcancados.size(); i++){
			if(i == postosAlcancados.size()-1){
				std::cout << postosAlcancados[i] << endl;
			}else{
				std::cout << postosAlcancados[i] << " ";
			}
		}
		std::cout << rotaCiclica << endl;
	}
}



//usado para quebrar as strings que representam cada linha do arquivo de leitura
vector<int> str_split(std::string str)
{
	vector<int> param;
	std::string temp;
	int pos0 = 0; 

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

//verifica se v está na lista l.
bool estaNaLista(int v, vector<int> l){
	for(int i = 0; i < l.size(); i++){
		if(l[i] == v){
			return true;
		}
	}
	return false;
}













/* ----------- REFERENCIAS
[1]https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/
[2]https://www.ime.usp.br/~pf/algoritmos_para_grafos/index.html
[3]https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/bfs.html
[4]https://pt.khanacademy.org/computing/computer-science/algorithms/breadth-first-search/pc/challenge-implement-breadth-first-search
[5]https://en.wikipedia.org/wiki/C%2B%2B_Standard_Library
[6]https://www.youtube.com/watch?v=aoOs3ADVH0s&feature=youtu.be
[7]https://www.youtube.com/watch?v=BwZvcq5K1wU&list=PL8eBmR3QtPL13Dkn5eEfmG9TmzPpTp0cV&index=68
[8]https://www.youtube.com/watch?v=DYLfrmHHAm0&list=PL8eBmR3QtPL13Dkn5eEfmG9TmzPpTp0cV&index=70
[9]https://www.youtube.com/watch?v=1jpuy3Vizt0
[10]https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

Acessados: Entre 12/01/2021 e 21/01/2021
*/