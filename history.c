#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#define MSGSIZE 32



int main(){
    pid_t pid;
    pid_t pidC;
    int status;
    char inbuf[MSGSIZE];
    int p[2], p1[2];
    if(pipe(p) < 0){exit(1);}
    if(pipe(p1) < 0){exit(1);}

    printf("Sou João e esse é meu PID %d\n", getpid());
    printf("Vou criar o Junior\n");

    if ((pid = fork()) < 0){
        perror("Junior não resistiu ao parto");
        exit(1);
    }
    if (pid == 0){
        //Execução Junior
        char* msg1 = "Bem vinda a familia irmã Joana!";
        write(p[1], msg1, MSGSIZE);
        printf("Eu nasci, sou o Junior e meu PID é: %d\n", getpid());
        read(p1[0], inbuf, MSGSIZE);
        printf("%s\n", inbuf);
        
    }
    else{
        //Execução Joao
        printf("O Junior foi criado!\n");
        printf("Agora quero criar a irmã de Junior, Joana\n");
        printf("Quando nascer me responda Junior, qual seu PID?\n");

        if ((pidC = fork()) < 0){
            perror("Joana não resistiu ao parto\n");
            exit(1);
        }

        if (pidC == 0){
            //Execução Joana
            read(p[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
            char* msg2 = "Obrigado irmão João!";
            write(p1[1], msg2, MSGSIZE);
            printf("Não estou me sentindo muito bem!\n");
            exit(0);
        }
        else{
            //Execução João
            waitpid(pidC, &status, 0);
            printf("Joana está ai?\n");
            printf("Joana morreu por causas naturais, que triste!\n");
            //printf("E agora? o que será de mim?\n");
        }
    }

    return 0;
}