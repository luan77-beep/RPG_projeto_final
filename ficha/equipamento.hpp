#ifndef EQUIPAMENTO_HPP
#define EQUIPAMENTO_HPP

double danoEspada = 12.5, danoAdagas = 10.5, danoArco = 13.4, danoLanca = 11.6;

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