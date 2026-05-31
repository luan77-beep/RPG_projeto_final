#include "equipamento.hpp"

double danoEspada = 7.5, danoAdagas = 7.0, danoArco = 9.0, danoLanca = 8.0;
Equipamento setEquipamento(Equipaveis e, double danoBonus){
    Equipamento equip {};
    switch (e){
        case (espada):
            equip = {"espada", danoEspada * ( 1 + danoBonus)};
            break;
        case (adagas):
            equip = {"adagas", danoAdagas * (1 + danoBonus)};
            break;
        case (lanca):
            equip = {"lança", danoLanca * (1+ danoBonus)};
            break;
        case (arco):
            equip = {"arco", danoArco * (1 + danoBonus)};
            break;
    }
    return equip;
}