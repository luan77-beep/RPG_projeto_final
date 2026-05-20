#include <iostream>
#include <string>
#include "equipamento.hpp"
#include "classe.hpp"
#include "ficha.hpp"

Ficha::Ficha(std::string nome, int idade, IClasse* classe, IEquipamento* equipamento){
    this -> nome = nome,
    this -> idade = idade,
    this -> classe = classe,
    this -> equipamento = equipamento;
}

void Ficha::status() {
    std::cout << "\n=== " << nome << " ===\n";
    std::cout << "Vida: " << vida << "\n";
    std::cout << "Idade: " << idade << "\n";
    std::cout << "Classe: " << classe << "\n";
    std::cout << "Arma: " << equipamento <<equipamento->getDano() << "\n";
    std::cout << "Resistência: " << resistencia << std::endl;
}
