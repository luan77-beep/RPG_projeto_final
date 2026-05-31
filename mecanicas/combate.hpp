#ifndef COMBATE_HPP
#define COMBATE_HPP

#include "../ficha/ficha.hpp"
#include "../inimigo.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../ficha/equipamento.hpp"
#include <thread>
#include <chrono>
#include <unistd.h>
#include <termios.h>
#include "funcoes.hpp"

void combate(Ficha &ficha, Inimigo &inimigo);

#endif