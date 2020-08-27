#include "Estudante.hpp"

float Estudante::calcularRSG(){
    float sum = 0;
    for(int i=0; i < 5; i++){
        sum += this->notas[i];
    }
    return sum/5;
}