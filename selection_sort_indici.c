#include <stdio.h>
void stampaArray(const int *arr, int dimensione){
    for(int i = 0; i < dimensione; i++){
        printf(" %d ",*(arr+i));
    }printf(" \n");
}
void estraiIndici(int indici[],int dimensione){
    for(int i = 0; i < dimensione; i++){
        indici[i] = i;
    }
    
}
void scambia(int *a, int *b){
    int appoggio = *a;
    *a = *b;
    *b = appoggio;
    return;
}
int trovaMin(int arr[],int indici[],int inizio, int fine){
    int indice_min;
    for(int i = inizio; i < fine; i++){
        if(i == inizio || arr[indici[i]] < arr[indici[indice_min]]){
            indice_min = i;
        }
    }
    return indice_min;
}
void selection_sort_indici(int arr[],int dimensione, int indici[dimensione]){
 
    estraiIndici(indici,dimensione);
    for(int i = 0; i < dimensione-1; i++){
    int posizioneMinimo = trovaMin(arr,indici,i,dimensione);
    scambia(&indici[posizioneMinimo],&indici[i]);
    }
    
    stampaArray(indici, dimensione);
}

int stampaOrdinato(int arr[], int indici[], int dimensione){
    for(int i = 0; i < dimensione; i++){
        printf(" %d ",arr[indici[i]]);
    }
    printf("\n");
}
int main(){
    int vettore[6] = {6,5,4,3,2,1};
    int indici[6];
    stampaArray(vettore,6);
    selection_sort_indici(vettore,6,indici);
    stampaArray(vettore,6);
    stampaOrdinato(vettore,indici,6);

}