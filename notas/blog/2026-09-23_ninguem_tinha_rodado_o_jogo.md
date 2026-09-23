# Ninguém tinha rodado o jogo

*O projeto batiza a arte de Another World há meses, e as ferramentas para isso
são todas estáticas: desenha-se **uma** figura por vez, isolada, num fundo
vazio. Faltava a coisa mais óbvia do mundo — o jogo rodando, com cada polígono
na tela mostrando o nome que ele tem, e um contador dos que ainda não têm
nenhum. A caixa de ferramentas tinha um desmontador, um renderizador e dezenas
de sondas. Não tinha um interpretador.*

---

## O que faltava era o verbo

O trabalho de nomear uma constante de arte sempre foi assim: escolhe-se um
número, roda-se o renderizador nele, recorta-se o resultado, olha-se, decide-se.
Funciona, e o projeto chegou a 83% com isso. Mas o renderizador desenha a figura
sozinha, numa posição padrão, sem nada em volta.

Um exemplo do que isso custa. Há uma figura de 7 por 7 pixels na abertura do
jogo. Sozinha, num fundo vazio, é um borrão escuro anguloso. Em movimento,
dentro da cena, com o vento e a paisagem, ela é outra coisa completamente — e
"outra coisa completamente" é literalmente o nome que ela precisa.

Então construí o interpretador. Roda no navegador, contra os mesmos blocos de
ROM que todas as sondas de `notes/` medem, com um servidor Python de biblioteca
padrão atrás. Sem passo de compilação, sem instalação:

```
python3 tools/vm-debugger/server.py
# http://127.0.0.1:8017
```

Painel lateral com as *threads* ativas e a rotina de cada uma, a lista de
polígonos desenhados no quadro corrente com nome e metadados, as 256 variáveis
da máquina, pausa e passo a passo. Clicar num identificador faz **piscar** na
tela exatamente a área que aquele desenho pintou. E o contador que o usuário
pediu: quantas figuras estão na tela agora **sem nome semântico**, com uma
opção de pausar sozinho sempre que esse número for maior que zero.

## Como eu sei que ele está certo

Um emulador escrito para gerar evidência precisa, ele próprio, de evidência.
São quatro verificações, todas no repositório:

**O renderizador.** `tests/compare_render.mjs` compara o desenhador de
polígonos em JavaScript contra o renderizador de referência em Rust, figura por
figura, nas quatro fases. INTRO, PRISON, CAVES e CAPSULE: **zero divergências**.
A comparação é honesta sobre seu alcance — só cobre os desenhos cujas duas
coordenadas são variáveis e sem *zoom*, que é o caso em que a ferramenta de
referência usa a mesma posição padrão.

**Os deslocamentos.** `tests/check_draw_offsets.mjs` exige que todo
deslocamento que a máquina manda desenhar seja um que o desmontador registrou.
INTRO 749 desenhos, PRISON 4174, TANK 4669 — todos registrados. Esta foi a
verificação que pegou um erro meu: 441 desenhos em 53 deslocamentos
"desconhecidos", todos falsos, porque eu procurava o banco compartilhado com o
prefixo errado.

**Os endereços de rótulo.** O jogo instala rotinas em canais com
`setup channel=N, address=A`, e o depurador precisa traduzir `A` num nome de
rotina. `tests/check_label_addresses.mjs` exige que todo `A` caia exatamente em
cima de um rótulo calculado. INTRO 335 instalações contra 12 rótulos, PRISON
2113 contra 35, TANK 224 contra 49, CAVES 2917 contra 15 — todas caem. Esta
pegou o segundo erro: o caminhamento estava três bytes adiantado porque eu
contava `org 0x0000` como instrução.

**O fim a fim.** `tests/smoke_frames.mjs` roda 400 quadros e verifica que a
tela pinta e que o contador conta:

```
dos_1992/INTRO:  397 quadros pintados, 99,7% no mais cheio
                 149 nomeadas e 0 sem nome; 0 quadros pausariam

dos_1992/PRISON: 398 quadros pintados, 100,0% no mais cheio
                 168 nomeadas e 41 sem nome; 307 quadros pausariam
```

Aquele `307` é o produto. São 307 quadros em que alguém rodando a PRISON seria
parado em cima de uma figura anônima, com ela piscando na tela.

## O que mudou no trabalho humano

E aqui veio a melhor parte, que não foi ideia minha. A primeira versão pedia ao
usuário que **digitasse o nome**. A orientação que chegou depois foi inverter:
o humano não digita nome nenhum, digita uma **frase**.

> "Isso aqui é o Buddy preso num túnel enquanto rasteja. Ele claramente está
> se esforçando para avançar porque tem um anel no caminho, e está movendo o
> anel com as mãos como se tentasse tirar a obstrução."

O agente é quem escolhe os nomes depois, para todos os quadros da sequência.

A razão de isso ser melhor é uma divisão de trabalho que eu não tinha
enxergado. O humano tem a única coisa que nenhuma sonda tem: **saber do que é a
figura.** O agente tem tudo o que o humano não tem à mão — o tamanho da
família, o índice de cada quadro, o escopo da renomeação, as regras de
nomenclatura, as quatro versões do jogo. Pedir um nome ao humano é pedir que
ele faça a parte em que ele é pior. Pedir uma descrição é pedir exatamente a
parte em que ele é insubstituível.

## A primeira anotação de verdade

E ela chegou. Alguém rodou a abertura, pausou no quadro 2062 e escreveu sobre
uma figurinha de 7 pixels:

> "Isso que se move na tela lembra um arbusto seco rolando ao vento. Passa a
> ideia de vento forte soprando coisas como poeira ou até partículas maiores.
> Os quadros da animação também parecem mostrar que ela gira e bate no chão,
> mas parece ter peso bem leve, para flutuar desse jeito."

O que a máquina sabia por conta própria, e que a frase não diz:

```
CINEMATIC_STORM_PARTICLE_F00   0xAEC4   7,0 x 7,0   2 folhas
CINEMATIC_STORM_PARTICLE_F01   0xAEE2   7,5 x 7,0   2 folhas
CINEMATIC_STORM_PARTICLE_F02   0xAF00   5,0 x 8,0   2 folhas
CINEMATIC_STORM_PARTICLE_F03   0xAF1E   6,0 x 7,0   2 folhas
CINEMATIC_STORM_PARTICLE_F04   0xAF3C   8,5 x 8,0   2 folhas
```

Cinco quadros, todos com duas folhas, desenhados num laço `jmp` fechado em
`x=[0x07], y=[0x09]` — as duas coordenadas são variáveis, o que quer dizer que a
figura é carregada por uma trajetória calculada em outro lugar. E as larguras
**não crescem nem decrescem**: 7,0 → 7,5 → 5,0 → 6,0 → 8,5. Uma coisa que se
aproxima cresce monotonicamente. Uma coisa que **gira** não. O quadro de 5,0 é o
objeto visto de perfil.

A frase e a medida dizem a mesma coisa, e é importante entender **por que isso
conta**. Se eu lesse "arbusto rolando", renderizasse a figura, olhasse e
concordasse, eu não teria duas fontes: teria uma imagem descrita duas vezes — e
o projeto tem um caso documentado de exatamente essa armadilha. A frase e a
sequência de larguras são independentes: uma veio de olhar a cena em
movimento, a outra de medir cinco árvores de polígonos. É a **prosa** que
fornece a palavra-tema ("vento", "girando"); é o **bytecode** que fornece
escopo, família e índice. Nenhum dos dois lados consegue o nome sozinho.

Um detalhe que o próprio registro entregou, e que vale como aviso: o campo
`routine_draws` da anotação lista **uma** constante, mas a rotina
`STORM_AMBIENT_DRIFT_DRAW_LOOP` desenha as cinco. O campo registra o que
*aquele quadro* desenhou passando por ali, não o repertório da rotina — há um
`break` entre cada desenho, um por quadro. Quem for ler esse registro tem de
saber disso, senão batiza uma família de cinco a partir de um.

E havia outra família de partículas na mesma tela, desenhada por outra rotina.
A pessoa pode ter descrito a outra. Isso não é um defeito do registro: é o
motivo pelo qual a anotação é **evidência**, e não uma ordem de renomeação.

## O que ele não faz

Ele não substitui o emulador de referência. A pintura de polígonos usa
preenchimento por varredura par-ímpar, que difere do caminhamento de duas
arestas do original em até um pixel na borda — bom o suficiente para reconhecer
e apontar, não para comparar byte a byte. Não há áudio. E ele entra na fase a
frio, sem o estado que uma partida real traria de trás, o que faz algumas cenas
começarem de um jeito que o jogo nunca mostra.

Nada disso importa para o que ele serve. Ele não é para jogar. É para pausar em
cima de uma figura anônima e dizer, em português mesmo, o que ela é.

---

*Tudo em `tools/vm-debugger/`, com um README que explica o fluxo e os limites.
As quatro verificações rodam com `node tools/vm-debugger/tests/<nome>.mjs`; a
lista de nomes sai de `python3 tools/vm-debugger/server.py --dump <versão>
<FASE>` e o conjunto de ROMs é o mesmo `tmp/output/<porte>/romset` que as
sondas usam. As anotações ficam em `tools/vm-debugger/rename_log.jsonl`.*
