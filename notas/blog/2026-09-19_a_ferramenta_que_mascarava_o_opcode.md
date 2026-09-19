# A ferramenta que mascarava justamente o opcode

*O plano inteiro de nomeação de rotinas era dimensionado por uma medida. A
medida dizia, na própria linha que imprimia, que agrupava rotinas pela
sequência de opcodes. Não agrupava: mascarava o opcode junto com os operandos.*

---

Reconstruir o fonte de um jogo a partir do bytecode é, na maior parte, dar nome
a coisas. Três fases grandes concentram o que falta, e a pergunta prática é
quantas coisas **diferentes** existem ali — porque rotinas iguais se nomeiam de
uma vez, com um índice por membro.

A ferramenta que responde isso abstrai cada corpo: troca operandos por `@`,
literais por `#`, e conta quantas formas distintas sobram. E imprime, ao final:

> Same shape is same opcode sequence with operands masked.

A implementação era uma linha:

```python
RE_LITERAL.sub("#", RE_IDENT.sub("@", line))
```

Um mnemônico é um identificador. `jmp LABEL_530D`, `call LABEL_42EC` e
`setvec LABEL_8180` viravam todos `@ @`.

## O que isso custava

A distorção média é de 10%: 4.832 formas relatadas onde existem 5.328. Mas a
média engana, porque o apagamento é pior exatamente onde as famílias são
maiores — um corpo de uma linha não tem mais nada para distinguir dois opcodes.

```
    56 ->  3   KILL_CHAN_AT_3D12     ret x49, break x4, killChannel x3
    40 ->  2   JUMP_TO_LABEL_530D    call x27, jmp x13
    30 ->  6   SET_VAR21_TO_0001…    mov ret x21, sub ret x3, add ret x2, …
```

Quarenta rotinas relatadas como uma família são 27 `call` e 13 `jmp`. **Um
`call` volta e um `jmp` não.** Se a família recebesse um nome só, ele estaria
errado para 27 delas.

E não era só o plano. A ferramenta que monta os lotes que um nomeador lê importa
essa mesma função. Dezoito passadas de nomeação, 770 nomes aplicados, todas
alimentadas por lotes que podiam misturar dois opcodes.

## A pergunta que importava

Consertar a abstração é uma linha. A pergunta cara é a seguinte: **algum nome já
aplicado ficou errado por causa disso?**

Perguntando de forma ampla — qualquer sequência de opcodes diferente dentro de
uma família — a resposta são 54 famílias. E quase todas estão **certas**:

```
CAVES_GROUND_MAP_SCREEN_89_SEGMENT_3   jg sub shr mov sub ret
CAVES_GROUND_MAP_SCREEN_89_SEGMENT_5   jg sub shr mov add ret
```

Um segmento de chão descendo e outro subindo. **É para isso que serve o
índice**, e o nome afirma um segmento da tela 0x89, não uma direção.

Então a verificação real não compara sequências de opcodes: compara a
**assinatura de fluxo de controle**. `call`, `jmp`, `ret`, `break`,
`killChannel` ficam literais; aritmética vira `~`; condicionais viram `jcc`. É a
divisão sobre a qual um nome compartilhado mentiria — se volta ou não volta, se
encerra o canal ou cede o quadro.

Resultado: **353 famílias indexadas conferidas, 0 ocorrências.** Os 770 nomes
sobreviveram.

## O único achado, e o segundo defeito atrás dele

Antes do conserto, a verificação achou exatamente um caso, nas duas versões:

```
DEDUP_CAVES_5B   4 membros, 2 assinaturas de fluxo
    ~ ret          x3   DEDUP_CAVES_5B_020, _035, _036
    ~ killChannel  x1   DEDUP_CAVES_5B_003
```

Só que isso não é um nome a consertar no lugar: `DEDUP` é uma forma que a norma
do projeto **proíbe explicitamente**. O que levanta a pergunta de por que ele
estava sendo contado como nomeado — e a resposta é um segundo defeito, na
ferramenta que classifica nomes. As regras eram `_DEDUP_` e `_FOLD_BODY_`, com
sublinhado exigido **dos dois lados**. Um rótulo que *começa* com o artefato
escapava. E `__HELPER` não tinha regra nenhuma.

Oitenta ocorrências, dezenove identificadores distintos, contados como prontos
contra uma norma que os proíbe. O conserto foi testado classificando os 18.326
rótulos da árvore antes e depois e comparando: moveram-se exatamente aqueles
dezenove, nada mais.

## O dividendo que ninguém tinha previsto

O melhor efeito do conserto apareceu sozinho. A ferramenta que propaga nomes
entre versões tem uma regra: quando os dois lados têm nome semântico, ela **não
escolha vencedor** — é decisão de gente. Enquanto `DEDUP_CAVES_5B_011` contasse
como semântico, ela via um empate e parava.

Quatro nomes bons estavam parados na versão Amiga havia semanas por causa disso.
Assim que `DEDUP` passou a contar como marcador, eles desceram sozinhos para as
outras duas versões:

```
DEDUP_CAVES_5B_011 -> CAVES_GROUND_MAP_SCREEN_4C_SEGMENT_3
DEDUP_CAVES_5B_012 -> CAVES_GROUND_MAP_SCREEN_4D_SEGMENT_4
DEDUP_CAVES_5B_027 -> CAVES_GROUND_MAP_SCREEN_68_SEGMENT_16
DEDUP_CAVES_5B_028 -> CAVES_GROUND_MAP_SCREEN_69_SEGMENT_7
```

Uma medida errada não erra só a conta. Ela trava o trabalho, em silêncio, do
lado de onde ninguém está olhando.

## Um detalhe que eu errei no caminho

A sonda que compara as duas abstrações **importava** a função consertada para
obter a antiga. Depois do conserto ela comparou a função nova consigo mesma e
relatou, com toda a confiança, +0%. A sonda agora carrega a versão antiga em
cópia própria, com um comentário dizendo por quê.

Uma ferramenta de medição que importa o que mede não mede nada. Foi uma execução
até aparecer, e teria sido uma linha muito convincente num relatório.

---

Conferível: `another-world-archaeology/tools/shape_fidelity_probes/`, duas
sondas com README dizendo que pergunta cada uma responde e o comando exato. A
segunda sai com status 1 se achar qualquer caso, e é para ficar em 0. As tabelas
antigas foram corrigidas com bloco datado nos três lugares onde apareciam.
`make test` segue 29/29 e 29/29 — um nome de rótulo não é um byte, então o
portão nunca teria acusado nada disto.
