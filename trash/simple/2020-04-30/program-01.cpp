
/*
Programa que preencha um vetor com nove números inteiros lidos do teclado, calcule e mostre os
números primos e suas respectivas posições.
*/

#include <iostream>
#include <fstream>


int count_quantPrimosAte(int );
bool numPrimo(int );
bool writeFile(std::ofstream& , char* );
bool interface_saveFale();


int main(){
    
    int n = 0;
    std::cout << "\nEntre com um inteiro n para cálculo dos primos até n: " << std::endl;
    std::cin >> n;

    int num_primos = count_quantPrimosAte(n); // conta o número de primos no intervalo dados,
    int primos[num_primos];                     // usado para definir o tamanho do array nessa linha.

    //aramazena os primos no array primos
    for(int i = 2, j = 0; i < n; i++){
        if(numPrimo(i) == true){
            primos[j] = i;
            j++;
        }
    }

    //exibe na saída padrão os valores primos no intervalo
    std::cout << "\n ----- Primos no intervalo 2 até " << n << " ------" << std::endl;
    for(int i = 0; i < num_primos; i++){
        std::cout << primos[i] << ' ';
    }

    if(interface_saveFale() == true){
        char nameFile[50];
        std::cout << "\nEntre com o nome do arquivo: [sem espaços]" << std::endl;
        std::cin >> nameFile;

        std::ofstream file;
        if(writeFile(file, nameFile)){
            for(int i = 0; i < num_primos; i++){
                file << primos[i] << ' ';
            }
        }
    }


    return 0;
}

int count_quantPrimosAte(int m)
{
    int count_primos = 0;
    
    for(int i = 2; i < m; i++){
        if(numPrimo(i) == true){
            count_primos++;
        }
    }

    return count_primos;
}

bool numPrimo(int num)
{
    for(int i=2; i < num; i++){
        if((num % i) == 0){
            return false;
        } 
    }
    return true;
}

bool writeFile(std::ofstream& out_to_file, char* name){
    out_to_file.open(name);
    return out_to_file.is_open() && out_to_file.good() && !out_to_file.fail();
}

bool interface_saveFale()
{
    char answer;

    std::cout << "\nDeseja salvar o valores em um arquivo: [y - sim, n - não]" << std::endl;
    std::cin >> answer;

    if(answer == 'y'){
        return true;
    }
    return false;
}


/*
References:

    [1] https://pt.wikibooks.org/wiki/Programar_em_C%2B%2B/Entrada_e_sa%C3%ADda_de_dados_2

*/
