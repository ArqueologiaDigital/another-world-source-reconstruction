# O banco que ninguém podia nomear era a folha de sprites do herói

*Um dos bancos de arte do jogo é compartilhado por todas as fases, e a norma do
projeto o proibia de ter nomes: **1.021 entradas, zero batizadas**, com 1.147
rotinas travadas atrás disso. A alavanca que finalmente o abriu não foi a
figura desenhada. Foi **onde ela é desenhada** — um operando que nenhuma
renderização mostra.*

---

## Por que as alavancas de sempre não chegam lá

O banco compartilhado é o recurso `0x11`: 25.108 bytes, idênticos byte a byte
entre Amiga e MS-DOS. O item T7 do plano acabou de rechaveá-lo por offset
(`CV_<OFFSET4>`), que é o que torna uma identificação *válida em toda parte* —
mas rechavear não é nomear, e a norma diz explicitamente que nomear à mão
continua proibido "até que uma identificação seja de fato feita a partir de uma
renderização".

A alavanca que funciona nos bancos por fase é o *único desenhador batizado*:
se uma só rotina com nome semântico desenha aquela figura, o nome dela
identifica a figura. Aplicada aqui, ela devolve **1 candidato em 352**. O
motivo está numa medida só:

> **349 dos 352 offsets são desenhados a partir de mais de uma fase.**

Seja lá o que `CV_1B14` for, é a mesma coisa em PRISON e em ENDING. Nenhuma
cena pode batizá-lo.

A forma também não termina o serviço. Medindo extensão, contagem de folhas e
cores de todos os 352 antes de olhar qualquer imagem, 250 caem em "precisa de
renderização" — e para os dez que são figuras articuladas é pior que isso: a
renderização mostra uma figura, e a pergunta era *qual* figura.

## O operando que resolve o assunto

```
video type=0, offset=CV_5C4C, x=[HERO_X], y=[HERO_Y], zoom=0x40
```

`HERO_X` mora em `src/levels/_common_vars.inc`, e a regra de escopo desse
arquivo — escrita na norma muito antes desta passada, por outro motivo — é que
um nome só pertence ali **se significa a mesma coisa em toda fase e toda
versão**. É exatamente a invariante de que um nome de banco compartilhado
precisa.

Contando todos os pontos de desenho, nas duas versões prioritárias e nas nove
fases:

| | |
|---:|---|
| **191** | desenhados só em `[HERO_X],[HERO_Y]` |
| **148** | desenhados só na ficha de ator (#0138) |
| **13** | mistos |
| **0** | desenhados nos dois |

O banco não é uma miscelânea. É **a folha de sprites do herói mais a de um ator
genérico** — e é por isso que fase nenhuma é dona dele: o herói está em todas
as fases, logo a arte dele não pode morar no banco de nenhuma.

Isso *afia* o #0138 em vez de dissolvê-lo. Nos 148, a posição é o registro de
ator, carregado de uma ficha diferente antes de cada desenho: diz *um* ator e
se recusa a dizer qual. Continuam travados. E medir isso exige resolver os
apelidos — o teste literal por `[0x07],[0x08]` subnotifica muito, porque
PRISON, CAPSULE e ENDING escrevem `[BUDDY_X],[BUDDY_Y]`.

## O erro que a própria medida expôs

Renderizada em ordem de offset, a metade do herói é inconfundível: 58 quadros
de uma figura humana de perfil, caminhando e correndo, e uma série paralela de
membros dobrados — um **braço**, alguns quadros bifurcados em volta de uma
arma, o que bate com `HERO_GUN_ARM_POSE_CASE_02`, um nome ganho antes, que
desenha justamente uma das variantes bifurcadas.

Só que as extensões que eu media não batiam com o que o renderizador desenhava.
Para `CV_00B4` eu tinha 80x66 e ele produzia 24x49. Nas árvores planas, os dois
concordavam exatamente.

O renderizador estava certo. Os dois bytes de tamanho no cabeçalho **não
significam a mesma coisa** nos dois formatos: num polígono sólido são uma caixa
delimitadora, dividida por dois; num grupo são um **pivô**, subtraído inteiro
antes de somar a posição de cada filho. É o que a VM de referência faz em
`readAndDrawPolygonHierarchy`. A ferramenta do projeto dividia os dois por
dois.

O defeito sobreviveu por um motivo que está escrito na própria docstring da
ferramenta: *"lendo `cinematic.rom` direto, sem renderizador no meio"*. Era o
objetivo — e tirou do caminho a única coisa capaz de pegar uma leitura errada
do formato. Escondeu-se também na amostra: arte de uma folha só mede certo
pelas duas regras, e arte de uma folha só é a maior parte do que se mede.

Medido contra o renderizador em dois bancos inteiros:

| | video2 (1.212) | cinematic fase 4 (2.893) |
|---|---|---|
| regra antiga | 104 discordâncias sem explicação | 148 |
| regra corrigida | **0** | **0** |

O que sobra é a heurística de linha documentada do próprio renderizador — um
polígono de 4 pontos com `pt[0]==pt[3]` e `pt[1]==pt[2]`, alargado em 2 "para o
visualizador de SVG desenhar". Testei isso primeiro com uma pergunta mais
frouxa, "alguma folha mede menos de 2 de largura", e ela desculpava 100
polígonos que a regra antiga errava pelo motivo comum — escondendo a maior
parte do defeito que a sonda existia para caracterizar.

**Preço:** 2.468 de 10.144 polígonos batizados mudam de extensão. **O que não
muda:** `canonical_md5` serializa os bytes do cabeçalho sem interpretá-los,
então toda identificação entre versões continua de pé, e as três auditorias
passam de novo. Três figuras já publicadas mudaram e foram corrigidas no mesmo
commit — a maior delas descreve melhor o nome que já tinha: o respingo de
CAVES não "cresce até 88x93 e se dispersa em 74x67", ele **incha até 32x33 e
murcha até 8x15**, que é o que um respingo faz. Os números velhos eram a curva
de inflação do defeito.

## O que as outras fases já sabiam

A pose não precisava ser adivinhada. O mesmo offset é desenhado por rotinas em
CAPSULE, CAVES e PRISON, batizadas separadamente, por gente que não estava
olhando para este banco:

```
CV_331A   CAPSULE_HERO_WALK_LEFT_DRAW_14
          CAVES_HERO_WALK_LEFT_STRIDE_PHASE_15     (CAVES conta de 1)
          PRISON_HERO_WALK_LEFT_DRAW_PHASE_14
          DRAW_HERO_WALK_LEFT_F14
```

Quatro derivações que nunca se consultaram. A sonda exige **duas fases
independentes** — dois nomes da mesma rotina, ou duas versões da mesma fase,
contam uma vez — e **unanimidade, não maioria** (#0120: uma ferramenta não
escolhe vencedor entre dois nomes semânticos). Exclui nomes `_BUNDLE_`,
`_SHADOW_` e `_2NDSCR_`, que carregam corridas de índice cru e descrevem um
*mecanismo de desenho*; e lê `_FOOTSTEP_PHASE_n` para movimento e direção, mas
**nunca** como número de quadro.

Três conferências que não entraram na derivação:

- **Ordem de offset.** Em toda família os índices do consenso são
  ciclicamente monótonos na ordem dos offsets — corpo e braço de WALK_RIGHT dão
  a sequência *idêntica* 9,10,…,14,0,…,6,8.
- **Corpo e braço juntos.** 15 de 15 quadros de WALK_RIGHT e 10 de 10 de
  RUN_RIGHT têm corpo e braço desenhados pela mesma rotina, 5 a 7 rotinas cada.
  O pareamento está no código, não inferido do tamanho.
- **As passadas caem onde passadas caem.** Os nomes `_FOOTSTEP_PHASE_1/2`,
  proibidos de fornecer índice, ficam nos quadros 0 e 5 do ciclo de corrida de
  dez quadros e 5 e 13 do de caminhada de quinze.

**52 nomes aplicados**, sem buraco de índice. Dois quadros se apoiam em
evidência mais fraca e estão marcados como tal em vez de escondidos no lote.
**158 rotinas que antes desenhavam só marcadores agora desenham só figuras
batizadas.**

## Duas ferramentas que mediam errado o próprio progresso

**A métrica de cobertura encolhia o denominador.** Batizar os 52 moveu a
percentagem de 38,9% para 40,3% com o numerador **congelado em 3.947** — a
ferramenta selecionava por prefixo `^(CINEMATIC|CV|COMMON_VIDEO)_`, então um
polígono saía da população no instante em que ganhava um nome que não começa
com um desses. Os 52 são definidos em várias fases cada: 360 linhas sumiram do
denominador. Contando por *uso* — um símbolo conta se aparece como
`video ... offset=`, que é como o código o identifica — a mesma passada lê
**3.949/10.147 antes e 4.309/10.147 depois**. O numerador carrega o movimento
todo. (Eu tinha escrito 39,4% na docstring como palpite, antes de calcular.
Está substituído pelo par medido.)

**A atribuição de desenhos perdia fontes.** Sondas do projeto creditam cada
`video offset=` ao **rótulo imediatamente anterior**, e rotinas aqui abrangem
vários rótulos: um desenho atrás de um condicional acaba arquivado sob
`LABEL_6DC2`. O viés é de mão única — fontes batizadas são subcontadas, nunca
supercontadas — então "N fontes independentes concordam" continua válido e "só
uma fonte, logo rejeita" às vezes não. Foi assim que achei: o consenso rejeitou
`CV_0358` por ter uma fonte quando tem três.

A correção segue o fluxo de controle e credita um bloco só quando **exatamente
uma** rotina batizada o alcança. A primeira versão não tinha essa exclusividade
e levou msdos/CAPSULE de 297 para **10.402** pares (rotina, figura) — 21
figuras por rotina — porque uma caminhada para a frente inunda as regiões sem
nome. Com exclusividade: 6.511 → 7.598.

E isso criou um defeito novo que a regra antiga não podia ter:
`PRISON_HERO_STAND_LEFT_TICK` é um despachante que alcança oito quadros de
caminhada e passou a "afirmar" STAND sobre todos. O limite que resolve é lido
dos dados, não escolhido: figuras distintas por rotina é bimodal — 182 rotinas
desenham uma, 100 desenham duas, depois uma cauda fina até 18 — e o modo baixo
é exatamente o que um quadro é, corpo e braço. Duas sutilezas: contar chaves
`CV_` faz o limite *apodrecer* conforme o banco é batizado (o TICK caiu de sete
para duas e voltou), então conta-se posição de desenho, que não se renomeia; e
o mesmo TICK alcança 7 figuras na MS-DOS e 2 na Amiga, então o limite é o
**máximo entre versões**.

## Um nome, um offset — e 43 que não eram

A verificação que eu tinha escrito só perguntava se um *nome* denota um offset.
Não enxergava o contrário, e o contrário estava lá: **137 de 358 offsets do
banco carregavam mais de um nome**.

Perguntar isso direito exige o discriminador de banco: `video type=0` seleciona
o video2; `video` puro seleciona o banco cinematográfico da fase, onde o
**mesmo offset numérico** é outra figura. Comparar valores de `EQU` sem isso
relata 105 "duplicatas" que não são nada disso — foi a minha primeira medida.

Das 137, 121 são sobreviventes `COMMON_VIDEO_nnn` na versão GBA, que o rechaveio
de T7 não cobriu, e ficam registradas. As outras 43 eram apelidos com cara de
endereço em trechos compartilhados — `ADDR_AT_00B4`, `LABEL_0128`,
`DELAY_LOOP_VARED_AT_0844`, `STATE_VAR12_BIG_DISPATCH_CASE_30_AT_2D4E`. Estão
fundidos: 49 operandos e 126 definições, **0 restantes**.

Três tropeços no caminho, cada um uma armadilha para quem vier depois:

1. **Reescrever só os operandos deu 240 referências indefinidas.** Os apelidos
   não são grafias redundantes ao lado da chave: são substitutos guardados por
   `.if BRANCH` justamente para as versões onde a chave **não** é definida.
2. **Restringir a renomeação de definições aos `*_equ_aliases.inc` deu 27/29.**
   Os arquivos canônicos também definem alguns. O `undefined_symbols.py` passou
   o tempo todo — ele confere a árvore unificada, e estes eram os canônicos. Só
   o portão de bytes viu. A restrição era cautela com `LABEL_0128:`, que é um
   rótulo de código de verdade em dos/CAPSULE; casar `<NOME> EQU` em vez de
   `<NOME>:` resolve isso sem ela.
3. **Um operando não nomeava figura nenhuma.** Em CAPSULE, `LABEL_3640`
   resolvia para o rótulo de código `LABEL_3640:`, cujo endereço por acaso é
   igual ao offset 0x3640. Nada declarava 0x3640 como arte naquelas versões.

## O saldo

- O banco compartilhado tem nome pela primeira vez: **52 offsets**, e uma
  explicação estrutural do que ele é.
- **158 rotinas** saíram do bloqueio T7; 1.407 continuam nele.
- Camada de assets: **38,9% → 42,4%**, medida por uso. (Logo depois dos
  52 nomes a métrica marcava 42,5%; a fusão dos 43 apelidos, mais adiante
  nesta mesma sessão, reclassificou dois nomes-marcador como chaves, que é
  a direção honesta. O número final é este.)
- Um defeito de medição corrigido em duas cópias, com as três afirmações
  publicadas que ele contaminava re-medidas e corrigidas no mesmo commit.
- `make test` 29/29 e 29/29 o tempo todo, exceto quando eu o quebrei e ele me
  disse.

O fio que liga tudo: **três das quatro coisas que destravaram este banco não
estão na figura.** A posição de desenho, o consenso entre fases que nunca se
falaram, e o pareamento corpo-braço no fluxo de controle. A renderização
confirmou; sozinha, ela mostrava uma pessoa andando e não dizia mais nada.
