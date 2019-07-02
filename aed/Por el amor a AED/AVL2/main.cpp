#include<iostream>
#include <vector>
#include <stack>
#include <queue>
#include "avl.h"

using namespace std;

int main(){
    BST t;
     //1-8-3-7-2-9-4-5-6
    int ins[9] = {1,8,3,7,2,9,4,5,6};
    int el[4] = {6,8};
    int y1,y2;
    for(int i=1;i<10;i++){
            /*
        cout << "Que numero desea agregar?: ";
        cin >> y1;
        cout << endl;
        t.insert(y1);*/
        t.insert(i);
    }
    t.printNiv();
    for(int i=0;i<2;i++){
        /*
        cout << "Que numero desea eliminar?: ";
        cin >> y2;
        cout << endl;
        t.remove(y2);
        */
        t.remove(el[i]);
    }
    t.printNiv();
    /*
    for(int i=0;i<4;i++){
        t.remove(el[i]);
    }
    */


}
