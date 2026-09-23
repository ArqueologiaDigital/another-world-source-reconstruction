# Olhar é uma ferramenta perigosa

Durante uma sessão inteira eu disse a mesma coisa de formas cada vez mais
longas: os métodos estruturais acabaram, o que sobra precisa de alguém que
olhe para a arte e diga o que ela é.

E o projeto tem um renderizador. E a norma dele, grau E3, manda **renderizar e
olhar antes de batizar**, desde sempre.

Eu estava falando em volta da única ferramenta que faltava usar.

## O que o olhar destrava

Uma nota anterior registra por que 185 de 186 camadas de fundo não podem ser
batizadas `_BACKDROP_LAYER_<i>`: o índice é uma **posição de desenho**, e a
maioria das figuras é pintada várias vezes, ou está numa pilha cujas outras
posições são compartilhadas — a família sairia com buracos, que a norma
proíbe.

Um nome por **assunto** não tem índice e não tem família. Nada disso se
aplica. Foi isso que olhar comprou, muito além dos nomes em si.

## O risco não é deixar de olhar. É acreditar no que se olha

Este projeto tem três leituras erradas registradas, todas do mesmo tipo:
julgar uma miniatura ampliada em vez dos números. Uma lasca de 1x12 lida como
"faixa". Um cano de arma lido numa renderização redimensionada.

Então cada quadro da folha de contato carrega três coisas além da figura:

**A extensão medida e a contagem de caminhos.** `CINEMATIC_336` renderiza como
um cogumelinho perfeito — chapéu triangular sobre um pé estreito. Ele tem
**quatro pixels de largura**. É um glifo de 4x2 com duas folhas, ampliado até
encher o quadro. Não foi batizado, e o motivo está escrito.

**Quantas vezes é desenhado e em que y da tela.** Isso é independente da
silhueta e costuma decidir. `CINEMATIC_410` é uma ponta de 12x30 que afina
para cima a partir de uma base larga — um estalagmite ou uma estalactite,
conforme o que for "em cima". Ele é desenhado **quatro vezes em y=165** numa
tela de 200 de altura, em x=83, 136, 233 e 293. Está de pé no chão.

**As rotinas que o desenham**, que dão o escopo de tela de graça e limitam o
assunto antes de a figura ser vista.

## O que eu batizei e o que recusei

Sete figuras de CAVES, lidas na renderização, mais sete carregadas para a
versão MS-DOS pelo md5 canônico da arte — nunca pelo índice — com o componente
`_SCREEN_<NN>_` conferido contra as guardas da própria versão receptora.

O motivo que se repete: uma faixa de teto com colunas que se alargam onde a
encontram, uma estrutura por tela, cada uma desenhada **uma vez** em x=160,
y=100 pelo pintor de fundo daquela tela e por mais ninguém. `CINEMATIC_340` é
a exceção: duas silhuetas de arco nascendo de pilares.

Recusei, e está anotado:

- `CINEMATIC_336` e o campo de 19 cópias dele — o cogumelo de quatro pixels.
- `CINEMATIC_589` e `CINEMATIC_590`, os dois fundos da tela 0x8A, que se leem
  como rocha escura com aberturas arredondadas claras. O renderizador usa
  duas cores aqui: claro-contra-escuro **não é profundidade**, e "abertura" é
  uma leitura que a figura sozinha não sustenta.
- `CINEMATIC_718`, `719`, `734` — patamares e chãos, cada um compartilhado
  entre duas telas, então não há escopo de tela disponível e o assunto sozinho
  não os distingue um do outro.

## A parte que precisa ficar dita

**Esses nomes não têm conferência independente nenhuma.**

Renomear não move byte. O portão de comparação byte a byte — que é o que
segura todo o resto deste projeto — não consegue pegar um desses estando
errado. É a única classe de nome na árvore sem nada atrás.

Por isso eles moram todos num diretório só, cada linha com sua confiança
declarada e sua evidência, e o README começa dizendo isso. Não é humildade
decorativa: é para que possam ser auditados, ou revertidos, **como conjunto**,
por quem vier depois e discordar.

Eu passei a sessão inteira recusando nomes por falta de conferência —
inclusive um que já tinha commitado e tive de reverter, porque a arte o
contradizia seis vezes em seis. Continuar recusando indefinidamente também é
uma escolha, e não era a certa depois que a permissão foi dada. O que muda não
é o rigor: é onde o rigor fica registrado.
