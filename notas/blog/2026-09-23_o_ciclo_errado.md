# O ciclo errado

No topo de uma sonda havia uma linha:

```python
CYCLE = 16
```

O teste que ela alimentava perguntava, para cada peça de membro de uma figura,
se o conjunto de quadros em que ela aparece contém um par que **soma 16** — os
dois instantes simétricos em torno do meio da passada, quando o membro está no
mesmo lugar. Para a caminhada isso está certo.

E a sonda aplicava o mesmo 16 à **corrida**, cuja folha tem dez quadros. O
espelho ali soma **9**. Resultado: todas as peças de corrida eram reportadas
como "fases não simétricas em torno do meio da passada", e a família inteira
ficava retida.

Elas são todas simétricas:

```
CV_2566  14x9/1   fase   0          -- o espelho, 9, não está atestado
CV_255C  10x7/1   fases  1, 8       -- 1 + 8 = 9
CV_2552  14x6/1   fases  2, 7, 8    -- 2 + 7 = 9
CV_2548  15x28/1  fases  3, 5, 6    -- 3 + 6 = 9
```

A soma agora é **derivada**, não escrita à mão: o único S para o qual toda
peça com duas ou mais fases tem um par somando S. Para as duas famílias de
corrida exatamente um S serve, e é 9.

A fase 4 não está atestada em nenhuma delas, e isso **corrobora** em vez de
abrir buraco: uma nota do próprio projeto já registra que
`HERO_RUN_LEFT_ARM` não tem exatamente o F04, porque naquele quadro não se
desenha braço nenhum.

## De onde vem a ordem

Não das fases. Foi essa a segunda coisa errada.

As duas direções de um mesmo andar são corridas paralelas no banco, a um passo
de offset constante. E a família `CV_FIGURE_WALK_<DIR>_LIMB_POSE_00..03` — que
uma pessoa numerou olhando só as fases, sem referência nenhuma ao banco — está
assim:

```
0x247C 0x2474 0x246C 0x2464     POSE_00..03, direita
0x2D6E 0x2D66 0x2D5E 0x2D56     POSE_00..03, esquerda
```

Índice sobe, offset **desce**, nas duas direções. O controle re-deriva todos
os índices já gravados a partir dos offsets sozinhos: **12 de 12**.

Então a ordem passou a ser o arranjo do banco, e as fases viraram a
**conferência** dele: lidas em ordem decrescente de offset, as primeiras fases
têm de subir estritamente. Uma família é o trecho mais longo onde as duas
coisas valem.

E o corte é evidência, não arrumação. `CV_2570` fica um passo acima da corrida
da direita e está atestado na fase 4, o que o colocaria antes da fase 0. Os
outros desenhadores dele são `BUDDY_RIGHT_FIRE_AIM_PHASE_1` — que o
interpretador de nomes não conseguia ler, porque ali a direção vem **antes** da
palavra de movimento.

## O erro que cometi no meio

A primeira tentativa colocou uma peça "sem fase" no lugar copiando o conjunto
de quadros do espelho dela. `CV_3200` não é sem fase: está atestado nas fases
8 e 9. A cópia teria gravado fases que ela não serve. Essa abordagem foi
apagada.

## O interpretador que não lia metade de uma família

Treze nomes na árvore põem toda palavra de movimento **depois** da direção, e
para todos eles o interpretador devolvia nada. Entre eles, a família inteira
`BUDDY_<DIR>_FIRE_{AIM,RECOIL,RECOVER}_PHASE_<n>` — cinco chaves do banco
compartilhado que **67 rótulos de desenho** esperam.

Agora ele lê o token imediatamente **depois** da direção quando não há nenhum
antes. Adjacência estrita nos dois sentidos, e a estritura é o que torna isso
seguro: pega os 6 nomes de tiro do companheiro e os 2
`HERO_<DIR>_CROUCH_KICK_LOOP`, e **recusa os outros cinco sozinho**.
`HERO_LEFT_ACTION_JOIN_WALK_OR_STAND` são duas afirmações, e
`CAPSULE_ACTOR_FACE_LEFT_THEN_RUN` tem `THEN` no lugar adjacente — uma direção
que pertence a *virar o rosto* e não a *mover* é exatamente o que não pode ser
lido, e a adjacência recusa isso sem que ninguém precise ensinar a palavra
`FACE` ao interpretador.

Não batizou nada. O que fez foi tornar uma exclusão **principiada**: `CV_2570`
e `CV_3212` passaram a carregar **duas** afirmações, `RUN` e `SHOOT`, então a
sonda os descarta pela regra de uma-afirmação-só que já existia, em vez de
pela heurística de arranjo que eu tinha acrescentado uma hora antes.

## O que ficou retido, e por quê exatamente

**RUN_LEFT.** Suas quatro peças espelham a corrida da direita exatamente:
mesma geometria, mesmo y, vãos em x refletidos em torno de ~0, mesmo passo de
10 bytes. Mas lidas em ordem de banco suas primeiras fases são 0, 8, 2, 3 —
não sobem. `CV_3200` está atestado em 8 e 9 e **nunca em 1**, onde seu gêmeo
da direita `CV_255C` está atestado em ambas.

Só o espelho o colocaria, e uma única família de precedente é pouco para
passar por cima de uma fase que contradiz. Um desenhador batizado à esquerda
na fase 1, ou uma renderização, resolve.

4 nomes, globais em todas as versões porque o banco é um arquivo só. Chaves do
banco ainda numeradas: 57 → 53. Assets: 63,6% → **63,8%**.
