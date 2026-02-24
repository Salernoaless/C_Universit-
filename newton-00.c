#include <stdio.h>

long long int fattoriale(int numero){
    long long int risultato = 1;
    
    for(int i = 1;numero >= i; i++){
        risultato = risultato *i;
    }
    return risultato;

}

long long int coeff_binomiale(int n,int k){
    return (fattoriale(n)/(fattoriale(k)*fattoriale(n-k)));
}


void binomio_newton(int n){
    int copia_n = n;
    for(int i=0; i  <= copia_n; i++,n--){

        //casi limite, in cui è anti-estetico
        //stampare la potenza 0-sima
        if( i == 0){
            printf("(A^%d)",n);
        } else if( n == 0){
            printf("+(B^%d)",i);
        } else{
        printf("+ %lld(A^%d)(B^%d)",coeff_binomiale(copia_n,i),n,i);
        }
    }
    printf("\n");
}

int main(){
    char terminazione;

    do{
        int esponente;
        
        printf("Inserire un esponente(non maggiore di 20) per visualizzarne il binomio di newton\n");
        scanf(" %d",&esponente);
        
        if( esponente > 0 && esponente <= 20){
        binomio_newton(esponente);
        } else{
            printf("Non est possibile calcolare il binomio per la potenza inserita\n");
        }

        printf("Desideri calcolare un altro binomio?(y/n)\n");
        scanf(" %c", &terminazione);
    }while(terminazione != 'n');

    printf("Programma Terminato\n");
}