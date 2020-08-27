#ifndef CIRCUNFERENCIA_HPP
#define CIRCUNFERENCIA_HPP

struct Circunferencia {
//atributos
double xc, yc, raio;

//construtor
Circunferencia(double x, double y, double r);

//métodos
double calcularArea();
bool possuiIntersecao(Circunferencia* circ);
};

#endif