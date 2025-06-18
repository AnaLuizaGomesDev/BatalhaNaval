# 🚢 Batalha Naval em C

Um clássico jogo de Batalha Naval implementado em linguagem C, desenvolvido como projeto acadêmico para a disciplina de APC1 (Algoritmos e Programação de Computadores 1).

## 🎯 Funcionalidades

- **Tabuleiro 5x5** com coordenadas A-E (colunas) e 1-5 (linhas)
- **3 navios por jogador** posicionados manualmente (usuário) e automaticamente (computador)
- **Sistema de turnos** alternados entre jogador e computador
- **Efeitos visuais** de digitação (typewriter effect) no menu
- **Validação robusta** de entradas do usuário
- **Interface limpa** com atualização de tela entre turnos

## 🛠️ Como Compilar e Executar

### Windows
```bash
gcc batalha_naval.c -o batalha_naval.exe
./batalha_naval.exe
```
### Linux
```bash
gcc batalha_naval.c -o batalha_naval
./batalha_naval
```
## 🕹️ Como Jogar

1. Posicione seus 3 navios digitando coordenadas (ex: A1, B3, E5)

2. Alterne turnos atacando coordenadas no tabuleiro inimigo

3. Vença afundando todos os navios do oponente!

## 📝 Notas Técnicas
- Desenvolvido usando apenas a função main()

- Implementação com matrizes bidimensionais

- Código comentado para fácil entendimento

- Compatível com Windows e Linux

## 👨‍💻 Autor
[Ana Luiza Gomes de Lima]

[Ciência da Computação] - [IESB]

[2025]

## Elementos importantes para incluir:

1. **Capturas de Tela**
 ![image](https://github.com/user-attachments/assets/d8818305-ac66-4c21-a71e-7b54a301b26b)
 ![image](https://github.com/user-attachments/assets/82c038e6-ac6a-4c55-be84-035f6c9aac38)
 ![image](https://github.com/user-attachments/assets/9b5e1d6c-36fb-4b11-9e03-61086609cef8)
 ![image](https://github.com/user-attachments/assets/2210f3e0-329e-4ebe-907e-5047d4433ced)

3. **Estrutura do Código**:
   ```plaintext
   /batalha_naval
   │── batalha_naval.c    # Código fonte principal
   │── README.md          # Este arquivo

## 💡 Desafios e Aprendizados

- Implementação de efeitos visuais sem funções adicionais
- Validação de entrada do usuário robusta
- Conversão entre coordenadas alfabéticas e índices de matriz
