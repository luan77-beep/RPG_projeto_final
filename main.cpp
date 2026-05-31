#include <string>
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "mecanicas/combate.hpp"
#include "ficha/classe.hpp"
#include "ficha/equipamento.hpp"
#include "ficha/ficha.hpp"
#include "inimigo.hpp"
#include "mecanicas/funcoes.hpp"

int main() {
    // Inicializa a semente para os "dados" do combate serem realmente aleatórios
    std::srand(std::time(nullptr));

    digitar("Seja bem-vindo!\n");
    std::string nome;
    int idade, nClasse, nEquipamento;
    digitar("Digite o nome do seu personagem: ");
    std::getline(std::cin, nome);
    digitar("Digite a idade: ");
    std::cin >> idade;
    
    digitar("Escolha a sua classe:\n 1 - Mago\n 2 - Guerreiro\n 3 - Arqueiro\n");
    std::cin >> nClasse;
    digitar("Digite o seu equipamento:\n0 - espada\n1 - adagas\n2 - lanca\n3 - arco\n");
    std::cin >> nEquipamento;

    // Correção: Uso de ponteiros com alocação dinâmica para evitar falha de segmentação
    IClasse* classe = nullptr;
    switch (nClasse){
        case 1:
            classe = new Mago();
            break;
        case 2:
            classe = new Guerreiro();
            break;
        case 3:
            classe = new Arqueiro();
            break;
        default:
            std::cout << "Classe inválida! Assumindo Guerreiro.\n";
            classe = new Guerreiro();
            break;
    }

    Equipaveis equipado = static_cast<Equipaveis>(nEquipamento);
    // Correção: Alocando o equipamento corretamente na memória
    Equipamento* equip = new Equipamento(setEquipamento(equipado, classe->getBonusDano()));

    Ficha Jogador(nome, idade, classe, equip);

    std::cout << "\n============================================\n";
    digitar("Olá ");
    digitar(Jogador.getNome()); 
    digitar("!\n");
    digitar("Nosso mundo está repleto de malfeitores que precisam ser derrotados.\n"); 
    digitar("Sua tarefa será derrotar três vilões para nós.\n");
    std::cout << "============================================\n";

    int opcao;
    int quantInimigos = 3;

    do {
        std::cout << "\n=== MENU ===\n";
        std::cout << "1 - Status\n";
        std::cout << "2 - Lutar\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;

        double vidaAntes = Jogador.getVida();

        switch(opcao) {
            case 1:
                Jogador.status();
                esperar(5000);
                break;
            case 2: {
                // Início da narrativa e sistema de spawn de inimigos
                digitar("\nVocê avança pelas trilhas escuras da floresta...\n");
                digitar("A neblina densa dificulta sua visão, mas um som de galhos quebrando chama sua atenção.\n");
                
                // Gera um inimigo aleatório
                Inimigo* inimigoAtual = nullptr;
                
                if (quantInimigos == 3) {
                    inimigoAtual = new Inimigo("Lobo Selvagem", 35.0, 7.0);
                } else if (quantInimigos == 2) {
                    inimigoAtual = new Inimigo("Bandido da Estrada", 50.0, 8.0);
                } else if (quantInimigos == 1) {
                    inimigoAtual = new Inimigo("Orc Desgarrado", 65.0, 10.0);
                }

                digitar("\nDas sombras, surge um ");
                digitar(inimigoAtual->getNome());
                std::cout << std::endl;
                digitar("Prepare-se para a batalha!\n");
                std::cout << "--------------------------------------------\n";

                // Inicia o loop de combate
                combate(Jogador, *inimigoAtual);

                // Consequências pós-combate
                if (Jogador.getVida() > 0) {
                    digitar("\nOfegante e com a adrenalina baixando, você guarda sua arma.\n");
                    digitar("O ");
                    digitar(inimigoAtual->getNome()); 
                    digitar(" cai sem vida aos seus pés. Você conquistou prestígio!\n");
                    digitar("Bônus da vitória: restaura 40\% da vida perdida e aumenta 20\% do dano e ganha mais 2\% de resistência.");
                    double vidaPerdida = vidaAntes - Jogador.getVida();
                    Jogador.setVida(Jogador.getVida() + 0.5 * vidaPerdida);
                    Jogador.getEquipamento().dano += Jogador.getEquipamento().dano * 0.2; 
                    Jogador.setResistencia(Jogador.getResistencia() + 0.02);

                    delete inimigoAtual;
                    quantInimigos --;

                } else {
                    digitar("\nA dor é insuportável. Suas pernas fraquejam e a escuridão toma conta...\n");
                    digitar("Sua jornada termina aqui.\n");
                    digitar("GAME OVER", 60);
                    std::cout << std::endl;
                }
                if (quantInimigos == 0){
                    digitar("Você conseguiu derrotar todos os inimigos!\n");
                    digitar("Nosso povo será eternamente grato.");
                    std::cout << std::endl;
                    break;
                }
                break;
            }
            case 0:
                std::cout << "Saindo do jogo...\n";
                break;

            default:
                std::cout << "Opção inválida!\n";
        }

    } while (opcao != 0 && Jogador.getVida() > 0);

    //liberar a memória alocada dinamicamente
    delete classe;
    delete equip;

    return 0;
}