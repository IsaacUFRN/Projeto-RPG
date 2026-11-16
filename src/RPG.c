#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/types.h"
#include "src/utils.h"
#include "src/personagem.h"
#include "src/fases.h"
#include "src/combate.h"
#include "src/jogo.h"

int main() {
    srand(time(NULL));

    Personagem jogador;
    Fase fases[3];
    int resultado;
    int i;

    printf("\n==================================================\n");
    printf("         RPG: OS SEGREDOS DA MANSAO SOMBRIA       \n");
    printf("==================================================\n\n");
    
    printf(" [PROLOGO]\n");
    printf(" Uma neblina densa e sufocante cobre os portoes de ferro\n");
    printf(" da antiga mansao abandonada. Atraidos por ecos do passado\n");
    printf(" e pesadelos recorrentes, voces cruzaram a entrada.\n");
    printf(" De repente, as portas pesadas de carvalho se fecham\n");
    printf(" com estrondo atras de voces. A unica saida e avancar\n");
    printf(" pelas alas amaldicoadas e desvendar este misterio...\n");
    printf("==================================================\n");

    criarPersonagem(&jogador);
    exibirStatus(&jogador);
    criarFases(fases);

    for(i = 0; i < 3; i++) {
        resultado = jogarFase(&jogador, &fases[i], i);

        if(resultado == 0 || jogador.vida <= 0) {
            printf("\n==================================================\n");
            printf("                    GAME OVER                     \n");
            printf("==================================================\n");
            printf(" Voce foi consumido pelas sombras da mansao...\n");
            printf("==================================================\n");
            return 0;
        }

        printf("\n==================================================\n");
        printf("              FASE %d CONCLUIDA!                  \n", i + 1);
        printf("==================================================\n");

        if(i < 2) {
            recuperarVida(&jogador, jogador.vidaMaxima);
            printf(" Voce descansou em um local seguro e recuperou\n");
            printf(" toda a sua vida (%d/%d)!\n", jogador.vida, jogador.vidaMaxima);
            printf(" Um novo setor sombrio foi desbloqueado!\n");
            printf("==================================================\n");
        }
    }

    printf("\n==================================================\n");
    printf("                PARABENSIZACOES!                  \n");
    printf("==================================================\n");
    printf(" Voce derrotou o mal ancestral, sobreviveu a mansao\n");
    printf(" e conquistou a vitoria final com sucesso!\n");
    printf("==================================================\n");

    return 0;
}