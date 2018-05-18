#include <iostream>
#include <string>

using namespace std;

void swap1(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void insertionSort1(int *a, int n){

    int key;
    int *j;
    for(int *i = a+1; i < a+n; i++){
        key = *i;
        j = i-1;
        while(j >= a && *j > key){
            *(j+1) = *(j);
            j--;
        }
        *(j+1) = key;
    }
}

void bubbleSort1(int *a , int n){
    for(int i =0;i<n-1;i++){
        for(int *j = a;j < a+n-i-1;j++ ){
            if( *j > *(j+1) ){
                swap1(j,j+1);
            }
        }
    }

}
int main (){
    string b;
    int a;
    cout << "Cuantos datos tendra su array?: "<<endl;
    cin >> a;
    cout << "Que algoritmo de orden desea usar?: "<<endl;
    cin >> b;
    int* arr = new int[a];
    for(int i=0;i<a;i++){
        cout << "Ingrese el dato " << i+1 << ": "<<endl;
        cin >> arr[i];
    }
    cout << "Su array: "<<endl;
    for(int i =0;i<a;i++){
        cout << arr[i] << " ";
    }

    if(b == "insertion"){
        cout << "\nSu array ordenado: " <<endl;
        insertionSort1(arr,a);
        for(int i =0;i<a;i++){
            cout << arr[i] << " ";
        }
    }
    else if(b == "bubble"){
        cout << "\nSu array ordenado: " <<endl;
        bubbleSort1(arr,a);
        for(int i =0;i<a;i++){
            cout << arr[i] << " ";
        }
    }
}

