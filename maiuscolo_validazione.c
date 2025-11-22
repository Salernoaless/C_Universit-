#include <stdio.h>

int main(){ 
char lettera;                                                   
   // Ciclo do-while per garantire che la richiesta sia eseguita almeno una volta
   do{                                     
    printf("Inserire carattere minuscolo\n");     //si chiede all'utente una lettera minuscola                                                              
    scanf(" %c", &lettera);                      //viene usato scanf per registrare l'input e memorizzarlo nella variabile lettera, lo spazio azzera lo \n precedente
    
    //se la lettera non è minuscola viene stampato
    if(lettera < 'a' || lettera > 'z'){        
        printf("carattere non valido\n");   
    }

    } while(lettera < 'a' || lettera > 'z');  // il ciclo si ripete fin quando l'utente non inserisce una lettera minuscola             
   
    //se si il ciclo termina allora verrà stampata a video la versione maiuscola di una lettera minuscola  
    printf("%c\n",lettera - ('a'-'A'));   
   }