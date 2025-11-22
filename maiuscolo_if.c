#include <stdio.h>
int main(){
    char lettera;                                                //dichiarazione di variabile lettera  e risulato
    char risultato;                                  
    printf("Inserire una lettera minuscola:\n");    
    scanf(" %c", &lettera);                                       //viene usato scanf per registrare l'input e memorizzarlo nella variabile lettera
    
    // un if statement è usato per verificare che la lettera sia minuscola
    if(lettera >= 'a' && lettera <= 'z'){            
        risultato = lettera - ('a'-'A');                         // si modifica il valore dell risultato assegnandogli il valore della maiuscola corrispondente
    } else{                                                   
        risultato = lettera;                                     // la lettera è già maiuscola quindi il risultato è la lettera di partenza
    } 

    printf("il risultato est:%c\n",risultato);                     // il risultato è stampato a video
    return 0;
}