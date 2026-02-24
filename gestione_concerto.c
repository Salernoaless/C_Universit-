#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_DIM 10
#define NOM_LEN 101
#define MIN_DUR 30
#define MAX_DUR 120
#define SOGLIA_STAR 1000

struct sArtista {
    char nomeArtista[NOM_LEN];
    float onorarioTotale;
    int durataEsibizione;
};

enum statusMenu {
    TERMINARE,
    INSERIRE,
    STAMPARE_LISTA,
    STAMPARE_CON_INIZIALE
};


/*
artistaDaUtente: permette l'inserimento delle informazioni su un artista da parte dell'utente
input: nessuno
output: struct sArtista nuovoArtista;
input/output:VOID
effetti collaterali: stampa a video messaggi inserimento,  lettura stream tastiera
*/
struct sArtista artistaDaUtente(){
    struct sArtista nuovoArtista;
    
    printf("Inserire nome dell'artista:");
    getchar();
    fgets(nuovoArtista.nomeArtista,NOM_LEN,stdin);
    nuovoArtista.nomeArtista[strcspn(nuovoArtista.nomeArtista,"\n")]='\0';

    printf("Inserire onorario Totale dell'artista:");
    scanf("%f",&nuovoArtista.onorarioTotale);
    

    do{
    printf("Inserire durata esibizione dell'artista:");
    scanf("%d",&nuovoArtista.durataEsibizione);

    if(nuovoArtista.durataEsibizione < MIN_DUR || nuovoArtista.durataEsibizione > MAX_DUR){
        printf("Durata non valida. Ritentare\n");
    }

    }while(nuovoArtista.durataEsibizione < MIN_DUR || nuovoArtista.durataEsibizione > MAX_DUR);
    
    return nuovoArtista;
}
/*
AggiungiArtista: permette di aggiungere un artista all'elenco degli artisti
input: dimensione massima dell'elenco
output:void
in/out:listaArtisti(struct sArtista *), numeroArtisti (int*) 
effetti collaterali: acquisizione da tastiera, stampa a video messaggi di errore/conferma
*/
void aggiungiArtista(struct sArtista * listaArtisti, int * numeroArtisti, int dimensioneMassima){
        if(*numeroArtisti >= dimensioneMassima){
            printf("ERRORE:lista piena\n");
            return;
        }

        listaArtisti[*numeroArtisti] = artistaDaUtente();
        printf("Artista inserito con successo!\n");
        (*numeroArtisti)++;
        return;
    
}
/*
stampaArtista: dato un artista ne vengono stampate a video le informazioni base
input: struct sArtista daStampare
output: nessuno
in/out:nessuno
effetti collateralI: stampa a video info su artista
*/
void stampaArtista(struct sArtista daStampare){
    printf("nome:%s - durata:%d min - onorario: %.2f eur\n",daStampare.nomeArtista,daStampare.durataEsibizione,daStampare.onorarioTotale);
    return;
}
/*
stampaElencoCompleto: stampa elenco tutti artisti
input: array artisti(puntatore primo elemento),numArtisti
output:NULL
input/output:NULL
effetti collaterali: stampa a video dell'elenco
*/
void stampaElencoCompleto(const struct sArtista * listaArtisti, int numeroArtisti){
    if(numeroArtisti == 0){
        printf("Lista Vuota\n");
        return;
    }

    for(int i = 0; i < numeroArtisti; i++){
        stampaArtista(listaArtisti[i]);
    }
    return;
}


/*
 calcola onorarioPerOra()
 dato un artista viene calcolato il suo onorario per ora
 input: artista(struct sArtista)
 output: OnorarioPerORa(float)
 effetti collaterali: nessuno
*/
float calcolaOnorarioPerOra(struct sArtista daCalcolare){
    return daCalcolare.onorarioTotale/(daCalcolare.durataEsibizione/60.0);
}
/*
data una lista artisti ed un iniziale vvengono stampati tutti gli artisti
che iniziano con quell'iniziale preceduti dalla stringa "STAR" se hanno
un onorario maggiore-uguale di 1000/ore
input: lista di Artisti(struct sArtista *), numero Artisti presenti,iniziale,(char)
output: nessuno
in/out: NULL
effetti collaterali: stampa a video messaggi errore o info su artisti che soddisfano requisiti
*/

void stampaListaArtistiConIniziale(struct sArtista * listaArtisti,int numeroArtisti, char iniziale){
    for(int i = 0; i < numeroArtisti;i++){
        if(toupper(listaArtisti[i].nomeArtista[0]) == iniziale){
            if(calcolaOnorarioPerOra(listaArtisti[i]) >= SOGLIA_STAR){
                printf("STAR ");
            }
            stampaArtista(listaArtisti[i]);
        }
    }
}

void stampaMenu(){
         printf("-----MENU-----\n");
        printf("0 - Arresto Programma\n");
        printf("1 - Inserimento nuovo Artista\n");
        printf("2 - Stampa Lista Artisti\n");
        printf("3 - Stampa Artisti che iniziano con una lettera\n");
        return;
}
int main(){
    int dimensioneMassima = MAX_DIM;
    struct sArtista listaArtisti[dimensioneMassima];
    int numeroArtisti = 0;
    
    enum statusMenu statoAttuale;
    do{

        char iniziale; 
        //lo dichiaro qui poichè alcuni compilatori hanno problemi se
        //viene dichiarato in un blocco switch
        stampaMenu();
        scanf("%d",&statoAttuale);
        
        switch(statoAttuale){
            case TERMINARE:
            break;

            case INSERIRE:
            aggiungiArtista(listaArtisti,&numeroArtisti,dimensioneMassima);
            break;

            case STAMPARE_LISTA:
            stampaElencoCompleto(listaArtisti,numeroArtisti);
            break;

            case STAMPARE_CON_INIZIALE:
            printf("Inserire una lettera maiuscola:");
            scanf(" %c",&iniziale);
            iniziale = toupper(iniziale);
            stampaListaArtistiConIniziale(listaArtisti,numeroArtisti,iniziale);
            break;
        }

    }while (statoAttuale != TERMINARE);
    printf("Programma terminato\n");
}