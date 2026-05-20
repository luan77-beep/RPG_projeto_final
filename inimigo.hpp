#ifndef INIMIGOS_HPP
#define INIMIGOS_HPP

#include <string>

class Inimigo {
private:
    std::string nome;
    int vida;
    int dano;

public:
    Inimigo(std::string nome, int vida, int dano);
    std::string getNome() {return nome;}
    int getVida() {return vida;}
    int getDano() {return dano;}
    void setVida(int novaVida) {vida = novaVida;}
    void setDano(int novoDano) {dano = novoDano;}
};

#endif