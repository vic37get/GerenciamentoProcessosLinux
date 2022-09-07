#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>



void nascimeno(char pai[]){
    if (fork() == 0){
        printf("Nasci!\n");
    }
    else{
        printf("%s: Meu filho acaba de nascer!\n", pai);
    }
}

void inicio(){
    printf("Narrador: Era uma vez um soldado chamado Jhon\n");
    sleep(4);
    printf("Narrador: Jhon era o soldado mais importante da guarda real, o mesmo tinha habilidades de combate incríveis\n");
    sleep(4);
    printf("Narrador: Era dito que Jhon teria recebido a benção do deus da guerra Ares\n");
    sleep(4);
    printf("Narrador: Jhon sabia que suas habilidades poderiam gerar inveja nos outros guerreiros\n");
}

int main(){
    char jhon[] = "Jhon";
    inicio();
    sleep(4);
    nascimeno(jhon);
    sleep(4);
    return 0;
}