#include "../ficha/ficha.hpp"
#include "../inimigo.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <termios.h>
#include "combate.hpp"
#include "../ficha/equipamento.hpp"
#include "funcoes.hpp"

void combate(Ficha &jogador, Inimigo &inimigo){
    std::cout << "Status do inimigo: Vida -> " << inimigo.getVida() << " | Dano -> " << inimigo.getDano() << std::endl;
    double danoInimigo = inimigo.getDano();
    double danoJogador = jogador.getEquipamento().dano;
    bool playerTurno;

    int escolhaPar;

    digitar("Quem ataca primeiro?\nDigite 0 para par ou 1 para ímpar: ");
    std::cin >> escolhaPar;

    digitar("\nRolando os dados.");
    esperar(500);
    std::cout << "."<< std::flush;
    esperar(500);
    std::cout << "." << std::endl;
    esperar(500);

    int dadoEscolha = std::rand() % 6 + 1;
    if (dadoEscolha % 2 == escolhaPar) {
        digitar("Dado: ");
        std::cout << dadoEscolha; 
        digitar(" - Você ataca primeiro!\n");
        playerTurno = true;
    } else {
        digitar("Dado: ");
        std::cout << dadoEscolha; 
        digitar(" - O inimigo ataca primeiro!\n");
        playerTurno = false;
    }
    esperar(3000);

    while (jogador.getVida() > 0 && inimigo.getVida() > 0) {
        double parcial = 0.5;
        double critico = 1.5;
        double danoAplicado;

        int dadoAtaque, dadoDefesa;

        switch (playerTurno){
            case true:
                std::cout << "\n";
                esperarJogadorRolarDados();
                esperar(1000);
                dadoAtaque = std::rand() % 6 + 1;
                std::cout << "Inimigo rolando os dados..." << std::endl;
                esperar(2000);
                dadoDefesa = std::rand() % 6 + 1;
                digitar("Dado ataque = "); 
                std::cout << dadoAtaque << std::endl;
                digitar("Dado defesa = ");
                std::cout << dadoDefesa << std::endl;

                if (dadoDefesa > dadoAtaque && dadoDefesa == 6) {
                    danoAplicado = (1 - jogador.getResistencia()) * (danoJogador / 2);
                    digitar("Inimigo devolveu o dano!\n");
                    jogador.setVida(jogador.getVida() - danoAplicado);
                } else if (dadoAtaque > dadoDefesa && dadoAtaque == 6) {
                    danoAplicado = danoJogador * critico;
                    digitar("Você acertou um crítico! Dano aumentado.\n");
                    inimigo.setVida(inimigo.getVida() - danoAplicado);
                } else if (dadoAtaque > dadoDefesa) {
                    danoAplicado = danoJogador;
                    digitar("Você conseguiu um acerto normal! Dano aplicado.\n");
                    inimigo.setVida(inimigo.getVida() - danoAplicado);
                } else {
                    danoAplicado = danoJogador * parcial;
                    digitar("O inimigo fez uma defesa bem-sucedida! Dano reduzido.\n");
                    inimigo.setVida(inimigo.getVida() - danoAplicado);
                }
                playerTurno = false;
                break;
            
            case false:
                digitar("\nInimigo rolando os dados...\n");
                esperar(2000);
                dadoAtaque = std::rand() % 6 + 1;
                esperarJogadorRolarDados();
                esperar(1000);
                dadoDefesa = std::rand() % 6 + 1;
                digitar("Dado ataque = ");
                std::cout << dadoAtaque << std::endl; 
                digitar("Dado defesa = ");
                std::cout << dadoDefesa << std::endl;

                if (dadoDefesa > dadoAtaque && dadoDefesa == 6) {
                    danoAplicado = danoInimigo / 2;
                    digitar("Você devolveu o dano!\n");
                    inimigo.setVida(inimigo.getVida() - danoAplicado);
                } else if (dadoAtaque > dadoDefesa && dadoAtaque == 6) {
                    danoAplicado = (1 - jogador.getResistencia()) * (danoInimigo * critico);
                    digitar("Inimigo acertou um crítico! Dano aumentado.\n");
                    jogador.setVida(jogador.getVida() - danoAplicado);
                } else if (dadoAtaque > dadoDefesa) {
                    danoAplicado = (1 - jogador.getResistencia()) * danoInimigo;
                    digitar("Inimigo acertou um ataque normal! Dano aplicado.\n");
                    jogador.setVida(jogador.getVida() - danoAplicado);
                } else {
                    danoAplicado = (1 - jogador.getResistencia()) * (danoInimigo * parcial);
                    digitar("Você defendeu o ataque! Dano reduzido.\n");
                    jogador.setVida(jogador.getVida() - danoAplicado);
                }                
                playerTurno = true;
                break;
        }
        digitar("Dano aplicado -> ");
        std::cout << danoAplicado;
        if (inimigo.getVida() < 0){
            inimigo.setVida(0);                   
        } else if (jogador.getVida() < 0){                    
            jogador.setVida(0);
        }
        digitar(" | Vida do inimigo -> ");
        std::cout << inimigo.getVida(); 
        digitar(" | Vida do jogador -> ");
        std::cout << jogador.getVida() << std::endl;
    }
}