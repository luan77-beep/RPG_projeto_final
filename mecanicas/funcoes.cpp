#include <thread>
#include <chrono>
#include <unistd.h>
#include <termios.h>
#include <iostream>
#include <string>
#include "funcoes.hpp"

char lerTeclaInstantanea() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0) perror("tcsetattr()");
    old.c_lflag &= ~ICANON; 
    old.c_lflag &= ~ECHO;   
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0) perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0) perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0) perror("tcsetattr ~ICANON");
    return (buf);
}

void esperarJogadorRolarDados() {
    std::cout << "[Pressione SETA PARA CIMA ou ESPAÇO para rolar os dados]\n";
    
    while (true) {
        char ch = lerTeclaInstantanea();
        
        // Verifica se é a Barra de Espaço
        if (ch == ' ') {
            break; // Sai do loop e rola os dados
        }
        
        // Verifica se iniciou a sequência da Seta (Código de Escape 27)
        if (ch == 27) { 
            char proximo1 = lerTeclaInstantanea(); // deve ser '[' (91)
            char proximo2 = lerTeclaInstantanea(); // deve ser 'A' (65) para Seta pra Cima
            
            if (proximo1 == '[' && proximo2 == 'A') {
                break; // Seta para cima detectada! Sai do loop para rolar os dados
            }
        }
    }
}

void esperar(int milisseg) {std::this_thread::sleep_for(std::chrono::milliseconds(milisseg));}

void digitar(const std::string& texto, int velocidade) {
    for (char letra : texto) {
        std::cout << letra << std::flush; 
        std::this_thread::sleep_for(std::chrono::milliseconds(velocidade));
    }
}