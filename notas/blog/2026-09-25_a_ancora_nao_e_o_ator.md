# A âncora não é o ator, e a prévia não é a frase

*Alguém jogou a fase PRISON e anotou 46 polígonos. Vinte e três viraram nomes.
Mas o resultado que muda o que o projeto acredita não foi um nome: foi uma
contradição entre o que a pessoa viu e o que a árvore diz — e ela é decidida
pelas próprias anotações, numa cena específica que a pessoa também anotou.*

---

## Duas taquigrafias

Este texto é sobre dois casos do mesmo erro, e o segundo é meu, cometido ontem.

Uma **âncora** é o par de variáveis que diz onde um desenho vai:
`x=[BUDDY_X], y=[BUDDY_Y]`. Ler isso como "logo, é o Buddy" é tentador e o
projeto já documentou que não vale: dez constantes da fase CAPSULE foram
batizadas assim e tiveram que ser renomeadas.

Uma **prévia** é a primeira oração de uma anotação, impressa na fila para você
decidir se vale abrir. Ler isso como "logo, é isso que a frase diz" também é
tentador, e também não vale.

## O ator

A pessoa anotou a figura desenhada em `[BUDDY_X],[BUDDY_Y]` assim:

| quadros | como ela chamou |
|---|---|
| 118 – 2546 | **o guarda principal** |
| 3073 – 3136 | **o Buddy** |

Sem margem para dúvida sobre qual dos dois: *"full body of the main guard,
standing with his back to the camera right after removing and storing his
cloak"* contra *"buddy's right arm while tapping lester's back/shoulder"*.

Os dois conjuntos são desenhados em regiões separadas do bytecode —
`PRISON.asm:8849-10045` contra `3631-3757` — e a virada cai exatamente no
desabamento da jaula, que a mesma sessão anotou nos quadros 3069 a 3075: a arma
arrancada da mão do guarda, os destroços passando pela câmera, os restos
parados no chão, e então *"frame of buddy starting to wake up from the fallen
cage"*.

**Então `BUDDY_X`/`BUDDY_Y` na PRISON é um *slot*, e a cena decide quem está
nele.** Essa era a tese do projeto, argumentada a partir da árvore. Agora ela
tem uma testemunha que nunca leu a árvore.

O que isso põe em questão: `dos_1992/PRISON.asm` define **9** constantes
`CINEMATIC_PRISON_BUDDY_*` e **98** rótulos de rotina com `BUDDY` no nome. Nada
foi retratado — nada acima mostra que alguma delas está errada. O que muda é
que a palavra-ator em qualquer uma delas precisa da *cena*, não da âncora, e uma
auditoria agora tem duas faixas de linhas por onde começar.

E onze anotações ficaram **retidas** em vez de virar nome, porque a pessoa e a
árvore discordam sobre a mesma constante: `DRAW_PRISON_BUDDY_POSE_3` desenha
`CINEMATIC_231`, que a pessoa chama de cabeça do guarda. A regra da casa diz
para não escolher entre nomes ganhos. A discordância é o achado; escolher um
lado seria perdê-lo.

## A prévia

No dia anterior eu tinha julgado duas anotações como **recusadas**, com o
fundamento de que "não enunciam sujeito". A fila mostrava:

```
"i dont understand why..."
```

As frases inteiras são *"i dont understand why, but this seems to be the
bounding box of lester's body while he is travelling up or down in the lift"* e
a mesma coisa para o Buddy. A função que monta a prévia cortava na vírgula.

O procedimento deste diretório manda **medir antes de acreditar na fila**, e eu
julguei pela fila. Isso é meu e não muda. Mas uma prévia que *inverte* o sentido
de uma frase é uma armadilha, não uma prévia, e isso é do código: o corte agora
não acontece antes de *but, although, however, perhaps* e companhia — a frase
ainda não começou a dizer nada ali.

As duas viraram as **melhores linhas do lote**. `CINEMATIC_102` é desenhada em
`[HERO_X],[HERO_Y]`; `CINEMATIC_131` em `[BUDDY_X],[BUDDY_Y]`, atrás de um
`je [0x11], 0x00` que só a desenha quando o companheiro está presente. A tira do
chão mede 58,0 de largura e o carro do elevador mede 58,0. As quatro são **um
polígono só, na cor de índice 1** — que é exatamente por que a pessoa viu
blocos sem traço nenhum e perguntou por quê: são silhuetas.

A pessoa atribuiu as duas caixas ao Lester e ao Buddy sem ter acesso a nada
disso, e as âncoras concordam.

## O que fica

Nas duas histórias alguma coisa curta ficou no lugar da coisa comprida: a
âncora no lugar do ator, a primeira oração no lugar da frase. Nas duas, o que
desfez o engano foi ir ler a coisa comprida — a cena em que o desenho acontece,
a anotação inteira.

E há uma simetria que eu não esperava. A âncora dizia "Buddy" e a pessoa
corrigiu. A prévia dizia "não entendo" e a pessoa, na frase inteira, entendia
perfeitamente. As duas taquigrafias erraram na mesma direção: para menos do que
havia ali.

---

*23 constantes e 7 rotinas nomeadas nesta leva, cobertura de 83,1% para 83,6%.
A fila é `make annotations`; o achado do slot está em
`notes/actor-anchors/README.md`, seção "2026-09-25"; as 15 anotações ainda
abertas estão agrupadas por assunto em `notes/HANDOFF.md`.*
