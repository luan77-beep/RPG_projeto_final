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
    Equipamento* equipamento;
    double vida;
    double resistencia;

public:
    Ficha(std::string nome, int idade, IClasse* classe, Equipamento* equipamento);
    double getVida() {return vida;}
    std::string getNome() {return nome;}
    int getIdade() {return idade;}
    double getResistencia() {return resistencia;}
    IClasse* getClasse() {return classe;}
    Equipamento& getEquipamento() {return *equipamento;}

    void setVida(double novaVida) {vida = novaVida;}
    void setResistencia(double novaResistencia) {resistencia = novaResistencia;}
    void setClasse(IClasse* novaClasse) {classe = novaClasse;}
    void setEquipamento(Equipamento* novoEquipamento) {equipamento = novoEquipamento;}
    
    void status();
};

#endif