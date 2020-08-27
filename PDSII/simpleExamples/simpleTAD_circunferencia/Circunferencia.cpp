#include "Circunferencia.hpp"
#include <math.h>

Circunferencia::Circunferencia(double x, double y, double r)
{
    this->xc = x;
    this->yc = y;
    this->raio = r;
}

double Circunferencia::calcularArea()
{
    double pi = 3.14;
    return pi*(this->raio*this->raio);
}

bool Circunferencia::possuiIntersecao(Circunferencia* circ)
{
   double ABSdeltaX = std::abs(this->xc-circ->xc);
   double ABSdeltaY = std::abs(this->yc-circ->yc);
   double sumR = this->raio + circ->raio;
   double nRaio = std::sqrt(std::pow(ABSdeltaY,2) + std::pow(ABSdeltaX, 2));

   if(nRaio > sumR){
       return false;
   }
   return true;

}