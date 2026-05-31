#ifndef EQUIPAMENTO_HPP
#define EQUIPAMENTO_HPP

#include <string>

extern double danoEspada, danoAdagas, danoArco, danoLanca;

enum Equipaveis{
    espada,
    adagas,
    lanca,
    arco,
};

struct Equipamento {
    std::string nome;
    double dano;
};

Equipamento setEquipamento(Equipaveis e, double danoBonus);

#endif