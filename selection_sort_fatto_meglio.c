#include <stdio.h>


void scambia(int *a, int *b){
    int appoggio = *a;
    *a = *b;
    *b = appoggio;
    return;
}

int idx_minimo(int v[],int inizio,int fine){
    int indice_min;
    for(int i = inizio; i <= fine; i++){
        if(i == inizio || v[i] < v[indice_min]){
            indice_min = i;
        }
        //altrimenti non fa nulla
    }
    return indice_min;
}

void selection_sort(int v[], int dimensione){
    for( int i = 0; i < dimensione-1; i++) {
        int pos_min = idx_minimo(v,i,dimensione-1);
        scambia(&v[i],&v[pos_min]);
        }

}


void stampaArray(const int *arr, int dimensione){
    for(int i = 0; i < dimensione; i++){
        printf(" %d ",*(arr+i));
    }printf(" \n");
}

int main(){
    int vettore[6] = {5,6,2,1,7,8};
    stampaArray(vettore,6);
    selection_sort(vettore,6);
   
    stampaArray(vettore,6);
}