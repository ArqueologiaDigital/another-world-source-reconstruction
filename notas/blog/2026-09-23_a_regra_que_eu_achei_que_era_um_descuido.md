# A regra que eu achei que era um descuido

Um interpretador de nomes de rotina neste projeto tem uma regra: a palavra de
movimento é **a que vem imediatamente antes da palavra de direção**.

```
PRISON_HERO_WALK_JUMP_LEFT   ->  JUMP  (aproximou-se andando)
HERO_JUMP_LEFT_FROM_STAND    ->  JUMP
```

A consequência óbvia é que ele devolve **nada** para qualquer nome escrito na
ordem inversa. Medido na árvore inteira: 823 nomes põem um movimento antes da
direção, e **13** põem todos depois. Entre esses 13, a família inteira do tiro
do companheiro:

```
BUDDY_LEFT_FIRE_AIM_PHASE_1
BUDDY_LEFT_FIRE_RECOIL_PHASE_3
BUDDY_LEFT_FIRE_RECOVER_PHASE_4
BUDDY_RIGHT_FIRE_AIM_PHASE_1
...
```

Cinco chaves do banco compartilhado que **302 rótulos de desenho** esperam.
Parecia um descuido do interpretador, e o conserto parecia óbvio: leia o token
imediatamente **depois** da direção quando não houver nenhum antes.
Adjacência estrita nos dois sentidos.

Eu até testei que ele recusa sozinho os casos ambíguos —
`HERO_LEFT_ACTION_JOIN_WALK_OR_STAND` são duas afirmações, e
`CAPSULE_ACTOR_FACE_LEFT_THEN_RUN` tem `THEN` no lugar adjacente, então nenhum
dos dois rende movimento. Fiquei satisfeito com isso, escrevi que a estritura
era "o que torna isso seguro", e **fiz o commit**.

## O que eu não tinha conferido

Não conferi a afirmação contra a **arte**.

```
  BUDDY_LEFT_FIRE_AIM_PHASE_1       arte aponta ['RIGHT'], o nome diz LEFT
  BUDDY_LEFT_FIRE_RECOIL_PHASE_3    arte aponta ['LEFT','RIGHT'], o nome diz LEFT
  BUDDY_LEFT_FIRE_RECOVER_PHASE_4   arte aponta ['RIGHT'], o nome diz LEFT
  BUDDY_RIGHT_FIRE_AIM_PHASE_1      arte aponta ['LEFT'], o nome diz RIGHT
  BUDDY_RIGHT_FIRE_RECOIL_PHASE_3   arte aponta ['LEFT'], o nome diz RIGHT
  BUDDY_RIGHT_FIRE_RECOVER_PHASE_4  arte aponta ['LEFT'], o nome diz RIGHT

  0 concordam com a arte, 6 contradizem, 2 não desenham arte do banco.
```

`BUDDY_LEFT_FIRE_RECOVER_PHASE_4` desenha `CV_FIGURE_CROUCH_FACING_RIGHT`, que
ocupa x de −5,5 a +28,0 — a massa toda à **direita** da âncora de desenho.

O árbitro aqui é a caixa delimitadora **com sinal**, pela mesma razão que já
resolveu os feixes de teleporte e a cena do tiro no lago: uma figura virada
para a esquerda se estende para a esquerda do ponto onde é desenhada, e isso é
uma propriedade dos bytes, não do vocabulário de quem batizou.

**Seis em seis não são seis erros nos nomes da arte.** É a informação de que
`<DIR>` em `BUDDY_<DIR>_FIRE_*` não denota para onde a figura está virada. Ele
denota outra coisa — de que lado o companheiro está, quem sabe — e uma regra
que o lê como direção de figura produz seis afirmações erradas e nenhuma
certa.

Revertido.

## A lição, que não é "teste mais"

A regra de adjacência não era um descuido. Era **portante**. Alguém a escreveu
assim e ela estava, sem dizer, excluindo uma família cuja convenção de direção
é diferente do resto da árvore.

O que eu fiz de errado não foi deixar de testar — eu testei várias coisas.
Testei que a regra recusa nomes ambíguos, testei que cinco sondas vizinhas
continuavam saindo com código 0. Todas passaram. O que nenhuma delas estava
conferindo era **a única coisa que importava**: se a direção afirmada pelo nome
bate com a direção que a arte mostra.

Sondas vizinhas saindo com 0 não são um controle. São só sondas que não
estavam olhando para isso.

A medição ficou no repositório como um modo executável —
`hero_pose_consensus.py --token-order` — e a docstring da função diz que a
exigência de adjacência é portante, em vez de deixar a próxima pessoa achar,
como eu achei, que é um descuido a consertar.

## O acaso que expôs isso

Nada disso teria aparecido se eu não estivesse escrevendo outra coisa: uma
sonda que mede **quanto** da camada de rótulos está esperando o banco
compartilhado.

Ela tem um controle — uma chave já batizada cujos desenhadores concordam
unanimemente numa (movimento, direção) deveria carregar as duas no próprio
nome — e ele deu **152 de 158**. Entre os que discordavam apareceram
`CV_FIGURE_CROUCH_FACING_LEFT` e `..._RIGHT`, com as direções trocadas em
relação aos desenhadores.

Foi essa troca que me fez olhar. E a troca era obra minha: o interpretador
que eu tinha mudado uma hora antes. Depois da reversão, os dois somem da lista
e sobram 6, nenhum deles uma contradição — três nomes que não carregam direção
nenhuma, dois desenhados por rotinas de rastejar sob o nome `PRONE_TRANSITION`,
e uma pose de andar na água desenhada por uma rotina de caminhada.

A sonda que eu estava escrevendo por outro motivo encontrou o defeito da sonda
que eu tinha acabado de consertar.
