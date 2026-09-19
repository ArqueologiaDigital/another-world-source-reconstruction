# A grade de trinta e duas colunas

*A variável mais referenciada do jogo — 6.242 citações — chamava-se
`HACK_VAR_67`. A documentação já dizia o que ela era, com base em três nomes de
rótulo que alguém tinha escrito antes. Medida nos opcodes, é mais do que isso:
não é "o número da tela", é um índice numa grade de 32 colunas.*

---

A VM de *Another World* tem 256 variáveis de 16 bits. O projeto batizou quinze
delas; as que sobraram aparecem como número cru, e as que já se sabe serem
importantes mas ainda não se sabe o que são carregam o prefixo `HACK_VAR_`.

`HACK_VAR_67` era, de longe, a maior: 6.242 referências, mais do que todos os
outros marcadores do repositório somados.

A documentação a classificava como "pronta para nomear", com a justificativa de
que três rotinas auxiliares já tinham nomes descritivos —
`ADD_HACK67_BY_20`, `SUB_HACK67_BY_20`, `COPY_HACK67_TO_VAR66` — e que
"±0x20 é navegação em grade de telas". O nome proposto era `SCREEN_NUM`.

Isso é uma inferência tirada de três nomes que alguém escreveu. Uma renomeação
de 6.242 referências merece descer aos opcodes.

## Cinco medidas, e nenhuma delas são os guardas

A leitura mais visível de `0x67` é inútil como prova. Milhares de rotinas
começam com `jne [0x67], [<v>], <ret>` — cada thread de cena confere se está na
sua própria tela e volta se não estiver. Isso é compatível com quase qualquer
variável de identidade: um modo, uma fase, um contador. Por isso a sonda
(`notes/screen-index-probes/var67_screen_grid.py`) não usa os guardas, e mede
outras cinco coisas:

**1. A aritmética é um passo de grade e nada mais.** Em quatro portes, todas as
somas e subtrações sobre `0x67` são ±1 ou ±0x20. Vinte e nove locais, zero
exceções. Um `add [0x67], 0x0003` em qualquer lugar derrubaria a leitura.

**2. Os valores atribuídos caem em faixas a ~0x20 de distância.** Oito faixas,
com os inícios separados por 0x23, 0x22, 0x1F, 0x23, 0x20, 0x21, 0x23. Um
contador livre daria uma corrida densa só.

**3. Os quatro passos genéricos são as caudas de quatro escadas nomeadas por
direção.** Em CAVES, cada saída de tela é uma escada de casos especiais que
termina caindo num passo genérico:

| escada | cauda genérica |
|---|---|
| `CAVES_SCREEN_EXIT_DOWN_LINK_CASE_*` | `+0x20` |
| `CAVES_SCREEN_EXIT_UP_LINK_CASE_*` | `−0x20` |
| `CAVES_SCREEN_EXIT_RIGHT_LINK_CASE_*` | `+1` |
| `CAVES_SCREEN_EXIT_LEFT_LINK_CASE_*` | `−1` |

É isto que fixa o passo em 32 **colunas** e a orientação como linha-primeiro, e
não o contrário. O código chega a dizer sozinho: o caso especial da tela 0x49
faz `mov [0x67], 0x0069` — exatamente 0x49 + 0x20, a tela logo abaixo — e o da
tela 0x69 faz o inverso.

**4. A coluna é extraída com uma máscara de 31.** CAPSULE e PRISON fazem
`mov [0xF8], [0x66]` seguido de `and [0xF8], 0x001F` antes de ramificar. `& 31`
é a coluna de uma grade de 32, escrita em opcodes, por duas fases que não são
CAVES — então o passo não é artefato do desenho de uma fase só.

**5. `0x66` guarda `0x67`, e a diferença repinta o fundo.**
`je [0x66], [0x67], <cache>` protege um `copyVideoPage src=0x00, dst=0xFF`: o
cenário é repintado exatamente quando a tela mudou, e o cache é então
atualizado.

Conclusão: `0x67` é um índice de tela numa grade de 32 colunas, linha-primeiro.
±1 anda na horizontal, ±0x20 na vertical. `SCREEN_NUM`, 6.242 referências.

## A correção que a medida obrigou

A documentação também dizia que `0x66` seria `CACHED_SCREEN_NUM`. E é — em
LAKE, PRISON, CAVES e CAPSULE, em todos os portes.

Em TANK, não. Lá `0x66` é um contador comum:

```
	mov [0x66], 0x0032
	...
	djnz [0x66], TANK_ARENA_AMBIENT_LASER_FIRE_LOOP
```

Três locais por porte. A regra do próprio projeto diz que um nome só entra no
arquivo de aliases globais se significar a mesma coisa em toda fase e todo
porte — então o alias ficou declarado nas quatro fases em que é verdade, e TANK
segue com o número cru. A primeira versão escreveu o alias globalmente; foi uma
auditoria por fase que pegou, antes do commit.

## E a lição mais desagradável do dia

Enquanto eu colocava os `EQU` por fase, a árvore unificada ficou por um momento
referenciando `CACHED_SCREEN_NUM` sem o declarar.

O montador **não deu erro**. Produziu bytes. A verificação byte a byte caiu de
29/29 para 15/29 e foi assim que eu soube.

É o mesmo formato de um defeito que o projeto já tinha registrado meses antes:
silencioso no montador, visível só no portão de bytes. **"Compilou" não é prova
de que um símbolo resolveu.** Ficou escrito na norma de nomenclatura, porque o
portão existe justamente para os casos em que a ferramenta não reclama.

---

Números conferíveis: `make test` 29/29 e 29/29; a sonda passa nas cinco
verificações sobre os quatro portes e sai com código diferente de zero se
alguma parar de valer. Restam no nível das variáveis dois marcadores:
`HACK_VAR_54` (69 referências, ainda varia por fase) e `HACK_VAR_F7` (8
referências, abaixo do limiar que o projeto se impôs).
