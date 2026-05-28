#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "mecanicas/combate.hpp"
#include "ficha/classe.hpp"
#include "ficha/equipamento.hpp"
#include "ficha/ficha.hpp"
#include "inimigo.hpp"

int main() {
    std::cout << "Seja bem-vindo!\n";
    std::string nome;
    int idade, nClasse, nEquipamento;
    std::cout << "Digite o nome do seu personagem e a idade: ";
    std::cin >> nome >> idade;
    
    std::cout << "Escolha a sua classe:\n 1 - Mago\n 2 - Guerreiro\n 3 - Arqueiro\n";
    std::cin >> nClasse;
    std::cout << "Digite o seu equipamento:\n0 - espada\n1 - adagas\n2 - lanca\n3 - arco\n";
    std::cin >> nEquipamento;

    IClasse* classe;
    Equipamento* equip;
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
    Equipaveis equipado = static_cast<Equipaveis>(nEquipamento);
    *equip = setEquipamento(equipado, classe -> getBonusDano());

    Ficha Jogador(nome, idade, classe, equip);

    std::cout << "Olá " << Jogador.getNome() << "!\n";
    std::cout << "Nosso mundo está repleto de malfeitores que precisam ser derrotados."; 
    std::cout << "Seus alvos são determinados de acordo com seu prestígio."; 
    std::cout << "Você adquire prestígio derrotando inimigos.";
    int nviloes = 15;
    int opcao;

    do {
        std::cout << "\n=== MENU ===\n";
        std::cout << "1 - Status\n";
        std::cout << "2 - Lutar\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;

        switch(opcao) {
            case 1:
                Jogador.status();
                break;
            case 2:
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