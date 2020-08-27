#include <iostream>
#include "Circunferencia.hpp"

int main(){

    Circunferencia c1 = {3,0,2};
    Circunferencia c2 = {-3,0,2};

    std::cout << "Área circunferencia 1: " << c1.calcularArea() << std::endl;
    std::cout << "C1 faz intersecção com C2: " << c1.possuiIntersecao(&c2) << std::endl;

    return 0;
}