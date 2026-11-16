#ifndef JOGO_H
#define JOGO_H

#include "types.h"

void executarEvento(TipoCasa tipo, Personagem *p, Fase *fase, int derrotados[], int numeroFase);
int jogarFase(Personagem *p, Fase *fase, int numeroFase);

#endif