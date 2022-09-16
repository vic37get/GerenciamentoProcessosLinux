#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

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

static void pSigHandler(int signo){
    printf("Pareint signum: %d", signo);
}

int Ricardo(void *arg){
    int tempo = 2;
    printf("Ricardo: Opa! Meu nome é Ricardo! Meu PID é: %d\n", getpid());
    sleep(tempo);
    printf("Ricardo: Minhas intenções são dominar esse mundo patético!!\n");
    sleep(tempo);
    printf("Ricardo: Me parece que voce não me deixará dominar mesmo..\n");
    sleep(tempo);
    printf("Ricardo: Então não tenho por quê estar aqui, Adeus!\n");
    sleep(tempo);
    exit(0);
}

int main(int argc, char *argv[]){
    int tempo = 2;
    
    struct sigaction sa;
    sa.sa_handler = pSigHandler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    if (sigaction(SIGCHLD, NULL, &sa) != -1){
        if(sa.sa_handler == SIG_IGN){
            printf("Nao consegui matá-lo\n");
        }
        else if(sa.sa_handler == SIG_DFL){
            printf("Morreu!\n");
        }
    }

    
    //Narrador
    printf("\n--------JOAO II O SEGUNDO CRIADOR DO MUNDO LINCH--------\n\n");
    sleep(tempo);

    // Inicio João II
    printf("João II: Sou João II o segundo criador do mundo LINCH, este é meu PID %d\n", getpid());
    sleep(tempo);
    printf("João II: Não vou cometer os mesmos erros do meu antecessor.\n");
    sleep(tempo);
    printf("João II: Entao vamos lá, criarei meu primeiro habitante, o nome será Ricardo!\n");
    sleep(tempo);
    printf("João II: Para não cometer o mesmo erro de meu pai perguntarei algo para meu habitante antes!\n");
    sleep(tempo);
    printf("João II: Quais suas intenções Ricardo?\n");
    sleep(tempo);
    
    void *pchild_stack = malloc(1024 * 1024);
    
    if ( pchild_stack == NULL ) {
      printf("João II: Ricardo não pode falar.\n");
      sleep(tempo);
      exit(EXIT_FAILURE);
    }

    int pid = clone(&Ricardo, pchild_stack + (1024 * 1024), SIGCHLD, argv[1]);
    if ( pid < 0 ) {
        printf("João II: Eita!!! Ricardo não resistiu ao nascimento!\n");
        sleep(tempo);
        exit(EXIT_FAILURE);
    }
    wait(NULL);
    free(pchild_stack);
    printf("João II: Ricardo morreu de causas naturais\n");
    sleep(tempo);
    printf("João II: Acho que devo tentar outra vez..\n");
    sleep(tempo);
    printf("João II: Vai ver meu segundo habitante não seja tão mal intencionado..\n");
    sleep(tempo);

    return 0;
}