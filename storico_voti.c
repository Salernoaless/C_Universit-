#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LUN_MTRCL 5
#define LUN_NOM 51
#define MAX_DIM 100

struct sEsame{
    char matricola_studente[LUN_MTRCL];
    char nome_esame[LUN_NOM];
    int voto;
    bool lode;
};


/*
dato un esame viene restituito un valore booleano
se il voto dell'esame è >=18 e <= 30  e in caso di lode
se il voto è 30
input: struct sEsame esame
output: valido(bool)
effetti collaterali: nessuno
*/
bool valida_esame(struct sEsame daValidare){
    bool valido;
    
    if(daValidare.voto <18 || daValidare.voto > 30){
        valido = false;
    }else{
        if(daValidare.lode == true && daValidare.voto != 30){
            valido = false;
        }else{
            valido = true;
        }
    }
    
    return valido;
}

/*
dato un esame vengono stampate a video le info
input : struct sEsame daStampare
output: nessuno
effetti collaterali: stampa a video info sull'esame
*/

void stampa_esame(struct sEsame daStampare){
    printf("Matricola: %s - Esame: %s - Voto: %d",daStampare.matricola_studente,daStampare.nome_esame,daStampare.voto);
    
    if(daStampare.lode == true){
        printf(" e lode");
    }
    
    printf("\n");
    
    return;
}
/*
stampa tutti gli esami nello storico.
se lo storico è vuoto l'utente è avvisato
input: struct sEsame storico[], int numeroEsami
output: nessuno
effetti collaterali:stampa a video tutti esami o eventuale errore
*/
void stampa_storico(const struct sEsame storico[MAX_DIM], int numeroEsami){
    if(numeroEsami == 0){
        printf("Lo storico è vuoto\n");
        return;
    }
    
    for(int i = 0; i < numeroEsami;i++){
        stampa_esame(storico[i]);
    }
    
    return;
}
/*
l'utente inserisci informazioni su un esame.
se l'esame è valido viene inserito nello storico
e il riempimento aumentato di 1.
se lo storico è pineo l'utente viene avvisato e si 
esce dalla funzione
input: storico[](struct sEsame), int* numeroEsami
output: nessuno
effetti collaterali: stampa a video messaggi per richiedere i dati sull'esame ed eventuali messaggi di errore
*/
void inserisci_esame(struct sEsame storico[MAX_DIM],int * numeroEsami){
    if(*numeroEsami == MAX_DIM){
        printf("Storico Pieno\n");
        return;
    }
    
    struct sEsame daInserire;
    do{
    printf("Inserisci il numero di matricola:");
    scanf("%s",daInserire.matricola_studente);
    
    printf("Inserisci il nome dell'esame  :");
    scanf("%s",daInserire.nome_esame);
    
    printf("Inserisci il voto:");
    scanf("%d",&daInserire.voto);
    
    printf("Inserire lode?(0-NO|1-SI:");
    scanf("%d",&daInserire.lode);
    
    if(valida_esame(daInserire)==  false){
        printf("Esame non Valido. Reinserirlo\n");
    }
    
    }while(valida_esame(daInserire)== false);

    storico[*numeroEsami] = daInserire;
    (*numeroEsami)++;
    printf("Esame Inserito con successo\n");
    return;
}
/* data una matricola inserita dall’utente da tastiera,
   il programma stampa a video la media degli esami sostenuti.
input: struct sEsame storico[ ]
output: nessuno
effetti collaterali: stampa a video media o messaggio errore
*/

void  calcola_media(const struct sEsame storico[MAX_DIM],int numeroEsami,char matricola[LUN_MTRCL]){
    int accumulatore = 0;
    int numeroVoti = 0;
    for(int i = 0; i < numeroEsami; i++){
        if(strcmp(storico[i].matricola_studente,matricola)==0){
            accumulatore = accumulatore + storico[i].voto;
            numeroVoti++;
        }
        
    }
    if(numeroVoti == 0){
        printf("Nessun voto associato a questa matricola\n");
        return;
    }
    
    printf("La media dello studente è:%d\n",(accumulatore)/numeroVoti);
    
}
/*
Stampa voti sopra soglia - dato un voto minimo inserito dall’utente da tastiera,
stampa a video la lista di esami con voto maggiore o uguale a quello inserito.
input : struct sEsame storico, int soglia
output:nessuno
effetti collaterali: stampa voti sopra la soglia
*/
void stampa_sopra_soglia(const struct sEsame storico[MAX_DIM],int numeroEsami, int soglia){
    for(int i = 0; i < numeroEsami;i++){
        if(storico[i].voto >= soglia){
            stampa_esame(storico[i]);
        }
    }
    
    return;
}
/*
cancella voti studente(). Prende in ingresso la struttura
    dati “storico” (ed il suo riempimento)  ed una matricola.
    Elimina dalla struttura dati *tutti* gli esami sostenuti
    dallo studente avente la matricola indicata.
    input: storico[](struct sEsame),int * numeroEsami;char matricola[]
    output: nessuno
    effetti collaterali: stampa a video messaggi su status cancellazione
    */
 void cancella_voti_studente(struct sEsame storico[MAX_DIM],int * numeroEsami,char matricolaDaCancellare[LUN_MTRCL]){
    int controlloFinale = *numeroEsami;
    
    for(int i = 0; i < *numeroEsami; i++){
        if(strcmp(storico[i].matricola_studente,matricolaDaCancellare)== 0){
            for(int j = i ; j <  (*numeroEsami)-1;j++){
                storico[j] = storico[j+1];
            }
            (*numeroEsami)--;
        }
    }
    
    if(controlloFinale == *numeroEsami){
        printf("Non sono stati trovati esami associati a questa matricola\n");
    }else{
        printf("Cancellazione avvenuta con successo!");
        }
    return;    
        
    
}
int main(){
    struct sEsame storico[MAX_DIM];
    storico[0] = (struct sEsame){"1234", "Fondamenti di Informatica", 25, false};
    storico[1] = (struct sEsame){"1235", "Fondamenti di Informatica", 28, false};
    storico[2] = (struct sEsame){"1236", "Fondamenti di Informatica", 30, true};
    storico[3] = (struct sEsame){"1234", "Analisi I", 18, false};
    storico[4] = (struct sEsame){"1236", "Analisi I", 27, false};
    storico[5] = (struct sEsame){"1235", "Fisica I", 28, false};
    storico[6] = (struct sEsame){"1236", "Fisica I", 26, false};
    
    int numeroEsami = 7;
    
    int scelta;
    do{
        printf("-----MENU----\n");
        printf("1- Stampare storico voti\n");
        printf("2- Inserire nuovo esame\n");
        printf("3- Calcolare media\n");
        printf("4- Stampare voti sopra soglia\n");
        printf("5- Cancellare voti utente\n");
        printf("0-Arresto programma\n");
        scanf("%d",&scelta);
        int soglia; //alcuni compilatori danno problemi con variabili dichirate nel corpo di switch
        char matricolaDaUtente[LUN_MTRCL];
        switch(scelta){
            case 0:
            break;
            
            case 1:
                stampa_storico(storico,numeroEsami);
                break;
            
            case 2:
                 inserisci_esame(storico,&numeroEsami);
            break;
            
            case 3:
                 printf("Inserire una matricola:");
                 scanf("%s",matricolaDaUtente);
                 calcola_media(storico,numeroEsami,matricolaDaUtente);
            break;
            
            case 4:
                 printf("Inserire una soglia:");
                 scanf("%d",&soglia);//inserire controlli di input
                 stampa_sopra_soglia(storico,numeroEsami,soglia);
            break;
            
            case 5:
                 printf("Inserire una matricola:");
                 scanf("%s",matricolaDaUtente);
                 cancella_voti_studente(storico,&numeroEsami,matricolaDaUtente);
            break;
            
            deafult:
            printf("Scelta non valida\n");
        }
    }while(scelta != 0);
    
    printf("Programma terminato\n");
    return 0;
}

