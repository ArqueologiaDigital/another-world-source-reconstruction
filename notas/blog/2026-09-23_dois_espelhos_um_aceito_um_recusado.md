# Dois espelhos, um aceito e outro recusado

Uma figura virada para a esquerda se estende **para a esquerda** do ponto onde
é desenhada. Isso não é uma opinião sobre a arte: a âncora do comando de
desenho é o referencial, e a caixa delimitadora com sinal em relação a ela é
uma propriedade dos bytes.

Já existia uma sonda neste projeto que pareia esquerda e direita por uma
**pontuação** de semelhança, e o controle dela falha justamente onde importa:
um pareamento errado entre "mirar" e "atirar" tira 0,451, contra pares
verdadeiros entre 0,520 e 0,923. Ou seja: só serve quando a distância é
grande, e ninguém sabe de antemão quando é.

Troquei a pergunta por uma de sim ou não. Duas peças são **espelho exato**
quando têm o mesmo número de folhas, a mesma largura, a mesma borda de cima e
a de baixo, e os vãos em x refletidos em torno de um mesmo eixo a menos de
meia unidade da âncora.

Todo par já batizado com `_LEFT`/`_RIGHT` cujo reflexo também existe vira um
caso de teste:

| folhas | espelho exato | não |
|---|---|---|
| 1 (membro) | 8 | **0** |
| 2 (corpo) | 24 | **0** |
| 3 | 2 | 2 |
| 4 | 0 | 2 |
| 5 (corpo) | 28 | 26 |

Exato para peças simples; **não confiável** para corpos complexos, onde as
duas direções foram desenhadas com larguras diferentes em vez de refletidas —
`CV_FIGURE_WALK_RIGHT_BODY_F00` ocupa −17,0..+15,5 contra −16,5..+17,0 do
gêmeo. A sonda se limita a duas folhas, que é onde o controle não tem falha
nenhuma.

E um **nome** espelhado só está certo se as famílias se correspondem membro a
membro. Correspondem: os pares `CV_FIGURE_WALK_{LEFT,RIGHT}_LIMB_POSE_00..03`
são espelhos exatos **no mesmo índice, 4 de 4**.

## O espelho que aceitei, derrubando uma decisão minha de uma hora antes

Nesta mesma sessão eu tinha **retido** a família `RUN_LEFT`, e tinha escrito o
motivo: `CV_3200` está atestado nas fases 8 e 9 e **nunca na 1**, onde o gêmeo
da direita está atestado nas duas. Ordem de banco e ordem de fase
discordavam, e eu não ia posicionar a peça só pelo espelho.

O espelho deixou de estar sozinho. Ele é exato, um-para-um, num número de
folhas onde o controle tem 0 falhas em 32, e **concorda** com a ordem de
offset decrescente que o controle de arranjo reproduz 16 vezes em 16.

A fase atestada diz **quando** uma peça é desenhada. O nome afirma **qual
casa** ela ocupa na folha. São coisas diferentes, e eu tinha deixado a
primeira vetar a segunda. Quatro nomes.

## O espelho que recusei, que parece idêntico e não é

`CV_245C` e `CV_2D4E` têm cara de ser uma quinta pose de membro da caminhada.
São um par de espelho exato — 11x17 de uma folha, vãos em x refletidos em
torno de −0,5, mesmo y — e cada um fica **um passo de 8 bytes abaixo** do
último membro da sua família: 0x245C abaixo de `..._WALK_RIGHT_LIMB_POSE_03`
em 0x2464, 0x2D4E abaixo do esquerdo em 0x2D56. Pela regra de offset, isso é
`POSE_04` dos dois lados.

As fases recusam. A família, em ordem de offset decrescente, serve primeiras
fases 0, 5, 6, 8 — crescente, que é exatamente a conferência que a regra de
offset tem de passar. `CV_2D4E` está atestado na fase **7**: como `POSE_04`
ele viria depois da fase 8, e pela fase ele pertence **entre** `POSE_02` e
`POSE_03`, onde os offsets não têm espaço.

É a mesma discordância que eu tinha acabado de resolver para `RUN_LEFT` — sem
a coisa que a resolveu. Lá, a família da direita **já estava numerada** e cada
chave sem nome era o espelho exato de uma chave **batizada**: a casa vinha do
espelho, e os offsets apenas concordavam. Aqui os dois espelham **um ao
outro**, então não há casa batizada para herdar, e os offsets ficam sozinhos
contra uma fase que os contradiz.

Retido, e anotado — para a próxima pessoa não refazer a análise e chegar ao
mesmo lugar.

## O que a diferença entre os dois casos ensina

Nos dois casos eu tinha exatamente as mesmas duas evidências: um espelho
geométrico exato e uma posição de offset. Num deles aceitei, no outro recusei,
e a diferença não é quanta evidência havia — é **se alguma delas era
independente do que eu queria concluir**.

Em `RUN_LEFT`, a casa vinha de fora: de uma família já numerada por outra
pessoa por outro motivo. Em `CV_245C`/`CV_2D4E`, a casa vinha da minha própria
regra de offset, e a única evidência externa disponível — a fase — dizia não.

Duas evidências que se apoiam mutuamente não são duas evidências.
