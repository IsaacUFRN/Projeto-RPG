#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "types.h"

void criarPersonagem(Personagem *p);
void exibirStatus(Personagem *p);
void receberDano(Personagem *p, int dano);
void recuperarVida(Personagem *p, int quantidade);
void ganharXP(Personagem *p, int xp);
void gerenciarInventario(Personagem *p);

#endif