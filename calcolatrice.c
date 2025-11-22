#include <stdio.h>

float input_valore();    //serve  a richiedere i valori agli utenti
int input_operatore();   //serve a far decidere all'utente che operatore usare
float somma(float a,float b);  // somma e stampa il risultato
float differenza(float a,float b);  //fa la differenza e stampa il risultato
float prodotto(float a,float b);   // fa il prodotto e stampa il risultato
double rapporto (double a,double b);  //fa il rapporto e stampa il risultato
double modulo(double a,double b);    //fa il modulo e stampa il risultato


float input_valore(){          
    float val; //dichiaro un intero
    printf("Inserisci valore su cui vuoi effettuare operazioni\n"); // chiedo di inserire valore
    scanf("%f",&val);    //input dell'utente assegna valore  a val
    return val;
}

int input_operatore(){
    int op; // intero corrispondente all'operatore scelto
    printf("Inserisci il codice corrispondente all'operatore desiderato\n"); //chiedo di inserire valore e metto tabella
    printf("0 = somma\n");                      
    printf("1 = differenza\n");
    printf("2 = prodotto\n");
    printf("3 = rapporto\n");
    printf("4 = modulo\n");
    printf("5 = arresto del programma\n");     //input dell'utente assegna valore a op
    scanf("%d",&op);
    return op;
}

float somma(float a, float b){
    float c = a+b;   //inizializzo c come somma di a e b
    printf("%f\n",c);    //stampo c
    return 0;
}
float differenza(float a, float b){ 
    float c = a-b;     // come prima ma con differenza
    printf("%f\n",c);
    return 0;
}

float prodotto(float a, float b){
    float c = a*b;    // come prima ma con prodotto
    printf("%f\n",c);
    return 0;
}

double rapporto(double a, double b){
    double c = a/b;                 // come prima ma con divisione
    printf("%f\n",c);
    return 0;
}

double modulo(double a, double b){   
    double div = a/b; 
    int intera = div;                    // utilizzo un intero e il casting forzato per far "cadere" la parte dopo la virgola
    double risultato = div - intera;     //sottraendo intera a div(intera e virgola) si ottiene solo la parte con la virgola(il modulo)
    printf("%.19f\n",risultato);
    return 0;
}

int main(){
       int op;  //se la variabile è indefinita la condizione di diverso da 5 è considerata vera
    printf("Questo programma è una calcolatrice\n");    
    while(op != 5)   // verifico che non si verifichi la condizione di exit, quando si verifica viene esequito il blocco di codice per op==5 e il loop smette di ripetersi portando alla fine del programma.
    {

    float x = input_valore(); // per prima cosa inizializzo i numeri usando le funzioni da me definite
    float y = input_valore();
    op = input_operatore();
    
    //printf("%d\n",y);    // con di il casting forzato non lo stampa proprio con f stampa 0
   
    if(op == 0){  // catena di if statement per i vari casi
        somma(x,y);
    } else if( op == 1){
        differenza(x,y);     
    } else if(op == 2){
        prodotto(x,y);
    }else if(op == 3){
        rapporto(x,y);
    }else if(op == 4){
        modulo(x,y);
    } else if(op == 5){
        printf("Grazie per averci scelto\n"); // sequenza da stampare prima di uscire
    }else{
         printf("Operatore non valido\n");   //messaggio di errore
    }
    }
}