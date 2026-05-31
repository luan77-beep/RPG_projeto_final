#include <iostream>
#include <string>
#include "equipamento.hpp"
#include "classe.hpp"
#include "ficha.hpp"

Ficha::Ficha(std::string nome, int idade, IClasse* classe, Equipamento* equipamento){
    this -> nome = nome,
    this -> idade = idade,
    this -> classe = classe,
    this -> equipamento = equipamento;
    this -> vida = classe -> getVida();
    this -> resistencia = 0.02 + classe -> getBonusResistencia();
}

void Ficha::status() {
    std::cout << "\n=== " << nome << " ===\n";
    std::cout << "Vida: " << vida << "\n";
    std::cout << "Idade: " << idade << "\n";
    std::cout << "Classe: " << classe -> getNome() << "\n";
    std::cout << "Arma: " << equipamento -> nome << " | Dano: " << equipamento -> dano << std::endl;
    std::cout << "Resistência: " << resistencia << std::endl;
}
