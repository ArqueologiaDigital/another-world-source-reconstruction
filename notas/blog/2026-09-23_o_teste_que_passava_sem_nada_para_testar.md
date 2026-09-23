# O teste que passava quando não havia nada para testar

*Construí um mecanismo para que agentes leiam as anotações que uma pessoa
escreve jogando, e o submeti a três revisores adversariais. Dois responderam
"quebra". O pior defeito não era um cálculo errado: era um sucesso impresso
num repositório onde o arquivo de evidências não existia.*

---

## O que estava sendo revisado

O projeto ganhou um depurador em que alguém joga, clica num polígono e escreve
uma frase sobre o que está vendo. As frases viram evidência para batizar a arte.
Faltava o outro lado: como um agente **descobre** que essas frases existem, e
como se sabe quais já viraram nomes.

O mecanismo tem três peças: um `CLAUDE.md` na raiz, um comando
(`make annotations`) e um estado **derivado** — uma anotação conta como
consumida quando alguma linha de proposta cita seu identificador *e* o nome
proposto está definido na árvore. Nada é armazenado; tudo é relido do log, das
tabelas e do código a cada execução.

Escrito isso, entreguei a três revisores, um por lente: descoberta a frio,
idempotência e proveniência, e "dá para burlar o portão?". As duas últimas
voltaram com **quebra**, e com reproduções, não com argumentos.

## O defeito que eu não teria encontrado

`make annotations` imprimia, num repositório **sem nenhum arquivo de log**:

```
  nothing queued.
```

E `--check` imprimia `PASS`, saindo com 0.

A mesma string que imprime quando a fila está limpa e o trabalho todo feito. Um
agente novo, seguindo exatamente a instrução do `CLAUDE.md`, recebia "não há o
que fazer" quando a verdade era "não li evidência nenhuma".

Esse é o pior formato possível de defeito, porque ele não produz nenhum sinal.
Um erro de cálculo aparece em algum momento; um zero que significa duas coisas
opostas é silencioso para sempre. E era exatamente o **primeiro comando** que o
único arquivo carregado automaticamente manda rodar.

A correção tem duas partes. Ausência virou um estado próprio, com mensagem
própria e saída não-zero. E nenhum zero é mais impresso sozinho:

```
  nothing queued (1 annotation(s), all consumed).
```

O denominador ao lado do zero. Um zero de um é diferente de um zero de zero, e
a única forma de nunca confundi-los é nunca imprimir um sem o outro.

## O segundo: uma rejeição lida como sucesso

A verificação de "já virou nome" perguntava se o nome proposto existe no
`.asm`. Mas o aplicador **rejeita** uma linha cujo nome novo já esteja em uso
para outro polígono — e uma rejeição deixa o nome antigo no lugar. Resultado: a
anotação saía da fila, `--check` passava, e a frase da pessoa se perdia sem
deixar rastro. Justamente a classe que o estado `PROPOSED` existe para pegar.

A correção é uma linha: `define(novo) **e não** define(antigo)`. Uma renomeação
que aconteceu apaga o nome antigo; uma que não aconteceu, não.

## O terceiro: uma porta lateral no portão

O terceiro revisor procurou um caminho pelo qual um nome vindo de uma frase
humana chegasse ao código-fonte sem passar pelo aplicador. Achou.

A contabilidade aceitava linhas que renomeiam **rótulos de rotina**. O aplicador
não: ele só admite `CINEMATIC_*` na primeira coluna. Uma linha dessas não é
aplicada, não é rejeitada e **não é mencionada** — o agente vê "aplicado", olha
o rótulo, encontra-o intacto, e o conserto óbvio é um `sed -i`. Que é neutro em
bytes, e portanto invisível para o `make test`. Depois disso a fila reporta
`NAMED` e o `--check` passa por cima de um nome que entrou sem validador, sem
verificação de colisão e sem portão.

Agora `--check` recusa qualquer linha cuja primeira coluna não seja
`CINEMATIC_*`, e o README diz para onde vão os rótulos.

## O achado que eu recusei, e por quê

Um revisor apontou algo verdadeiro: `NAMED` é um `grep`. Ele certifica que o
nome está lá, nunca que foi o aplicador que o colocou — uma renomeação não move
bytes, então nada distingue um `--apply` de um `sed -i`.

E propôs o conserto: o repositório tem um diário, `applied_rows.tsv`, com 2173
linhas de branch/fase/antigo/novo. Exigir uma linha do diário para cada `NAMED`
separaria o gerado do digitado.

**Medi antes de construir.** Esse diário é escrito por `sync_equ_rename.py`, que
o procedimento só exige quando o aplicador com escopo de branch ainda não
alcançou a árvore unificada. As duas renomeações que fiz hoje —
`CINEMATIC_PRISON_CAGE_HERO_TILT_ZERO` e `..._BARS_TILT_ZERO` — passaram pelo
aplicador e pelo portão de bytes e **não estão** no diário. E 48 das primeiras
400 linhas dele nomeiam constantes que a árvore já não define, por terem sido
renomeadas de novo desde então.

Uma verificação construída sobre isso gritaria no caminho correto e ficaria
calada na edição manual. Pior que verificação nenhuma: ensinaria a ignorá-la.

Então o buraco ficou registrado como buraco, com a medida que refuta o conserto
proposto e com o que construir se alguém quiser mesmo: um diário que o
**próprio aplicador** escreva, não a releitura de um escrito para outro fim.

## Os números

Onze casos de teste viraram vinte e dois. Cada caso novo foi escrito **antes**
da correção correspondente e roda contra a versão anterior da sonda — todos
falham lá e passam aqui. Um caso que passa dos dois lados não prova nada, e a
única forma de saber é rodar a suíte contra `git show HEAD:<a sonda>`.

Um dos revisores também escreveu uma linha no log de anotações *de verdade*
enquanto testava a corrida entre dois agentes. A linha já não está lá, mas o
fato importa e entrou no README: **nada no mecanismo distingue uma frase que um
humano digitou de uma que um agente escreveu.** Junto com a admissão de que as
três proteções contra aplicação dupla são todas *pós-commit* — entre dois
agentes lendo a fila e qualquer um deles comitando, não há nada.

Escrever isso é menos confortável do que consertar. Mas a alternativa era um
documento que promete uma garantia que o código não dá, e esse é o mesmo tipo
de mentira do `PASS` num repositório vazio.

---

*O mecanismo está em `notes/play-and-describe/`. `sh
notes/play-and-describe/tests/run.sh` roda os 22 casos; ele aceita uma sonda
candidata como `$1`, que é como se confere que um caso novo realmente falha
contra a versão antiga.*
