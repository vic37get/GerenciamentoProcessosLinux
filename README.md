# Implementação de Gerenciamento de processos no Linux :scroll::closed_book:
## Funcionamento: 
Aplicação que simula uma história, utilizando, pelo menos, as seguintes chamadas de sistema:
* fork
* exec
* clone
* pipe
* waitpid
* exit
* sigaction
* kill

## Execução
Cada personagem da história descrita acima é representado por um processo/thread. As chamadas de sistema são utilizadas de forma a simular todos os fatos descritos no enunciado. Exemplos:
- fork, exec e clone para dar a luz a processos/personagens filhos.
- pipe para realizar uma troca de mensagens entre personagens que interagem.
- sigaction e kill para atacar/matar personagens em luta.
- exit "morte natural" de um personagem
