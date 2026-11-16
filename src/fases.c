#include <string.h>
#include "fases.h"

void criarFases(Fase fases[]) {

    // FASE 1: O Corredor das Máscaras Vazias
    strcpy(fases[0].nome, "O Corredor das Mascaras Vazias");
    strcpy(fases[0].missao, "Reunir o grupo e abrir a porta de carvalho da ala oeste.");

    strcpy(fases[0].monstros[0].nome, "Manequim Despedacado");
    strcpy(fases[0].monstros[0].descricao, "Um manequim animado por uma presenca hostil.");
    fases[0].monstros[0].vida = 45;
    fases[0].monstros[0].ataque = 8;
    fases[0].monstros[0].defesa = 7;
    fases[0].monstros[0].nivel = 1;
    fases[0].monstros[0].experiencia = 40;

    strcpy(fases[0].monstros[1].nome, "Eco Silencioso");
    strcpy(fases[0].monstros[1].descricao, "Uma manifestacao vaga que sussurra nos corredores.");
    fases[0].monstros[1].vida = 55;
    fases[0].monstros[1].ataque = 10;
    fases[0].monstros[1].defesa = 5;
    fases[0].monstros[1].nivel = 2;
    fases[0].monstros[1].experiencia = 50;

    strcpy(fases[0].monstros[2].nome, "A Sombra Costurada");
    strcpy(fases[0].monstros[2].descricao, "Entidade de roupas velhas e dezenas de mascaras mortuarias.");
    fases[0].monstros[2].vida = 70;
    fases[0].monstros[2].ataque = 12;
    fases[0].monstros[2].defesa = 9;
    fases[0].monstros[2].nivel = 3;
    fases[0].monstros[2].experiencia = 70;

    // FASE 2: O Cemitério
    strcpy(fases[1].nome, "O Cemiterio dos Insepultos");
    strcpy(fases[1].missao, "Exumar o tumulo central para recuperar o diario com a senha.");

    strcpy(fases[1].monstros[0].nome, "Cadaver Exumado");
    strcpy(fases[1].monstros[0].descricao, "Um corpo recem-desenterrado tomado por furia.");
    fases[1].monstros[0].vida = 85;
    fases[1].monstros[0].ataque = 14;
    fases[1].monstros[0].defesa = 10;
    fases[1].monstros[0].nivel = 4;
    fases[1].monstros[0].experiencia = 70;

    strcpy(fases[1].monstros[1].nome, "Cao Esqueletico");
    strcpy(fases[1].monstros[1].descricao, "Feras caninas reanimadas pela neblina do cemiterio.");
    fases[1].monstros[1].vida = 100;
    fases[1].monstros[1].ataque = 16;
    fases[1].monstros[1].defesa = 12;
    fases[1].monstros[1].nivel = 5;
    fases[1].monstros[1].experiencia = 80;

    strcpy(fases[1].monstros[2].nome, "O Coveiro Sem Rosto");
    strcpy(fases[1].monstros[2].descricao, "Colosso desproporcional armado com uma pesada pa de ferro.");
    fases[1].monstros[2].vida = 125;
    fases[1].monstros[2].ataque = 19;
    fases[1].monstros[2].defesa = 14;
    fases[1].monstros[2].nivel = 6;
    fases[1].monstros[2].experiencia = 100;

    // FASE 3: O Santuário do Espelho Quebrado
    strcpy(fases[2].nome, "Santuario do Espelho Quebrado");
    strcpy(fases[2].missao, "Destruir os tres grandes espelhos ancestrais para quebrar a maldicao.");

    strcpy(fases[2].monstros[0].nome, "Reflexo Distorcido");
    strcpy(fases[2].monstros[0].descricao, "Uma copia instavel que imita os movimentos do grupo.");
    fases[2].monstros[0].vida = 140;
    fases[2].monstros[0].ataque = 21;
    fases[2].monstros[0].defesa = 15;
    fases[2].monstros[0].nivel = 7;
    fases[2].monstros[0].experiencia = 100;

    strcpy(fases[2].monstros[1].nome, "Guardião Espetral");
    strcpy(fases[2].monstros[1].descricao, "Protege o limiar do altar subterraneo.");
    fases[2].monstros[1].vida = 165;
    fases[2].monstros[1].ataque = 24;
    fases[2].monstros[1].defesa = 18;
    fases[2].monstros[1].nivel = 8;
    fases[2].monstros[1].experiencia = 120;

    strcpy(fases[2].monstros[2].nome, "O Reflexo Voraz");
    strcpy(fases[2].monstros[2].descricao, "Manifestacao definitiva dos medos e culpas dos protagonistas.");
    fases[2].monstros[2].vida = 200;
    fases[2].monstros[2].ataque = 28;
    fases[2].monstros[2].defesa = 20;
    fases[2].monstros[2].nivel = 10;
    fases[2].monstros[2].experiencia = 180;

    // Tabuleiros das tres fases
    for(int f = 0; f < 3; f++) {

        fases[f].tabuleiro[0] = CASA_VAZIA;
        fases[f].tabuleiro[1] = CASA_COMBATE;
        fases[f].tabuleiro[2] = CASA_CURA;
        fases[f].tabuleiro[3] = CASA_COMBATE;
        fases[f].tabuleiro[4] = CASA_TESOURO;
        fases[f].tabuleiro[5] = CASA_COMBATE;
        fases[f].tabuleiro[6] = CASA_ARMADILHA;
        fases[f].tabuleiro[7] = CASA_MISSAO;
    }
}
