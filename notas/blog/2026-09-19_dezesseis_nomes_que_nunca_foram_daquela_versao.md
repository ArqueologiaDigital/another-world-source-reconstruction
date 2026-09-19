# Dezesseis nomes que nunca foram daquela versão

*Uma família de nomes ganha honestamente numa versão do jogo foi copiada para
outra pelo **índice** da constante, e não pela arte correspondente. Levou um dia
inteiro e três descobertas separadas para desmontar — e cada uma delas começou
com uma rotina que fazia uma coisa enquanto o polígono que desenhava dizia
outra.*

---

O projeto mantém o mesmo jogo em quatro versões. Um polígono é identificado
renderizando e olhando, numa versão; depois alguém quer o nome nas outras. O
manual do projeto é explícito sobre o risco:

> Nunca leve um nome ganho na renderização de um porte para o símbolo de outro
> porte. Estaria certo 2% das vezes.

Este texto é sobre as outras 98%, num caso em que ninguém percebeu por meses.

## Como apareceu

De manhã, duas rotinas da fase CAPSULE foram recusadas numa passada de
nomeação. Elas **ladrilhavam um feixe** — o corpo anda `[0x2B]` de 0x70 em 0x70
e desconta o mesmo de um comprimento restante — mas o polígono que desenhavam
se chamava `CINEMATIC_BUDDY_SMASHING_WINDOW_F7`, um quadro de "o alienígena
quebrando a janela". Registrei a dúvida assim: *as rotinas estão certas, quem
está em dúvida é o nome da constante.* E segui.

À tarde, nomeando polígonos em três fases, apareceu o mesmo conjunto de
ladrilhos três vezes: barras de 1 px com 2, 6, 14 e 30 px, ancoradas em x=64,
uma versão para cada lado. PRISON, CAVES, CAPSULE. Mais uma variante pesada de
5 px em PRISON, com 15, 47 e 111 px.

Quinze, quarenta e sete, cento e onze. E as três rotinas de CAPSULE que
desenham `_F5`, `_F6` e `_F7` andam de 0x10, 0x30 e 0x70 — dezesseis, quarenta e
oito, cento e doze.

> **Cada ladrilho mede exatamente um pixel menos que o passo da sua própria
> rotina.** É o que um laço de ladrilhamento precisa, e é o que os três de
> PRISON também medem.

Não são quadros de janela nenhuma. São ladrilhos de feixe.

## O que sobrou da família

Com três dos dezesseis explicados, fui ver os outros treze na versão Amiga.
Nenhum é desenhado pela rotina da animação.

| constantes | quem desenha | o que são |
|---|---|---|
| F5, F6, F7 | os três ladrilhadores | ladrilhos de feixe pesado |
| F9..F15 | `CAPSULE_CHARGED_BLAST_FADE_*` | o clarão carregado esmaecendo |
| F0..F4, F8 | três rótulos ainda sem nome | desconhecido |

E os sete do clarão trazem, pela quinta vez no dia, o mesmo padrão: as escadas
`_LEFT_` e `_RIGHT_` desenham **as mesmas seis constantes**. Medidas ao longo da
escada de casos, elas encolhem monotonicamente — 71x125 com 53 folhas até 30x7
com 6. Um esmaecimento.

## Onde a família era verdadeira

Na versão MS-DOS. Lá a rotina `BUDDY_SMASHING_WINDOW_ANIMATION` desenha, de
fato, `CINEMATIC_461` seguido de `F0..F15`, na ordem, no mesmo ponto fixo que
ela mesma semeia. O nome foi ganho ali e está certo ali.

A prova de que é a mesma animação nas duas versões não precisou de renderização
nova: as dezesseis constantes da MS-DOS têm **a mesma extensão e o mesmo número
de folhas** que as dezesseis da Amiga, uma a uma.

```
F0  139x190/40 = amiga 151      F8  94x100/13 = amiga 159
F1  158x188/40 = amiga 152      F9 164x176/36 = amiga 160
F2   94x106/16 = amiga 153      F10   6x7/2   = amiga 161
...                             F15  84x102/11= amiga 166
```

Dezesseis para dezesseis. Só que na Amiga essa animação está nas constantes
**150 a 166**, e os nomes tinham sido escritos nas constantes de mesmo índice
que a MS-DOS usava — que na Amiga são outra coisa inteiramente.

## O que ficou

A animação, nas duas versões, virou três camadas intercaladas que a
renderização individual mostra e que as extensões confirmam sozinhas: sete
poses de uma figura de pé, seis rajadas de estilhaços coloridos, três pontinhos
isolados. O nome não afirma **quem** é a figura — a rotina diz "buddy", mas
nenhuma renderização identifica ninguém, e esta é exatamente a categoria de
afirmação que já derrubou trinta nomes neste projeto.

E seis constantes da Amiga voltaram aos seus índices numéricos originais,
recuperados do histórico do git, porque quem as desenha ainda não tem nome e
**um nome falso é pior que um número**.

Isso faz a contagem de "polígonos sem nome" da Amiga em CAPSULE **subir** de 479
para 485. É a direção honesta: seis nomes saíram de uma arte que não descreviam,
e nada foi inventado para substituí-los.

---

Conferível: `make test` segue 29/29 e 29/29 o tempo todo — um nome de rótulo não
é um byte, então o portão nunca teria acusado nada disto. As tabelas com a
evidência por constante estão em
`another-world-archaeology/docs/content/research/2026-09-19-screen-num-and-small-stage-finish/`.
