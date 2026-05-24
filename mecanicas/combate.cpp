#include "ficha/ficha.hpp"
#include "inimigo.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "combate.hpp"

void combate(Ficha &jogador, Inimigo &inimigo){
    std::cout << "Um inimigo apareceu: " << inimigo.getNome() << " com " << inimigo.getVida() << " de vida e " << inimigo.getDano() << " de dano!\n";
    double danoInimigo = inimigo.getDano();
    double danoJogador = jogador.getEquipamento().getDano();
    bool playerTurno;

    int escolhaPar;
        std::cout << "Quem ataca primeiro?\nDigite 0 para par ou 1 para ímpar: ";
        std::cin >> escolhaPar;
        int dadoEscolha = std::rand() % 7 + 1;
        if (dadoEscolha % 2 == escolhaPar) {
            std::cout << "Dado: " << dadoEscolha << " - Você ataca primeiro!\n";
            playerTurno = true;
        } else {
            std::cout << "Dado: " << dadoEscolha << " - O inimigo ataca primeiro!\n";
            playerTurno = false;
        }

    while (jogador.getVida() > 0 && inimigo.getVida() > 0) {
        double parcial = 0.3;
        double critico = 1.5;

        int dadoAtaque = std::rand() % 7 + 1;
        int dadoDefesa = std::rand() % 7 + 1;

        switch (playerTurno){
            case true:        
                if (dadoDefesa > dadoAtaque && dadoDefesa == 6) {
                    std::cout << "Inimigo devolveu o dano\n";
                    jogador.setVida(jogador.getVida() - (1 - jogador.getClasse().getBonusResistencia()) * (danoJogador / 2));
                } else if (dadoAtaque > dadoDefesa && dadoAtaque == 6) {
                    std::cout << "Acerto crítico! Dano aumentado.\n";
                    inimigo.setVida(inimigo.getVida() - (danoJogador * critico));
                } else if (dadoAtaque > dadoDefesa) {
                    std::cout << "Acerto normal! Dano aplicado.\n";
                    inimigo.setVida(inimigo.getVida() - danoJogador);
                } else {
                    std::cout << "Defesa bem-sucedida! Dano reduzido.\n";
                    inimigo.setVida(inimigo.getVida() - (danoJogador * parcial));
                }
                playerTurno = false;
                break;
            
            case false:
                if (dadoDefesa > dadoAtaque && dadoDefesa == 6) {
                    std::cout << "Você devolveu o dano\n";
                    inimigo.setVida(inimigo.getVida() - (danoInimigo / 2));
                } else if (dadoAtaque > dadoDefesa && dadoAtaque == 6) {
                    std::cout << "Inimigo acertou um crítico! Dano aumentado.\n";
                    jogador.setVida(jogador.getVida() - (1 - jogador.getClasse().getBonusResistencia()) * (danoInimigo * critico));
                } else if (dadoAtaque > dadoDefesa) {
                    std::cout << "Inimigo acertou um ataque normal! Dano aplicado.\n";
                    jogador.setVida(jogador.getVida() - (1 - jogador.getClasse().getBonusResistencia()) * (danoInimigo));
                } else {
                    std::cout << "Você defendeu o ataque! Dano reduzido.\n";
                    jogador.setVida(jogador.getVida() - (1 - jogador.getClasse().getBonusResistencia()) * (danoInimigo * parcial));
                }
                playerTurno = true;
                break;
        }

        if (inimigo.getVida() <= 0) {
            inimigo.setVida(0);
            std::cout << "Você derrotou o inimigo!\n";
        }
        if (jogador.getVida() <= 0) {
            jogador.setVida(0);
            std::cout << "Você foi derrotado pelo inimigo...\n";
        }
    }
}