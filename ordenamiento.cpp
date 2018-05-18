#include <iostream>
#include <string>

using namespace std;


void insertionSort(int arr[], int n){
   int i, key, j;
   for (i = 1; i < n; i++){
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key){
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

void bubbleSort(int arr[], int n)
{
   int i, j , key;
   for (i = 0; i < n-1; i++){
       for (j = 0; j < n-i-1; j++){
           if (arr[j] > arr[j+1]){
                key = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=key;

           }
       }
   }
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx,key;
    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++){
          if (arr[j] < arr[min_idx]){
            min_idx = j;
          }
        }
    key = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i]=key;
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
    if(b == "selection"){
        cout << "\nSu array ordenado: " <<endl;
        selectionSort(arr,a);
        for(int i =0;i<a;i++){
            cout << arr[i] << " ";
        }
    }
    else if(b == "insertion"){
        cout << "\nSu array ordenado: " <<endl;
        insertionSort(arr,a);
        for(int i =0;i<a;i++){
            cout << arr[i] << " ";
        }
    }
    else if(b == "bubble"){
        cout << "\nSu array ordenado: " <<endl;
        bubbleSort(arr,a);
        for(int i =0;i<a;i++){
            cout << arr[i] << " ";
        }
    }
}




