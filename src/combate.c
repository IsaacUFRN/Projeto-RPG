#include <stdio.h>
#include <string.h>
#include "combate.h"
#include "utils.h"
#include "personagem.h"
#include "types.h"

int combater(Personagem *p, Monstro *m) {
    int escolha;
    int danoCausado;
    int danoRecebido;
    int usouHabilidade = 0;

    printf("\n==================================================\n");
    printf("           ALERTA DE COMBATE IMINENTE!            \n");
    printf("==================================================\n");
    printf(" Inimigo: %s (Nível %d)\n", m->nome, m->nivel);
    printf(" Descricao: %s\n", m->descricao);
    printf("--------------------------------------------------\n");

    while (p->vida > 0 && m->vida > 0) {
        printf("\n---------------- STATUS ATUAL ------------------\n");
        printf(" [Herói] %s (%s) | Vida: %d/%d | Ataque: %d\n", p->nome, p->classe, p->vida, p->vidaMaxima, p->ataque);
        printf(" [Inimigo] %s    | Vida: %d    | Ataque: %d\n", m->nome, m->vida, m->ataque);
        printf("--------------------------------------------------\n");
        printf(" Escolha sua acao:\n");
        printf(" %d. Atacar\n", ATACAR);
        printf(" %d. Defender (Reduz o dano pela metade)\n", DEFENDER);
        printf(" 3. Usar Pocao de Cura (Possui: %d)\n", p->pocoes);
        if (!usouHabilidade) {
            printf(" %d. Usar Habilidade Especial (Disponivel)\n", HABILIDADE);
            printf(" %d. Tentar Fugir\n", FUGIR);
        } else {
            printf(" %d. Habilidade Especial (Ja utilizada neste combate)\n", HABILIDADE);
            printf(" %d. Tentar Fugir\n", FUGIR);
        }
        printf("--------------------------------------------------\n");
        printf(" Sua escolha: ");
        
        escolha = lerInteiro();

        switch (escolha) {
            case ATACAR:
                danoCausado = p->ataque - (m->defesa / 2);
                if (danoCausado < 1) danoCausado = 1;
                m->vida -= danoCausado;
                printf("\n-> Voce atacou o %s causando %d de dano!\n", m->nome, danoCausado);
                break;

            case DEFENDER:
                printf("\n-> Voce assume uma postura defensiva, antecipando o golpe.\n");
                danoRecebido = m->ataque - ((p->defesa + 5) / 2);
                if (danoRecebido < 1) danoRecebido = 1;
                receberDano(p, danoRecebido);
                printf("-> O golpe foi amortecido! Voce sofreu apenas %d de dano.\n", danoRecebido);
                continue;

            case 3: // Usar Poção de Cura
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
                    continue;
                }
                break;

            case HABILIDADE:
                if (usouHabilidade) {
                    printf("\n-> Voce ja utilizou sua habilidade especial neste combate!\n");
                    continue;
                }
                
                usouHabilidade = 1;
                danoCausado = (p->ataque * 2) - m->defesa;
                if (danoCausado < 10) danoCausado = 10;
                m->vida -= danoCausado;
                
                printf("\n==================================================\n");
                printf("         HABILIDADE ESPECIAL ATIVADA!             \n");
                printf("==================================================\n");
                printf(" Voce desferiu um golpe critico devastador em %s!\n", m->nome);
                printf(" Dano monstruoso causado: %d pontos!\n", danoCausado);
                printf("==================================================\n");
                break;

            case FUGIR:
                if (rolarDado(6) > 3) {
                    printf("\n-> Voce conseguiu despistar o monstro e fugiu com sucesso!\n");
                    return 0;
                } else {
                    printf("\n-> Tentativa de fuga falhou! O monstro bloqueou sua saida.\n");
                }
                break;

            default:
                printf("\n-> Opcao invalida! Perdeu a vez.\n");
                break;
        }

        if (m->vida > 0) {
            danoRecebido = m->ataque - (p->defesa / 2);
            if (danoRecebido < 1) danoRecebido = 1;
            receberDano(p, danoRecebido);
            printf("-> O %s retalia e te causa %d de dano!\n", m->nome, danoRecebido);
        }
    }

    if (p->vida <= 0) {
        printf("\n==================================================\n");
        printf("             VOCE FOI DERROTADO...                \n");
        printf("==================================================\n");
        return 0;
    } else {
        printf("\n==================================================\n");
        printf("              VITORIA NO COMBATE!                 \n");
        printf("==================================================\n");
        printf(" O %s foi abatido com sucesso!\n", m->nome);
        
        ganharXP(p, m->experiencia);
        return 1;
    }
}