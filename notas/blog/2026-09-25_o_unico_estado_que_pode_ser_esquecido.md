# O único estado que pode ser esquecido

*Texto curto sobre uma decisão de projeto. O depurador ganhou uma memória que
some quando a página recarrega — de propósito, e não por preguiça. Num projeto
que deriva tudo do git, vale explicar por que esse pedaço é a exceção certa.*

---

## O problema

Uma pessoa joga a fase, clica num polígono anônimo e escreve o que ele é. O
contador no cabeçalho continua dizendo que ele é anônimo.

E está tecnicamente certo: a árvore não tem nome nenhum para aquela constante e
não vai ter por um bom tempo. Uma frase vira nome passando por uma tabela de
proposta, um aplicador, a regra de buraco de família, a checagem de colisão e o
portão de bytes. Isso são minutos no melhor caso e dias no caso normal.

Enquanto isso o contador aponta para trabalho já feito, e a opção "pausar em
anônimos" para em cima da mesma figura que a pessoa acabou de descrever. Uma
ferramenta que insiste em te mostrar o que você já resolveu ensina você a
ignorá-la.

## A correção óbvia, e por que ela é perigosa

O conserto é imediato: lembrar do que foi descrito e não contar mais.

A tentação seguinte também: **persistir** essa lembrança. Gravar num arquivo,
ou no armazenamento do navegador, para que ela sobreviva a um recarregamento.
Parece um brinde.

É o começo de um segundo registro de nomes.

Este repositório tem exatamente um lugar onde um nome existe: `src/levels/`. O
mecanismo de anotações foi construído com um cuidado desproporcional para não
criar outro — todo estado dele é **derivado** a cada execução, lendo o log, as
tabelas de proposta e a própria árvore. Não há banco, não há cache, não há
arquivo de status. A razão é que um registro paralelo diverge, e quando diverge
ninguém sabe qual dos dois está certo.

"Já descrevi isso" persistido é um registro paralelo. Pequeno, bem-intencionado,
e com a mesma doença: daqui a três semanas ele diria que 40 constantes estão
resolvidas, e a árvore diria que 12 têm nome, e a diferença seria de propostas
rejeitadas, aplicações pela metade e frases que não deram em nada — exatamente
as três coisas que o `--check` do mecanismo existe para encontrar.

## A vida útil honesta

Então a lembrança dura enquanto a página estiver aberta, e o F5 pergunta de
novo.

O detalhe que faz isso funcionar e não ser só teimosia: **na hora do F5 a
resposta pode já ter chegado da fonte.** Se o nome foi aplicado, a constante
está nomeada de verdade e sai da conta pelo caminho certo. Se não foi, ela volta
a ser anônima — e deve mesmo, porque não foi.

A memória de sessão é a vida útil honesta de "eu já olhei para isso". Ela cobre
exatamente o intervalo em que a informação existe só na cabeça de quem está
olhando, e expira no momento em que a árvore passa a ter uma opinião.

Três consequências que caíram de graça:

- trocar de fase limpa a lembrança — outra fase é outro acúmulo;
- quando a fonte passa a nomear uma constante descrita, a anotação de sessão é
  **descartada**, senão uma reversão posterior daquele nome ficaria escondida
  atrás dela;
- o contador mostra os dois estados em vez de fundi-los — `3 unnamed
  (+2 described)` —, porque "sem nome" e "sem nome mas já resolvido" são coisas
  diferentes e juntá-las seria refazer o problema num lugar novo.

## O outro pedaço, com a medida que o justifica

Na mesma leva, o depurador passou a reler a listagem sozinho: aplicar um lote de
nomes reescreve `src/levels/<versão>/<FASE>.asm` embaixo de uma página aberta, e
até então a única forma de ver era F5 — que joga fora a partida, a posição na
fase e tudo que foi descrito.

Agora existe uma rota que devolve `mtime` e tamanho, e a página consulta a cada
dois segundos, buscando os nomes **só quando esse par muda**. A medida que
justifica a frequência: **200 consultas de versão custam 1,6 ms; uma única
leitura da tabela de nomes custa 23,6 ms.** Consultar a versão a cada dois
segundos custa cerca de um décimo de milésimo do que custaria consultar a tabela.

A máquina virtual nunca lê os nomes, então nada reinicia. Os nomes aparecem
debaixo de quem está jogando.

---

*`tools/vm-debugger/README.md` tem as duas seções; a medida está em
`tools/vm-debugger/tests/check_watch_and_described.py`, que também confere que o
token se move numa escrita, é estável fora dela, e responde "missing" em vez de
estourar para uma fase que não existe.*
