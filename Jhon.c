#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

//Funções utilizadas:
/*

 fork OK
 exec OK
 clone OK
 pipe OK
 waitpid OK
 exit OK
 sigaction
 kill OK

*/

volatile sig_atomic_t shutdown_flag = 1;

void Myke(int sinal){
    shutdown_flag = 0;
    printf("Myke: Estou morrendo!\n");
    sleep(5);
    printf("Myke: Eu não posso acreditar que você faria isso!\n");
    sleep(5);
    printf("Myke: Adeus!\n");
    sleep(5);
}

int Ricardo(void *arg){
    int tempo = 5;
    
    printf("Ricardo: Meu nome é Ricardo! Minha identidade é: %d\n", getpid());
    sleep(tempo);
    printf("Ricardo: Minhas intenções são matar July, a sua habitante que ainda está para nascer!\n");
    sleep(tempo);
    printf("Ricardo: Me parece que você foi esperto, e que pôde quebrar esse laço!\n");
    sleep(tempo);
    printf("Ricardo: O laço que se repetiria pela milésima primeira vez!\n");
    sleep(tempo);
    printf("Ricardo: Me parece que voce não me deixará dominar seu mundo criando mais uma cópia dele..\n");
    sleep(tempo);
    printf("Ricardo: Então não tenho motivos para estar aqui!\n");
    sleep(tempo);
    printf("Ricardo: Até outro mundo!\n");
    sleep(tempo);
    printf("Ricardo: ADEUS!\n");
    sleep(tempo);
    
    exit(0);
}

int main(int argc, char *argv[]){
    int tempo = 5;
    int status;
    
    //Narrador
    printf("\n--------JHON O SEGUNDO CRIADOR DO MUNDO LINCH--------\n\n");
    sleep(tempo);

    // Inicio Jhon
    printf("Jhon: Sou Jhon o segundo criador do mundo LINCH, a minha identidade é: %d\n", getpid());
    sleep(tempo);
    printf("Jhon: Esse mundo me é familiar!\n");
    sleep(tempo);
    printf("Jhon: Fui mandado para esse mundo para corrigir os erros do meu antecessor!\n");
    sleep(tempo);
    printf("Jhon: Não vou cometer os mesmos erros que ele cometeu..\n");
    sleep(tempo);
    printf("Jhon: Entao vamos lá, criarei meu primeiro habitante, o nome dele será Ricardo!\n");
    sleep(tempo);
    printf("Jhon: Para não cometer o mesmo erro de meu pai perguntarei algo para meu habitante antes!\n");
    sleep(tempo);
    printf("Narrador: A maldição diz que sempre que se é perguntado as intenções do habitante antes do seu nascimento ser completado, o mesmo revela suas reais intenções!\n");
    sleep(tempo);
    printf("Narrador: Com isso, o habitante decide se morre ou vive..\n");
    sleep(tempo);
    printf("Narrador: A maldição o obriga a se revelar e se decidir..\n");
    sleep(tempo);
    printf("Jhon: Quais suas reais intenções neste mundo Ricardo?\n");
    sleep(tempo);
    
    void *pchild_stack = malloc(1024 * 1024);
    
    if ( pchild_stack == NULL ) {
      printf("Jhon: Ricardo não pode falar.\n");
      sleep(tempo);
      exit(EXIT_FAILURE);
    }

    int pid = clone(&Ricardo, pchild_stack + (1024 * 1024), SIGCHLD, argv[1]);
    if ( pid < 0 ) {
        printf("Jhon: Eita!!! Ricardo não resistiu ao nascimento!\n");
        sleep(tempo);
        exit(EXIT_FAILURE);
    }
    wait(NULL);
    free(pchild_stack);
    printf("Jhon: Ricardo preferiu se matar..\n");
    sleep(tempo);
    printf("Jhon: Acho que devo tentar outra vez..\n");
    sleep(tempo);
    printf("Jhon: Vai ver meu segundo habitante não seja tão mal intencionado..\n");
    sleep(tempo);

    int statusMyke;

    pid_t c_pid = fork();

    if (c_pid == -1) {
        perror("Jhon: Myke não conseguiu nascer!");
        exit(EXIT_FAILURE);
    }

    if (c_pid == 0) {
        //Execução Myke
        printf("Myke: Eu sou Myke, minha identidade é: %d\n", getpid());
        sleep(tempo);
        printf("Myke: Por favor, não me mate!\n");
        sleep(tempo);
        printf("Myke: Minhas intenções são boas!\n");
        sleep(tempo);
        printf("Myke: Aquilo que eu disse era verdade!\n");
        sleep(tempo);
        printf("Myke: Kate que é o centro da destruição do mundo e de toda essa confusão que está acontecendo aqui!!\n");
        sleep(tempo);
        printf("Myke: Por favor! Não faça isso!!\n");
        sleep(tempo);

        int count = 0;
        struct sigaction sigterm_action;
        memset(&sigterm_action, 0, sizeof(sigterm_action));
        sigterm_action.sa_handler = &Myke;
        sigterm_action.sa_flags = 0;

        if (sigfillset(&sigterm_action.sa_mask) != 0){
            perror("Erro");
            exit(EXIT_FAILURE);
        }

        if (sigaction(SIGTERM, &sigterm_action, NULL) != 0){
            perror("SIGTERM");
            exit(EXIT_FAILURE);
        }

        while (shutdown_flag) {
            count += 1;
        }

        exit(EXIT_SUCCESS);

    } else {
        int ret;

        sleep(30);

        ret = kill(c_pid, SIGTERM);
        if (ret == -1) {
            perror("Não consegui matar o Lindomar");
            exit(EXIT_FAILURE);
        }

        if (waitpid(c_pid, &statusMyke, WUNTRACED | WCONTINUED) == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }
    }
    printf("Narrador: E Jhon finalmente mata Myke..\n");
    sleep(tempo);
    printf("Narrador: A raiz de todo o problema..\n");
    sleep(tempo);
    printf("Jhon: Enfim, esse mundo foi extinto desses filhos ruins!\n");
    sleep(tempo);
    printf("Jhon: Agora poderei descansar em paz!\n");
    sleep(tempo);
    printf("Narrador: Depois de mil e 1 anos a maldição finalmente foi quebrada!\n");
    sleep(tempo);
    printf("Narrador: Com a astúcia de Jhon, foi possível destruir Myke, antes que ele conseguisse matar a real esperança do mundo!\n");
    sleep(tempo);
    printf("Narrador: Essa, que veio como nome de Kate, era a personificação da esperança, a qual mantém a vida no planeta..\n");
    sleep(tempo);
    printf("Narrador: Sem ela, os habitantes não teriam chances de sobrevivência.\n");
    sleep(tempo);
    printf("...\n");
    sleep(tempo);
    printf("...\n");
    sleep(tempo);
    printf("...\n");
    sleep(tempo);
    printf("...\n");
    sleep(tempo);
    printf("---------- FIM ----------\n");
    sleep(tempo);

    return 0;
}