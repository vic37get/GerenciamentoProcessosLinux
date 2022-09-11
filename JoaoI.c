#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#define MSGSIZE 128



int main(){
    int tempo = 2;
    pid_t pid;
    pid_t pidC;
    int status;
    char inbuf[MSGSIZE];
    int p[2], p1[2], p2[2], p3[2];

    if(pipe(p) < 0){exit(1);}
    if(pipe(p1) < 0){exit(1);}
    if(pipe(p2) < 0){exit(1);}
    if(pipe(p3) < 0){exit(1);}

    printf("\n--------JOAO I O PRIMEIRO CRIADOR DO MUNDO LINCH--------\n\n");
    //Inicio João
    printf("João: Sou João o criador do mundo LINCH, este é meu PID %d\n", getpid());
    sleep(tempo);
    printf("João: Criarei o primeiro habitante, o nome dele será Junior\n");
    sleep(tempo);

    if ((pid = fork()) < 0){
        perror("João: Junior não resistiu ao nascimento");
        sleep(tempo);
        exit(1);
    }
    if (pid == 0){
        //Execução Junior
        char* msg1 = "Junior: Bem vinda a familia irmãzinha Joana!";
        write(p[1], msg1, MSGSIZE);
        printf("Junior: Eu nasci, sou o Junior e meu PID é: %d\n", getpid());
        sleep(tempo);
        read(p1[0], inbuf, MSGSIZE);
        printf("%s\n", inbuf);
        sleep(tempo);
        read(p2[0], inbuf, MSGSIZE);
        printf("%s\n", inbuf);
        sleep(tempo);
        char* msg4 = "Junior: Joana morreu por causas naturais, que triste! hahaha!\nJunior: Agora sou seu filho predileto certo?\n";
        write(p3[1], msg4, MSGSIZE);
    }

    else{
        //Execução Joao
        printf("João: O habitante Junior foi criado!\n");
        sleep(tempo);
        printf("João: Agora quero criar a irmã de Junior, o nome dela será Joana!\n");
        sleep(tempo);

        if ((pidC = fork()) < 0){
            perror("João: Joana não resistiu ao parto\n");
            sleep(tempo);
            exit(1);
        }

        if (pidC == 0){
            //Execução Joana
            read(p[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
            sleep(tempo);
            char* msg2 = "Joana: Obrigado irmão João!";
            write(p1[1], msg2, MSGSIZE);
            printf("Joana: Não estou me sentindo muito bem!\n");
            sleep(tempo);
            printf("Joana: Acho que estou morrendo...\n");
            sleep(tempo);
        }
        else{
            //Execução João
            waitpid(pidC, &status, 0);
            printf("João: Joana está ai?\n");
            sleep(tempo);

            char* msg3 = "João: O que voce fez com ela Junior?\n";
            write(p2[1], msg3, MSGSIZE);
            waitpid(pid, &status, 0);
            
            read(p3[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
            sleep(tempo);
            printf("João: E voce ri da sua irmã?\n");
            sleep(tempo);

            printf("João: Acho que falhei com o Junior, devo mata-lo e começar esse mundo de novo!\n");
            sleep(tempo);
            printf("João: Adeus Junior!!!\n");
            sleep(tempo);
            kill(pid, SIGSEGV);

            printf("João: ...\n");
            sleep(tempo);
            printf("João: ...\n");
            sleep(tempo);
            printf("João: É..\n");
            sleep(tempo);
            printf("João: Acho que falhei como criador, devo dar essa oportunidade a outro.\n");
            sleep(tempo);
            printf("João: Vai ver eu nao sirvo pra isso..\n");
            sleep(tempo);
            printf("João: Me sacrificarei para que João II possa viver e construir um mundo melhor..\n");
            sleep(tempo);
            printf("João: Adeus mundo!!\n");
            sleep(tempo);

            char *args[]={"./JoaoII",NULL};
            execvp(args[0],args);
        }
    }

    return 0;
}