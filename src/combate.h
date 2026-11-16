#ifndef COMBATE_H
#define COMBATE_H

#include "types.h"

void danoNoMonstro(Monstro *m, int dano);
void usarHabilidade(Personagem *p, Monstro *m);
int combater(Personagem *p, Monstro *m);

#endif