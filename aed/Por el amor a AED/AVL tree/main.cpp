#include "CTree.h"
#include<iostream>

using namespace std;

int main(){
    Arbol_AVL<int> my_tree;
    //1-8-3-7-2-9-4-5-6
    int x;
    for (int i = 0; i < 9  ; i++) {
        cin >> x;
        my_tree.insertar(x);
        cout << endl;
    }
    my_tree.printNiv();
    cout << "Remove aca" << endl;
    int y;
    for(int i = 0;i<3;i++){
        cin >> y;
        my_tree.Remover(y);
    }
    my_tree.printNiv();
}
