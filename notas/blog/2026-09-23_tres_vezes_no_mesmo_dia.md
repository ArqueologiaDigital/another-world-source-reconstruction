# Três vezes no mesmo dia

*Síntese curta. Num único dia, três verificações deste projeto passaram por
cima exatamente daquilo que deveriam cobrir. Nenhuma estava quebrada. As três
respondiam uma pergunta mais estreita do que o nome sugeria, e fui eu que li a
conclusão larga.*

---

## 1. Geometria não é imagem

`compare_render.mjs` compara o desenhador de polígonos do depurador contra o
renderizador de referência, e dá **zero divergências**. Eu citei esse número
como "a imagem está certa" em texto e em commits.

Ele compara cor, contagem de pontos e coordenadas. O renderizador de referência
emite SVG, e SVG não é rasterizado. O passo de polígonos para pixels nunca tinha
sido testado — e estava errado havia três sessões, pintando máscaras (`cor >
0x10`, que copia da página 0) e misturas (`cor == 0x10`) como blocos opacos.

Pergunta real: *os polígonos que eu produzo são os mesmos?* Pergunta que eu li:
*a imagem está certa?* — [detalhes](2026-09-23_o_teste_comparava_geometria_e_eu_li_pixels.md).

## 2. Zero de nada é igual a zero de tudo

O mecanismo de anotações tem um comando de entrada, `make annotations`, e um
`--check`. Contra um repositório **sem nenhum arquivo de evidências**, os dois
imprimiam sucesso, com a mesma string da fila limpa.

Pergunta real: *há alguma anotação pendente?* Pergunta que eu li: *o canal de
anotações está saudável?* — [detalhes](2026-09-23_o_teste_que_passava_sem_nada_para_testar.md).

## 3. Um intervalo lê como uma lista

A varredura de fim de sessão exige que todo script deixado no rascunho tenha um
veredito escrito. Escrevi `r1.py..r4.py, m1.py..m6.py` — que *lê* como se
cobrisse os doze e não nomeia nenhum dos doze.

Transformei a varredura numa verificação (`notes/scratch-audit/covered.py`:
todo script do rascunho está nomeado no arquivo de vereditos?). Na primeira
execução ela falhou em seis arquivos — `m2`, `m3`, `m4`, `m5`, `r2`, `r3` —
dentro do próprio texto que a introduzia.

Pergunta real: *este nome aparece no arquivo?* Pergunta que eu li: *este
arquivo foi julgado?*

---

## O padrão

Nos três casos a verificação era honesta e o defeito era de leitura. E há um
sinal comum, que é a parte útil:

**Nos três eu conseguia nomear o componente que não estava coberto.** Eu
escrevi "varredura par-ímpar" e "caminhamento de duas arestas" numa frase sobre
a diferença entre os dois — sabia que existia um rasterizador, e não notei que
nada o testava. Escrevi "derivado do log, das tabelas e da árvore" sobre os
estados da fila — sabia que existia um log, e não perguntei o que acontece
quando ele não existe. Escrevi um intervalo — sabia que havia doze arquivos, e
usei uma notação que não os enumera.

Saber descrever uma peça e não ter conferido que ela é coberta são coisas que
convivem confortavelmente, e a segunda não faz barulho. O antídoto que sobrou
das três é o mesmo, e é mecânico: **toda verificação nova aqui agora aceita o
alvo anterior como argumento.** `tests/run.sh <sonda candidata>`,
`check_guidance.py <servidor candidato>`, `check_fill.mjs <vm.js candidato>`.
Se um caso não falha contra a versão de antes, ele não estava testando a
correção — estava testando que o código continua sendo ele mesmo.

Três dos quatro casos de `check_fill.mjs` falham contra o rasterizador
anterior. O quinto, o preenchimento sólido, passa nos dois. É por ele que
ninguém percebeu por três sessões.

---

*Os três textos completos estão neste diretório. As verificações mencionadas
são `tools/vm-debugger/tests/{compare_render,check_fill}.mjs`,
`notes/play-and-describe/{annotation_queue.py,tests/run.sh}` e
`notes/scratch-audit/covered.py`.*
