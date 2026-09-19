# Três fichas e quatro canais

*Havia uma regra no projeto que dizia: essa rotina não pode receber nome de
personagem. A regra estava certa e era uma frase — sem estrutura por trás. São
434 rotinas paradas atrás dela. Este é o dia em que a frase virou um diagrama.*

---

Uma das duas travas documentadas do backlog de nomeação se chama #0138. Ela diz
que uma rotina que desenha em `x=[0x07], y=[0x08]` não pode ser nomeada por
**quem** ela desenha, porque esse par é carregado de um registro diferente antes
de cada desenho. A formulação registrada falava em "nove registros diferentes".

Nove de quê? De que tamanho? Onde? A regra dava para obedecer e não dava para
conferir. E 434 rotinas da fase CAVES, nas duas versões prioritárias, estão
paradas nela.

## Achar a estrutura em vez de afirmá-la

A pista é um **bloco de troca**: uma sequência reta de `mov [A], [B]` entre os
registradores de trabalho baixos e palavras consecutivas a partir de alguma
base. Se existir um registro, ele aparece aí.

Duas coisas precisaram estar certas antes de a sonda enxergar qualquer coisa, e
eu errei as duas na primeira tentativa.

**A primeira: dividir pela direção.** Uma rotação grava oito registradores num
registro e carrega o próximo nos mesmos oito — dezesseis `mov` sem nada no meio.
Testar a direção da sequência inteira descarta as duas metades. A sonda
respondeu "bases 0x68 0x78, passo 16": um arranjo real, descrito errado.

**A segunda: exigir densidade.** Sem isso, `mov` vizinhos sem relação nenhuma
voltavam como "registros de 4 campos ocupando 21 palavras".

Com as duas, a resposta é a mesma em PRISON, CAVES e CAPSULE, nas versões
Amiga, MS-DOS e SNES:

```
8 campos, largura 8: +0->0x07 +1->0x08 +2->0x10 +3->0x11
                     +4->0x12 +5->0x09 +6->0x13 +7->0x29
  bases 0x68 0x70 0x78   passo 8
  -> três registros de oito palavras, 0x68..0x7F, empacotados
```

Três. Não nove.

## O diagrama

O que amarra tudo é de onde as quatro rotinas são chamadas. Um único bloco de
`setup` as instala em canais **pares consecutivos**: 0x22, 0x24, 0x26, 0x28. E a
máquina virtual roda os canais em ordem crescente dentro de um quadro — então a
ordem da corrente **é** a ordem dos canais.

| canal | faz | deixa nos registradores |
|---|---|---|
| 0x22 | carrega o registro 0 | registro 0 |
| 0x24 | processa, grava o 0, carrega o 1 | registro 1 |
| 0x26 | processa, grava o 1, carrega o 2 | registro 2 |
| 0x28 | processa, grava o 2 | — |

Quatro threads passando uma ficha adiante, uma por quadro, compartilhando um
único conjunto de registradores. `[0x07]` e `[0x08]` são os campos 0 e 1 — x e
y — **de qualquer registro que a corrente esteja segurando naquele instante**.

Em CAVES o processamento envolve a borda da tela: quando x passa de 0x150 ou
de 0xFFF0, ele soma ou subtrai 0x15F, anda o índice de tela guardado no campo
+2, e recalcula o y consultando o mapa de chão — que é para isso que serve
aquela família enorme de rotinas `..._GROUND_MAP_SCREEN_<hex>_SEGMENT_<n>`.

## O que isso destravou: nada

Vale ser explícito, porque a tentação é grande. Saber a forma do registro **não
torna o ocupante conhecível**. Três fichas intercambiáveis, rodadas por canal,
preenchidas por quem quer que as tenha preenchido, é a explicação mais clara
possível de por que o local do desenho não identifica ninguém.

**#0138 continua de pé.** Ele só deixou de ser uma afirmação e virou uma
consequência. Os 434 continuam parados, agora por um motivo que se pode
desenhar num quadro.

O que a estrutura destravou foram as dez rotinas da própria corrente, em três
fases e três versões. Duas delas se chamavam `PRISON_FILL_AND_DRAW_CIN_24_28_L1`
e `_L3` — sufixo de dobra que a norma proíbe, sobre um radical que **não existe
no arquivo**: não há nenhuma rotina `PRISON_FILL_AND_DRAW_CIN_24_28`. São pontos
de entrada de thread, não rótulos internos de uma rotina de desenho.

## A restrição que sobrou, que vale mais que os dez nomes

Rodando a sonda, 26 outras rotinas de CAVES carregam as **mesmas palavras**
0x68..0x7F nos mesmos registradores sob um **layout diferente**.
`CAVES_FALLING_ROCK_SLOT_0_*` lê 0x74/0x75/0x76 como x/y/estado — que no mapa de
oito palavras são os campos 4, 5 e 6 do registro 1, com outros registradores.

As duas leituras não podem valer ao mesmo tempo. E não valem: as rotinas de
pedra e de armadilha são instaladas **nos mesmos canais** 0x22/0x24/0x26/0x28, e
um canal guarda um endereço de cada vez. Cenas diferentes instalam corpos
diferentes nos mesmos canais e reaproveitam as mesmas palavras.

> **0x68..0x7F tem escopo de cena.** Nenhum apelido válido para a fase inteira
> existe para essas palavras.

É a mesma lição que já tinha custado um erro neste projeto, quando um apelido
global para `0x66` ignorou que TANK usa aquela palavra como contador de `djnz`.
Da segunda vez ela apareceu antes do estrago, porque desta vez havia uma sonda
perguntando quem mais mexe aqui.

---

Conferível: `notes/draw-slot-probes/`, com README dizendo que pergunta a sonda
responde, o comando, os dois erros de abstração que precisaram ser consertados
antes e o que o achado autoriza e o que não autoriza. `make test` segue 29/29 e
29/29.
