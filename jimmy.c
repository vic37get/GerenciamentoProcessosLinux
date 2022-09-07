#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void InicioJimmy(int tempo){
    printf("\n-----O NASCIMENTO DE JIMMY----\n");
    sleep(tempo);
    printf("\nNARRADOR: Jimmy nasce e desperta o interesse de Jammie.\n");
    sleep(tempo);
    printf("\nNARRADOR: Jammie sabe que se Jimmy crescer, o mesmo o substituirá na ascenção ao trono\n");
    sleep(tempo);
    printf("\nNARRADOR: Jammie começa a traçar planos para que isso não aconteça\n");
}

int main(){
    int tempo = 1;
    InicioJimmy(tempo);
    return 0;
}