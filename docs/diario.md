# Diário da atividade

Escreva com as suas palavras. Frases curtas bastam. Não cole a conversa inteira
com a IA. Cole só os pedidos que você enviou.

## Ambiente

- Versão do OpenCode (`opencode --version`): 
 Usei OpenCode Desktop/integração no VS Code, mas o comando opencode não estava disponível no terminal.
- Modelo usado: 
 GPT 5.5

## Parte 1: antes de programar

- O que cada classe guarda:
 Astronauta guarda CPF, nome, idade, se está vivo e se está disponível;
 Voo guarda o código do voo, o estado do voo e os CPFs dos astronautas a bordo;
 Agencia guarda a lista de astronautas e a lista de voos.
- O que acontece em `LANCAR_VOO`, em palavras: 
 Quando lança um voo, o programa primeiro verifica se o voo existe, se ele ainda está planejado e se tem astronautas a bordo. Depois confere se todos os astronautas estão vivos e disponíveis. Se tudo der certo, o voo passa para em percurso e os astronautas ficam indisponíveis.
- Uma dúvida que eu tinha antes de começar:
 Como mediar a relação entre astronautas estarem vivos e mortos, e as demais funções pedidas pelos outros passos na Parte 1 (nunca usei esse tipo de dados em atividades anteriores, é algo bem diferente pra mim).

## Parte 1: uso de IA para entender algo

- O que perguntei (ou "não usei"): 
 Perguntei onde os astronautas cadastrados ficam armazenados, como fazer os ifs de adicionar/remover astronauta e como testar/commitar os passos.

- O que aprendi:
 Aprendi que os astronautas ficam em vector<Astronauta> dentro da Agencia, que
buscarAstronauta retorna -1 quando não encontra, e que os testes precisam seguir
a ordem exata das verificações.

## Primeiro contato: revisão sem editar

- As três melhorias que a IA sugeriu, em uma linha cada:
 1. Melhorar a indentação para o código ficar mais organizado e fácil de ler.

 2. Criar funções auxiliares para evitar repetir trechos parecidos em vários métodos.

 3. Usar `const` nos métodos que só leem dados, para deixar claro que eles não alteram o objeto.
- A que escolhi e por quê: 
 a 2. Estava entre a primeira e a segunda por melhorias na leitura, mas além de melhorar a organização do código, evita repetições e erros mais consistentemente.
- O que mudou no código, e se os seis testes continuaram passando :
 Ela alterou apenas `src/main.cpp`, criando métodos para embarcar, desembarcar e matar todos os astronautas de um voo, e usou esses métodos em `lancarVoo`, `finalizarVoo` e `explodirVoo`. O programa compilou sem erros e os 6 testes da Parte 1 continuaram passando.
- O que entendi que não sabia antes:
 percebi que a indentação irregular não muda o funcionamento do programa, mas dificulta a leitura e pode atrapalhar na hora de encontrar erros ou entender onde cada bloco começa e termina.

## Missão 1: LISTAR_ASTRONAUTAS e HISTORICO

- Primeira mensagem (o pedido do plano):
 Este programa em C++11 controla astronautas e voos de uma agência espacial.
Ele lê comandos da entrada padrão. As classes Astronauta, Voo e Agencia estão em src/main.cpp.
Os testes da Parte 1 passam.

Quero dois comandos novos: LISTAR_ASTRONAUTAS e HISTORICO cpf.
Use exatamente as regras da seção 4.5 do ENUNCIADO.md.

Não mude nenhum comando que já existe nem a saída deles.
Não use nada fora da biblioteca padrão.

Vou conferir com os testes de missao1 e depois com os testes da parte1.

Antes de editar, me diga quais arquivos e quais métodos você vai criar ou alterar, e por quê.
- O plano que a IA apresentou, resumido:
 Resumo: vou alterar só src/main.cpp, criando listarAstronautas() e historico(cpf) na Agencia, e ligar os comandos LISTAR_ASTRONAUTAS e HISTORICO no main, sem mudar comandos antigos. Depois vou compilar e testar missão 1 + parte 1.
- Mudei algo no plano antes de liberar?
- Resultado de `testar.sh missao1` e de `testar.sh parte1`:
 missao1/01_listar_astronautas: FC: nenhuma diferença encontrada
missao1/02_historico: FC: nenhuma diferença encontrada
parte1/01 a 06: FC: nenhuma diferença encontrada

- Precisei refazer? O que mudou no pedido:
 Não precisei Refazer.

## Missão 2: SALVAR e CARREGAR

- Primeira mensagem:
 Este programa em C++11 controla astronautas e voos de uma agência espacial.
Ele lê comandos da entrada padrão. As classes Astronauta, Voo e Agencia estão em src/main.cpp.
A Parte 1 passa nos testes e a Missão 1 já foi feita.

Quero implementar a Missão 2: SALVAR nome_do_arquivo e CARREGAR nome_do_arquivo.
Use exatamente as regras da seção 4.6 do ENUNCIADO.md.

Regras:
- SALVAR grava todos os dados em arquivo texto e imprime:
  OK: dados salvos em nome_do_arquivo
- Se não conseguir salvar:
  ERRO: nao foi possivel salvar em nome_do_arquivo
- CARREGAR substitui os dados atuais pelos dados do arquivo e imprime:
  OK: dados carregados de nome_do_arquivo
- Se o arquivo não existir:
  ERRO: nao foi possivel carregar de nome_do_arquivo
  e os dados atuais continuam como estavam.
- O formato do arquivo pode ser escolhido, mas precisa reconstruir tudo:
  astronautas com vivo/disponivel, voos com estado e lista de CPFs.
- Não mude nenhum comando que já existe nem a saída deles.
- Use C++11 e somente biblioteca padrão.

Vou conferir com os testes de missao2 e depois com os testes da parte1.

Antes de editar, me diga quais arquivos e quais métodos você vai criar ou alterar, por quê, e mostre o formato do arquivo com um exemplo.
- O plano, resumido:
 Resumo: vou mexer só em src/main.cpp, adicionando leitura/escrita com fstream, métodos simples para restaurar estados, comandos SALVAR e CARREGAR, e mantendo os dados atuais se o arquivo não abrir. Vou implementar agora.
- O formato do arquivo (cole cinco linhas do `dados_teste.txt`): 
 ASTRONAUTAS 3
  111
  30
  1
  1
- Resultado de `testar.sh missao2` e de `testar.sh parte1`:
 missao2: 3 de 3 testes passaram.
parte1: 6 de 6 testes passaram.
- Precisei refazer? O que mudou no pedido: Não.

## Missão 3: RELATORIO

- Primeira mensagem: 
 Este programa em C++11 controla astronautas e voos de uma agência espacial.
A Parte 1, Missão 1 e Missão 2 já estão implementadas.
Quero implementar a Missão 3: RELATORIO, seguindo exatamente a seção 4.7 do ENUNCIADO.md.

Regras:
- RELATORIO imprime a linha RELATORIO e depois:
  voos planejados
  voos em curso
  voos finalizados com sucesso
  voos finalizados com explosao
  astronautas cadastrados
  astronautas vivos
  astronautas mortos
  astronauta mais experiente
  taxa de sucesso
- Experiência é o número de voos lançados em que o astronauta estava a bordo.
- Voo planejado não conta.
- Em empate, vale o astronauta cadastrado primeiro.
- Se ninguém voou: astronauta mais experiente: (nenhum)
- Taxa de sucesso é sucessos * 100 / finalizados, usando parte inteira.
- Se não houver voos finalizados: taxa de sucesso: (nenhum voo finalizado)
- Não mude os comandos existentes nem a saída deles.
- Use C++11 e somente biblioteca padrão.

Antes de editar, me diga quais arquivos e métodos vai criar ou alterar, e por quê.
- O plano, resumido:
 Resumo : Na Missão 3, implementei o comando RELATORIO. Ele mostra a quantidade de voos por estado, astronautas cadastrados/vivos/mortos, o astronauta mais experiente contando apenas voos lançados, e a taxa de sucesso dos voos finalizados. A experiência é calculada a partir dos voos salvos, então continua correta depois de carregar arquivo.
- Resultado de `testar.sh missao3` e de `testar.sh parte1`:
 parte1:
6 de 6 testes passaram.

missao3:
5 de 5 testes passaram.
- Precisei refazer? O que mudou no pedido: Não.

## Missão 4: livre

- O que escolhi e por quê:
 Buscar Astronautas pelo Cpf, uma ferramenta que permite procurar astronautas com base no seu cpf e mostrar sua situação. Como estava sem tempo, pensei em uma ferramenta simples que não mexe no código antigo, e é pertinente.
- O comando novo, a saída que eu esperava e o nome do meu arquivo de comandos
  (escritos antes de pedir):
 Comando novo: BUSCAR_ASTRONAUTA cpf.

Saída esperada para astronauta disponível:
BUSCA DE ASTRONAUTA
111 Ana Maria (30 anos) - vivo, disponivel

Saída esperada para astronauta em voo:
BUSCA DE ASTRONAUTA
111 Ana Maria (30 anos) - vivo, em voo

Saída esperada para astronauta morto:
BUSCA DE ASTRONAUTA
111 Ana Maria (30 anos) - morto

Saída esperada para CPF não cadastrado:
ERRO: astronauta 999 nao cadastrado

Arquivo de comandos: teste_missao4.txt
- Primeira mensagem:
 Vou fazer a missão 4.

Escolhi criar o comando BUSCAR_ASTRONAUTA cpf.
Ele deve procurar um astronauta pelo CPF e mostrar a situação dele.

Regras:
- Se o CPF não existir, imprimir:
  ERRO: astronauta 999 nao cadastrado
- Se existir, imprimir:
  BUSCA DE ASTRONAUTA
  111 Ana Maria (30 anos) - vivo, disponivel
- Se o astronauta estiver em um voo em curso, imprimir:
  111 Ana Maria (30 anos) - vivo, em voo
- Se estiver morto, imprimir:
  111 Ana Maria (30 anos) - morto

Não mude nenhum comando antigo nem a saída deles.
Use C++11 e somente biblioteca padrão.

Antes de editar, me diga quais arquivos e métodos vai criar ou alterar, e por quê.
- O que veio, comparado com o que eu esperava:
 ERRO: astronauta 999 nao cadastrado
OK: astronauta 111 cadastrado
BUSCA DE ASTRONAUTA
111 Ana Maria (30 anos) - vivo, disponivel
OK: voo 10 cadastrado
OK: astronauta 111 adicionado ao voo 10
OK: voo 10 lancado
BUSCA DE ASTRONAUTA
111 Ana Maria (30 anos) - vivo, em voo
OK: voo 10 explodiu
BUSCA DE ASTRONAUTA
111 Ana Maria (30 anos) - morto

perfeitamente da forma que queria, é algo bem simples, então faz sentido.
- `testar.sh parte1` continuou passando? Sim.
- Aceitei, ajustei ou descartei? Por quê:
 Aceitei, porque o comando funcionou no meu teste e não quebrou os comandos antigos.

## Fechamento

- O que a IA fez que eu não conseguiria fazer sozinho nesse prazo:
 A missão 2 foi a mais trabalhosa, acredito que a manipulação dos dados do arquivo é algo que eu teria bastante dificuldade sozinho.
- Onde ela errou ou fez algo que eu não pedi:
 Incrivelmente, as dicas que a IA me proporcionou no planejamento resultaram em uma execução perfeita,apesar de as vezes a ia dar circulos durante a execução dos projetos.
- O que eu faria diferente da próxima vez:
 Acredito que eu deveria ter pedido um prompt de acordo com as regras desde o começo, e criado um novo chat, pois a IA começou a misturar contextos ao longo do chat inicial.
