#include <stdio.h>
#include <stdbool.h>                                                          // inclusione della libreria bool che introduce il tipo bool
 
bool carattere_est_minuscolo (char inserito);                                 // essendo di tipo bool restituisce vero o falso 
char in_maiuscolo(char inserito);

bool carattere_est_minuscolo (char inserito){              
     return (inserito >= 'a' && inserito <= 'z');                             //restituisce il valore logico di questa proposizione
}

char in_maiuscolo(char inserito){
    return inserito - ('a'-'A');                                             //la funzione restituisce la lettera in versione maiuscola
}


int main(){ 
    char lettera;          //dichiarazione della variabile lettera
    
    
    // Ciclo do-while per garantisce che la richiesta sia eseguita almeno una volta
    do{                                     
    printf("Inserire carattere minuscolo\n");        //si chiede all'utente una lettera minuscola                                                              
    scanf(" %c", &lettera);                          //viene usato scanf per registrare l'input e memorizzarlo nella variabile lettera, lo spazio azzera lo \n precedente
    
    // il blocco seguente è eseguito solo se la lettera non è minuscola(proprietà varificata dalla funzione)  
    if(!carattere_est_minuscolo(lettera)){        
        //se la lettera non è minuscola viene stampato un errore
        printf("carattere non valido\n");   
    }
    } while(!carattere_est_minuscolo(lettera));          
    
  
    printf("%c\n",in_maiuscolo(lettera));                  //stampa della lettera in versione maiuscola  restituita dalla funzione in_minuscolo
}
