#include <stdio.h>
#include "types.h"
#include "jogo.h"
#include "utils.h"
#include "personagem.h"
#include "combate.h"

void executarEvento(TipoCasa tipo, Personagem *p, Fase *fase, int derrotados[], int numeroFase) {
    int i;
    int resultado;

    switch(tipo) {
        case CASA_VAZIA:
            printf("\nA casa esta em um silencio mortal.\n");
            break;

        case CASA_COMBATE:
            for(i = 0; i < 3; i++) {
                if(derrotados[i] == 0) {
                    Monstro inimigo = fase->monstros[i];
                    resultado = combater(p, &inimigo);
                    if(resultado == 1) {
                        derrotados[i] = 1;
                    } else {
                        printf("\nVoce conseguiu escapar por pouco desta ameaca, mas ela continua a espreita...\n");
                        derrotados[i] = -1;
                    }
                    break;
                }
            }
            if(i == 3) {
                printf("\nNao ha mais monstros ativos neste setor.\n");
            }
            break;

        case CASA_TESOURO:
            printf("\n========================================\n");
            printf("          CASA DE SUPRIMENTOS             \n");
            printf("========================================\n");
            p->ouro += 20;
            p->pocoes += 1;
            printf(" Voce vasculhou o esconderijo abandonado!\n");
            printf(" Recompensas obtidas: +20 Moedas de Ouro e +1 Pocao de Cura!\n");
            printf(" Status atual -> Ouro: %d | Pocoes: %d\n", p->ouro, p->pocoes);
            printf("========================================\n");
            break;

        case CASA_CURA:
            printf("\n========================================\n");
            printf("          REFUGIO SEGURO                  \n");
            printf("========================================\n");
            printf(" Voce encontrou um quarto seguro para recuperar o folego.\n");
            recuperarVida(p, 45);
            printf(" Sua vida foi recuperada em 45 pontos! (Vida: %d/%d)\n", p->vida, p->vidaMaxima);
            printf("========================================\n");
            break;

        case CASA_ARMADILHA:
            printf("\n========================================\n");
            printf("          ALERTA: ARMADILHA!              \n");
            printf("========================================\n");
            printf(" Voce acionou um mecanismo oculto no chao!\n");
            receberDano(p, 15);
            printf(" Voce sofreu 15 de dano! (Vida: %d/%d)\n", p->vida, p->vidaMaxima);
            printf("========================================\n");
            break;

        case CASA_MISSAO:
            printf("\n==================================================\n");
            printf("MISSAO: %s\n", fase->missao);
            printf("==================================================\n");

            if(numeroFase == 0) {
                for(i = 0; i < 3; i++) {
                    if(derrotados[i] == 0) {
                        printf(" Ainda existe um monstro a ser derrotado no corredor!\n");
                        return;
                    }
                }
                printf("\n Todos os monstros do corredor foram eliminados!\n");
                printf(" Missao da Fase 1 concluida com sucesso!\n");
            } else {
                if(derrotados[2] == 0) {
                    printf("\n O guardiao principal desta area bloqueia o objetivo: %s!\n", fase->monstros[2].nome);
                    Monstro chefe = fase->monstros[2];
                    resultado = combater(p, &chefe);
                    if(resultado == 1) {
                        derrotados[2] = 1;
                        printf("\n Chefe derrotado! Missao concluida com sucesso!\n");
                    }
                } else {
                    printf("\n O caminho esta livre e o objetivo foi cumprido!\n");
                }
            }
            break;
    }
}

int jogarFase(Personagem *p, Fase *fase, int numeroFase) {
    int posicao = 0;
    int dado;
    int i;
    int derrotados[3] = {0, 0, 0};
    int opcaoMenu;

    while(posicao < 7 && p->vida > 0) {
        printf("\n==================================================\n");
        printf(" [FASE %d/3] %s\n", numeroFase + 1, fase->nome);
        printf(" [STATUS] Vida: %d/%d | Ouro: %d | Pocoes: %d\n", p->vida, p->vidaMaxima, p->ouro, p->pocoes);
        printf(" [MAPA] Casa atual: %d de 8\n", posicao + 1);
        printf("--------------------------------------------------\n");
        printf(" 1. Jogar Dado e Avancar\n");
        printf(" 2. Abrir Inventario / Usar Pocao\n");
        printf("--------------------------------------------------\n");
        printf(" Escolha uma opcao: ");
        
        opcaoMenu = lerInteiro();

        if (opcaoMenu == 2) {
            gerenciarInventario(p);
            continue; 
        }

        dado = rolarDado(6);
        printf("\n Voce tirou %d no dado!\n", dado);

        moverJogador(&posicao, dado, 8);
        printf(" Voce avancou para a casa %d!\n", posicao + 1);

        executarEvento(fase->tabuleiro[posicao], p, fase, derrotados, numeroFase);

        if(p->vida <= 0) {
            return 0;
        }

        if(posicao == 7) {
            if(numeroFase == 0) {
                for(i = 0; i < 3; i++) {
                    if(derrotados[i] == 0) {
                        break;
                    }
                }
                if(i == 3) {
                    return 1;
                }
                printf("\n A missao exige que todos os monstros do corredor sejam eliminados!\n");
                posicao = 2; 
            } else {
                if(derrotados[2] == 1) {
                    return 1;
                }
                posicao = 6;
            }
        }
    }
    return 0;
}