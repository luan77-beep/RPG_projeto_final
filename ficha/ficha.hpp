#ifndef FICHA_HPP
#define FICHA_HPP

#include <string>
#include "classe.hpp"
#include "equipamento.hpp"

class Ficha{
private:
    std::string nome;
    int idade;
    IClasse* classe;
    IEquipamento* equipamento;
    int vida = (*classe).getVida();
    double resistencia = 0.02 + (*classe).getBonusResistencia();


public:
    Ficha(std::string nome, int idade, IClasse* classe, IEquipamento* equipamento);
    int getVida() {return vida;}
    std::string getNome() {return nome;}
    int getIdade() {return idade;}
    double getResistencia() {return resistencia;}

    void setVida(int novaVida) {vida = novaVida;}
    void setResistencia(double novaResistencia) {resistencia = novaResistencia;}
    void setClasse(IClasse* novaClasse) {classe = novaClasse;}
    void setEquipamento(IEquipamento* novoEquipamento) {equipamento = novoEquipamento;}

};
#endif