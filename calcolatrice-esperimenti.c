#include <stdio.h>
//questa versione del codice sorgente presenta sperimentazioni con i tipi

long double input_valore();    
int input_operatore();   
long double potenza(long double base,int esponente);  
int richiesta_terminazione();   //serve a chiedere all'utente se vuole continuare ad usare il programma

long double input_valore(){          
    long double valore; 
    printf("Inserisci valore su cui vuoi effettuare operazioni\n"); 
    scanf(" %Lf",&valore);    
    return valore;
}

int input_operatore(){
    int numero_operatore; // intero corrispondente all'operatore scelto
    do{ 
        printf("Inserisci il codice corrispondente all'operatore desiderato\n"); 
        printf("0 = somma(+)\n");                      
        printf("1 = differenza(-)\n");
        printf("2 = prodotto(*)\n");
        printf("3 = rapporto(/)\n");
        printf("4 = potenza(^)\n");
        scanf("%d",&numero_operatore); 


    
    if(numero_operatore < 0 || numero_operatore>4){
        printf("Operatore non trovato. Inserisci un valore tra 0 e 4.\n");
    }
    //alla fine del blocco viene verificata la condizione;se il numero di operatore non è valido si reitera il while fino a quando l'utente non inserisce un carattere valido
    } while(numero_operatore <0 || numero_operatore >4);

    return numero_operatore;  
    }

long double potenza(long double base, int esponente){ 
    long double risultato = 1.0;   //viene posto il risultato = 1.0 per dare senso al blocco contenuto nel for 
    
    if(esponente == 0){  // se l'esponente è uguale a 0 restituisce 1.0
        return 1.0;
    }

    for(int i = 0; i < esponente; i++){  //il loop è iterato esponente volte
        risultato = risultato*base; //alla fine del loop il risultato sarà uguale alla base moltiplicata per se stessa tante volte quante sono le iterazioni
    }
    
     return risultato;  
}

int richiesta_terminazione(){
    int terminazione; 
    do{
        printf("Desideri eseguire un altro calcolo?\n");
        printf("NO = 0\n");
        printf("SI = 1\n");
    
        scanf(" %d",&terminazione);

        //se è minore di 0 o maggiore di 1 viene stampato un errore e si ripete il blocco di codice
        if(terminazione < 0 || terminazione > 1){
        printf("Carattere non valido. Reinserirlo\n");
        }
    } while(terminazione < 0 || terminazione >1);
    
    return terminazione; 
    }

int main(){
    printf("Questo programma est una calcolatrice\n");
    
    //la variabile di controllo è solo definita, non serve inizializzarla grazie al do-while
    int controllo_loop;
    do{

        
        long double valore1 = input_valore();
        float valore2 = input_valore();
        int operatore = input_operatore();
        switch(operatore){
            case 0:
            //inserite 30 cifre significative dopo la virgola per la stampa dei valori
             printf("%.30f + %.30f = %.30Lf\n",valore1,valore2,valore1 + valore2);
            break;
            
            case 1:
            //inizializzazione variabili ausiliare tramite casting
            int intero1= (int) valore1;
            int intero2= (int) valore2;
            printf("%d - %d = %u\n",intero1,intero2,intero1-intero2);
            break;

            case 2:
            short int breve1 = (short int) valore1;
            short int breve2 = (short int) valore2;
            printf("%d * %d = %d\n",breve1,breve2,breve1*breve2);
            break;

            case 3:
            //if per evitare divisioni per 0(errore di runtime)
            if(valore2 == 0){
                printf("Impossibile dividere per 0\n");
            }else{
                //stampa degli operandi con numeri di cifre significative diverse
                //stampa del risultato della divisione come intero
                printf("%.15Lf / %.9f = %d\n",valore1,valore2,valore1 / valore2);
            }
            break;

            
            //% è definito solo per i tipi interi. In questa versione il % non è supportato
            
            case 4:
            //impiego della notazione esponenziale
            printf("%Lf ^ %f = %Le\n",valore1,valore2,potenza((long double)valore1,valore2)); 
            break;
            
            default: 
            //il default case è superfluo grazie al controllo già effettuato in "input_operatore"
        }
        controllo_loop = richiesta_terminazione(); 

    } while(controllo_loop != 0);

    printf("Programma terminato\n"); //conclusosi il ciclo do-while viene stampato un messagio prima della terminazione del programma
    return 0;
}