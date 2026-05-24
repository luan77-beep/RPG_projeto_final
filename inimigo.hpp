#ifndef INIMIGOS_HPP
#define INIMIGOS_HPP

#include <string>

class Inimigo {
private:
    std::string nome;
    double vida;
    double dano;

public:
    Inimigo(std::string nome, double vida, double dano);
    std::string getNome() {return nome;}
    double getVida() {return vida;}
    double getDano() {return dano;}
    void setVida(double novaVida) {vida = novaVida;}
    void setDano(double novoDano) {dano = novoDano;}
};

#endif