#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#define MSGSIZE 128

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


int main(){
    int tempo = 5;
    pid_t pid;
    pid_t pidC;
    int status;
    char inbuf[MSGSIZE];
    int p[2], p1[2], p2[2], p3[2];

    if(pipe(p) < 0){exit(1);}
    if(pipe(p1) < 0){exit(1);}
    if(pipe(p2) < 0){exit(1);}
    if(pipe(p3) < 0){exit(1);}

    //Narrador
    printf("\n--------O MUNDO LINCH--------\n\n");
    printf("Narrador: Há milhões de anos atrás se dava início ao mundo LINCH.\n");
    sleep(tempo);
    printf("Narrador: Um mundo totalmente mágico e que contava com uma terrível maldição.\n");
    sleep(tempo);
    printf("Narrador: Esse mundo era composto por ciclos, em que esses ciclos sempre se repetiam... (É claro!).\n");
    sleep(tempo);
    printf("Narrador: Ele sempre começava com um único habitante que dava vida aos outros de maneira mágica.\n");
    sleep(tempo);
    printf("Narrador: Mas sempre suas criações acabavam de maneira desastrosa, com seus filhos se matando ou o pai matando os próprios filhos.\n");
    sleep(tempo);
    printf("Narrador: Atualmente o planeta LINCH se encontra no seu ciclo de número mil.\n");
    sleep(tempo);
    printf("Narrador: E o habitante mestre, criador do mundo, dessa vez se chama Garry.\n");
    sleep(tempo);
    printf("\n-------- Garry CRIADOR ATUAL DO MUNDO LINCH --------\n\n");

    //Inicio Garry
    printf("Garry: Sou Garry o criador do mundo LINCH, esta é a minha identidade - %d\n", getpid());
    sleep(tempo);
    printf("Garry: Esse mundo está bastante solitário, já estou há mais de 400 anos aqui sem nenhuma companhia.\n");
    sleep(tempo);
    printf("Narrador: Garry se dirigia á floresta principal neste exato momento..\n");
    sleep(tempo);
    printf("Narrador: Garry estava completamente maravilhado com tudo o que via na floresta principal..\n");
    sleep(tempo);
    printf("Narrador: Ele mal sabia que ali se encontrava o poder central do planeta..\n");
    sleep(tempo);
    printf("Narrador: Tal poder poderia ditar o que aconteceria daqui pra frente nesse mundo..\n");
    sleep(tempo);
    printf("Garry: Olha que legal essa árvore!\n");
    sleep(tempo);
    printf("Garry: O que tem de errado com essa raiz?\n");
    sleep(tempo);
    printf("Narrador: A raiz pela qual Garry estava vislumbrando era a raiz da vida, de onde nasciam todas as ramificações..\n");
    sleep(tempo);
    printf("Narrador: Eis que Garry descobre que ao remover raizes e as plantar por volta da árvore, ele pode criar novos habitantes..\n");
    sleep(tempo);
    printf("Garry: Acho que entendi! Se eu plantar um pequeno pedaço dessa raiz aqui, posso gerar um novo habitante para meu mundo\n");
    sleep(tempo);
    printf("Garry: Assim não ficarei solitário nesse mundo tão vasto..\n");
    sleep(tempo);
    printf("Garry: Sendo assim, criarei o segundo habitante deste mundo, o nome dele será Myke!!\n");
    sleep(tempo);

    if ((pid = fork()) < 0){
        perror("Garry: Myke não resistiu ao nascimento, que pena!\n");
        sleep(tempo);
        exit(1);
    }
    if (pid == 0){
        //Execução Myke
        char* msg1 = "Myke: Bem vinda ao nosso mundo fantástico Kate!";
        write(p[1], msg1, MSGSIZE);
        printf("Myke: onde estou?\n");
        sleep(tempo);
        printf("Myke: Eu morri e vim pra cá? Não sei o que aconteceu\n");
        sleep(tempo);
        printf("Myke: Minha cabeça está doendo muito!!\n");
        sleep(tempo);
        printf("Myke: Ah! Oi Garry! Minha identidade é: %d\n", getpid());
        sleep(tempo);
        read(p1[0], inbuf, MSGSIZE);
        printf("%s\n", inbuf);
        sleep(tempo);
        read(p2[0], inbuf, MSGSIZE);
        printf("%s\n", inbuf);
        sleep(tempo);
        char* msg4 = "Myke: Kate é o centro da destruição, ela vem ao mundo com essa missão, destruir tudo e todos!\nMyke: Agora restam nós dois, vamos acabar com essa maldição! Me escute!\n";
        write(p3[1], msg4, MSGSIZE);
    }

    else{
        //Execução Garry
        printf("Garry: Veja só!\n");
        sleep(tempo);
        printf("Garry: Funciona mesmo!\n");
        sleep(tempo);
        printf("Garry: O segundo habitante foi criado!! Viva!!\n");
        sleep(tempo);
        printf("Garry: Que bom ter uma companhia para desbravar esse mundo!\n");
        sleep(tempo);
        printf("Garry: Mykael, vou criar uma habitante!\n");
        sleep(tempo);
        printf("Garry: Acho que quanto mais habitantes tivermos nesse mundo, melhor ele será!\n");
        sleep(tempo);
        printf("Garry: Darei início agora á criação da mais nova habitante! O nome dela será Kate\n");
        sleep(tempo);

        if ((pidC = fork()) < 0){
            perror("Garry: Kate não resistiu ao nascimento! Que pena!\n");
            sleep(tempo);
            exit(1);
        }

        if (pidC == 0){
            //Execução Kate
            printf("Kate: Meu nome é Kate, e minha identidade é: %d\n", getpid());
            sleep(tempo);
            read(p[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
            sleep(tempo);
            char* msg2 = "Kate: Muito obrigada! Desejo que sejamos muito felizes aqui!\n";
            write(p1[1], msg2, MSGSIZE);
            printf("Kate: Tenho vagas lembranças deste lugar..\n");
            sleep(tempo);
            printf("Kate: Estou lembrando dos seus rostos, acho que são Garry e Myke...\n");
            sleep(tempo);
            printf("Kate: Agora minha memória está se recuperando, esse é o mundo LINCH...\n");
            sleep(tempo);
            printf("Kate: Um mundo em que sempre se autodestrói por seu próprio criador...\n");
            sleep(tempo);
            printf("Kate: O que? O que voces estão fazendo comigo?...\n");
            sleep(tempo);
            printf("Kate: Estou perdendo meus movimentos...\n");
            sleep(tempo);
            printf("Kate: Não acredito...\n");
            sleep(tempo);
            printf("Kate: De novo não...\n");
            sleep(tempo);
        }
        else{
            //Execução Garry
            waitpid(pidC, &status, 0);
            printf("Garry: Kate??\n");
            sleep(tempo);
            printf("Garry: Kate???\n");
            sleep(tempo);
            printf("Garry: Me responda!!\n");
            sleep(tempo);

            char* msg3 = "Garry: O que você fez com ela Myke?\n";
            write(p2[1], msg3, MSGSIZE);
            waitpid(pid, &status, 0);
            
            read(p3[0], inbuf, MSGSIZE);
            printf("%s\n", inbuf);
            sleep(tempo);
            printf("Garry: E voce acha que eu vou acreditar nisso?\n");
            sleep(tempo);
            printf("Garry: Por que você matou nossa segunda habitante??\n");
            sleep(tempo);

            printf("Garry: Acho que falhei com o Myke...\n");
            sleep(tempo);
            printf("Garry: Eu não deveria ter perdido a atenção nele enquanto vislumbrava o nascimento de outro habitante...\n");
            sleep(tempo);
            printf("Garry: Receio que meu próximo habitante possa ser morto por ele novamente...\n");
            sleep(tempo);
            printf("Garry: Sendo assim, devo matá-lo, e dar fim a essa maldição que ele tanto diz...\n");
            sleep(tempo);
            printf("Garry: Me desculpe Myke, eu falhei com voce e a Kate...\n");
            sleep(tempo);
            printf("Garry: Adeus Myke!!!\n");
            sleep(tempo);
            kill(pid, SIGSEGV);

            printf("Narrador: Garry matou Myke...\n");
            sleep(tempo);
            printf("Narrador: Com a morte de Kate e Myke, ele continua sozinho no mundo novamente...\n");
            sleep(tempo);
            printf("Garry: ...\n");
            sleep(tempo);
            printf("Garry: ...\n");
            sleep(tempo);
            printf("Garry: É..\n");
            sleep(tempo);
            printf("Garry: Acho que falhei como criador, devo dar essa oportunidade a outro.\n");
            sleep(tempo);
            printf("Garry: Achei que criando novos habitantes esse mundo seria muito melhor.\n");
            sleep(tempo);
            printf("Garry: E no final resta isso, eu e minha solidão..\n");
            sleep(tempo);
            printf("Garry: Entao me pergunto, por que eu nasci?..\n");
            sleep(tempo);
            printf("Garry: Se a Kate estiver certa e tudo isso se repetir, qual o sentido da minha vida?\n");
            sleep(tempo);
            printf("Garry: Ficar a eternidade sofrendo? Vagando sozinho por aí?\n");
            sleep(tempo);
            printf("Garry: Vai ver eu nao sirvo pra isso..\n");
            sleep(tempo);
            printf("Garry: Vai ver eu nem deveria ter nascido..\n");
            sleep(tempo);
            printf("Garry: Me sacrificarei para que possa dar vida á Jhon, espero que ele possa viver e construir um mundo melhor..\n");
            sleep(tempo);
            printf("Garry: Adeus mundo!!\n");
            sleep(tempo);
            printf("Narrador: E Garry morreu!\n");
            sleep(tempo);
            printf("Narrador: Garry se matou, se afogando no lago principal do mundo LINCH!\n");
            sleep(tempo);
            printf("Narrador: Com a recente morte de Garry, o ciclo se repete, então Jhon será o novo criador do mundo LINCH, o mundo de número 1001.\n");
            sleep(tempo);
            char *args[]={"./Jhon",NULL};
            execvp(args[0],args);
        }
    }

    return 0;
}