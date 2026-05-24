#include <string>
#include "inimigo.hpp"

Inimigo::Inimigo(std::string nome, double vida, double dano){
    this -> nome = nome;
    this -> vida = vida;
    this -> dano = dano;
}