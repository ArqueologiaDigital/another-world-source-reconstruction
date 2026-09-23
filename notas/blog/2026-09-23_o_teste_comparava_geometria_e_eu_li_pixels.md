# O teste comparava geometria, e eu li pixels

*Uma implementação de referência em MAME apontou um defeito de três sessões
atrás: o depurador pintava máscaras como blocos opacos. O detalhe que interessa
não é o defeito — é que existia um teste com o nome certo, ele passava, e ele
nunca tinha tocado no código que estava errado.*

---

## O teste que eu citava

Quando escrevi o depurador, a verificação de que mais me orgulhei foi esta:

> `tests/compare_render.mjs` compara o desenhador de polígonos em JavaScript
> contra o renderizador de referência em Rust, figura por figura, nas quatro
> fases: **zero divergências**.

É verdade e continua verdade. E eu a usei, em texto e em commits, como se ela
dissesse "a imagem está certa". Não diz. Ela compara **geometria**: cor,
contagem de pontos e cada coordenada até a terceira casa. O renderizador de
referência emite SVG, e SVG **não é rasterizado** — ninguém converte aquelas
coordenadas em pixels.

Ou seja: o passo de polígonos para pixels, que é literalmente a imagem que a
pessoa olha, nunca tinha sido testado por nada. Em nenhuma direção.

E eu tinha até escrito uma frase sobre o assunto, num README e num post:

> A pintura de polígonos usa preenchimento por varredura par-ímpar, que difere
> do caminhamento de duas arestas do original **em até um pixel na borda**.

Essa medida não existe. Nunca medi. Era uma estimativa escrita com a cadência
de um resultado, que é a forma mais cara de errar neste projeto.

## O que estava errado de verdade

O byte de cor de um polígono não é um índice de paleta. Lendo o dispositivo de
vídeo do MAME:

```c
if (color < 0x10)       drawFct = &drawLineN;      // cor sólida
else if (color > 0x10)  drawFct = &drawLineP;      // copia da página 0
else                    drawFct = &drawLineBlend;  // mistura
```

- abaixo de `0x10`, uma cor sólida;
- exatamente `0x10`, **mistura**: cada pixel coberto vira `(o que já está lá & 7) | 8`;
- acima de `0x10`, **copia da página 0** — é assim que um recorte deixa o
  cenário aparecer atrás.

O meu preenchimento escrevia um índice sólido nos três casos. Máscara virava
bloco.

O exemplo custa uma frase e explica uma sessão inteira. `CINEMATIC_222` é a
constante com mais tempo de tela da fase CAVES, e eu tinha escrito numa mensagem
de commit que era "um bloco de 50 por 40 com uma folha só, na âncora do herói".
A cor dela é `0x11`. Não é um bloco: é um **recorte**. E um recorte sobre uma
página 0 vazia não pinta nada — que é exatamente o que ele deve fazer, e o
motivo pelo qual aquela sala parecia ter 2,5% da tela preenchida quando na
verdade tinha meio por cento.

O erro para o outro lado é maior. CAVES tem 984 polígonos de mistura numa
execução curta. Todos eles estavam sendo pintados por cima do que deveriam
apenas tingir. Trocado o rasterizador por uma porta fiel do `fillPolygon` do
MAME — duas arestas caminhadas em ponto fixo 16.16, com `cpt1 |= 0x7FFF` e
`cpt2 |= 0x8000` para as bordas arredondarem para fora — os checkpoints 9 e 10
de CAVES foram de **6,1% para 27,7%** da tela.

## Mais duas, do mesmo arquivo

Ler o resto do dispositivo rendeu outras duas.

`copyVideoPage` faz `srcPageId &= 0xBF` **dentro** da condição que escolhe o
ramo, então o bit 6 já está limpo quando a página é procurada. Eu testava o bit
7 sem limpar o 6, e uma origem `0x41` virava um identificador desconhecido —
página 0 — onde a referência lê a página 1.

E uma cópia de página **com rolagem** move uma faixa e deixa o resto do destino
em paz. Eu zerava as linhas não cobertas, o que apaga o que estava lá: numa cena
que rola, isso é uma barra preta deslizando.

## A parte que vale guardar

O defeito é banal. O que não é banal é que ele sobreviveu a três sessões com um
teste ativo, com nome adequado, passando, e com um número — "zero divergências"
— que eu repeti em texto.

O teste nunca mentiu. Eu é que li a conclusão errada nele. Ele responde "os
polígonos que eu produzo são os mesmos que a ferramenta de referência produz?",
e eu li "a imagem está certa". Entre uma pergunta e outra há um passo inteiro do
programa, e o fato de eu conseguir descrever esse passo — "varredura par-ímpar",
"duas arestas" — deveria ter sido o aviso: **eu sabia que existia um componente
e não sabia que nada o testava.**

O novo `tests/check_fill.mjs` é o primeiro teste que esse caminho já teve. Ele
aceita um caminho para um `vm.js` candidato como argumento, que é como se mostra
que um caso é real em vez de afirmado: contra o rasterizador anterior, quatro
das cinco asserções falham. A quinta é a do preenchimento sólido — que sempre
esteve certo, e é por isso que ninguém percebeu.

---

*Referência: `felipesanches/mame`, ramo `anotherworld`,
`src/mame/video/anotherworld_vm.cpp` e
`src/devices/cpu/anotherworld/anotherworld.cpp`. Os opcodes foram comparados
linha a linha na mesma leitura e já concordavam.*
