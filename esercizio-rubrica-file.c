#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 40

struct sContatto{
    char nome[MAX_LEN];
    char cognome[MAX_LEN];
    char telefono[MAX_LEN];
    bool preferito;
};


/*
dato un record contatto ne stampa le informazioni
input: contatto ( struct sContatto)
output: nessuno
effetti collaterali: stampa a video info contatto
*/
void stampaContatto(struct sContatto contatto){
    printf("------------------\n");
    printf("Nome: %s\n",contatto.nome);
    printf("Cognome: %s\n",contatto.cognome);
    printf("Numero: %s\n",contatto.telefono);
    if(contatto.preferito == true){
        printf("Il contatto est tra i preferiti\n");
    }
}

/*
dato il file di testo il contenuto viene stampato sotto forma di
elementi della rubrica. 
input: rubrica (FILE *)
output:nessuno
effetti collaterali: lettura file rubrica,stampa a video elementi della rubrica
*/
void stampaRubrica(FILE * rubrica){
    struct sContatto contattoAttuale;
    while(fscanf(rubrica,"%s %s %s %d",
         contattoAttuale.nome,
         contattoAttuale.cognome,
         contattoAttuale.telefono,
         &contattoAttuale.preferito) == 4){
        stampaContatto(contattoAttuale);
        }
}


/*
l'utente inserisce le info di un contatto, 
se vengono confermate le stampa sul file di testo,
altrimenti le reinserisce
input: rubrica( FILE *)
output: nessuno
effetti collaterali: stampa a video messaggi di inserimento, scrittura su file rubrica
*/

void inserisciContatto(FILE * rubrica){
    struct sContatto nuovoContatto;
    int conferma;

    do{
    printf("Inserire Nome:");
    scanf("%s",nuovoContatto.nome);

    printf("Inserire Cognome:");
    scanf("%s",nuovoContatto.cognome);

    printf("Inserire telefono:");
    scanf("%s",nuovoContatto.telefono);
    printf("Inserire contatto tra preferiti? 1 si 0 no\n");
    scanf("%d",&nuovoContatto.preferito);

    printf("Se si è sicuri delle info contatto?\n");
    printf("0=NO|1=SI\n");
    scanf("%d",&conferma);
    } while ( conferma != 1);

    fprintf(rubrica,"%s\n",nuovoContatto.nome);
    fprintf(rubrica,"%s\n",nuovoContatto.cognome);
    fprintf(rubrica,"%s\n",nuovoContatto.telefono);
    fprintf(rubrica,"%d\n",nuovoContatto.preferito);

    printf("Contatto inserito con successo\n");
}




/*
Programma che gestisce la rubrica
*/
int main(){
    printf("Questo programma permette la gestione di una Rubrica.\n");
    int scelta;
    FILE * rubrica;
    do{
        printf("-------MENU-------\n");
        printf("1-Lettura File Rubrica\n");
        printf("2-Inserimento nuovo contatto\n");
        printf("0-Arresto Programma\n");
        scanf("%d",&scelta);
        switch(scelta){
            case 0:
            break;

            case 1:
            rubrica = fopen("rubrica.txt","r");
            stampaRubrica(rubrica);
            fclose(rubrica);
            break;

            case 2:
            rubrica = fopen("rubrica.txt","a");
            inserisciContatto(rubrica);
            fclose(rubrica);
            break;

            default:
            printf("Operazione non valida!\n");
        }
    }while(scelta != 0);

}