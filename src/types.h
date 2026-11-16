#ifndef TYPES_H
#define TYPES_H

typedef enum {
    CACADOR = 1,
    OCULTISTA,
    MEDICO
} Classe;

typedef enum {
    CASA_VAZIA,
    CASA_COMBATE,
    CASA_TESOURO,
    CASA_CURA,
    CASA_ARMADILHA,
    CASA_MISSAO
} TipoCasa;

typedef enum {
    ATACAR = 1,
    DEFENDER,
    USAR_POCAO,
    HABILIDADE,
    FUGIR
} Acao;

typedef struct {
    char nome[50];
    char classe[50];
    int vida;
    int vidaMaxima;
    int ataque;
    int defesa;
    int nivel;
    int experiencia;
    int ouro;
    int pocoes;
    int habilidadeReviverUsada;
} Personagem;

typedef struct {
    char nome[50];
    char descricao[100];
    int vida;
    int ataque;
    int defesa;
    int nivel;
    int experiencia;
} Monstro;

typedef struct {
    char nome[60];
    char missao[150];
    Monstro monstros[3];
    TipoCasa tabuleiro[8];
} Fase;

#endif