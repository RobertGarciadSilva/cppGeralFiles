
#include <iostream>

#include <fstream>

#define LINHAS 22
#define COLUNAS 80
#define NUMERO_GERACOES 150

void leituraArquivo(char mundo[][COLUNAS]);
void escritaArquivo();
void geracao(char mundo[][COLUNAS] );
void displayMundo(char mundo[][COLUNAS]);
void algumasConfiguracoesIniciais(int numConfiguracao, char grade[][COLUNAS]);

int main()
{
    char mundo[LINHAS][COLUNAS];
    escritaArquivo();
    leituraArquivo(mundo);
    
    int i = 0;
    while(i < NUMERO_GERACOES){
        std::cout << i + 1 << "º Geração --------------------------------------------------" << std::endl;
        displayMundo(mundo);
        geracao(mundo);
        std::cout << "----------------------------------------------------------------------" << std::endl;
        std::cin.get();
        i++;
    }
    
    
    
    return 0;
}

void leituraArquivo(char mundo[][COLUNAS])
{
    std::ifstream fin;
    std::string str;
    //char mundo[LINHAS][COLUNAS];
    
    fin.open("grade.txt");
    
    if(fin.is_open() && fin.good()){
        
        for(int i = 0; i < LINHAS; i++){
            std::getline(fin,str); //obtem as linhas do arquivo
            for(int j = 0; j < COLUNAS; j++){
                mundo[i][j] = str[j]; //percorre str, gravando seu valor na linha i, posicoes j da matriz
            }
            str.clear();
        }
        
        
    }
    
    fin.close();
    
}

void escritaArquivo()
{
    /*  Constroi a grade da vida em um arquivo .txt     
     */
    
    std::ofstream fout;
    char grade[LINHAS][COLUNAS];
    
    
    //constroi a grade
    for(int i = 0; i < LINHAS; i++){
        for(int j = 0; j < COLUNAS; j++){
            grade[i][j] = ' ';
        }
    }
    
    
    //configuracao inicial, condicoes iniciais
    algumasConfiguracoesIniciais(1,grade);
    
    
    //faz a gravacao da matriz grade no arquivo
    fout.open("grade.txt");
    
    if(fout.is_open() && fout.good()){
        for(int i = 0; i < LINHAS; i++){
            for(int j = 0; j < COLUNAS; j++){
                fout << grade[i][j];
            }
            if(i <= COLUNAS-2){
               fout << std::endl;
            }
        }
    }
    
    
    fout.close();
}


/*
 *  CELULAS VIZINHAS
 * 
 *          //mundo[i][j+1] celula a direita
            //mundo[i][j-1] celula a esquerda
            //mundo[i+1][j] celula abaixo
            //mundo[i-1][j] celula acima
            //mundo[i+1][j+1] celula diagonal abaixo direita
            //mundo[i+1][j-1] celula diagonal abaixo esquerda
            //mundo[i-1][j+1] celula diagonal acima direita
            //mundo[i-1][j-1] celula diagonal acima esquerda
 *  
 */



void geracao(char mundo[][COLUNAS])
{
   //essa funcao aplica as regras do jogo da vida a cada celula individualmente
    
   //cria uma copia do mundo atual
   char cmundo[LINHAS][COLUNAS];
   for(int i = 0; i < LINHAS; i++){
       for(int j = 0; j < COLUNAS; j++){
           cmundo[i][j] = mundo[i][j];
       }
   }
    
    int quantVizinhas = 0;

    /*NAO TRATA OS CANTOS DO MUNDO. De acordo com as especificacoes do "jogo da vida",
     * cada celula possui 8 vizinhas, por essa definacao, as posicoes localizadas nas bordas
     * nao podem ser celulas, logo, a tratamento feito abaixo nao trata os cantos do mundo,
     * mas pode ser feito se necessario.
     */
    for(int i = 1; i < LINHAS-1; i++){
        for(int j = 1; j < COLUNAS-1; j++){
            if(cmundo[i][j-1] == '*'){
                quantVizinhas++;
            }
            if(cmundo[i][j+1] == '*'){
                quantVizinhas++;
            }
            if(cmundo[i+1][j] == '*'){
                quantVizinhas++;
            }
            if(cmundo[i-1][j] == '*'){
                quantVizinhas++;
            }
            if(cmundo[i+1][j+1] == '*'){
                quantVizinhas++;
            }
            if(cmundo[i+1][j-1] == '*'){
                quantVizinhas++;
            }
            if(cmundo[i-1][j+1] == '*'){
                quantVizinhas++;
            }
            if(cmundo[i-1][j-1] == '*'){
                quantVizinhas++;
            }
            
            //a morte de uma nao influencia na morte da outra
            if(quantVizinhas == 0 || quantVizinhas == 1 || quantVizinhas > 3){
                mundo[i][j] = ' ';
            }
            
            //uma célula recém-nascida não pode ressuscitar uma célula que está morrendo,
            if(cmundo[i][j] == ' ' && quantVizinhas == 3){
                mundo[i][j] = '*';
            }
            
            //Uma celula que morre por qualquer razao pode ajudar a provocar o nascimento
            if(mundo[i][j] == ' ' && quantVizinhas == 3){
                mundo[i][j] = '*';
            }
            quantVizinhas = 0;
        }
    }
    
    
}

void displayMundo(char mundo[][COLUNAS])
{
    //exibir na tela a matriz mundo
    for(int i = 0; i < LINHAS; i++){
        for(int j = 0; j < COLUNAS; j++){
            std::cout << mundo[i][j];
        }
        std::cout << std::endl;
    }
    
}

void algumasConfiguracoesIniciais(int numConfiguracao, char grade[][COLUNAS])
{
    //aqui estao algumas configuracoes para teste
    int quantConfiguracoesAdicionadas = 3; //deve ser alterado sempre que for adicionado alguma configuracao
    int l = LINHAS/2;
    int c = COLUNAS/2;
    
    if(numConfiguracao == 1 || numConfiguracao <= 0 || numConfiguracao > quantConfiguracoesAdicionadas){
        grade[11][40] = '*';
        grade[12][40] = '*';
        grade[12][39] = '*';
        grade[12][41] = '*';
        grade[13][39] = '*';
        grade[13][41] = '*';
        grade[14][40] = '*';
    }else if(numConfiguracao == 2){
        grade[11][40] = '*';
        grade[11][42] = '*';
        grade[11][38] = '*';
        grade[12][38] = '*';
        grade[12][42] = '*';
        grade[13][38] = '*';
        grade[13][42] = '*';
        grade[14][38] = '*';
        grade[14][42] = '*';
        grade[15][38] = '*';
        grade[15][42] = '*';
        grade[15][40] = '*';
    }else if(numConfiguracao == 3){
        grade[l][c] = '*';
        grade[l][c-1] = '*';
        grade[l][c-2] = '*';
        grade[l][c-3] = '*';
        grade[l][c-4] = '*';
        grade[l][c+1] = '*';
        grade[l][c+2] = '*';
        grade[l][c+3] = '*';
        grade[l][c+4] = '*';
    }
    
    
    
}