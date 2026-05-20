#include <string>
#include "inimigo.hpp"

Inimigo::Inimigo(std::string nome, int vida, int dano){
    this -> nome = nome;
    this -> vida = vida;
    this -> dano = dano;
}