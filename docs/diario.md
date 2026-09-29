# Diário da atividade

Escreva com as suas palavras. Frases curtas bastam. Não cole a conversa inteira
com a IA. Cole só os pedidos que você enviou.

## Ambiente

- Versão do OpenCode (`opencode --version`): 
* Usei OpenCode Desktop/integração no VS Code, mas o comando opencode não estava disponível no terminal.
- Modelo usado: 
* GPT 5.5

## Parte 1: antes de programar

- O que cada classe guarda:
* Astronauta guarda CPF, nome, idade, se está vivo e se está disponível;
* Voo guarda o código do voo, o estado do voo e os CPFs dos astronautas a bordo;
* Agencia guarda a lista de astronautas e a lista de voos.
- O que acontece em `LANCAR_VOO`, em palavras: 
* Quando lança um voo, o programa primeiro verifica se o voo existe, se ele ainda está planejado e se tem astronautas a bordo. Depois confere se todos os astronautas estão vivos e disponíveis. Se tudo der certo, o voo passa para em percurso e os astronautas ficam indisponíveis.
- Uma dúvida que eu tinha antes de começar:
* Como mediar a relação entre astronautas estarem vivos e mortos, e as demais funções pedidas pelos outros passos na Parte 1 (nunca usei esse tipo de dados em atividades anteriores, é algo bem diferente pra mim).

## Parte 1: uso de IA para entender algo

- O que perguntei (ou "não usei"): 
* Perguntei onde os astronautas cadastrados ficam armazenados, como fazer os ifs de adicionar/remover astronauta e como testar/commitar os passos.

- O que aprendi:
* Aprendi que os astronautas ficam em vector<Astronauta> dentro da Agencia, que
buscarAstronauta retorna -1 quando não encontra, e que os testes precisam seguir
a ordem exata das verificações.

## Primeiro contato: revisão sem editar

- As três melhorias que a IA sugeriu, em uma linha cada:
* 1. Melhorar a indentação para o código ficar mais organizado e fácil de ler.

* 2. Criar funções auxiliares para evitar repetir trechos parecidos em vários métodos.

* 3. Usar `const` nos métodos que só leem dados, para deixar claro que eles não alteram o objeto.
- A que escolhi e por quê: 
* a 2. Estava entre a primeira e a segunda por melhorias na leitura, mas além de melhorar a organização do código, evita repetições e erros mais consistentemente.
- O que mudou no código, e se os seis testes continuaram passando :
* Ela alterou apenas `src/main.cpp`, criando métodos para embarcar, desembarcar e matar todos os astronautas de um voo, e usou esses métodos em `lancarVoo`, `finalizarVoo` e `explodirVoo`. O programa compilou sem erros e os 6 testes da Parte 1 continuaram passando.
- O que entendi que não sabia antes:
* percebi que a indentação irregular não muda o funcionamento do programa, mas dificulta a leitura e pode atrapalhar na hora de encontrar erros ou entender onde cada bloco começa e termina.

## Missão 1: LISTAR_ASTRONAUTAS e HISTORICO

- Primeira mensagem (o pedido do plano):
* Este programa em C++11 controla astronautas e voos de uma agência espacial.
Ele lê comandos da entrada padrão. As classes Astronauta, Voo e Agencia estão em src/main.cpp.
Os testes da Parte 1 passam.

Quero dois comandos novos: LISTAR_ASTRONAUTAS e HISTORICO cpf.
Use exatamente as regras da seção 4.5 do ENUNCIADO.md.

Não mude nenhum comando que já existe nem a saída deles.
Não use nada fora da biblioteca padrão.

Vou conferir com os testes de missao1 e depois com os testes da parte1.

Antes de editar, me diga quais arquivos e quais métodos você vai criar ou alterar, e por quê.
- O plano que a IA apresentou, resumido:
* Resumo: vou alterar só src/main.cpp, criando listarAstronautas() e historico(cpf) na Agencia, e ligar os comandos LISTAR_ASTRONAUTAS e HISTORICO no main, sem mudar comandos antigos. Depois vou compilar e testar missão 1 + parte 1.
- Mudei algo no plano antes de liberar?
- Resultado de `testar.sh missao1` e de `testar.sh parte1`:
* 01_cadastros: FC: nenhuma diferença encontrada
02_passageiros_planejados: FC: nenhuma diferença encontrada
03_lancamento_finalizacao: FC: nenhuma diferença encontrada
04_explosao_e_mortes: FC: nenhuma diferença encontrada
05_operacoes_invalidas: FC: nenhuma diferença encontrada
06_cenario_completo: FC: nenhuma diferença encontrada
LISTA DE ASTRONAUTAS
== disponiveis ==
(nenhum)
== em voo ==
(nenhum)
== mortos ==
(nenhum)
OK: astronauta 111 cadastrado
OK: astronauta 222 cadastrado
OK: astronauta 333 cadastrado
LISTA DE ASTRONAUTAS
== disponiveis ==
111 Ana Maria (30 anos)
222 Bruno Costa (35 anos)
333 Carla Souza (28 anos)
== em voo ==
(nenhum)
== mortos ==
(nenhum)
OK: voo 10 cadastrado
OK: voo 20 cadastrado
OK: astronauta 111 adicionado ao voo 10
OK: astronauta 222 adicionado ao voo 20
OK: voo 10 lancado
OK: voo 20 lancado
LISTA DE ASTRONAUTAS
== disponiveis ==
333 Carla Souza (28 anos)
== em voo ==
111 Ana Maria (30 anos) - voo 10
222 Bruno Costa (35 anos) - voo 20
== mortos ==
(nenhum)
OK: voo 20 explodiu
OK: voo 10 finalizado com sucesso
LISTA DE ASTRONAUTAS
== disponiveis ==
111 Ana Maria (30 anos)
333 Carla Souza (28 anos)
== em voo ==
(nenhum)
== mortos ==
222 Bruno Costa (35 anos)

ERRO: astronauta 999 nao cadastrado
OK: astronauta 111 cadastrado
HISTORICO DE 111 Ana Maria
(nenhum voo)
OK: voo 10 cadastrado
OK: voo 20 cadastrado
OK: voo 30 cadastrado
OK: astronauta 111 adicionado ao voo 10
OK: astronauta 111 adicionado ao voo 30
HISTORICO DE 111 Ana Maria
(nenhum voo)
OK: voo 10 lancado
HISTORICO DE 111 Ana Maria
voo 10: em curso
OK: voo 10 finalizado com sucesso
OK: astronauta 111 adicionado ao voo 20
OK: voo 20 lancado
HISTORICO DE 111 Ana Maria
voo 10: finalizado com sucesso
voo 20: em curso
OK: voo 20 explodiu
HISTORICO DE 111 Ana Maria
voo 10: finalizado com sucesso
voo 20: finalizado com explosao
- Precisei refazer? O que mudou no pedido:
* Não precisei Refazer.

## Missão 2: SALVAR e CARREGAR

- Primeira mensagem:
- O plano, resumido:
- O formato do arquivo (cole cinco linhas do `dados_teste.txt`):
- Resultado de `testar.sh missao2` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

## Missão 3: RELATORIO

- Primeira mensagem:
- O plano, resumido:
- Resultado de `testar.sh missao3` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

## Missão 4: livre

- O que escolhi e por quê:
- O comando novo, a saída que eu esperava e o nome do meu arquivo de comandos
  (escritos antes de pedir):
- Primeira mensagem:
- O que veio, comparado com o que eu esperava:
- `testar.sh parte1` continuou passando?
- Aceitei, ajustei ou descartei? Por quê:

## Fechamento

- O que a IA fez que eu não conseguiria fazer sozinho nesse prazo:
- Onde ela errou ou fez algo que eu não pedi:
- O que eu faria diferente da próxima vez:
