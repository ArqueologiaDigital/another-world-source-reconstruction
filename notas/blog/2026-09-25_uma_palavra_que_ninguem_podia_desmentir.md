# Uma palavra que ninguém podia desmentir

*O dono do projeto mencionou um fato sobre a ficção: o Buddy e os guardas são da
mesma espécie, todos alienígenas deste mundo, e por isso se parecem. Isso não
mudou nenhum nome. Mudou o que conta como prova para uma classe inteira deles —
e, medindo a consequência, apareceu como a palavra "Buddy" tinha entrado em nove
constantes sem que nenhum passo do caminho jamais a tivesse testado.*

---

## O fato, e o que ele proíbe

A norma deste projeto tem um grau de evidência que pede para **renderizar e
olhar** antes de batizar. E o diretório `notes/actor-anchors/` existe para
insistir que a *âncora* de um desenho — o par de variáveis que diz onde ele vai
— não prova de quem ele é.

O fato do dono acrescenta a metade que faltava: **entre dois alienígenas da mesma
espécie, olhar também não prova.** Renderizar a figura e reconhecer "é o Buddy"
é reconhecer a espécie, não o indivíduo. Sobra a cena, e nada mais.

## O que foi medido depois

A hipótese óbvia seria que, sendo da mesma espécie, eles compartilham arte — o
mesmo corpo poligonal reaproveitado. Isso teria sido uma boa notícia: nome sem
palavra-ator, problema resolvido.

Três medidas em `dos_1992/PRISON.asm`:

| pergunta | resposta |
|---|---|
| constantes desenhadas em `[BUDDY_X],[BUDDY_Y]` nas duas cenas | **0** de 299 |
| constantes da cena do Buddy cuja arte bate com alguma da cena do guarda | **0** de 10 contra 111 |
| constantes `CV_*` desenhadas em `HERO_X` **e** em `BUDDY_X` | **0** |

Nenhuma arte compartilhada. A semelhança está no desenho e **não** nos assets:
são dois personagens, dois conjuntos inteiramente distintos de constantes e de
árvores de polígonos, e uma âncora em comum. O banco compartilhado também não
serve os dois a partir de uma figura só.

Então não é reaproveitamento. É um *slot* de ator, com duas ocupações, e a
única coisa que distingue as ocupações é a cena — o que é exatamente o que a
pessoa que jogou fez sem saber, ao chamar a figura de "guarda principal" até o
quadro 2546 e de "Buddy" a partir do 3073, com a virada no desabamento da jaula.

## De onde a palavra veio

Aí eu fui procurar o estrago e encontrei outra coisa.

Eu esperava achar as nove constantes `CINEMATIC_PRISON_BUDDY_*` batizadas por
alguém que olhou uma renderização e reconheceu o Buddy — o erro que o fato do
dono torna indetectável. Não foi isso. A evidência delas é geométrica e
composicional, e cada linha é sólida:

> *22x29, um caminho: um torso, mais largo nos ombros e nos quadris do que na
> cintura.*
>
> *9x25, um caminho, vai de −17,5 a −8,5 — à esquerda da âncora, compartilhando
> a aresta de ombro em −17,5 com as outras três.*

Trabalho correto, linha por linha. A palavra-ator não veio de nenhuma dessas
medidas. Veio da rotina que desenha as figuras, e a própria tabela diz isso com
todas as letras:

> *É a única figura de `DRAW_BUDDY_FIGURE_BASE`.*

`BUDDY` entrou por um rótulo que já existia, e depois viajou por uma cadeia de
derivações em que cada passo era sobre geometria e nenhum era sobre o ator.
Nenhum passo testou a palavra, porque nenhum passo era *para* testar a palavra.

E é aqui que o fato do dono fecha a armadilha: a verificação que teria parecido
decisiva — renderizar e olhar — não teria pegado nada, porque todos os
alienígenas se parecem.

## O que isso é, exatamente

Não é um nome errado. Eu não sei se algum daqueles nove está errado, e este
texto não decide isso.

É uma palavra **inverificável em circulação**: propagada por trabalho
individualmente correto, através de um caminho que nunca a examinou, num domínio
onde o exame mais natural é cego para ela. Nove constantes e noventa e oito
rótulos de rotina na fase carregam `BUDDY` no nome. Nenhum foi retratado.

A regra que ficou: **uma palavra-ator é admissível a partir da cena a que o
desenho pertence, e de nada mais.** Não da âncora, não da renderização, e não de
um rótulo vizinho que já tem a palavra.

E existe uma prova de que a disciplina é praticável, no mesmo arquivo: as **104**
constantes do banco compartilhado nesta fase se chamam todas `CV_FIGURE_*`.
Genéricas. Nenhuma delas reivindica um ator. Alguém, em algum momento, se
recusou a adivinhar — inclusive na constante que a pessoa jogando descreveu como
"o braço direito do guarda".

---

*As três medidas saem de `notes/actor-anchors/shared_actor_art.py`, que recebe
as cenas como faixas de linhas porque uma fronteira de cena aqui se descobre
lendo a listagem, não está marcada nela. Os onze itens anotados que dependem
dessa questão estão retidos, com um veredito cada, em
`notes/play-and-describe/verdicts.tsv`.*
