#include <string>
#include "equipamento.hpp"

Equipamento setEquipamento(Equipaveis e, double danoBonus){
    switch (e){
        case (espada):
            return Equipamento {"espada", danoEspada * ( 1 + danoBonus)};
            break;
        case (adagas):
            return Equipamento {"adagas", danoAdagas * (1 + danoBonus)};
            break;
        case (lanca):
            return Equipamento {"lança", danoLanca * (1+ danoBonus)};
            break;
        case (arco):
            return Equipamento {"arco", danoArco * (1 + danoBonus)};
            break;
    }
}