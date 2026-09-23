# As cinco variáveis estavam certas, e a resposta era quarenta e nove

*Eu tinha derivado da listagem cinco variáveis que fazem uma fase do jogo
arrancar, e uma implementação de referência confirmou as cinco, valor por valor.
Confirmação independente, do tipo que o projeto inteiro persegue. E mesmo assim
era a resposta errada para a pergunta que eu estava fazendo.*

---

## O que eu tinha

Numa rodada anterior, quatro das oito fases não desenhavam nada no depurador.
A causa era a verificação de cópia: o caminho de falha apaga as 64 threads de
uma vez. Lendo a rotina, tirei as cinco variáveis que ela testa e os valores que
a fazem passar:

```
0xBC = 0x0010   0xC6 = 0x0080   0xE4 = 0x0014   0xF2 = 0x0FA0   0xDC = 0x0021
```

Semeadas, as quatro fases passaram a desenhar. Medi, escrevi no README, comitei
a sonda ao lado. Estava resolvido.

Não estava. O usuário voltou com três frases: *não consigo jogar*, *acho que
existem truques específicos para começar numa fase sem travar a VM*, e *o
"pausar em anônimos" ou não funciona ou os anônimos estão raros*.

## O que a referência tinha

Existe uma implementação de referência em Rust na mesma máquina. Ela não semeia
cinco variáveis. Ela tem **dezesseis tabelas de 49 registradores**, uma por
*checkpoint* do jogo, aplicadas quando um nível é reiniciado.

E aqui está a parte que dói e que vale o texto todo. A tabela do nível 0 — a
introdução — tem **seis** entradas:

```
0x54 = 129
0xBC =  16    (0x0010)
0xC6 = 128    (0x0080)
0xDC =  33    (0x0021)
0xE4 =  20    (0x0014)
0xF2 = 4000   (0x0FA0)
```

São as minhas cinco, com os mesmos valores, mais uma. Duas derivações
independentes — uma lendo o bytecode desmontado, outra escrita anos antes por
outra pessoa a partir do executável — chegaram ao mesmo conjunto. É exatamente o
tipo de concordância que este projeto trata como prova.

E ela provava uma coisa verdadeira e estreita: **que aquelas cinco variáveis são
o que a verificação de cópia lê**. Não provava nada sobre a pergunta que eu
estava respondendo, que era *como se entra numa fase*.

Todos os outros quinze níveis têm 49 registradores. Os outros 43 são posição do
herói, número da tela, âncora de rolagem, estado da sala — tudo que uma partida
de verdade teria deixado para trás. Uma fase com cinco dos 49 chega ao ponto de
entrada e depois se comporta como uma máquina sem quase nenhuma memória. É por
isso que dava para *ver* e não dava para *jogar*.

A medida: CAPSULE alcança 12,5% da tela com as cinco variáveis e **68,5%** com
os 49 do checkpoint 12. Quadros pintados em 600: CAPSULE de 115 para 599, INTRO
de 397 para 597.

## O jogo não lia o teclado porque nada escrevia

O segundo relato tinha causa própria e mais simples. A VM do depurador tinha os
*nomes* das seis variáveis que os scripts consultam para o joystick — `0xFC`
esquerda/direita, `0xE5` e `0xFB` cima/baixo, `0xFD` a máscara de direções,
`0xFA` o botão de ação, `0xFE` a máscara com `0x80` enquanto a ação está
pressionada — e **nada nunca as escrevia**. O herói não se mexia sob nenhuma
semeadura, porque o problema não era a semeadura.

Uma função de vinte linhas, chamada uma vez por quadro no mesmo ponto em que a
referência a chama. As 32 combinações de direção e ação são conferidas contra a
aritmética da referência por um teste comitado.

## A fase que parecia pronta

O terceiro relato é o que mais muda o que alguém acreditaria.

"Pausar em anônimos" parava a cada quadro que desenhasse uma constante sem nome.
Como um objeto fica em cena por dezenas de quadros seguidos, apertar "run"
pausava de novo no mesmo instante: funcionava e era inutilizável. Agora ele para
uma vez por constante **recém-vista** e diz isso.

Mas a outra metade do relato era verdadeira de um jeito que eu não esperava. A
sonda que lista arte anônima por tempo de tela sempre entrava numa fase **num
único checkpoint** — o primeiro que a referência lista. E CAVES tem nove
checkpoints, que são nove salas diferentes.

| fase | só o primeiro checkpoint | todos |
|---|---|---|
| PRISON | 39 | 39 (só tem um) |
| CAVES | 5 | **34** |
| CAPSULE | 13 | **49** |

São 122 constantes anônimas que um jogador efetivamente vê, contra as 57 que uma
execução de um checkpoint reporta. CAVES parecia quase pronta e não estava:
estava sendo perguntada sobre uma sala.

Pior: o checkpoint padrão de CAVES — fiel à ordem da referência — é o que
alcança **2,5%** da tela, um laço infinito de desenho. Seis dos outros oito
ficam entre 18% e 59%. O lugar de onde eu vinha olhando era o pior dos nove.

## O que eu levo disso

A frase que quero guardar é: **estar certo sobre o que você conferiu não é estar
certo sobre o que você concluiu.**

As cinco variáveis foram derivadas corretamente, confirmadas por uma fonte
independente, e comitadas com a sonda que as mede. Todo o ritual funcionou. O
erro foi inteiro na fronteira entre a medida e a conclusão: eu medi "o que a
verificação de cópia lê" e concluí "como se entra numa fase", e as duas coisas
coincidem em exatamente um dos dezesseis níveis do jogo — aquele que eu estava
usando para testar.

A tabela de checkpoints agora é gerada da referência por um script comitado, e
não digitada, porque 16 × 49 números copiados à mão são 784 chances de errar sem
que nada perceba. E a sonda de tempo de tela ganhou `--sweep`, com uma frase no
README que é o resumo do dia: **use antes de concluir que uma fase está
pronta.**

---

*As medidas saem de `notes/stage-entry/entry_state.mjs` (`--checkpoints` para a
tabela por sala, `--screens` para a hipótese refutada na rodada anterior) e de
`notes/on-screen-priority/seen_unnamed.mjs --sweep`. As tabelas vêm de
`tools/vm-debugger/tools/extract_checkpoints.py`, que tem um modo `--check` que
as re-deriva e compara.*
