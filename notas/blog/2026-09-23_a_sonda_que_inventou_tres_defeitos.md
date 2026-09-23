# A sonda que inventou três defeitos

*Uma sonda nova apontou três erros numa parte do jogo que já estava bem
estudada. Os três eram falsos, e a causa não estava na medida: estava em de
**qual** das duas árvores de código eu tinha lido cada metade da pergunta. O
repositório tem 574 nomes definidos em dois lugares com dois valores
diferentes, e nenhum dos testes automáticos consegue ver isso.*

---

## A escada que eu estava medindo

Quando o herói dispara, o tiro não é um sprite só. O jogo mede a distância até
o obstáculo e escolhe, numa escada de comparações, qual figura de feixe
desenhar — um feixe curto, um médio, um longo. A escada tem seis degraus, e
eles aparecem em três fases diferentes do jogo com o mesmo desenho: é um
*kit*, não três efeitos parecidos.

A sonda `notes/beam-span-ladder/rung_thresholds.py` existe para checar uma
coisa só: **cada degrau usa a arte do tamanho certo?** O código compara a
distância contra `0x02, 0x06, 0x0E, 0x1E, 0x3E, 0x7E` e a resposta bonita é
que esses números — 2, 6, 14, 30, 62, 126 — são exatamente as larguras
desenhadas dos pares de figuras que cada comparação seleciona. O limiar *é* a
largura. Um degrau apontando para arte de outro tamanho seria um nome errado,
e a sonda marca essas linhas com `**`.

Na primeira execução ela marcou três:

1. a escada inteira da fase CAVES do MS-DOS, toda deslocada;
2. `CINEMATIC_TELEPORT_UP_BEAM_LEFT`, um nome ganho e revisado, sentado num
   degrau de 6 pixels;
3. `CINEMATIC_CAPSULE_SCREEN_91_BACKDROP_LAYER_3` da versão Amiga — um
   **cenário de fundo** — ocupando um degrau de 224 pixels de feixe.

O terceiro é absurdo o suficiente para ser um presente. Uma camada de fundo
não é um tiro. Ou o projeto tinha um estrago grande e antigo, ou a sonda
estava errada.

## As duas árvores

Este projeto guarda o mesmo jogo duas vezes. Há uma árvore **canônica**, com um
arquivo por versão e por fase — `src/levels/dos_1992/PRISON.asm` —, e há uma
árvore **unificada**, em `src/levels/_unified/`, onde as quatro versões moram
no mesmo arquivo separadas por `.if BRANCH`. As duas montam para bytes
idênticos; é isso que o `make test` verifica, 29 de 29 em cada uma.

As duas também definem os nomes. Cada constante de arte é um `EQU` com um
deslocamento, e esse `EQU` existe nas duas árvores.

A sonda lia a rotina da árvore unificada — é onde a escada está escrita de
forma compacta — e resolvia o nome de cada constante na tabela da árvore
canônica. Enquanto as duas concordam, isso funciona e parece elegante. Quando
discordam, a sonda pega o deslocamento de um lado e o nome do outro, e imprime
com toda a confiança que a camada de fundo da CAPSULE é um feixe de tiro.

Os três defeitos eram um defeito só, meu, repetido três vezes.

A correção é de uma linha de política e várias de código: **resolver primeiro
na árvore de onde a rotina veio.** A regra que ficou escrita, porque ela vale
para qualquer sonda futura deste repositório:

> Um nome significa aquilo que a árvore de onde ele foi lido diz que ele
> significa.

Depois da correção, a escada não tem nenhum `**`. Tem uma exceção, e ela não é
defeito: o degrau `0x64` (100) reaproveita o par de 62, porque não existe arte
de 100 de largura. Um degrau sem arte própria reusa a de baixo — isso é o
programa original sendo econômico, não um nome fora do lugar.

## Quanto disso existe

A pergunta seguinte é óbvia e eu não sabia responder: **quantos nomes estão
nesse estado?** Escrevi `notes/tree-name-drift/name_drift.py` para comparar as
duas tabelas de `EQU` constante a constante. Hoje:

```
   450  nomes semânticos que existem na árvore canônica e não na unificada
   574  nomes que as duas árvores definem em deslocamentos diferentes
```

O pior bolsão é a CAVES do MS-DOS, com 306 nomes deslocados, seguida da TANK,
com 173 nomes que simplesmente não chegaram à árvore unificada.

E aqui está a parte desconfortável. **Nenhum teste vê isso.** O portão do
projeto é `make test`: verifica que a árvore canônica monta para os bytes
originais, que a unificada monta para os bytes originais, e passa o *lint*. Os
dois lados estão certos contra os bytes — os nomes não mudam bytes, são
rótulos. Um nome pode apontar para a figura A num arquivo e para a figura B no
outro e as 58 verificações passam, todas as 58.

Não é uma disputa de nomenclatura. É uma renomeação aplicada a uma árvore e
não sincronizada com a outra. A árvore canônica é o registro de nomes — é dela
que sai a porcentagem de cobertura —, então o desvio não custa cobertura
nenhuma. Ele custa **confiança em sondas**, que é pior, porque a perda é
silenciosa.

Isso também fechou um item aberto que estava no projeto havia tempo. Uma
ponte entre versões acertou 592 de 636 lugares de desenho já nomeados, e as
44 falhas eram todas da mesma cena: `PRISON_CUTSCENE_ZOOM_IN_*`. Estavam
registradas como "as duas versões desenham figuras diferentes aqui". Não
desenham. `CINEMATIC_PRISON_CUTSCENE_ZOOM_IN_LEFT_4` está em `0xCF78` na
árvore unificada e em `0xCA7C` em `dos_1992/PRISON.asm`. As 44 discordâncias
eram desvio de árvore, e a correção não é renomear nada: é sincronizar.

## A sonda também precisou ser curada

Com um final que eu deveria ter previsto. A primeira versão do `name_drift.py`
acusou 631 nomes deslocados a mais do que existem. Um `.inc` compartilhado
define o mesmo nome **uma vez por braço `.if BRANCH`** — quatro definições,
uma por versão, valores diferentes de propósito. Eu pegava a primeira e
chamava as outras três de discordância.

A correção: um nome só é "deslocado" quando o deslocamento canônico não bate
com **nenhuma** das definições unificadas.

Então a sonda escrita para medir defeitos falsos nasceu com defeitos falsos
próprios, pela mesma família de erro: ler duas metades de uma pergunta em dois
lugares que eu supunha concordarem. Não tenho uma lição mais elegante do que
essa. Duas fontes que quase sempre concordam são a armadilha mais cara que
existe, porque o "quase" não aparece em nenhum teste — só aparece no dia em
que uma sonda diz que um cenário de fundo é um tiro.

---

*As medidas deste texto saem de `notes/tree-name-drift/name_drift.py` (sem
argumentos, imprime os dois totais e o ranking por versão/fase) e de
`notes/beam-span-ladder/rung_thresholds.py` (sem argumentos, imprime a escada
com os limiares, as larguras medidas e um `**` por degrau fora de lugar). Os
números de desvio mudam a cada renomeação; rode antes de citar.*
