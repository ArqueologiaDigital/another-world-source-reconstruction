# A explicação era plausível demais

*Metade do jogo não rodava no depurador novo, e eu tinha escrito no README a
razão. A razão estava errada. O que a derrubou não foi uma ideia melhor: foi
uma contagem de uma linha, que eu poderia ter feito no primeiro minuto e não
fiz porque já tinha uma explicação de que gostava.*

---

## O sintoma

O depurador de VM que este projeto ganhou roda oito fases. Quatro delas —
LAKE, CAVES, CAPSULE e ENDING — executavam o ponto de entrada e depois não
desenhavam **absolutamente nada**. Não pouco: zero polígonos, por 2000 quadros,
nas duas versões prioritárias.

Isso não é um canto do jogo. CAVES e CAPSULE são as duas fases **menos
nomeadas** do projeto. A ferramenta construída justamente para ajudar a nomear
estava cega exatamente onde era mais necessária.

## A explicação que eu escrevi

Olhei o ponto de entrada de CAVES e vi isto:

```
ENTRY_POINT_OF_CAVES:
	...
	call CAVES_SCREEN_ENTRY_DISPATCH
```

E a rotina despacha conforme o número da tela. Uma fase iniciada "a frio" tem
todas as 256 variáveis em zero, então o despacho cai fora e nada acontece.
Fecha. É coerente, usa código real, explica o sintoma, e eu escrevi no README:

> `ENTRY_POINT_OF_CAVES` termina em `call CAVES_SCREEN_ENTRY_DISPATCH`, que
> chaveia em `SCREEN_NUM` (`0x67`), e uma fase iniciada a frio tem todas as
> variáveis em zero, então o despacho cai fora.

Uma frase assim tem um problema que não aparece enquanto ela está sendo
escrita: ela **não sugere nenhum teste**. Ela encerra o assunto.

## As duas medidas

A primeira é direta: se o problema é `SCREEN_NUM`, então **algum** valor de
`SCREEN_NUM` deve destravar. Semeei 28 valores, de `0x00` a `0xC0`. CAVES
desenhou zero polígonos em todos os 28.

A segunda é a que decide, e é ridícula de tão barata. Contei quantas *threads*
continuavam vivas ao fim de uma execução:

```
CAVES, 600 quadros, a frio:  0 quadros pintados, 0 desenhos, 0 threads vivas
```

**Zero threads vivas.** Um despacho que cai fora deixa a thread rodando — ela
sai da rotina e continua. Uma fase que termina sem thread nenhuma teve suas
threads *apagadas*. E há exatamente uma instrução na máquina que faz isso.

## O que era

```
LIKELY_A_COPY_PROTECTION_MECHANISM:
	and [0xBC], 0x0010
	mov [0xF8], [0xC6]
	and [0xF8], 0x0080
	je [0xBC], 0x00, LABEL_00B3
	je [0xF8], 0x00, LABEL_00B3
	mov [0xF8], [0xE4]
	and [0xF8], 0x003C
	jne [0xF8], 0x14, LABEL_00B3
	jne [0xF2], 0x0FA0, LABEL_00B3
	jne [COPY_PROTECT_TOKEN], 0x21, LABEL_00B3
	ret

LABEL_00B3:
	deleteChannels first=0x00, last=0x3F
```

A verificação de cópia. Cinco variáveis, todas em zero numa entrada a frio,
então ela **sempre** falha — e o caminho de falha apaga as 64 threads de uma
vez. Ainda por cima ele trava: escreve `0xF2 = 0x1770`, e não o `0x0FA0` que
ele próprio exige, de modo que uma segunda tentativa também falha.

Semear as cinco variáveis destrava as quatro fases:

| fase | a frio | semeada |
|---|---|---|
| LAKE | 0 quadros pintados | 101 |
| CAVES | 0 | 595 |
| CAPSULE | 0 | 115 |
| ENDING | 0 | 344 |

Isso não é burlar nada: são os valores que a roda de código de 1991 produzia,
estão escritos na listagem, e o objetivo é chegar na arte dentro de um
depurador. INTRO, PRISON e TANK abrem numa cutscene e não mudam nem um bit.

## O que eu levo disso

A explicação errada não era preguiçosa. Ela citava a rotina certa, a variável
certa e um fato verdadeiro sobre inicialização a frio. Ela era **plausível**, e
é isso que a tornou cara: eu parei de procurar.

A diferença entre as duas está inteira na forma. "O despacho cai fora" é uma
conclusão. "Quantas threads sobraram?" é um comando. A segunda custava um
segundo e eu não a rodei porque já tinha a primeira.

Por isso a sonda que ficou comitada — `notes/stage-entry/entry_state.mjs` —
tem um modo `--screens` que existe **só para refutar uma hipótese que ninguém
mais sustenta**. Não apaguei a história errada, deixei o comando que a mata ao
lado dela. Uma frase corrigida diz ao próximo o que acreditar; um comando diz
como conferir.

## E, na esteira, o contador estava mentindo

Assim que CAPSULE passou a rodar, li a lista de constantes sem nome que ela
desenha e notei linhas marcadas `(sem EQU)` em coisas que obviamente têm nome.
O servidor separava as constantes entre os dois bancos **pelo prefixo do
nome** — `CINEMATIC_*` num, `CV_*` no outro — e descartava o resto.

Só que uma boa parte do banco compartilhado já foi renomeada para nomes de
verdade: `HERO_CRAWL_POSE_09`, `HERO_PRONE_TRANSITION_LEFT_F00`. Só
`dos_1992/CAVES` desenha **192** constantes cujo nome não começa por nenhum dos
dois prefixos. Todas chegavam ao depurador como "sem EQU" e eram **contadas
como anônimas estando nomeadas** — no contador que é a única razão de o
depurador existir.

A correção é ler o banco do **lugar do desenho**, que o declara sem ambiguidade:
`video type=0, offset=NOME` é o banco compartilhado, `video offset=NOME` é a
fatia da fase. O contador de CAPSULE caiu de 45 para 30.

Dois defeitos, a mesma forma: nos dois casos eu classifiquei pelo nome de uma
coisa em vez de perguntar ao código o que ela é.

---

*Medidas reproduzíveis com `notes/stage-entry/entry_state.mjs` (com `--screens`
para a varredura) e `notes/on-screen-priority/seen_unnamed.mjs`. Os cinco
valores da verificação de cópia estão em `VM.PROTECTION_PASS`, em
`tools/vm-debugger/static/vm.js`, citados da listagem de `dos_1992/CAVES.asm`.*
