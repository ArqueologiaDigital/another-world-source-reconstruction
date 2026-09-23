# 592 de 636, e por que isso não era bom o suficiente

O jogo tem duas versões prioritárias no projeto, Amiga e MS-DOS, e elas
desenham as mesmas cenas com os polígonos guardados em ordens diferentes. A
ponte legítima entre as duas é o `canonical_md5`: se as duas versões desenham
uma figura com o mesmo hash, um nome ganho numa pode ser carregado para a
outra. Casar pelo *índice* da constante é um erro documentado do projeto — os
bancos não correspondem, e o nome aterrissa em arte alheia.

A ponte por hash tem um limite, e ele apareceu inteiro numa cena só.

## Quinze constantes, cinco figuras

A cena que o close-up do olho entrega: um rosto pairando sobre a câmera, com
pescoço e dois braços. O `canonical_md5` diz que as três cópias de cada forma
são **idênticas byte a byte**:

```
  (183,40)   CINEMATIC_638 641 645   todas canonical_md5 2d66cda0
```

Não são quadros. As quinze são desenhadas numa **única** passada, cada uma com
`zoom=[0x14]`, e `[0x14]` é recalculado entre elas:

```
	mov [0x14], 0x0042 ; +[0x15] x3   -> 637     depois -[0x15]  -> 638,639,640
	mov [0x14], 0x0040 ; +[0x15] x2   -> 641     depois -[0x15]  -> 642,643,644
	mov [0x14], 0x0040 ; -[0x15]      -> 645,646,647,648
```

Com `[0x15]` em 0, todas as passadas caem em 0x40 ou 0x42 e as cópias
coincidem: uma figura nítida. Com `[0x15]` em 5, elas se espalham em 1,27 /
1,19 / 1,16 / 1,08 / 0,92 do tamanho: uma figura borrada. E a escada
`jne [0x15], N` no fim da rotina desenha o detalhe do rosto — 19 caminhos em
`[0x15] = 0`, dois pontinhos em 4, nada em 5.

A rotina que inicia a cena semeia `[0x15]` em 5 e o caminha 5 → 2 → 6 → 0. O
borrão fecha e o detalhe chega juntos. **A imagem entra em foco.**

É uma cena bonita e o hash não conseguia nomear catorze das dezenove
constantes, porque com três constantes segurando uma figura ele não sabe qual
é qual.

## A segunda ponte

Onde as duas versões rodam o mesmo programa, a n-ésima instrução `video` de
uma é a n-ésima da outra. Isso não é nomear pelo índice: o índice do banco é o
número dentro de `CINEMATIC_<n>`, atribuído independentemente por cada versão;
isto é a posição numa sequência de instruções compartilhada.

Mas precisa de prova. A primeira tentativa comparou os arquivos inteiros, e o
portão reprova em **todas** as fases:

```
  PRISON   1420 sítios de desenho contra 1480      CAPSULE  1473 contra 2026
  CAVES    2346 contra 2485                        TANK      572 contra  693
```

inclusive PRISON, que a norma do projeto chama de uma das três fases
"totalmente idênticas". O que alinha é o pareamento que a própria árvore
unificada já calculou: `amiga__post_X.inc` e `dos__post_X.inc` são os dois
braços de uma região. PRISON tem 88 desses pares; 39 carregam sítios de
desenho que batem em contagem e em todos os argumentos.

## O controle

A pergunta que decide: nos sítios em que **as duas** versões já têm nome,
o método reproduz o que uma pessoa escreveu?

**592 de 636.** 93,1%.

Em quase qualquer outro contexto isso seria um bom número. Aqui não é, e o
motivo está na forma dos 44 erros. Eles são todos de uma família, e erram
assim:

```
  amiga ..._ZOOM_IN_LEFT_0  contra  msdos ..._ZOOM_IN_RIGHT_13
  amiga ..._ZOOM_IN_LEFT_1  contra  msdos ..._ZOOM_IN_RIGHT_12
  amiga ..._ZOOM_IN_LEFT_2  contra  msdos ..._ZOOM_IN_RIGHT_11
```

Numeração invertida e `LEFT`/`RIGHT` trocados. Parece um erro de nomeação de
alguém — até rodar o `canonical_md5` nesses pares: **0 iguais, 27
diferentes**.

Os sítios estão alinhados. As figuras desenhadas neles não são as mesmas
figuras.

Óbvio depois de ver: um trecho é de uma versão só **porque** as versões
diferem nele, e duas figuras diferentes desenhadas no mesmo x, y e zoom passam
por uma conferência de argumentos sem alterar nada.

6,9% de erro não é um método de nomeação. Um nome errado não é meio nome — é
uma afirmação falsa que o próximo leitor toma por evidência, e o portão de
bytes não consegue vê-la, porque renomear não move byte nenhum.

## As duas pontes juntas

A ferramenta passou a exigir as duas: o sítio tem de alinhar **e** o
`canonical_md5` tem de bater.

```
  552 de 552 sítios alinhados-e-com-a-mesma-arte reproduzem o nome escrito
  193 sítios alinhados recusados porque a arte difere, 44 deles mal nomeados
```

Nenhuma das duas pontes basta sozinha. O alinhamento resolve o que o hash não
consegue distinguir; o hash pega o que o alinhamento não consegue enxergar. As
dezenove constantes foram para a MS-DOS e não sobrou nenhuma.

O número que ficou pior — 138 transferíveis viraram 19 — é o número honesto.

## O que ficou aberto

As 44 discordâncias de `PRISON_CUTSCENE_ZOOM_IN_*` são um conflito de verdade,
não ruído. As duas versões estão numeradas a partir de pontas opostas, com
`LEFT` e `RIGHT` trocados, `LEFT_n` contra `RIGHT_(13-n)`. A arte difere, então
as duas podem estar certas sobre a própria versão — mas ninguém conferiu, e a
sonda que achou isso é por onde começar.

É o terceiro controle desta leva a reprovar e parar o trabalho em vez de
liberá-lo. Os outros dois foram uma regra de adjacência que discordava da arte
em 6 de 6 casos, e um par de espelhos em que 0 de 48 compartilhavam a
assinatura de folhas que a hipótese exigia. Um controle que nunca reprova não
estava medindo nada.
