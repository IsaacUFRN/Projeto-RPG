# RPG: OS SEGREDOS DA MANSÃO SOMBRIA

## OBSERVACAO! ##
Este projeto foi construido com os conhecimentos adquiridos em sala de aula + auxilio de inteligencia artificial. Divirta-se!

## GITHUB: https://github.com/IsaacUFRN/Projeto-RPG.git

## 1. IDENTIFICACAO

- Aluno: Isaac Bruno do Vale Souza
- Matricula: 20260051706

## 2. HISTORIA DO JOGO

Uma neblina densa e sufocante cobre os portoes de ferro de uma antiga mansao abandonada. Atraidos por ecos do passado e pesadelos recorrentes, os corajosos herois cruzaram a entrada em busca de respostas. De repente, as pesadas portas de carvalho se fecham com um estrondo atras deles. Agora, a unica saida e avancar pelas alas amaldicoadas, enfrentar os horrores que habitam o local e desvendar este misterio milenar para sobreviver.

Objetivo final: Explorar os ambientes da mansao, sobreviver aos perigos, derrotar as criaturas e desvendar os segredos escondidos em cada fase.

## 3. PERSONAGENS E CLASSES

O jogador escolhe uma das tres classes disponiveis no inicio da jornada, cada uma com atributos e mecanicas proprias.

### 3.1 Lucas - Cacador

- Estilo: Focado em ataques fisicos precisos e dano direto.
- Vida inicial: 110 PV.
- Caracteristicas: Alto ataque fisico e boa versatilidade para abater alvos rapidamente.
- Equipamentos: Escopeta de cano serrado acoplada ao cinto e capa de viagem.
- Habilidade especial: Disparo certeiro de escopeta para causar dano critico massivo em um unico alvo.

### 3.2 Mariana - Ocultista

- Estilo: Dominio de artes misticas e conhecimentos ocultos.
- Vida inicial: 95 PV.
- Caracteristicas: Maior poder ofensivo magico da equipe.
- Habilidade passiva - Pacto Sombrio: Permite reviver automaticamente com 50% da vida maxima apos sofrer um golpe fatal, uma unica vez por partida.
- Equipamentos: Grimorio de magias ancestrais e amuletos misticos.
- Habilidade especial: Conjuracao de chamas misticas ou feiticos de enfraquecimento em area.

### 3.3 Renato - Medico

- Estilo: Especialista em sobrevivencia e primeiros socorros.
- Vida inicial: 130 PV.
- Caracteristicas: Alta resistencia e inicio da jornada com Pocoes de Cura no inventario.
- Equipamentos: Bolsa de primeiros socorros, bandagens e frascos de antidotos.
- Habilidade especial: Tratamento avancado de campo para curar grandes quantidades de PV de si mesmo ou dos aliados.

## 4. MONSTROS E FASES

O jogo e dividido em tres fases progressivas:

1. Corredor - Fase 1.
2. Cemiterio - Fase 2.
3. Santuario - Fase 3 (Etapa Final).

### 4.1 Fase 1 - Corredor

- Monstros: Manequim Despedacado, Eco Silencioso e A Sombra Costurada.
- Caracteristicas dos inimigos: Entidades com formas corporais distorcidas, foco em ataques furtivos e manipulacao de ecos sonoros para confundir e desorientar os herois.
- Missao principal: Sobreviver ao labirinto de corredores amaldicoados e desvendar o segredo das mascaras nas paredes para encontrar a passagem secreta rumo aos fundos da mansao.

### 4.2 Fase 2 - Cemiterio

- Monstros: Cadaver Exumado, Cao Esqueletico e O Coveiro Sem Rosto.
- Caracteristicas dos inimigos: Criaturas mortas-vivas amarradas a correntes e ossadas que saem da terra, focadas em causar dano fisico continuo e exaustao.
- Missao principal: Atravessar as covas abertas e derrotar o Coveiro Sem Rosto para purificar o solo sagrado profanado.

### 4.3 Fase 3 - Santuario

- Monstros: Reflexo Distorcido e Guardiao Espiritual.
- Caracteristicas dos inimigos: Entidades etereas e ilusorias de alto poder magico e defensivo, capazes de manipular fragmentos de vidro dimensional e refletir ataques.
- Missao principal: Destruir o nucleo do santuario dimensional, derrotar os guardioes finais do espelho e quebrar a maldicao milenar para escapar da mansao.

## 5. DINAMICA DO JOGO

### 5.1 Tabuleiro e movimentacao

Cada fase possui um tabuleiro linear de 8 casas. A cada rodada, o jogador lanca um dado de 6 faces para avancar e acionar eventos aleatorios ou obrigatorios.

### 5.2 Tipos de casas

- CASA_VAZIA: Um silencio mortal onde nada acontece.
- CASA_COMBATE: Confronto direto contra entidades hostis e chefes de setor.
- CASA_TESOURO: Permite coletar moedas de ouro ou pocoes de cura em esconderijos.
- CASA_CURA: Um local seguro para recuperar pontos de vida.
- CASA_ARMADILHA: Mecanismos ocultos que causam dano direto ao heroi.
- CASA_MISSAO: Objetivo principal da fase, exigindo a eliminacao de guardioes ou a conclusao de metas para avancar.

### 5.3 Combate por turnos

Durante as lutas, o jogador pode escolher entre:

- Atacar: Realizar um ataque contra o inimigo.
- Defender: Reduzir o dano recebido pela metade.
- Usar pocao: Recuperar pontos de vida.
- Habilidade especial: Causar dano critico dobrado, uma vez por luta.
- Tentar fugir: Tentar escapar do confronto.

### 5.4 Formulas de combate

A preencher conforme as formulas utilizadas na implementacao do jogo:

- Calculo de ataque: O dano inicial e determinado pelo poder de ataque do personagem ou monstro.
- Calculo de defesa: A defesa reduz a quantidade de dano recebido pelo personagem ou inimigo.
- Calculo de dano recebido: O dano efetivo considera o ataque do adversario e a defesa do alvo.
- Efeitos das habilidades especiais: As habilidades especiais permitem executar ataques com efeitos diferenciados, como dano critico ou recuperacao de pontos de vida, conforme a classe do personagem.

### 5.5 Progressao e recompensas

Derrotar monstros concede pontos de experiencia (XP). Ao acumular 100 XP, o heroi sobe de nivel, aumenta seus atributos permanentemente e tem sua vida totalmente restaurada.

Outras recompensas, como moedas e pocoes, podem ser obtidas em casas de tesouro.

### 5.6 Condicoes de vitoria e derrota

- Vitoria: O jogador vence ao concluir as tres fases da mansao, derrotando os inimigos e cumprindo as respectivas missoes principais, ate destruir o nucleo do Santuario do Espelho Quebrado.
- Derrota: O jogador perde caso todos os personagens disponiveis sejam derrotados e nao haja possibilidade de continuar a jornada.

## 6. ESTRUTURA DO CODIGO

A arquitetura do sistema foi desenvolvida em linguagem C de forma modular, separando a logica de estados, entidades, fases e motor de jogo em arquivos distintos para garantir a manutenibilidade e a clareza do codigo-fonte. A estrutura de dados principal fundamenta-se no uso de enumeracoes (enum) para definir de maneira estrita os estados do heroi, os tipos de classes disponiveis, as fases da mansao e as categorias de casas presentes no tabuleiro linear, o que evita ambiguidades logicas durante a execucao. Complementarmente, estruturas (struct) complexas agrupam as propriedades dinamicas e estaticas dos personagens e inimigos, encapsulando atributos vitais como pontos de vida atuais e maximos, poder de ataque, defesa, quantidade de ouro, pocoes de cura no inventario, nivel atual e experiencia acumulada, alem de sinalizadores booleanos essenciais para o controle de habilidades especiais e passivas exclusivas, a exemplo do pacto de ressurreicao da Ocultista. O fluxo de controle principal gerencia o loop de turnos, o lancamento do dado simulador de avanco, a resolucao dos eventos especificos de cada casa e os calculos matematicos de combate que determinam a mitigacao de danos e a progressao de nivel. As funcoes de manipulacao de fases e entidades coordenam a inicializacao dos vetores de monstros correspondentes aos horrores de cada setor, desde o Corredor das Mascaras Vazias ate o Santuario do Espelho Quebrado, enquanto os modulos de entrada e saida controlam a interface textual imersiva exibida ao usuario no terminal.

## 7. COMO COMPILAR E EXECUTAR

### 7.1 Pre-requisitos

- Compilador GCC instalado.
- Terminal ou ambiente de desenvolvimento compativel com a linguagem C.

### 7.2 Compilacao

A preencher com o comando definitivo de compilacao de todos os arquivos .c do projeto.

### 7.3 Execucao

Windows:
RPG.exe

Linux:
./RPG

## 8. IMAGENS

As imagens dos personagens e monstros serao disponibilizadas nas pastas correspondentes, caso utilizadas.

## 9. VIDEO DE DEMONSTRACAO

Link do video de apresentacao do projeto:
https://drive.google.com/drive/folders/1henIThnvbz3vcLUQzIhIphM43ChkwQo-?usp=drive_link

## 10. ESTRUTURA DO REPOSITORIO

Projeto RPG/
|
|-- README.md
|
|-- src/
|   |-- main.c
|   |-- ...
|
|-- Makefile
|
|-- images/
|   |-- personagens/
|   |-- monstros/
|
|-- video/
    |-- link_video.md