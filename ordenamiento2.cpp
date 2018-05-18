#include <iostream>

using namespace std;
void imprimirLista(int lista[],int n){
    for(int i =0;i<n-1;i++){
        cout<<lista[i]<<",";
    }
    cout<<lista[n-1]<<"\n";
}
void cambio(int*a,int*b){
    int aux=*a;
    *a=*b;
    *b=aux;
}
void cocktail(int lista[],int n){
    bool flag;
    int i,aux,inicio=0,fin=n-1,iv=1;
    do{
        flag=false;
        for(i=inicio;i!=fin;i+=iv){
            if(lista[i]>lista[i+1]){
                cambio(&lista[i],&lista[i+1]);
                flag=true;
            }
        }
        if(iv==1){
            fin--;
            cambio(&fin,&inicio);
        }else if(iv==-1){
            inicio++;
            cambio(&fin,&inicio);
        }
        iv*=-1;
    }while(flag);
}
int part(int lista[],int inicio,int fin){
    int pivote=lista[fin];
    int j,i=inicio-1;
    for(j=inicio;j<=fin-1;j++){
        if(lista[j]<pivote){
            i++;
            cambio(&lista[i],&lista[j]);
        }
    }
    cambio(&lista[i+1],&lista[fin]);
    return i+1;
}
void quickSort(int lista[],int inicio,int fin){
    if(inicio<fin){
        int pivote=part(lista,inicio,fin);
        quickSort(lista,inicio,pivote-1);
        quickSort(lista,pivote+1,fin);
    }
}
int main(){
    while(true){
        int n=1000;
        cout<<"ingresa la cantidad de elementos";
        cin>>n;
        int lista[n];
        for(int i=0;i<n;i++){
            lista[i]=n-i;
            //cout<<"ingresa el elemento "<<i;
            //cin>>lista[i];
        }
        cout <<"lista a ordenar";
        imprimirLista(lista,n);
        char a;
        cin>>a;
        if(a=='c'){
            cocktail(lista,n);
        }else if(a=='q'){
            quickSort(lista,0,n);
        }
        imprimirLista(lista,n);
    }
    return 0;
}
