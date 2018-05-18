#include <iostream>

using namespace std;

int main()
{
    int cantidades[]={7,5,3,1};
    int leche;
    cout << "Cuantos litros se dividiran?: " << endl;
    cin>>leche;
    cout << "Se divide en:" << endl;
    for(int i=0;i<4;i++){
        int n=leche/cantidades[i];
        cout << n;
        if(n==1){
            cout<<" botella de ";
        }else{
            cout<<" botellas de ";
        }

            cout << cantidades[i] << " litros ";
        leche%=cantidades[i];
        if(i==2){
            cout<<" y ";
        }
    }

    return 0;
}
