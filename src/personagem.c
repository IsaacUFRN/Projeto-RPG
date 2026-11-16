#include <stdio.h>
#include <string.h>
#include "personagem.h"
#include "utils.h"

void criarPersonagem(Personagem *p) {
    int escolha;
    printf("\n==================================================\n");
    printf("         ESCOLHA SUA CLASSE DE COMBATE            \n");
    printf("==================================================\n");
    printf(" 1. Cacador (Lucas)    - Focado em ataques precisos\n");
    printf(" 2. Ocultista (Mariana) - Dominio de artes misticas (Revive 1x)\n");
    printf(" 3. Medico (Renato)     - Especialista em sobrevivencia\n");
    printf("--------------------------------------------------\n");
    printf(" Escolha a classe (1-3): ");
    escolha = lerInteiro();

    switch(escolha) {
        case CACADOR:
            strcpy(p->nome, "Lucas");
            strcpy(p->classe, "Cacador");
            p->vidaMaxima = 110;
            p->ataque = 18;
            p->defesa = 8;
            p->pocoes = 0;
            p->habilidadeReviverUsada = 1;
            break;
        case OCULTISTA:
            strcpy(p->nome, "Mariana");
            strcpy(p->classe, "Ocultista");
            p->vidaMaxima = 95;
            p->ataque = 22;
            p->defesa = 6;
            p->pocoes = 0;
            p->habilidadeReviverUsada = 0; // Habilidade de reviver disponível!
            break;
        case MEDICO:
        default:
            strcpy(p->nome, "Renato");
            strcpy(p->classe, "Medico");
            p->vidaMaxima = 130;
            p->ataque = 14;
            p->defesa = 11;
            p->pocoes = 1;
            p->habilidadeReviverUsada = 1;
            break;
    }
    p->vida = p->vidaMaxima;
    p->nivel = 1;
    p->experiencia = 0;
    p->ouro = 50;
}

void exibirStatus(Personagem *p) {
    printf("\n---------------- STATUS DO HEROI -----------------\n");
    printf(" Nome: %s | Classe: %s | Nivel: %d\n", p->nome, p->classe, p->nivel);
    printf(" Vida: %d/%d | Ataque: %d | Defesa: %d\n", p->vida, p->vidaMaxima, p->ataque, p->defesa);
    printf(" EXP: %d/100 | Ouro: %d | Pocoes: %d\n", p->experiencia, p->ouro, p->pocoes);
    printf("--------------------------------------------------\n");
}

void receberDano(Personagem *p, int dano) {
    p->vida -= dano;
    if (p->vida <= 0) {
        if (strcmp(p->classe, "Ocultista") == 0 && p->habilidadeReviverUsada == 0) {
            p->habilidadeReviverUsada = 1;
            p->vida = p->vidaMaxima / 2; // Revive com metade da vida máxima
            printf("\n==================================================\n");
            printf("         PACTO SOMBRIO ATIVADO!                   \n");
            printf("==================================================\n");
            printf(" Quando as forcas de Mariana se esvairam, as trevas\n");
            printf(" a trouxeram de volta do limiar da morte!\n");
            printf(" Ela ressuscitou com %d/%d pontos de vida!\n", p->vida, p->vidaMaxima);
            printf("==================================================\n");
        } else {
            p->vida = 0;
        }
    }
}

void recuperarVida(Personagem *p, int quantidade) {
    p->vida += quantidade;
    if (p->vida > p->vidaMaxima) {
        p->vida = p->vidaMaxima;
    }
}

void ganharXP(Personagem *p, int xp) {
    p->experiencia += xp;
    printf("\n-> Voce ganhou %d pontos de experiencia!\n", xp);
    if (p->experiencia >= 100) {
        p->nivel++;
        p->experiencia -= 100;
        p->vidaMaxima += 20;
        p->ataque += 4;
        p->defesa += 2;
        p->vida = p->vidaMaxima;

        printf("\n==================================================\n");
        printf("             SUBIRAM DE NIVEL! (NIVEL %d)         \n", p->nivel);
        printf("==================================================\n");
        printf(" Seus atributos aumentaram e sua VIDA FOI TOTALMENTE\n");
        printf(" RESTAURADA para %d/%d!\n", p->vida, p->vidaMaxima);
        printf("==================================================\n");
    }
}

void gerenciarInventario(Personagem *p) {
    int opcao;
    do {
        printf("\n==================================================\n");
        printf("               INVENTARIO DO HEROI                \n");
        printf("==================================================\n");
        printf(" 1. Usar Pocao de Cura (Possui: %d) [Recupera 40 PV]\n", p->pocoes);
        printf(" 2. Ver Status Detalhados\n");
        printf(" 3. Sair do Inventario\n");
        printf("--------------------------------------------------\n");
        printf(" Escolha uma opcao: ");
        opcao = lerInteiro();

        switch(opcao) {
            case 1:
                if (p->pocoes > 0) {
                    if (p->vida == p->vidaMaxima) {
                        printf("\n-> Sua vida ja esta no maximo!\n");
                    } else {
                        p->pocoes--;
                        recuperarVida(p, 40);
                        printf("\n-> Pocao utilizada com sucesso! Vida atual: %d/%d (Restam: %d)\n", p->vida, p->vidaMaxima, p->pocoes);
                    }
                } else {
                    printf("\n-> Voce nao possui nenhuma pocao no momento!\n");
                }
                break;
            case 2:
                exibirStatus(p);
                break;
            case 3:
                printf("\n-> Fechando inventario...\n");
                break;
            default:
                printf("\n-> Opcao invalida!\n");
                break;
        }
    } while (opcao != 3);
}