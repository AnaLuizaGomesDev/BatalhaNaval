#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>

//Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//Regular bold text
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

//Regular underline text
#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"

//Regular background
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"

//High intensty background 
#define BLKHB "\e[0;100m"
#define REDHB "\e[0;101m"
#define GRNHB "\e[0;102m"
#define YELHB "\e[0;103m"
#define BLUHB "\e[0;104m"
#define MAGHB "\e[0;105m"
#define CYNHB "\e[0;106m"
#define WHTHB "\e[0;107m"

//High intensty text
#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"

//Bold high intensity text
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"

//Reset
#define reset "\e[0m"
#define CRESET "\e[0m"
#define COLOR_RESET "\e[0m"

#ifdef _WIN32
#endif

#define TAM 5 // Tabuleiro 5x5

int main(){
    //configuracao inicial

    // configuração de linguagem
    #ifdef _WIN32
    SetConsoleOutputCP(65001);  // 65001 é o código para UTF-8 p/ usar caracteres especiais
    #endif

    //Tabuleiros: 0 = água, 1 = navio, -1 = tiro na água, -2 = navio atingido
    int jogador[TAM][TAM] = {0}; //tabuleiro do jogador
    int computador[TAM][TAM] = {0}; //tabuleiro do computador
    int opcao = 0;// opcao do menu
    char x_char;
    int x,y; // variáveis para as coordenadas
    int navios_jogador = 3; //numero de navios do jogador
    int navios_computador = 3; // numero de navios do computador

    do{
        system("cls");// limpa a tela

        //zera os tabuleiros
        for(int i=0; i<TAM; i++){
            for(int j=0; j < TAM; j++){
                jogador[i][j] = 0;
                computador[i][j] = 0;
            }
        }

        // efeito typewriter para o título
        char *titulo[] = {
            "==============================================================================================================",
            "     ______       _        _ _             _   _                  _ ", 
            "     | ___ \\     | |      | | |           | \\ | |                | |                   __/___            ",
            "     | |_/ / __ _| |_ __ _| | |__   __ _  |  \\| | __ ___   ____ _| |             _____/______|           ",
            "     | ___ \\/ _` | __/ _` | | '_ \\ / _` | | . ` |/ _` \\ \\ / / _` | |     _______/_____\\_______\\_____     ",
            "     | |_/ / (_| | || (_| | | | | | (_| | | |\\  | (_| |\\ V / (_| | |     \\              < < <       |    ",
            "     \\____/ \\__,_|\\__\\__,_|_|_| |_|\\__,_| \\_| \\_/\\__,_| \\_/ \\__,_|_|   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ",
            "                                                                         ",
            "==============================================================================================================",
            NULL// marca o final do array
        };

        int total = 9;

        for (int i = 0; i < total; i++) {
        for (int j = 0; titulo[i][j] != '\0'; j++) {
            printf(BHCYN "%c", titulo[i][j]);
            fflush(stdout);     // força a impressão imediata do caractere
            Sleep(0);          // espera 50 milissegundos entre cada caractere
            }
        printf("\n");
        }


        //menu do jogo
        printf(BHWHT"\n*** Seja Bem vindo(a) ao Menu do Jogo ***\n\n");
        printf(HWHT" 1 - Iniciar Jogo\n");
        printf(HWHT" 2 - Regras\n");
        printf(HWHT" 3 - Créditos\n");
        printf(HWHT" 4 - Sair do Jogo\n\n");
        printf(HWHT" Opção: ");
        scanf("%d", &opcao);
        while(getchar() != '\n'); // limpa o buffer

        switch(opcao){
            case 1: {
                srand(time(NULL)); // inicializa o gerador de numeros aleatorios
                
                system("cls");

                printf(BHCYN"==============================================================================================================\n");
                printf(BHCYN"     ______       _        _ _             _   _                  _ \n");
                printf(BHCYN"     | ___ \\     | |      | | |           | \\ | |                | |                   __/___            \n");
                printf(BHCYN"     | |_/ / __ _| |_ __ _| | |__   __ _  |  \\| | __ ___   ____ _| |             _____/______|           \n");
                printf(BHCYN"     | ___ \\/ _` | __/ _` | | '_ \\ / _` | | . ` |/ _` \\ \\ / / _` | |     _______/_____\\_______\\_____     \n");
                printf(BHCYN"     | |_/ / (_| | || (_| | | | | | (_| | | |\\  | (_| |\\ V / (_| | |     \\              < < <       |    \n");
                printf(BHCYN"     \\____/ \\__,_|\\__\\__,_|_|_| |_|\\__,_| \\_| \\_/\\__,_| \\_/ \\__,_|_|   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
                printf(BHCYN"                                                                         \n");
                printf(BHCYN"==============================================================================================================\n");
                
                // posiciona navios do jogador
                printf(BHWHT"\n*** POSICIONE SEUS NAVIOS ***\n\n");
                for(int i = 1; i <= 3; i++){
                    int valido = 0;
                    do {
                        printf(HWHT"Navio %d - Digite as coordenadas (ex: A1): ", i);
                        if(scanf(" %c%d", &x_char, &y) != 2) {
                            printf(HRED"Entrada inválida! Use como exemplo: B3\n");
                            while(getchar() != '\n'); // Limpa o buffer
                            continue;
                        }
                        while(getchar() != '\n'); // Limpa o buffer

                        //converte letra maiuscula e depois para índice(A=0, B=1,etc.)
                        x_char = toupper(x_char); // faz uma conversão de letra maiúscula para minúscula e armazena o resultado de volta na variável x_char
                        x= x_char - 'A'; //converte para 0-4
                        y--;//converte para 0-4

                        if(x < 0 || x >= TAM || y < 0 || y >= TAM){
                            printf(HRED"Coordenadas inválidas! Use de A1 a E5.\n");
                        } else if (jogador[y][x] == 1){
                            printf(HRED"Você já posicionou um navio aqui!\n");
                        } else{
                            valido = 1;
                        }
                    } while (!valido);

                    jogador[y][x] = 1; //marca a posição com um navio
                    printf(HWHT"Navio posicionado em %c%d!\n\n", x_char, y+1);
                }

                printf(HCYN"Pressione Enter para continuar...");
                while(getchar() != '\n');

                // posiciona navios do computador (aleatório)
                for(int i=0; i<3;i++){
                    do{
                        x = rand() % TAM; // gera x entre 0 e 4
                        y = rand() % TAM; // gera y entre 0 e 4
                    } while (computador[y][x] == 1); // evita repetição

                    computador[y][x] = 1; // marca a posição com um navio
                }
                
                system("cls");
                printf(BHCYN"==============================================================================================================\n");
                printf(BHCYN"     ______       _        _ _             _   _                  _ \n");
                printf(BHCYN"     | ___ \\     | |      | | |           | \\ | |                | |                   __/___            \n");
                printf(BHCYN"     | |_/ / __ _| |_ __ _| | |__   __ _  |  \\| | __ ___   ____ _| |             _____/______|           \n");
                printf(BHCYN"     | ___ \\/ _` | __/ _` | | '_ \\ / _` | | . ` |/ _` \\ \\ / / _` | |     _______/_____\\_______\\_____     \n");
                printf(BHCYN"     | |_/ / (_| | || (_| | | | | | (_| | | |\\  | (_| |\\ V / (_| | |     \\              < < <       |    \n");
                printf(BHCYN"     \\____/ \\__,_|\\__\\__,_|_|_| |_|\\__,_| \\_| \\_/\\__,_| \\_/ \\__,_|_|   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
                printf(BHCYN"                                                                         \n");
                printf(BHCYN"==============================================================================================================\n");
                printf(HWHT"\nO computador posicionou seus navios!\n\n");
                printf(HCYN"Pressione Enter para começar o jogo...");
                while(getchar() != '\n');

                // loop principal do jogo
                while (navios_jogador > 0 && navios_computador > 0){

                    system("cls");
                    //turno do jogador
                    printf(BHCYN"==============================================================================================================\n");
                    printf(BHCYN"     ______       _        _ _             _   _                  _ \n");
                    printf(BHCYN"     | ___ \\     | |      | | |           | \\ | |                | |                   __/___            \n");
                    printf(BHCYN"     | |_/ / __ _| |_ __ _| | |__   __ _  |  \\| | __ ___   ____ _| |             _____/______|           \n");
                    printf(BHCYN"     | ___ \\/ _` | __/ _` | | '_ \\ / _` | | . ` |/ _` \\ \\ / / _` | |     _______/_____\\_______\\_____     \n");
                    printf(BHCYN"     | |_/ / (_| | || (_| | | | | | (_| | | |\\  | (_| |\\ V / (_| | |     \\              < < <       |    \n");
                    printf(BHCYN"     \\____/ \\__,_|\\__\\__,_|_|_| |_|\\__,_| \\_| \\_/\\__,_| \\_/ \\__,_|_|   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
                    printf(BHCYN"                                                                         \n");
                    printf(BHCYN"==============================================================================================================\n");
                    printf(BHWHT"\n*** SEU TURNO ***\n");
                    printf(HWHT"Navios restantes: Você %d x Computador %d\n", navios_jogador, navios_computador);

                    // mostra o tabuleiro do computador (escondendo navios)
                    printf(HWHT"\nTabuleiro do Computador:\n");
                    printf(BHWHT"  A B C D E\n");
                    for(int i = 0; i < TAM; i++){
                        printf(BHWHT"%d ", i+1);
                        for(int j=0; j < TAM; j++){
                            if (computador[i][j] == -1) printf(HRED"X ");
                            else if (computador[i][j] == -2) printf(HGRN"* ");
                            else printf(HBLU". ");
                        }
                        printf("\n");
                    }

                    int valido = 0;
                    do{
                        printf(HWHT"\nDigite as coordenadas para atacar(ex: C4): ");
                        if(scanf(" %c%d", &x_char, &y) != 2) {
                            printf(HRED"Entrada inválida! Use como exemplo: B3\n");
                            while(getchar() != '\n'); //limpa o buffer
                            continue;
                        }
                        while(getchar() != '\n');

                        x_char = toupper(x_char);
                        x = x_char - 'A';
                        y--;

                        //validacao
                        if(x < 0 || x >= TAM || y < 0 || y >= TAM){
                            printf(HRED"Coordenadas inválidas! Use de A1 a E5.\n");
                        } else if (computador[y][x] == -1 || computador[y][x] == -2){
                            printf(HRED"Você já atirou aqui!\n");
                        } else{
                            valido = 1;
                        }
                    } while (!valido);

                    // verifica se acertou um navio
                    if(computador[y][x] == 1){
                        printf(BHGRN"\n *** Você acertou um navio em %c%d! ***\n", x_char, y+1);
                        computador[y][x] = -2; // marca como navio atingido
                        navios_computador--;
                    } else{
                        printf(BHRED"\n*** Você atingiu a água em %c%d! ***\n", x_char, y+1);
                        computador[y][x] = -1; // marca como tiro na água
                    }

                    //pausa para o jogador ver o resultado
                    printf(HCYN"\nPressione Enter para continuar...");
                    while(getchar() != '\n'); //limpa o buffer

                    if(navios_computador == 0) break;
                    
                    // limpa antes do turno do computador
                    system("cls");

                    // turno do computador (se ainda houver navios do jogador)
                    if(navios_jogador > 0){
                        printf("==============================================================================================================\n");
                        printf("     ______       _        _ _             _   _                  _ \n");
                        printf("     | ___ \\     | |      | | |           | \\ | |                | |                   __/___            \n");
                        printf("     | |_/ / __ _| |_ __ _| | |__   __ _  |  \\| | __ ___   ____ _| |             _____/______|           \n");
                        printf("     | ___ \\/ _` | __/ _` | | '_ \\ / _` | | . ` |/ _` \\ \\ / / _` | |     _______/_____\\_______\\_____     \n");
                        printf("     | |_/ / (_| | || (_| | | | | | (_| | | |\\  | (_| |\\ V / (_| | |     \\              < < <       |    \n");
                        printf("     \\____/ \\__,_|\\__\\__,_|_|_| |_|\\__,_| \\_| \\_/\\__,_| \\_/ \\__,_|_|   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
                        printf("                                                                         \n");
                        printf("==============================================================================================================\n");
                        printf(BHWHT"\n*** TURNO DO COMPUTADOR ***\n");
                        printf(HWHT"Navios restantes: Você %d x Computador %d\n", navios_jogador, navios_computador);
                        do{
                            x = rand() % TAM;
                            y = rand() % TAM;
                        } while (jogador[y][x] == -1|| jogador[y][x] == -2);

                        // mostra o tabuleiro do jogador (escondendo navios)
                        printf(HWHT"\nTabuleiro do Jogador:\n");
                        printf(BHWHT"  A B C D E\n");
                        for(int i = 0; i < TAM; i++){
                            printf(BHWHT"%d ", i+1);
                            for(int j=0; j < TAM; j++){
                                if (jogador[i][j] == -1) printf(HRED"X ");
                                else if (jogador[i][j] == -2) printf(HGRN"* ");
                                else printf(HBLU". ");
                            }
                            printf("\n");
                        }

                        if(jogador[y][x] == 1){
                            printf(BHGRN"\n*** O computador acertou seu navio em %c%d! ***\n", 'A'+x,y+1);
                            jogador[y][x] = -2; // marca como navio atingido
                            navios_jogador--;
                        } else{
                            printf(BHRED"\n*** O computador atirou em %c%d e errou! ***\n", 'A'+x, y+1);
                            jogador[y][x] = -1;
                        }
                    }

                    //pausa para o jogador ver o resultado
                    printf(HCYN"\nPressione Enter para continuar...");
                    while(getchar() != '\n');
                }

                // fim de jogo
                system("cls");

                printf(BHCYN"==============================================================================================================\n");
                printf(BHCYN"     ______       _        _ _             _   _                  _ \n");
                printf(BHCYN"     | ___ \\     | |      | | |           | \\ | |                | |                   __/___            \n");
                printf(BHCYN"     | |_/ / __ _| |_ __ _| | |__   __ _  |  \\| | __ ___   ____ _| |             _____/______|           \n");
                printf(BHCYN"     | ___ \\/ _` | __/ _` | | '_ \\ / _` | | . ` |/ _` \\ \\ / / _` | |     _______/_____\\_______\\_____     \n");
                printf(BHCYN"     | |_/ / (_| | || (_| | | | | | (_| | | |\\  | (_| |\\ V / (_| | |     \\              < < <       |    \n");
                printf(BHCYN"     \\____/ \\__,_|\\__\\__,_|_|_| |_|\\__,_| \\_| \\_/\\__,_| \\_/ \\__,_|_|   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
                printf(BHCYN"                                                                         \n");
                printf(BHCYN"==============================================================================================================\n");
                printf(BHWHT"\n*** FIM DE JOGO ***\n");
                if(navios_computador == 0){
                    printf(BHGRN"PARABÉNS! Você venceu!\n");
                } else{
                    printf(BHRED"Você perdeu! O computador venceu.\n");
                }

                // mostra tabuleiros finais
                printf(HWHT"\nSeu tabuleiro:\n");
                printf(BHWHT"  A B C D E\n");
                for(int i = 0; i < TAM; i++){
                    printf(BHWHT"%d ", i+1);
                    for(int j = 0; j < TAM; j++){
                        if(jogador[i][j] == -1) printf(HRED"X ");
                        else if(jogador[i][j] == -2) printf(HGRN"* ");
                        else if(jogador[i][j] == 1) printf(HCYN"N ");
                        else printf(HBLU". ");
                    }
                    printf("\n");
                }

                printf(HWHT"\nTabuleiro do Computador:\n");
                printf(BHWHT"  A B C D E\n");
                for(int i = 0; i < TAM; i++){
                    printf(BHWHT"%d ", i+1);
                    for(int j = 0; j < TAM; j++){
                        if(computador[i][j] == -1) printf(HRED"X ");
                        else if(computador[i][j] == -2) printf(HGRN"* ");
                        else if(computador[i][j] == 1) printf(HCYN"N ");
                        else printf(HBLU". ");
                    }
                    printf("\n");
                }
                
                printf(HCYN"\nPressione Enter para voltar ao menu...");
                while(getchar() != '\n');
                break;
            }

            case 2:
                system("cls");
                printf(BHCYN"==============================================================================================================\n");
                printf(BHCYN"     ______       _        _ _             _   _                  _ \n");
                printf(BHCYN"     | ___ \\     | |      | | |           | \\ | |                | |                   __/___            \n");
                printf(BHCYN"     | |_/ / __ _| |_ __ _| | |__   __ _  |  \\| | __ ___   ____ _| |             _____/______|           \n");
                printf(BHCYN"     | ___ \\/ _` | __/ _` | | '_ \\ / _` | | . ` |/ _` \\ \\ / / _` | |     _______/_____\\_______\\_____     \n");
                printf(BHCYN"     | |_/ / (_| | || (_| | | | | | (_| | | |\\  | (_| |\\ V / (_| | |     \\              < < <       |    \n");
                printf(BHCYN"     \\____/ \\__,_|\\__\\__,_|_|_| |_|\\__,_| \\_| \\_/\\__,_| \\_/ \\__,_|_|   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
                printf(BHCYN"                                                                         \n");
                printf(BHCYN"==============================================================================================================\n");
                printf(BHWHT"*** REGRAS ***\n\n");
                printf(HWHT"- Tabuleiro 5x5 (A-E e 1-5)\n");
                printf(HWHT"- Digite coordenadas como 'A1' ou 'C4'\n");
                printf(HWHT"- * = acerto, X = tiro na água, N = navio não afundado\n");
                printf(HWHT"- Afunde todos os navios inimigos para vencer\n");
                printf(HCYN"\nPressione Enter para voltar...");
                while(getchar() != '\n');
                break;

            case 3:
                system("cls");
                printf(BHCYN"==============================================================================================================\n");
                printf(BHCYN"     ______       _        _ _             _   _                  _ \n");
                printf(BHCYN"     | ___ \\     | |      | | |           | \\ | |                | |                   __/___            \n");
                printf(BHCYN"     | |_/ / __ _| |_ __ _| | |__   __ _  |  \\| | __ ___   ____ _| |             _____/______|           \n");
                printf(BHCYN"     | ___ \\/ _` | __/ _` | | '_ \\ / _` | | . ` |/ _` \\ \\ / / _` | |     _______/_____\\_______\\_____     \n");
                printf(BHCYN"     | |_/ / (_| | || (_| | | | | | (_| | | |\\  | (_| |\\ V / (_| | |     \\              < < <       |    \n");
                printf(BHCYN"     \\____/ \\__,_|\\__\\__,_|_|_| |_|\\__,_| \\_| \\_/\\__,_| \\_/ \\__,_|_|   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
                printf(BHCYN"                                                                         \n");
                printf(BHCYN"==============================================================================================================\n");
                printf(BHWHT"\n*** CRÉDITOS ***\n\n");
                printf(HWHT"Desenvolvido por Ana Luiza Gomes\n");
                printf(HWHT"Disciplina: APC1 ( Algoritmos e Programação de Computadores 1 )\n");
                printf(HWHT"Linguagem utilizada: C\n");
                printf(HCYN"\nPressione Enter para voltar...");
                while(getchar() != '\n');
                break;

            case 4:
                system("cls");
                printf(BHCYN"==============================================================================================================\n");
                printf(BHCYN"     ______       _        _ _             _   _                  _ \n");
                printf(BHCYN"     | ___ \\     | |      | | |           | \\ | |                | |                   __/___            \n");
                printf(BHCYN"     | |_/ / __ _| |_ __ _| | |__   __ _  |  \\| | __ ___   ____ _| |             _____/______|           \n");
                printf(BHCYN"     | ___ \\/ _` | __/ _` | | '_ \\ / _` | | . ` |/ _` \\ \\ / / _` | |     _______/_____\\_______\\_____     \n");
                printf(BHCYN"     | |_/ / (_| | || (_| | | | | | (_| | | |\\  | (_| |\\ V / (_| | |     \\              < < <       |    \n");
                printf(BHCYN"     \\____/ \\__,_|\\__\\__,_|_|_| |_|\\__,_| \\_| \\_/\\__,_| \\_/ \\__,_|_|   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
                printf(BHCYN"                                                                         \n");
                printf(BHCYN"==============================================================================================================\n");
                printf(HWHT"\nSaindo do jogo...\n");
            break;

            default:
                system("cls");
                printf(BHCYN"==============================================================================================================\n");
                printf(BHCYN"     ______       _        _ _             _   _                  _ \n");
                printf(BHCYN"     | ___ \\     | |      | | |           | \\ | |                | |                   __/___            \n");
                printf(BHCYN"     | |_/ / __ _| |_ __ _| | |__   __ _  |  \\| | __ ___   ____ _| |             _____/______|           \n");
                printf(BHCYN"     | ___ \\/ _` | __/ _` | | '_ \\ / _` | | . ` |/ _` \\ \\ / / _` | |     _______/_____\\_______\\_____     \n");
                printf(BHCYN"     | |_/ / (_| | || (_| | | | | | (_| | | |\\  | (_| |\\ V / (_| | |     \\              < < <       |    \n");
                printf(BHCYN"     \\____/ \\__,_|\\__\\__,_|_|_| |_|\\__,_| \\_| \\_/\\__,_| \\_/ \\__,_|_|   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
                printf(BHCYN"                                                                         \n");
                printf(BHCYN"==============================================================================================================\n");
                printf(HRED"\nOpção inválida tente novamente!\n");
                system("pause");
            break;
        }
    }while(opcao != 4);

    return 0;
}