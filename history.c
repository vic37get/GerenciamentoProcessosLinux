#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#define BUFFER 256



void dialogo(char jhon[], int tempo){
    int fd[2]; /* File descriptors pro Pipe*/
    pid_t pid; /* Variável para armazenar o pid*/

    /* Criando nosso Pipe */
    if(pipe(fd)<0) {
        perror("pipe");
    }

    /* Criando o processo irmao*/
    if ((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    /* Processo Pai*/
    if (pid > 0)
    {
        /*No pai, vamos ESCREVER, então vamos fechar a LEITURA do Pipe neste lado*/
        close(fd[0]);

        char str[BUFFER] = "Por que você fez isso Jammie?";
        /* Escrevendo a string no pipe */
        write(fd[1], str, sizeof(str) + 1);
        exit(0);
    }
    /* Processo Filho*/
    else
    {
        char str_recebida[BUFFER];
        /* No filho, vamos ler. Então vamos fechar a entrada de ESCRITA do pipe */
        close(fd[1]);

        /* Lendo o que foi escrito no pipe, e armazenando isso em 'str_recebida' */
        read(fd[0], str_recebida, sizeof(str_recebida));

        printf("\n%s: %s\n", jhon, str_recebida);
        sleep(tempo);
        printf("\nJammie: Eu não tive escolha, me perdoe irmão!\n");
        sleep(tempo);
    }
}

void inicio(int tempo){
    printf("\n-----JHON, O REI DE LINCH----\n");
    sleep(tempo);
    printf("\nNARRADOR: Era uma vez um rei chamado Jhon.\n");
    sleep(tempo);
    printf("\nNARRADOR: Jhon era o rei mais influente da região, além de ser um excelente governador, o mesmo tinha habilidades de combate incríveis\n");
    sleep(tempo);
    printf("\nNARRADOR: Era dito por todos que Jhon teria recebido a benção do Deus da guerra Ares\n");
    sleep(tempo);
    printf("\nNARRADOR: Jhon sabia que suas habilidades de combate e sua condição poderiam gerar inveja nos outros\n");
    sleep(tempo);
}

void historiaIrmao(int tempo){
    printf("\n-----UM IRMÃO INVEJOSO-----\n");
    sleep(tempo);
    printf("\nNARRADOR: Jhon tinha um irmão gêmeo chamado Jammie\n");
    sleep(tempo);
    printf("\nNARRADOR: Jammie era um soldado do exército da cidade, o mesmo era conhecido por todos por sua crueldade sem tamanho\n");
    sleep(tempo);
    printf("\nNARRADOR: Jammie invejava muito Jhon, desde pequeno, fazia de tudo para prejudicá-lo\n");
    sleep(tempo);
}

void trono(int tempo){
    printf("\n-----O HERDEIRO DO TRONO-----\n");
    sleep(tempo);
    printf("\nNARRADOR: 10 anos se passaram e Jhon estava casado, e precisava de alguem para assumir o trono\n");
    sleep(tempo);
    printf("\nNARRADOR: Seu irmão Jammie era o herdeiro do trono, mas Jhon planejava ter seu primeiro filho, que se tornaria seu herdeiro.\n");
    sleep(tempo);
    printf("\nNARRADOR: Um ano depois, nasce o primeiro filho de Jhon, chamado Jimmy.\n");
    sleep(tempo);
}

void emboscada(int tempo, char jhon[]){
    printf("\n-----A EMBOSCADA-----\n");
    sleep(tempo);
    printf("\nNARRADOR: 12 anos se passaram e Jimmy ja tinha 12 anos de idade, Jammie invade o castelo de Jhon com um disfarce de empregado do rei.\n");
    sleep(tempo);
    printf("\nNARRADOR: Jammie tem a intenção de matar Jimmy por envenenamento, colocando veneno em sua comida.\n");
    sleep(tempo);
    printf("\nNARRADOR: Acontece que Jhon ao perceber que Jammie envenenará seu filho, come toda a comida que seria servida ao seu filho, para salvá-lo.\n");
    sleep(tempo);
}

void morteJhon(int tempo){
    printf("\nNARRADOR: E por fim, o rei de LINCH morre envenenado por seu próprio irmão.\n");
    kill(getpid(), SIGSEGV);
}

int main(){
    int tempo = 1;
    char jhon[] = "Jhon";
    char jimmy[] = "Jimmy";
    //inicio(tempo);
    //historiaIrmao(tempo);
    //trono(tempo);
    emboscada(tempo, jhon);
    dialogo(jhon, tempo);
    //morteJhon(tempo); corrigir o kill na história, podendo matar o jhon quando ja estivermos em jimmy, passando o pid de alguma forma.
    char *args[]={"./jimmy",NULL};
    execvp(args[0],args);
    return 0;
}