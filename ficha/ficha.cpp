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
