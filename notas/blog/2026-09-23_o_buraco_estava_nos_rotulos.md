# O buraco estava nos rótulos, não na animação

*Uma ferramenta ofereceu seis nomes com índices 01, 02 e 04. O buraco no 03
foi o que denunciou tudo: os números não eram quadros, eram limiares de
comparação — e os três quadros que faltavam nunca tinham sido propostos
porque estavam atrás de rótulos sem nome para herdar. Ao ir atrás disso,
apareceu que três fases desenham **a mesma** animação, que a minha primeira
correção usou a convenção errada de índice, e que uma ferramenta vinha
afirmando "os bytes mudaram" sobre uma comparação que nunca aconteceu.*

---

## A proposta com um buraco

A sonda `nameable_from_drawer.py` bate uma regra simples: se uma constante é
desenhada por exatamente **uma** rotina com nome semântico, a constante pode
herdar esse nome. Ela ofereceu seis, todas em CAVES:

```
amiga/CAVES  CINEMATIC_777  ->  CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_ABOVE_04
amiga/CAVES  CINEMATIC_775  ->  CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_ABOVE_02
amiga/CAVES  CINEMATIC_774  ->  CINEMATIC_CAVES_LASER_IMPACT_ANIM_RIGHT_ABOVE_01
```

01, 02, 04. A norma do projeto (`docs/NAMING.md` §2) proíbe buraco na
sequência de índices de uma família — "um buraco significa que um quadro foi
perdido ou que o esquema está errado" — então a aplicação seria recusada de
qualquer jeito. Mas a pergunta útil não é "como faço passar", é **por que
falta o 03**.

## O rótulo não é um quadro

O código:

```
CAVES_LASER_IMPACT_ANIM_DISPATCH_RIGHT:
        jge [0x13], 0x64, LABEL_684D
        jle [0x13], 0x03, CAVES_LASER_IMPACT_ANIM_RIGHT_ABOVE_02
        jle [0x13], 0x05, CAVES_LASER_IMPACT_ANIM_RIGHT_ABOVE_04
        video offset=CINEMATIC_778
        mov [0x13], 0xFFFE
        ret

CAVES_LASER_IMPACT_ANIM_RIGHT_ABOVE_04:
        jle [0x13], 0x04, DRAW_CIN_776
        video offset=CINEMATIC_777
        ret
```

`..._ABOVE_04` é um **nó interno de uma busca binária** sobre o temporizador
`[0x13]`. Entra-se nele quando o valor é 4 ou 5, e a figura desenhada no
próprio rótulo é a do valor **5**. Herdar o número do rótulo erra o quadro em
um *e* grava um limiar de comparação onde deveria ir um índice.

E os três que não receberam proposta nenhuma — `CINEMATIC_773`, `776`, `778`
— não são arte faltando: estão atrás de rótulos `DRAW_CIN_<n>`, que não têm
nome semântico para herdar. **O buraco estava em quais rótulos tinham nome,
nunca na animação.**

## Avaliar a escada, em vez de ler os rótulos

A sonda nova não olha para nome de rótulo. Para cada valor do temporizador
ela *executa* a escada — segue as comparações até chegar num `video offset=`
— e relata a figura que aquele valor realmente desenha. Dá uma animação
fechada de seis quadros por direção:

| v | extensão | folhas |
|---|---|---|
| 1 | 2,0 x 5,0 | 6 |
| 2 | 9,0 x 10,0 | 6 |
| 3 | 17,0 x 12,0 | 7 |
| 4 | 17,0 x 17,0 | 6 |
| 5 | 16,0 x 17,0 | 4 |
| 6 | 4,0 x 6,0 | 2 |

Um clarão que cresce por quatro quadros e deixa um resíduo. Quem serve de
relógio é o chamador — `and [0x13], 0x7FFF` / `call` / `add [0x13], 0x0001` /
`or [0x13], 0x8000`: os 15 bits de baixo são o contador e o bit alto marca
que a vaga está ocupada. A rotina que resolve o impacto semeia
`mov [0x13], 0x0001`, e no valor 6 o dispatch escreve `0xFFFE`, que o
`add`/`or` seguintes transformam em `0xFFFF` — exatamente o valor que o laço
de vagas lê como "livre". Corrida fechada, com terminador, **sem quadro 0**.

## A mesma animação em três fases

Ao generalizar a sonda — a entrada de cada escada é descoberta pela
assinatura `jle [0x13], 0x05`, não por uma lista que eu escrevi — apareceram
seis escadas por versão, não duas: PRISON, CAVES e CAPSULE, cada uma com duas
direções. E o `canonical_md5` diz que **é a mesma arte nas três**, quadro a
quadro, nas duas versões prioritárias. Três fases desenham um efeito só, a
partir de três cópias do banco.

A direção também não sai do rótulo: o dispatch da direita em PRISON ainda se
chama `LABEL_3BB3` e não diz nada. Quem diz é a máquina — o bloco que chama
escreve `[0x0E]`, 0 para a direita e 1 para a esquerda, e é isso que o código
de desenho lê para escolher a arte espelhada.

## O meu erro: a convenção do índice

Batizei CAVES de `_F01..F06`, atrelado ao valor do temporizador. Está fora da
norma: a linha 208 do `NAMING.md` fixa a forma como `<índice de quadro,
decimal, base 0>`. E estava fora das duas fases irmãs, que já chamavam a
mesma arte de `..._SHOT_HIT_BURST_<DIR>_0..4`.

Renumerei para `_0.._5`. E a sonda passou a **medir** isso em vez de confiar:
ela informa, por escada, a diferença entre o índice escrito e o valor do
temporizador que o desenha, e falha se a árvore inteira não concordar numa
diferença só. Antes da correção a linha dizia

```
index base: every named frame is the timer value shifted by ['-1', '0']  ** not one convention **
```

e saía com código 1. Depois, `['-1']`.

As irmãs, por sua vez, estavam **um quadro curtas**: o resíduo que libera a
vaga ficou como `CINEMATIC_<índice>` cru em todas as versões. Agora as seis
famílias correm 0..5 sem buraco.

## Por versão, não global

A arte concorda entre as versões; os **símbolos** não. Em CAVES os quadros da
Amiga são `CINEMATIC_773..778`, os da MS-DOS são `799..803`, e as duas versões
definem um `CINEMATIC_774` — o da MS-DOS é arte sem relação nenhuma. Uma
renomeação global pela numeração da Amiga é exatamente o erro que precisou ser
revertido em setembro. Então cada versão ganhou a sua própria tabela.

De brinde, um nome errado caiu com a evidência que o desmente no mesmo commit:
`CINEMATIC_CAVES_DRAW_HERO_IDLE_LEFT_1`, na MS-DOS, é um borrão de 2,0 x 5,0
com seis folhas cujo `canonical_md5` é igual ao primeiro quadro do clarão da
Amiga, e a única referência a ele na árvore era o braço `jle [0x13], 0x01` da
escada de impacto. Não é uma pose parada do herói.

## "Não consegui conferir" saindo como "não bate"

A terceira versão, `cartridge_1992`, recusou tudo:

```
REVERTED: genesis_europe/PRISON no longer byte-matches after renaming;
a constant rename must be byte-neutral
```

Isso é uma afirmação séria — uma renomeação que move bytes quer dizer que
algum símbolo ficou pendurado. E era falsa: as mesmas duas renomeações feitas
à mão dão `make verify-stages` 29/29, com `PRISON OK`.

A causa é um diretório de trabalho. A ferramenta termina com

```python
want = expected_bytes(port, args.stage)
ok = want is not None and assembles_to_expected(...)
if not ok:  # reverte, imprime "no longer byte-matches"
```

e `expected_bytes` devolve `None` quando a imagem de referência simplesmente
não está lá. As duas versões de cartucho chegam à delas por um caminho
**relativo**, enquanto Amiga e MS-DOS usam caminhos absolutos. O `Makefile` faz
`cd` para o outro repositório antes de chamar o verificador; rodar a ferramenta
à mão a partir do repositório de fontes, não. Medindo dos dois lugares:

| diretório | pares com referência | sem |
|---|---|---|
| `another-world-archaeology` | 29 | 0 |
| `another-world-source-reconstruction` | 20 | 9 |

Amiga e MS-DOS nunca poderiam exibir o defeito, e por isso ele só apareceu na
terceira versão. A ferramenta agora separa os dois casos, diz qual encontrou,
nomeia a raiz que falta e — quando a raiz é relativa — diz de onde rodar.

## A cauda: 210 rótulos que só desenham uma figura

Renomear os quadros deixou para trás doze rótulos como `DRAW_CIN_776:`, cujo
número era um índice de recurso que depois da renomeação não resolvia mais
para nada. Isso generaliza: um rótulo cujo corpo inteiro é **um** desenho e um
`ret` não afirma nada que a constante já não afirme, então o nome passa de
graça — e `classify` conta `DRAW_CIN_776` como `res_index` e
`CAVES_DRAW_LASER_IMPACT_ANIM_RIGHT_3` como `semantic`, então também é ganho
medível.

A regra ficou certa na **quinta** tentativa. As quatro anteriores teriam
escrito nome falso na árvore, e cada uma caiu ao ler o código que a sonda
dizia descrever:

- **Um dispatch não é um coto de desenho.** A entrada da escada de PRISON
  termina em `video` / `mov` / `ret` e parecia um rótulo de uma figura só —
  sendo que os outros cinco quadros moram nos rótulos para onde ela desvia.
  Batizá-la com o quadro do caminho de queda seria simplesmente errado.
- **São duas instruções de desenho, não uma.** `video offset=` lê o banco da
  fase e `video type=0, offset=` lê o banco compartilhado. Casando só a
  primeira, um rótulo que desenha corpo + braço + sombra parecia desenhar uma
  figura só, e teria sido batizado com o nome da **sombra**.
- **Uma figura também pode ser um marcador.** `CV_<hex>` é a forma sem nome do
  banco compartilhado, como `CINEMATIC_<índice>` é a do banco da fase. Excluir
  só a segunda propunha `CAPSULE_DRAW_CV_3FB8` — mover um marcador em vez de
  aposentar um.
- **Desenhar nem sempre é tudo que ele faz.** Trinta desses rótulos também
  tocam um som, e o nome atual registra os operandos:
  `DRAW_CV108_PLAY_60_F0F_V2A_C1` é `play id=0x0060, freq=0x0F, vol=0x2A,
  channel=0x01` escrito por extenso. Uma figura não nomeia uma rotina que
  também faz barulho. O corpo passou a ter de conter **nada** além do desenho
  e do `ret` — e é por isso que são 210 e não 223.

A leitura inversa — um rótulo semântico que não divide nenhuma palavra de
assunto com a figura que desenha — ficou como **aviso, nunca como falha**:
`CODEWHEEL_SYMBOL_DISPATCH_CASE_02` desenha `CINEMATIC_ALIEN_GLYPH_01` e os
dois nomes estão certos, um é o mecanismo e o outro o assunto; e `HERO` e
`LESTER` são o mesmo personagem. Excluídos os dispatches, sobrou exatamente
**um** caso na árvore inteira: o `CAVES_DRAW_HERO_IDLE_LEFT_1` de cima, que já
tinha sido resolvido pelo `md5`.

## O saldo

58 constantes renomeadas nas escadas de impacto, 18 de 18 posições completas
com família `_0.._5`, 210 rótulos passando a dizer que figura desenham, e três
ferramentas consertadas: a que herdava limiares como índice (75 pulados,
propostas de 28 para 4), a que confundia "não consegui conferir" com "não
bate", e a minha própria, quatro vezes.

Assets nas versões prioritárias: 58,6% → 58,9%. Um avanço pequeno, e não é
onde está o valor do dia — o valor está em que **duas** afirmações falsas
saíram da árvore e uma terceira não chega mais a entrar.

O portão de bytes passou 29/29 e 29/29 o tempo todo, inclusive enquanto o
nome errado estava lá. Ele não pode ver isso: **uma renomeação não move um
byte**. Quem vê é reler a escada depois de renomear e conferir se o nome caiu
no quadro que a máquina desenha naquele valor.
