#include <iostream>
#include <string>
#include<stdlib.h>
#include <time.h>

using namespace std;

class Bubble{
public:
    virtual void ordenamiento(int arr[],int n){
        return; }
    void cambio(int *xp, int *yp){
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
    void printArray(int arr[], int tam){
        int i;
        for (i=0; i < tam; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

class Ascendente: public Bubble{
public:
    void ordenamiento(int arr[], int n){
       int i, j;
       for (i = 0; i < n-1; i++)
           for (j = 0; j < n-i-1; j++)
               if (arr[j] > arr[j+1])
                  cambio(&arr[j], &arr[j+1]);
    }
    void operator()(int arr[],int n){
       int i, j;
       for (i = 0; i < n-1; i++)
           for (j = 0; j < n-i-1; j++)
               if (arr[j] > arr[j+1])
                  cambio(&arr[j], &arr[j+1]);
    }
};

class Descendente: public Bubble{
public:
    void ordenamiento(int arr[], int n){
       int i, j;
       for (i = 0; i < n-1; i++)
           for (j = 0; j < n-i-1; j++)
               if (arr[j] < arr[j+1])
                  cambio(&arr[j], &arr[j+1]);
    }
    void operator()(int arr[],int n){
       int i, j;
       for (i = 0; i < n-1; i++)
           for (j = 0; j < n-i-1; j++)
               if (arr[j] < arr[j+1])
                  cambio(&arr[j], &arr[j+1]);
    }
};

void generarArr(int arr[],int tam){
    for(int i=0;i<tam;i++){
        arr[i] = rand()%1000;
    }
}

void printArray1(int arr[], int tam){
    int i;
    for (i=0; i < tam; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void cambio1(int *xp, int *yp){
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
}

void asc(int arr[], int n){
       int i, j;
       for (i = 0; i < n-1; i++)
           for (j = 0; j < n-i-1; j++)
               if (arr[j] > arr[j+1])
                  cambio1(&arr[j], &arr[j+1]);
}

void des(int arr[], int n){
       int i, j;
       for (i = 0; i < n-1; i++)
           for (j = 0; j < n-i-1; j++)
               if (arr[j] < arr[j+1])
                  cambio1(&arr[j], &arr[j+1]);
}

int main(){
    srand(time(NULL));
    /*int arr[8] = {12,11,78,1,54,45,98,122}; //herencia
    Ascendente hola;
    hola.ordenamiento(arr,8);
    hola.printArray(arr,8);
    return 0;*/

    /*int arr[8] = {12,11,78,1,54,45,98,122}; //pointer function
    void (*ordenar)(int arr[], int);
    ordenar = des;
    ordenar(arr,8);
    printArray1(arr,8);
    return 0;*/

   // int arr[8] = {12,11,78,1,54,45,98,122}; //functor
    int arr[100];
    generarArr(arr,100);
    Ascendente hola;
    hola(arr,100);
    hola.printArray(arr,100);

}
