#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DIM 40

//conviene astrarre il più possibile
//metto un tipo definito dall'utente
typedef int element; 

struct pila{
    element v[MAX_DIM];
    int sp;
};

typedef struct pila * ppila;

ppila newStack(){
    ppila nuova = malloc(sizeof(struct pila));
    if(nuova == NULL){
        return nuova;
    }
    nuova->sp = 0;
    return nuova;
}

void showStack(ppila daLeggere){
    printf("Pila(da ultimo inserito):\n");
    for(int i = (daLeggere->sp)-1; i >= 0;i-- ){
        printf("[%d]\n",daLeggere->v[i]);
    }

    printf("Fine lettura\n");
}

bool pushStack(ppila pila, element daInserire){
    if(pila->sp >= MAX_DIM){
        return false;
    }else{
        pila->v[pila->sp] = daInserire;
        pila->sp++;
        return true;
    }
}

bool popStack(ppila pila, element * inUscita){
    if(pila->sp == 0){
        return false;
    }else{
        *inUscita = pila->v[(pila->sp)-1];
        pila->sp--;
        return true;
    }
}

bool topStack(ppila pila, element * inUscita){
    if(pila->sp == 0){
        return false;
    }else{
        *inUscita = pila->v[(pila->sp)-1];
        return true;
    }
}

bool isFullStack(ppila pila){
    if(pila->sp == MAX_DIM){
        return true;
    }else{
        return false;
    }
}


bool isEmptyStack(ppila pila){
    if(pila->sp == 0){
        return true;
    }else{
        return false;
    }
}

void deleteStack(ppila pila){
    if(pila != NULL){
        free(pila);
    }
    
    return;
}

int main(){
    ppila miaPila = newStack();

    if(isEmptyStack(miaPila)){
        printf("La pila è vuota\n");
    }
    for(int i = 0; i <= MAX_DIM;i++){
    printf("%d\n",pushStack(miaPila,i));
    }

    
    if(isEmptyStack(miaPila)){
        printf("La pila è vuota\n");
    }

    showStack(miaPila);

    if(isFullStack(miaPila)){
        printf("La pila è piena\n");
    }
    
    int x;
    while(popStack(miaPila,&x)){
        
    if(isFullStack(miaPila)){
        printf("La pila è piena\n");
    }
        //printf("%d\n",x);
    }

    showStack(miaPila);

    return 0;
}