#ifndef FUNCOES_HPP
#define FUNCOES_HPP

#include <thread>
#include <chrono>
#include <unistd.h>
#include <termios.h>
#include <iostream>
#include <string>

char lerTeclaInstantanea();

void esperarJogadorRolarDados();

void esperar(int milisseg);

void digitar(const std::string& texto, int velocidade = 35);

#endif