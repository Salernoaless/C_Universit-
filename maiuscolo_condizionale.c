#include <stdio.h>
int main(){
    char lettera;                             //dichiarazione della variabile lettera e risultato nel tipo char
    char risultato;
    printf("Questo programma trasforma le lettere minuscole in maiuscole.\n") ;
    printf("Inserire una lettera minuscola:\n");            //si chiede all'utente una lettera minuscola
    scanf(" %c", &lettera);                             //viene usato scanf per registrare l'input e memorizzarlo nella variabile lettera
   
     //uso dell'operatore condizionale per verificare che tipo di carattere è stato inserito e di conseguenza assegnare e stampare il risultato
    risultato = (lettera >= 'a' && lettera <= 'z')               
      ?lettera - ('a'-'A')
      :lettera;
      printf("Il carattere risultante est: %c\n",risultato);                       
                     
    
    return 0; 
    
}