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
- O plano que a IA apresentou, resumido:
- Mudei algo no plano antes de liberar?
- Resultado de `testar.sh missao1` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

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
