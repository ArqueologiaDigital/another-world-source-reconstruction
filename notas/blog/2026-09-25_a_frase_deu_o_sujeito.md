# A frase deu o sujeito, e o bytecode deu todo o resto

*O canal de anotações funcionou de ponta a ponta pela primeira vez. Alguém jogou
a fase PRISON, escreveu 46 frases, e cinco delas viraram seis nomes. O que vale
contar não é que funcionou: é que a divisão de trabalho que eu tinha proposto no
papel sobreviveu ao primeiro teste real, e que dá para mostrar exatamente onde
cada metade entrou.*

---

## As cinco frases

Entre os quadros 3069 e 3075, a pessoa clicou em cinco polígonos e escreveu:

> "the guard's gun flying away from his hands when we is hit y the falling cage"
> "the gun rotating mid-air"
> "yet another frame of the gun mid-air"
> "the gun in the floor"
> "the gun on the floor"

Erros de digitação inclusos, porque é isso que sai de alguém olhando um jogo em
movimento, e o registro é *append-only*: uma linha editada muda o seu próprio
identificador e órfã tudo que a cita.

A regra de admissibilidade deste projeto diz que uma frase é evidência **para a
palavra-tema de um nome e nada mais**. O índice, os limites da família, o escopo
e a versão saem da listagem, como sempre. Então: as frases deram "a arma do
guarda". Vejamos o que o bytecode deu.

## Quatro medidas, nenhuma delas visual

**A trajetória**, em coordenadas literais dentro da rotina:

```
576 (215,131)  577 (227,141)  578 (231,158)  579 (239,175)
578 (243,174)  274 (245,175)  580 (247,175)  274 (249,175)
274 (250,175)  274 (251,175)
```

x sobe monotonicamente de 215 a 251; y cai 131 → 141 → 158 → 175 e depois fica
em 174/175. Um arco, uma aterrissagem e um deslizamento até parar. Nada disso
precisou de renderizador.

**A proporção gira.** Extensões medidas nas árvores de polígonos, na ordem dos
deslocamentos:

```
576  16,5 x  6,0    larga e achatada
577  12,5 x  9,0    mais curta, mais alta
578  10,0 x 14,0    estreita e ALTA  -- de ponta
579  16,0 x  6,0    larga e achatada de novo
580  15,0 x  4,5    mais achatada
274  14,0 x  3,5    a mais achatada -- deitada
```

Larga → alta → larga é uma **rotação**. A pessoa escreveu "rotating mid-air"; a
medida diz qual dos seis quadros é o objeto visto de ponta, e é o único com
proporção invertida. Duas fontes independentes: uma olhou a cena, a outra mediu
seis árvores.

**Um som toca no impacto.** `play id=0x0060, freq=0x14, vol=0x40` aparece duas
vezes na rotina — imediatamente antes de `CINEMATIC_274` em (245,175) e de novo
antes de `CINEMATIC_274` em (249,175). Exatamente quando o objeto alcança a
linha do chão e quando assenta.

**Os deslocamentos são uma sequência contígua**: `0x564C 0x5670 0x5698 0x56C4
0x56E8 0x5700`, seis membros sem buraco.

## O índice não veio da ordem de desenho

E aqui está o detalhe que justifica a regra. `CINEMATIC_578` é desenhado **duas
vezes** e `CINEMATIC_274` **quatro vezes**. Indexar por ordem de desenho daria
ambiguidade: `274` aparece *antes* de `580`. A sequência contígua de
deslocamentos não tem essa ambiguidade, e ela concorda com a trajetória para
todo membro cuja posição é distinta.

Se eu tivesse deixado a frase decidir o índice — "este é o terceiro quadro que
ele descreveu" — teria acertado por acidente em quatro dos seis e errado nos
dois últimos.

Resultado: `CINEMATIC_PRISON_GUARD_GUN_KNOCKED_F0..F5`, nas duas versões
prioritárias. Cobertura de 83,1% para 83,3%.

## O portão pegou um passo que eu mesmo escrevi

Depois de aplicar, o `make test` **falhou**: `verify-unified` 27 de 29, com 12
símbolos indefinidos.

Os pontos de desenho desta sequência moram num `.inc` **compartilhado**, então
renomeá-los alcança todas as quatro versões, enquanto o aplicador com escopo de
branch só tinha posto as definições nos dois arquivos de entrada por versão. O
passo 7 do meu próprio procedimento manda rodar `sync_equ_rename.py --shared`
em seguida. Eu não rodei.

Vale registrar sem enfeite porque é justamente o caso que o portão de bytes
consegue ver. Uma renomeação não move byte nenhum, então `make test` não pega um
nome **errado**. Mas pega um nome **aplicado pela metade**, e este estava pela
metade exatamente do jeito que a última linha do próprio aplicador avisa.

## As que não deram nome

Sete vereditos escritos, porque um resultado que não deixa rastro na árvore só
existe se alguém o escrever.

Cinco "faíscas do elevador" ficaram **retidas**, e por um motivo que vale mais do
que um nome: elas **não** são membros de `CINEMATIC_PRISON_GREEN_TRACER_F0..F7`.
Aquela família é uma sequência contígua em `0x864A..0x86B2` desenhada por uma
rotina só; estas ficam em `0x854A..0x8622` e são desenhadas por rotinas de três
quadros separadas, cada uma em seu canal, cada uma abrindo com `play id=0x0058`
com frequência e volume diferentes, todas ancoradas em `x=160, y=[0x19]`. A
palavra da pessoa concorda com a palavra que a árvore já usa na vizinhança — e o
**índice não segue**: são três rajadas de três, e `F0..F7` já está ocupado.

Duas entradas diziam "i dont understand why". Uma frase sem sujeito não fornece
palavra-tema, e isso é toda a recusa — explicitamente não é um clique errado.
Ficaram registradas porque deixam um ponteiro: as duas são desenhadas no mesmo
quadro 6924 que "o chão do elevador" e "o tamanho total do carro do elevador",
então pertencem ao elevador, e a próxima sessão pode ser perguntada sobre elas
especificamente.

## O que eu levo disso

A sonda de tempo de tela deste projeto tinha apontado `CINEMATIC_035` como a
constante mais vista da fase — 284 de 400 quadros — e não tinha nada a dizer
sobre o que ela é. A frase que chegou: *"this is buddy sitting down inside the
cage."*

Nenhuma medida daqui produziria essa palavra. E nenhuma frase daquelas
produziria o índice. Escrever isso como regra foi fácil; ver as duas metades se
encaixarem numa sequência de seis quadros, com a proporção girando no quadro que
a pessoa chamou de rotação, é a primeira evidência de que a regra não era só
uma frase bonita.

---

*O registro é `tools/vm-debugger/rename_log.jsonl`; a fila é
`make annotations`; o procedimento e a regra de admissibilidade estão em
`notes/play-and-describe/README.md`. As 34 anotações ainda abertas estão
agrupadas por assunto em `notes/HANDOFF.md`.*
