# O herói não está caindo

*A fase que o projeto chamava de pronta — 100% dos rótulos com nome semântico —
tinha a animação central do personagem batizada com o nome de um evento que o
bytecode prova não acontecer. A prova é uma instrução que não faz nada, e é
justamente ela que faz o `grep` mentir.*

---

O projeto reconstrói o código-fonte de *Another World* a partir do bytecode das
versões originais. LAKE é a primeira fase jogável, e é a que o projeto trata
como terminada: dos 558 rótulos da versão Amiga, 558 têm nome semântico.

Duas rotinas cuidam do herói andando para a esquerda. Chamavam-se
`HERO_FALL_LEFT_LOOP` e `HERO_WALK_LEFT_LOOP` — "cai para a esquerda" e "anda
para a esquerda". Os polígonos que elas desenham chamavam-se
`CINEMATIC_HERO_FALL_LEFT_1..4`, `CINEMATIC_HERO_RESUME_LEFT_0..9` e
`CINEMATIC_HERO_WALK_LEFT_0..3`.

Fui olhar por um motivo lateral: a regra de nomenclatura do projeto exige que
uma família de quadros não tenha buracos na numeração, e `FALL_LEFT` começa em
1. Um revisor tinha apontado isso em setembro, rebaixado cinco nomes da versão
MS-DOS por causa disso, e escrito que ninguém havia re-renderizado a base.

## Uma queda mexe o personagem para baixo

É o teste mais simples que existe, e decide sozinho. Se a rotina nunca escreve
a coordenada vertical, não é uma queda — não importa o que os quadros pareçam.

`HERO_FALL_LEFT_LOOP` escreve `HERO_Y` **quatro vezes**. As quatro são:

```
	add [HERO_Y], 0x0000
```

Somar zero. O valor nunca muda, em nenhum dos quinze quadros.

E essa é a armadilha: um `grep HERO_Y` na rotina devolve quatro linhas. Quem
procura "essa rotina mexe na vertical?" com uma busca textual recebe *sim* como
resposta. Por isso a sonda que escrevi
(`notes/hero-walk-cycle-probes/lake_hero_left_locomotion.py`) relata as
escritas totais e as escritas **não-nulas** em colunas separadas, e falha com
código de saída diferente de zero se alguma não-nula aparecer — ela é ao mesmo
tempo a prova e o teste de regressão da conclusão.

## O que a rotina faz, então

| | laço lento | laço rápido |
|---|---|---|
| quadros | 15 | 12 |
| `HERO_X` por quadro | −2, duas vezes −3; média **−2,13** | −5, −7, **−13**, −12, −2, −7, −4, −7 |
| escritas em `HERO_Y` | 4, **todas `add [HERO_Y], 0x0000`** | nenhuma |
| sons | `play id=0x0051` ×2 | nenhum |
| termina em | o próprio laço de espera | `CINEMATIC_HERO_STOP_LEFT_0..2` |

Quinze quadros a dois pixels por quadro, com dois passos sonoros — um por pé
que toca o chão. É uma caminhada.

O laço vizinho é 4,3× mais rápido, parte do repouso, acelera até treze pixels
por quadro e desacelera até os quadros de parada. É a corrida. **Os dois nomes
estavam trocados**, e os quatro quadros que seguravam o nome `WALK_LEFT` não têm
deslocamento horizontal nenhum e vêm imediatamente antes de `RUN_LEFT_0`: são o
impulso inicial da corrida.

## A arte concorda, e diz que a divisão também estava errada

Os oito polígonos do bloco contíguo (passo de 0x28 entre eles, de 0x0A3C a
0x0B54) renderizados lado a lado são um ciclo de caminhada de perfil: a passada
abre até o máximo no quarto quadro e fecha de volta à posição de pé no oitavo.
Nada está no ar em quadro nenhum.

Ou seja: a fronteira entre "FALL" e "RESUME" não é fronteira na arte, não é
fronteira no banco de polígonos (o passo de 0x28 é ininterrupto) e não é
fronteira no laço, que desenha os quinze seguidos. Eram três famílias para uma
animação só.

Viraram uma, sem buraco:

```
CINEMATIC_HERO_LEFT_PROFILE      -> CINEMATIC_HERO_WALK_LEFT_0
CINEMATIC_HERO_FALL_LEFT_1..4    -> CINEMATIC_HERO_WALK_LEFT_1..4
CINEMATIC_HERO_RESUME_LEFT_0..9  -> CINEMATIC_HERO_WALK_LEFT_5..14
```

## A confirmação que ninguém arranjou

A versão MS-DOS não desenha um polígono por quadro: monta o herói a partir de
peças de um banco compartilhado, com uma pequena rotina por quadro. Depois da
correção, essas rotinas na versão MS-DOS eram `DRAW_HERO_WALK_LEFT_F0` e
`F6`..`F14`.

Cinco índices faltando. E havia exatamente cinco rotinas sem nome naquela fase,
cujas posições no bytecode o revisor de setembro já tinha casado, uma a uma,
com os quadros 1 a 5 do Amiga — por deslocamentos de X, por marcadores
`mov [0x29],[HERO_X]` e por uma âncora sonora. Elas preenchem o buraco
exatamente. Nenhuma das duas medições foi feita sabendo da outra.

## Onde eu parei, e por quê

**Só o lado esquerdo.** O espelho para a direita tem o mesmo defeito —
`HERO_FALL_RIGHT_LOOP` anda +2 por quadro, escreve `HERO_Y` só como
`add [HERO_Y], 0x0000` e dispara os mesmos dois passos — e **não** foi
renomeado. Cinco dos seus quinze quadros vêm de uma família cujo índice é, na
verdade, um índice do banco compartilhado disfarçado, e mexer nisso depende de
uma tarefa maior que ainda não foi feita. Ficou escrito no README do diretório,
com o comando para reconferir, em vez de ficar implícito.

## O erro que eu cometi no meio

A primeira versão do renomeador não estava restrita a LAKE. `HERO_WALK_LEFT_LOOP`
também existe, como rotina independente e diferente, em PRISON, CAVES e CAPSULE
— e eu renomeei as três, sobre uma medição que não diz nada a respeito delas.
611 referências em vez de 401.

O que salvou foi olhar quais arquivos tinham mudado antes de confiar no total.
O script hoje imprime o próprio escopo e afirma que nenhum rótulo afetado está
definido num trecho compartilhado entre fases; está guardado junto com a sonda,
e se recusa a rodar numa árvore já corrigida.

---

Números conferíveis: `make test` passa 29/29 e 29/29 (bytes idênticos aos
originais em todas as combinações de porte e fase), antes e depois. A sonda
sai com 0. LAKE na Amiga continua em 100%; na MS-DOS foi de 99,1% para 99,8%,
na cartucho de 96,7% para 99,2%, na GBA de 96,5% para 99,1%.
