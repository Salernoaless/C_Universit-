#include <stdio.h>
#include <string.h>

#define MAX_LEN 30
#define MAX_DIM 10
#define MAX_SALUTE 100
#define MAX_MAGIA 100
#define MAX_FORZA 100

struct sAvatar{
    char  nome[MAX_LEN];
    int idRazza;
    int salute;
    int forza;
    int magia;
};

void inserisciAvatar(struct sAvatar listaAvatar[MAX_DIM],int *dimensioneAttuale);
void ricercaAvatar(const struct sAvatar listaAvatar[MAX_DIM],int dimensioneAttuale, char nomeDaStampare[]);
void stampaListaAvatar(const struct sAvatar listaAvatar[MAX_DIM],int dimensioneAttuale);
void cancellaAvatar(struct sAvatar listaAvatar[MAX_DIM],int *dimensioneAttuale,char nomeCancellare[]);
void rimuoviNewline(char *stringa);
int leggiInteroLimitato(const char *richiesta,int min, int max);
int trovaIndice(const struct sAvatar listaAvatar[MAX_DIM], int dimensioneAttuale, char nomeCercato[]);


//restituisce la posizione di un avatar nell'array 
//in base allla corrispondenza del suo nome 
int trovaIndice(const struct sAvatar listaAvatar[MAX_DIM], int dimensioneAttuale, char nomeCercato[]){
    for(int i = 0; i < dimensioneAttuale;i++){
        if(strcmp(listaAvatar[i].nome,nomeCercato)==0){
            printf(" %s trovato!\n",nomeCercato);
            return i;
        }
    } 
    printf("Non esiste un Avatar con questo nome\n");
    return -1;
}


int leggiInteroLimitato(const char *richiesta,int min, int max){
    int valoreLetto;
    
    do{
        printf("%s (%d-%d):\n",richiesta,min,max);
        scanf("%d",&valoreLetto);

        while(getchar() != '\n');

        if( valoreLetto <min || valoreLetto > max){
            printf("Valore non Valido. Ritentare\n");
        }
    }while( valoreLetto <min || valoreLetto > max);

    return valoreLetto;
}

void rimuoviNewline(char *stringa){
    int lunghezza = strlen(stringa);
    if(lunghezza > 0 && stringa[lunghezza-1] =='\n'){
        stringa[lunghezza-1] = '\0';
    }
}

void inserisciAvatar(struct sAvatar listaAvatar[MAX_DIM],int *dimensioneAttuale){
    
    if(*dimensioneAttuale == MAX_DIM){
        printf("Non è possibile inserire un nuovo personaggio. Provare a cancellarne uno vecchio\n");
        return;
    }


    //impiego una variabile indice su cui
    //non è necessario impiegare la dereferenziazione
    //per migliorare la leggibilità
    int i = *dimensioneAttuale;
    printf("Inserire nome del personaggio\n");
    fgets(listaAvatar[i].nome,MAX_LEN, stdin);
    rimuoviNewline(listaAvatar[i].nome);

    listaAvatar[i].idRazza = leggiInteroLimitato("Inserire identificativo razza(0-UMANO|1-ELFO|2-NANO|3-ORCO)",0,3);
    listaAvatar[i].salute = leggiInteroLimitato("Inserire punti salute:",0,MAX_SALUTE);
    listaAvatar[i].forza = leggiInteroLimitato("Inserire punti forza:",0,MAX_FORZA);
    listaAvatar[i].magia = leggiInteroLimitato("Inserire punti magia:",0,MAX_MAGIA);

    printf("Avatar Inserito con successo.\n");
    
    (*dimensioneAttuale)++;
  
    return;

}

void stampaListaAvatar(const struct sAvatar listaAvatar[MAX_DIM],int dimensioneAttuale){
    if(dimensioneAttuale == 0){
        printf("Non ci sono avatar\n");
        return;
    }
    
    
    for(int i = 0; i < dimensioneAttuale;i++){
        printf("%s (id razza: %d), salute:%d, forza:%d, magia: %d\n",listaAvatar[i].nome,listaAvatar[i].idRazza,listaAvatar[i].salute,listaAvatar[i].forza,listaAvatar[i].magia);
    }

    return;
}

void ricercaAvatar(const struct sAvatar listaAvatar[MAX_DIM],int dimensioneAttuale, char nomeCercato[]){
    int posizione = trovaIndice(listaAvatar,dimensioneAttuale,nomeCercato);
    if( posizione != -1){
        printf("%s (id razza: %d), salute:%d, forza:%d, magia: %d\n",listaAvatar[posizione].nome,listaAvatar[posizione].idRazza,listaAvatar[posizione].salute,listaAvatar[posizione].forza,listaAvatar[posizione].magia);
        return;
    }
}

void cancellaAvatar(struct sAvatar listaAvatar[MAX_DIM],int *dimensioneAttuale,char nomeCancellare[]){
    int posizione = trovaIndice(listaAvatar,*dimensioneAttuale,nomeCancellare);
    if( posizione != -1){
     for(int i = posizione; i < *dimensioneAttuale-1 ;i++){
                listaAvatar[i] = listaAvatar[i+1];
            }
            printf("Avatar Eliminato con successo\n");
            (*dimensioneAttuale)--;
            return;
    }
}


int main(){
    struct sAvatar personaggi[MAX_DIM];
    int dimensioneElenco = 0;

    printf("Questo programma permette di modificare avatar in un gioco di ruolo\n");

    int scelta;
    do{
        printf("-----MENU----- \n");
        printf("1 - Inserisci un Avatar\n");
        printf("2 - Ricerca un Avatar\n");
        printf("3 - Cancella un Avatar\n");
        printf("4 - Visualizza tutti gli Avatar\n");
        printf("0 - Termina il programma\n");
        scelta = leggiInteroLimitato("Inserire numero operazione desiderata",0,4);
        switch(scelta){
            case 0:
            break;

            case 1:
            inserisciAvatar(personaggi,&dimensioneElenco);
            break;

            case 2:
            char nomeCercato[MAX_LEN];

            printf("Inserire nome dell'avatar cercato:");

            fgets(nomeCercato,MAX_LEN,stdin);
            rimuoviNewline(nomeCercato);

            ricercaAvatar(personaggi,dimensioneElenco,nomeCercato);
            break;

            case 3:
            char nomeCancellare[MAX_LEN];
            
            printf("Inserire nome dell'avatar da cancellare:");
            
            fgets(nomeCancellare,MAX_LEN, stdin);
            rimuoviNewline(nomeCancellare);

            cancellaAvatar(personaggi,&dimensioneElenco,nomeCancellare);
            break;

            case 4:
            stampaListaAvatar(personaggi,dimensioneElenco);
            break;

            default:
            printf("Input non valido\n");
            }
    }while(scelta != 0);
    printf("Programma terminato\n");
}