#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ficha/classe.hpp"
#include "ficha/equipamento.hpp"
#include "ficha/ficha.hpp"
#include "inimigo.hpp"

void combate(Ficha &ficha, Inimigo &inimigo);

int main() {
    std::srand(std::time(nullptr));
    std::string nome;
    int idade, nClasse, nEquipamento;
    std::cout << "Digite o nome do seu personagem e a idade: ";
    std::cin >> nome >> idade;
    
    std::cout << "Escolha a sua classe:\n 1 - Mago\n 2 - Guerreiro\n 3 - Arqueiro\n";
    std::cin >> nClasse;
    std::cout << "Escolhe o seu equipamento:\n 1 - Espada\n 2 - Adagas\n 3 - Lança\n 4 - Arco\n";
    std::cin >> nEquipamento;

    IClasse* classe;
    IEquipamento* equip;
    switch (nClasse){
        case (1):
            *classe = Mago();
            break;
        case(2):
            *classe = Guerreiro();
            break;
        case(3):
            *classe = Arqueiro();
            break;
    }
    switch (nEquipamento){
        case(1):
            *equip = Espada();
            break;
        case(2):
            *equip = Adagas();
            break;
        case(3):
            *equip = Lanca();
            break;
        case(4):
            *equip = Arco();
            break;
    }

    Ficha Jogador(nome, idade, classe, equip);
    Jogador.getEquipamento().setDano(Jogador.getEquipamento().getDano() * (1 + Jogador.getClasse().getBonusDano()));

    int opcao;

    do {
        std::cout << "\n=== MENU ===\n";
        std::cout << "1 - Status\n";
        std::cout << "2 - Explorar\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;

        switch(opcao) {
            case 1:
                Jogador.status();
                break;
            
            

            case 0:
                std::cout << "Saindo do jogo...\n";
                break;

            default:
                std::cout << "Opção inválida!\n";
        }

    } while (opcao != 0 && Jogador.getVida() > 0);

    return 0;
}