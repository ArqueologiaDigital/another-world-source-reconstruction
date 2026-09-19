# A conta errada do que falta

*O projeto media o trabalho restante em rotinas sem nome: cerca de 3.800 na
versão Amiga. A medida está certa e a conta é enganosa — 3.495 das 3.515 que
desenham alguma coisa desenham **só** polígonos que ninguém identificou. A
unidade de trabalho não é a rotina; é o polígono.*

---

Reconstruir o fonte de um jogo a partir do bytecode tem duas metades: dar nome
às rotinas e dar nome aos dados que elas usam. O projeto mede a primeira com
cuidado — quantas rotinas alcançáveis ainda estão com nome de marcador, por
fase e por porte — e essa é a régua que aparece em todo relatório de progresso.

Três fases dominam o que sobrou: PRISON, CAVES e CAPSULE. Juntas, 3.796 rotinas
com corpo real e sem nome na versão Amiga.

A pergunta que eu não tinha visto ninguém fazer: **quantas dessas dependem de
algo que ainda não foi feito?**

## A medida

Uma rotina que só desenha polígonos já identificados tem o assunto resolvido
pela arte. Quem nomeou a constante já cumpriu a exigência do projeto — desenhar
o polígono e olhar antes de dar nome — e a rotina herda. Onde um único operando
ainda é `CINEMATIC_<número>` ou vem do banco compartilhado, nada está resolvido:
aquele número é um contador de ordem de encontro do desassemblador, não um
assunto.

Contando assim, para todas as rotinas alcançáveis e sem nome das três fases,
nos dois portes prioritários:

```
porte/fase            desenham algo   arte toda nomeada   mista   nada nomeado
amiga/PRISON                    488                   0       1            487
amiga/CAVES                     673                   1       3            669
amiga/CAPSULE                   448                   7       5            436
msdos/PRISON                    521                   0       2            519
msdos/CAVES                     722                   0       1            721
msdos/CAPSULE                   663                   0       0            663
TOTAL                          3515                   8      12           3495
```

Oito. De três mil quinhentas e quinze.

## O que isso muda

Contar as 3.800 rotinas como "o que falta" sugere um trabalho que se pode
atacar em paralelo, rotina a rotina ou família a família. Não é. A camada de
rotinas dessas três fases está **travada** pela camada de polígonos, e a
unidade real de trabalho são os cerca de 2.100 `CINEMATIC_NNN` sem nome que as
três guardam na versão Amiga — 677 em PRISON, 903 em CAVES, 521 em CAPSULE —
cada um exigindo uma renderização e um olhar.

Isso também explica uma coisa que estava à vista e que eu tinha lido como
acaso: as maiores famílias de rotinas que sobraram são trechos de duas linhas
que desenham um polígono e retornam. CAVES tem 51 rotinas com essa mesma forma;
CAPSULE, 36. Os membros de cada família **diferem apenas em qual polígono
nomeiam**. Não há o que decidir sobre a rotina até que se saiba o que é o
desenho.

## Das oito, duas

Rodei a lista e li as oito. Duas sobreviveram e foram aplicadas. Quatro são
duas cópias da mesma animação de quatro quadros, instaladas em dois canais
diferentes com dois pares de coordenadas diferentes — separá-las exige ler as
duas threads, e os pares de coordenadas são campos de registro de ator, que é
exatamente o tipo de coisa sobre a qual este projeto já derrubou trinta nomes
por afirmar demais.

As duas últimas são a sonda funcionando, não falhando. `LABEL_4CC4` e
`LABEL_4DDE` desenham `CINEMATIC_BUDDY_SMASHING_WINDOW_F8` e `_F7` — ambos
nomeados, ambos passariam no critério. Mas os corpos **ladrilham um feixe**: as
rotinas vizinhas se chamam `CAPSULE_SHOT_BEAM_TILE_MEDIUM` e `..._SHORT`, e
esta anda `[0x2B]`/`[0x2C]` de 0x70 em 0x70 por ladrilho. Ou a constante está
sendo reaproveitada como segmento de feixe, ou o nome dela é que está errado.
De qualquer forma a rotina não pode herdar.

> **Um polígono nomeado resolve o assunto de uma rotina só quando a rotina o
> usa como esse assunto.** A sonda acha candidatos, não vereditos.

## O critério de parada de uma medida

Vale registrar o que essa sonda **não** faz: ela não olha o número do polígono
para nada. Uma rotina que desenha `CINEMATIC_124` não se qualifica — e é bom
que não, porque `CINEMATIC_124` é precisamente o tipo de constante que, no
mesmo dia, custou a este projeto três nomes aplicados sobre a arte errada.

Uma medida de "o que está destravado" que aceitasse o índice como identidade
teria devolvido três mil e estaria errada em três mil.

## A alavanca, medida em vez de suposta

Se a camada de polígonos é o gargalo, vale saber quanto cada polígono destrava.
A sonda irmã (`art_with_named_drawers.py`) faz a busca inversa: quais
constantes sem nome são desenhadas **só** por rotinas que já têm nome — ou
seja, quais podem ser renderizadas com uma legenda já na mão. São 321 na Amiga
nas três fases.

O maior grupo coerente é a jaula suspensa de PRISON, 22 constantes sob um
dispatch inteiramente nomeado. Ler cada braço do dispatch transformou 22 em
**42**: cada valor de inclinação possui um *trio* de constantes consecutivas,
`3k`/`3k+1`/`3k+2`, e as três são sempre as mesmas três camadas — o herói com
um braço lançado (a "bombeada" que faz a jaula balançar), as barras da jaula
naquela inclinação, e o herói parado. Catorze linhas, nenhuma exceção. As 42
foram renderizadas e olhadas.

Resultado:

| | antes | depois |
|---|---:|---:|
| `CINEMATIC_NNN` sem nome em PRISON (Amiga) | 677 | 635 |
| rotinas de PRISON destravadas (dois portes) | 0 | 18 |

**42 nomes de polígono destravaram 18 rotinas.** É a razão de alavanca que a
medida do início previa, agora medida.

Seguindo a mesma ordem de serviço até o fim da lista de PRISON — o impacto de
tiro, os dois clarões, os segmentos de feixe, as tiras do poço do elevador, o
zoom da cutscene em dez fases, a pupila, os ladrilhos do feixe pesado —
**PRISON fecha o dia com 677 → 560 constantes sem nome na Amiga**, 117
identificadas, nenhuma nomeada pelo índice.

Duas coisas que só apareceram por fazer o lote inteiro. A primeira: o sprite de
impacto de tiro **não tem direção** — as famílias `..._IMPACT_LEFT_CASE_*` e
`..._IMPACT_RIGHT_CASE_*` desenham as *mesmas nove constantes*, o que só se vê
construindo o mapa constante→rotina em vez de ler os nomes das rotinas. Chamar
aquilo de `_LEFT_` teria sido falso. A segunda: existem **dois** conjuntos de
ladrilho de feixe, um de 1 px de altura (2/6/14/30) e um de 5 px (15/47/111),
o que retroativamente explica as duas rotinas de CAPSULE que eu tinha recusado
de manhã por desenharem um polígono chamado `BUDDY_SMASHING_WINDOW` enquanto
ladrilhavam um feixe: ladrilhar feixe é um idioma de primeira classe neste
jogo, com arte própria — quem está em dúvida é o nome daquela constante, não a
rotina.

E duas correções pelo caminho, as duas típicas. A primeira: o mapa
inclinação→constante que eu supus pela ordem dos offsets estava **errado**, e o
código desmentiu em dois braços — a inclinação 0x02 desenha `CINEMATIC_074`, e
não a 0x06 que os offsets sugeriam. O mapa final é extraído de todos os braços,
não inferido. A segunda: `..._TILT_FFFA` foi **recusado pela ferramenta**, e com
razão — a norma proíbe nome terminado em endereço hexadecimal cru, e o
classificador não tem como distinguir um imediato com sinal de um endereço. O
sinal passou a ser escrito por extenso (`_MINUS_6`), e os doze nomes positivos
que já tinham entrado como `_TILT_01` foram reescritos `_TILT_PLUS_1` para que
ninguém precise adivinhar se `01` é sinal ou índice.

Fica registrada uma colisão de regras que não tem culpado: a mesma seção da
norma proíbe terminar um nome em hexadecimal **e** exige o imediato em
hexadecimal na cauda `_CASE_` de uma rotina. Então, para a mesma inclinação, a
rotina se chama `..._TILT_CASE_FFFE` e o polígono `..._TILT_MINUS_2`. As duas
ferramentas discordam entre si e as duas estão certas.

## O que aparece quando se faz o lote inteiro das três fases

Levar a mesma ordem de serviço até CAVES e CAPSULE fechou o dia em **2.061 →
1.849** constantes sem nome nas três fases grandes da Amiga. E, como em PRISON,
o que pagou não foram só os nomes: foi o que só se vê olhando o conjunto.

**As direções mentem com frequência.** Em três famílias de duas fases
diferentes, as rotinas `..._LEFT_*` e `..._RIGHT_*` desenham **as mesmas
constantes** — o impacto de tiro de PRISON, o clarão de laser de CAVES, e a
virada do herói, cuja animação é um único percurso de nove quadros tocado para
frente ou para trás. Botar `_LEFT_` no nome teria sido falso nas três, e isso
só aparece construindo o mapa constante→rotina em vez de ler o nome da rotina.

**E há idiomas de engine.** O mesmo conjunto de ladrilhos de feixe — barras de
1 px com 2, 6, 14 e 30 px de comprimento, ancoradas em x=64, uma versão para
cada lado — aparece em PRISON, em CAVES e em CAPSULE, mais uma variante pesada
de 5 px em PRISON. Quatro comprimentos que são potências de dois menos dois:
um feixe de qualquer tamanho se monta com eles em decomposição binária. Isso
não é detalhe de uma fase, é como o motor desenha feixes — e é o que finalmente
resolve a dúvida que abriu o dia, com duas rotinas de CAPSULE que ladrilhavam
um feixe usando um polígono chamado `BUDDY_SMASHING_WINDOW`: as rotinas estão
certas, quem está errado é o nome daquela constante.

**Escopo por porte não é formalidade.** PRISON pôde receber os nomes em todos
os portes (delta +0x000, bancos idênticos). CAVES não: os deltas são
+0x1A0..+0x1AC e as rotinas dos dois portes desenham *símbolos diferentes* na
mesma posição do bytecode. CAPSULE é pior — a ferramenta não encontra
correspondência nenhuma. Nessas duas, os nomes foram aplicados só ao braço da
Amiga. Um `apply` global teria repetido, em 95 constantes, o mesmo erro que
custou três nomes de manhã.

---

Conferível: `notes/caller-derived-naming/named_art_only.py`, que imprime a
tabela acima e, com `--list`, os candidatos com os polígonos que cada um
desenha. `make test` segue 29/29 e 29/29.
