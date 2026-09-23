# A família começava quatro passos antes

A cutscene de zoom de PRISON desenha painéis laterais, um par por etapa, e as
larguras deles caem monotonicamente do começo ao fim:

```
272/273  79,0      266/267  72,0      LEFT_1  68,0
270/271  74,5      LEFT_0   70,0      LEFT_2  65,5   ... até 41,5
```

As quatro primeiras não tinham nome. As outras dez tinham, numeradas de 0 a 9.

Ou seja: `CINEMATIC_266` a `273` são quatro pares **do mesmo movimento de
câmera**, desenhados antes dos que já estavam batizados. A família existente
estava com a base errada em quatro.

Esquerda e direita não vieram da ordem em que a rotina desenha, e sim da
**caixa delimitadora com sinal**: toda `LEFT` ocupa x negativo — −115,0..−36,0
na mais larga — e toda `RIGHT` é o espelho dela.

Renumerar vinte nomes já ganhos é o ponto da mudança, não um efeito colateral.
As alternativas eram uma família que começa em 4, ou uma segunda família para
os quatro primeiros passos, e as duas descrevem mal um único movimento
contínuo de câmera. A versão MS-DOS foi casada com a Amiga pelo md5 canônico o
tempo todo, nunca por índice, com zero ambiguidades.

## E aí quebrou, por um motivo que vale guardar

O portão acusou **28/29 na metade unificada** — o arquivo canônico estava
certo e a árvore unificada errada.

`apply_branch_scoped_names.py` renomeia o arquivo canônico
**simultaneamente**. É isso que faz uma permutação funcionar: a docstring dele
registra o caso de `CINEMATIC_795` assumir o `_0` enquanto o antigo `_0` vira
`_2`, terminando com cada nome usado uma vez.

`sync_equ_rename.py` **não**. Ele reescreve os tokens dos pedaços unificados
uma regra de cada vez. Então renomeou `CINEMATIC_272` para `LEFT_0`, e a regra
posterior `LEFT_0 -> LEFT_4` pegou o nome que ele próprio acabara de criar:

```
CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_4 definido 2 vezes, 2 VALORES DIFERENTES
    EQU 0xCA7C   <- o LEFT_0 antigo, deslocado corretamente
    EQU 0xCA04   <- o LEFT_0 novo, deslocado de novo
```

O conserto não é no código, é uma **regra de ordenação**: as linhas de
deslocamento primeiro e em ordem decrescente de índice, e as linhas que
introduzem nomes novos por último. Assim nenhuma regra jamais vê um nome que
uma regra anterior produziu. Está escrita agora no README de
`notes/unified-scoping/` e no topo das duas tabelas de proposta.

## O que isso diz sobre o portão

Vale reparar em qual metade acusou. A comparação byte a byte do arquivo
canônico passou — 29/29 — porque o arquivo canônico estava correto. Só a
árvore unificada quebrou.

Se eu tivesse rodado só metade do portão, teria commitado uma árvore com dois
EQUs do mesmo nome apontando para offsets diferentes, que **montam em
silêncio** e movem bytes numa versão que eu não estava olhando. As duas
metades não são redundantes.
