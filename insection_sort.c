#include <stdio.h>

void scambia(int *a, int *b);
int idx_minimo(int v[],int inizio,int fine);
void stampaArray(const int *arr, int dimensione);

void scambia(int *a, int *b){
    int appoggio = *a;
    *a = *b;
    *b = appoggio;
    return;
}


void stampaArray(const int *arr, int dimensione){
    for(int i = 0; i < dimensione; i++){
        printf(" %d ",*(arr+i));
    }printf(" \n");
}

int posizioneInserimento(int arr[], int indiceAnalizzato){
    for(int i = 0; i <= indiceAnalizzato;i++){
        if(arr[indiceAnalizzato]<=arr[i]){
            return i;
        }
    }
}

void scalaDestra(int arr[],int inizio,int fine){
    for(int i =fine; i >= inizio;i--){
        arr[i] = arr[i-1];
    }
}

int insertionSort(int arr[],int dimensione){
    for(int i = 1; i < dimensione; i++){
    int daInserire = arr[i];
    int pos = posizioneInserimento(arr,i);
    scalaDestra(arr,pos,i);
    arr[pos] = daInserire;
    }

}
int main(){
    int vettore[6] = {3,4,1,9,0,1};
    stampaArray(vettore,6);
    insertionSort(vettore,6);
    stampaArray(vettore,6);
    
}  