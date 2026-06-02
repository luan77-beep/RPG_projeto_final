# RPG_projeto_final

# RPG de Terminal - Jogo de Turnos em C++

Este é um projeto de um jogo de RPG baseado em texto para terminal desenvolvido em C++. O jogo apresenta um sistema dinâmico de escolha de classes (Mago, Guerreiro, Arqueiro), gerenciamento de equipamentos com bônus calculados em tempo real, mecânicas de combate baseadas em turnos com rolagem de dados interativa, além de efeitos estéticos como delays dramáticos e efeito de digitação (*typewriter*) no terminal.

## 🛠️ Pré-requisitos

Para compilar e executar este projeto, você precisará de:

* Um compilador que suporte **C++17** ou superior (como o `g++` da coleção GCC, Clang ou MSVC). *Nota: O C++17 é necessário devido ao uso de propriedades `inline static` nas classes.*
* Ambiente Linux, macOS ou Windows com suporte a terminais ANSI (para o correto funcionamento dos efeitos de captura de tecla instantânea e paginação de texto).

---

## 🚀 Instruções de Compilação e Execução

Como o projeto possui múltiplos arquivos de implementação (`.cpp`) distribuídos em pastas, a compilação precisa incluir todos os módulos de forma explícita.

### Método 1: Compilação Direta via Terminal (g++)

Abra o terminal na raiz do projeto (onde o arquivo `main.cpp` está localizado) e execute o comando abaixo de acordo com seu sistema operacional:

#### No Linux / macOS:

```bash
g++ -std=c++17 main.cpp inimigo.cpp ficha/ficha.cpp ficha/equipamento.cpp mecanicas/funcoes.cpp mecanicas/combate.cpp -o jogo

```

#### No Windows (MinGW / PowerShell):

```powershell
g++ -std=c++17 main.cpp inimigo.cpp ficha/ficha.cpp ficha/equipamento.cpp mecanicas/funcoes.cpp mecanicas/combate.cpp -o jogo.exe

```
## 🎮 Como Executar

Após realizar a compilação com sucesso usando qualquer um dos métodos acima, um arquivo executável terá sido gerado na raiz do projeto. Para iniciar o jogo, utilize:

#### No Linux / macOS:

```bash
./jogo

```

#### No Windows:

```powershell
.\\jogo.exe

```

---

## 🕹️ Funcionalidades Implementadas e Demonstração Técnica

1. **Gestão Segura de Memória:** Alocação dinâmica polimórfica para as classes (`IClasse*`) e estruturas de armas (`Equipamento*`), com desalocação limpa no escopo correto, evitando vazamentos (*memory leaks*) e ponteiros inválidos (`free(): invalid pointer`).
2. **Efeito de Digitação:** As mensagens de narrativa e ambientação utilizam um sistema de escoamento de buffer (`std::flush`) com pausas medidas por caractere, criando imersão de RPG clássico.
3. **Captura Avançada de Input:** Sistema de combate que interrompe o fluxo de execução esperando uma resposta física do hardware (pressionar a **Barra de Espaço** ou a **Seta para Cima**) para rolar os dados, sem a necessidade de pressionar a tecla *Enter*.
